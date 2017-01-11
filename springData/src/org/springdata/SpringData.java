package org.springdata;

import java.sql.SQLException;

import org.springdata.dao.JdbcDaoImpl;
import org.springdata.model.Circle;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringData {
	public static void main(String[] args){
		
		// Create the context of application based on the file
		ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");
		// Get an instance of the class JdbcDaoImpl from the above context
		JdbcDaoImpl dao = context.getBean("jdbcDaoImpl", JdbcDaoImpl.class);
		
		Circle circle = null;
		try {
			circle = dao.getCircle(1);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		dao.insertCircle(new Circle(10,"TenthCircle"));
//		dao.createTriangle();	
		System.out.println(circle.getName());
		System.out.println(dao.getCircleCount());
		System.out.println(dao.getCircleName(1));
		System.out.println(dao.getCircleForId(1).getName());
		System.out.println(dao.getAllCircles().size());
	}
}
