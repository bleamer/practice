package org.springdemo;

import org.springframework.beans.factory.BeanFactory;
import org.springframework.beans.factory.xml.XmlBeanFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.core.io.FileSystemResource;
import java.nio.file.Paths;

public class DrawingApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		

		ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
		BeanFactory factory = context;
		Triangle triangle = (Triangle)factory.getBean("triangle");
		triangle.draw();
		
		System.out.println(context.getMessage("greeting", new Object[]{5,10}, "Greeting not found!", null));
		System.out.println(context.getMessage("drawing.point", new Object[]{5,10}, "Greeting not found!", null));
	}

}
