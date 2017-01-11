package org.jdbcdemo;

import java.sql.SQLException;

import org.jdbcdemo.dao.JdbcDaoImpl;
import org.jdbcdemo.model.Circle;

public class JdbcDemo {
	public static void main(String[] args){
		Circle circle = null;
		try {
			circle = new JdbcDaoImpl().getCircle(1);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(circle.getName());
	}
}
