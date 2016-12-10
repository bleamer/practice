 package game;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class GamePanel extends JPanel implements Runnable, KeyListener {

	public static final int WIDTH =400;
	public static final int HEIGHT=400;

	private Graphics2D g2d;
	private BufferedImage image;
	
	private Thread thread;
	private boolean running;
	private long targetTime;
	
	// Game logic
	private final int SIZE=10;
	Block head, food;
	ArrayList<Block> snake;
	private int score;
	private int level;
	private boolean gameover;

	private String GameOverString = "Game Over !!";
	private String ReadyString = "Ready";
	
	// animation / movement
	private int dx, dy;
	
	// keyboard input 
	private boolean up, down, right, left, start; 
	
	public GamePanel(){
		setPreferredSize(new Dimension(WIDTH,HEIGHT));
		setFocusable(true);
		requestFocus();
		addKeyListener(this);
		
	}
	
	@Override
	public void addNotify() {
		super.addNotify();
		thread = new Thread(this);
		thread.start();
	}
	
	private void setFPS(int fps){
		targetTime = 1000 / fps;
	}
	@Override
	public void keyPressed(KeyEvent e) {
		int k = e.getKeyCode();
		if (k == KeyEvent.VK_UP) 	up = true;
		if (k == KeyEvent.VK_DOWN) 	down = true;
		if (k == KeyEvent.VK_LEFT) 	left = true;
		if (k == KeyEvent.VK_RIGHT) right = true;
		if (k == KeyEvent.VK_ENTER) start = true;
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		int k = arg0.getKeyCode();
		if (k == KeyEvent.VK_UP) 	up = false;
		if (k == KeyEvent.VK_DOWN) 	down = false;
		if (k == KeyEvent.VK_LEFT) 	left = false;
		if (k == KeyEvent.VK_RIGHT) right = false;
		if (k == KeyEvent.VK_ENTER) start = false;

	}

	@Override
	public void keyTyped(KeyEvent arg0) {

	}

	@Override
	public void run() {
		if (running) return;
		init();
		long startTime;
		long elapsed;
		long wait;
		while(running){
			startTime = System.nanoTime();
			
			update();
			requestRender();
			
			
			elapsed =  System.nanoTime() - startTime;
			wait = targetTime - elapsed / 1000000;
			if (wait > 0){
				try {
					Thread.sleep(wait);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}
	private void update() {
		
		if (gameover){			// If game is over
			if(start){			// If enter key was pressed
				setUpLevel();	// Set up the game
			}
			return;
		}
		
		
		if (up && dy == 0){		// If up key is pressed we are not moving vertically
			dy = -SIZE;			// set move Y rate to 1 block size up
			dx = 0;
		}
		if (down && dy == 0){	// If down key is pressed we are not moving vertically 
			dy = SIZE;			// set move Y rate to 1 block size down
			dx = 0;
		}
		if (left && dx == 0){	// If left key is pressed we are not moving horizontally already
			dy = 0;
			dx = -SIZE;			// set move X rate to 1 block size left
		}
		if (right && dx == 0 && dy != 0){	// If right key is pressed we are not moving horizontally already
			dy = 0;
			dx = SIZE;			// set move X rate to 1 block size right
		}
		if (dx != 0 || dy != 0){ // If we are moving vertically or horizontally
			for(int i = snake.size()-1; i > 0;i--){ // for all snake blocks
				snake.get(i).setPosition( // set the position of current block to position of previous block
						snake.get(i-1).getX(),
						snake.get(i-1).getY());
			}
			head.move(dx,dy); 	// Advance head block by one block element
		}
		
		for (Block e : snake){		// Check head for collision against snake blocks
			if(e.isCollision(head)){
				gameover = true;
			}
		}
		
		if (food.isCollision(head)){ // if the head element hits a food item
			score++;					// increment the score
			setFood();					// set the next food item
			
			Block e = new Block(SIZE);	// Create a new block to simulate growth of size of snake after eating food 
			e.setPosition(-100, -100);
			snake.add(e);				// Add to snake list
			if ((score % 10) == 0){		// Level up according to score
				level++;
				if (level > 10) level = 10;
				setFPS(level * 10);
			}
		
		}
		// If the head hits a boundary, fold the 
		// head to other side of frame
		
		if (head.getX() < 0) head.setX(WIDTH);
		if (head.getY() < 0) head.setY(HEIGHT);
		if (head.getX() > WIDTH) head.setX(0);
		if (head.getY() > HEIGHT) head.setY(0);
	}

	private void requestRender() {
		render(g2d);
		Graphics g = getGraphics(); // get the graphics context
		g.drawImage(image, 0, 0, null); // Draw as much as image is available at this point
		g.dispose(); // release the graphics context and system resources
	}

	public void render(Graphics2D g2d){
		g2d.clearRect(0, 0, WIDTH,HEIGHT); // Clear the canvas

		// Draw the head element of snake
		g2d.setColor(Color.BLUE);		
		Block e = snake.get(0);
		e.render(g2d);
		//Draw other elements of snake
		g2d.setColor(Color.GREEN);
		for(int i = 1; i < snake.size(); i++){
			e = snake.get(i);
			e.render(g2d);
		}
		
//		for(Entity e:snake){
//			e.render(g2d);
//		}
		
		
		// Draw the string for "Game over" based on condition
		g2d.setColor(Color.RED);
		food.render(g2d);
		if (gameover){
			int strwidth = g2d.getFontMetrics().stringWidth(GameOverString);
			int strHeight = g2d.getFontMetrics().getHeight();
			g2d.drawString(GameOverString,(WIDTH-strwidth)/2, (HEIGHT-strHeight)/2);
		}
		
		// Draw the ready string anc current score and levels
		g2d.setColor(Color.WHITE);
		if(dx == 0 && dy == 0){
			int strwidth = g2d.getFontMetrics().stringWidth(ReadyString);
			int strHeight = g2d.getFontMetrics().getHeight();
			g2d.drawString(ReadyString, (WIDTH-strwidth)/2, (HEIGHT-strHeight)/2);
		}		g2d.drawString("Score : " + score + " Level : "+level, 10, 10);
		
		
	}
	private void init(){
		image = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_ARGB);
		g2d = image.createGraphics(); // create a buffered image graphics for updating
		running = true;
		setUpLevel();
		gameover = false;
		level = 1;
		
		setFPS(10 * level);
		
	}
	
	public void setUpLevel(){
		snake = new ArrayList<Block>();
		head = new Block(SIZE);
		head.setPosition(WIDTH/2, HEIGHT/2);
		snake.add(head);
		for (int i =1 ; i < 5; i++){
			Block e = new Block(SIZE);
			e.setPosition(head.getX() + (i*SIZE), head.getY());
			snake.add(e);
		}
		food = new Block(SIZE);
		setFood();
		score = 0;
		gameover = false;
		level = 1;
		dx = dy = 0;
		setFPS(level * 10);
	}
	public void setFood(){
		int x = (int)(Math.random()*(WIDTH-SIZE));
		int y = (int)(Math.random()*(HEIGHT-SIZE));
		x = x - (x % SIZE);
		y = y - (y % SIZE);
		
		food.setPosition(x, y);
	}

}
