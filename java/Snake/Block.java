package game;

import java.awt.Graphics2D;
import java.awt.Rectangle;

// Block is each block on the grid

public class Block {
	private int x,y;
	private int size;
	public Block(int size){
		this.size = size;
	}
	
	
	public int getX() {
		return x;
	}


	public void setX(int x) {
		this.x = x;
	}


	public int getY() {
		return y;
	}


	public void setY(int y) {
		this.y = y;
	}

	public void setPosition(int x, int y){
		this.x = x;
		this.y = y;
	}
	public void move(int dx, int dy){
		x +=  dx;
		y += dy;
	}
	
	public Rectangle getBound(){
		return new Rectangle(x, y, size, size);
	}
	
	public boolean isCollision(Block o){
		if(o == this) return false;
		// Check for other entity collision by checking 
		// if other object o intersects with this object
		return getBound().intersects(o.getBound());
	}
	
	public void render(Graphics2D g2d){
		// Draw a rectangle a pixel less than grid size
		g2d.fillRect(x+1, y+1, size-2, size-2);
	}

}
