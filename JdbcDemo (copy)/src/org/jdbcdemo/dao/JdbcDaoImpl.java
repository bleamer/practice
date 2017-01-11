package org.jdbcdemo.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


import org.jdbcdemo.model.Circle;

public class JdbcDaoImpl {

	public Circle getCircle(int circleId) throws SQLException{
		Connection conn = null;
		
		String driver = "org.apache.derby.jdbc.ClientDriver";
		try {
			Class.forName(driver).newInstance();
			conn = DriverManager.getConnection("jdbc:derby://localhost:1527/db");
			PreparedStatement  ps = conn.prepareStatement("SELECT * FROM circle where id = ?");
			ps.setInt(1, circleId);
			
			Circle circle = null;
			ResultSet rs = (ResultSet) ps.executeQuery();
			
			if (rs.next()){
				circle = new Circle(circleId, rs.getString("name"));
			}
			rs.close();
			ps.close();
			return circle;
			
		} catch (Exception e){
			throw new RuntimeException();
		}
		finally{
			try{
				conn.close();
			}
			catch(SQLException ec){
				
			}
		}


	}
}
