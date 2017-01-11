package org.springdemo;

import org.springframework.beans.BeansException;
import org.springframework.beans.factory.BeanNameAware;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationContextAware;
import org.springframework.context.ApplicationEventPublisher;
import org.springframework.context.ApplicationEventPublisherAware;
import org.springframework.context.MessageSource;

public class Triangle implements ApplicationContextAware, BeanNameAware, ApplicationEventPublisherAware {
	private String type;
	private int height; 
	private ApplicationContext context = null;
	private MessageSource messageSource;
	private ApplicationEventPublisher publisher;

	@Autowired
	public void setMessageSource(MessageSource messageSource) {
		this.messageSource = messageSource;
	}
	public Triangle(String type){
		this.type = type;
	}
	public Triangle(int ht){
		this.height = ht;
	}
	public Triangle(String type, int ht){
		this.type = type;
		this.height = ht;
	}
	public void draw(){
		System.out.println("Triangle drawn of type = "+ getType() + " and of height = " + getHeight());
//		System.out.println(this.messageSource.getMessage("drawing.triangle", null, "default triangle message", null));
		publisher.publishEvent(new DrawEvent(this));
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}
	public int getHeight() {
		return height;
	}
	public void setHeight(int height) {
		this.height = height;
	}
	
	@Override
	public void setApplicationContext(ApplicationContext context) throws BeansException {
		// TODO Auto-generated method stub
		this.context = context;
	}
	@Override
	public void setBeanName(String arg0) {
		System.out.println("Bean name = "+ arg0);

	}
	@Override
	public void setApplicationEventPublisher(ApplicationEventPublisher publisher) {
		this.publisher = publisher;
		
	}
}
