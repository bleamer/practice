package org.springdata.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import javax.sql.DataSource;

import org.springdata.model.Circle;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.namedparam.MapSqlParameterSource;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.jdbc.core.namedparam.SqlParameterSource;
import org.springframework.stereotype.Component;

@Component
public class JdbcDaoImpl {
	
	@Autowired
	private DataSource dataSource;
	
	private JdbcTemplate jdbcTemplate = new JdbcTemplate();
	private NamedParameterJdbcTemplate namedParameterJdbcTemplate;

	
	public Circle getCircle(int circleId) throws SQLException{
		Connection conn = null;
		
		
		try {
			conn = dataSource.getConnection();
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
	
	public int getCircleCount(){
		String sql = "SELECT COUNT(*) FROM CIRCLE";
		return jdbcTemplate.queryForObject(sql, Integer.class);
	}

	public DataSource getDataSource() {
		return dataSource;
	}

	@Autowired
	public void setDataSource(DataSource dataSource) {
		this.dataSource = dataSource;
		this.jdbcTemplate.setDataSource(dataSource);
		this.namedParameterJdbcTemplate = new NamedParameterJdbcTemplate(dataSource);
	}
	
	public String getCircleName(int circleId){
		String sql = "SELECT NAME FROM CIRCLE WHERE ID = ?";
		return jdbcTemplate.queryForObject(sql,new Object[] {circleId}, String.class);
	}
	
	public Circle getCircleForId(int circleId){
		String sql = "SELECT * FROM CIRCLE WHERE ID = ?";
		return jdbcTemplate.queryForObject(sql, new Object[]{circleId}, new CircleMapper());
	}
	
	public List<Circle> getAllCircles(){
		String sql = "SELECT * FROM CIRCLE";
		return jdbcTemplate.query(sql, new CircleMapper());

	}
	
	
	public void insertCircle(Circle circle){
//		String sql = "INSERT INTO CIRCLE (ID, NAME) VALUES(?,?)";
//		jdbcTemplate.update(sql,new Object[] {circle.getId(),circle.getName()} );
		String sql = "INSERT INTO CIRCLE (ID, NAME) VALUES(:id,:name)";
		SqlParameterSource namedParameters =  new MapSqlParameterSource("id", circle.getId())
																.addValue("name", circle.getName());
		namedParameterJdbcTemplate.update(sql, namedParameters);
		
	}
	
	public void createTriangle(){
		String sql = "CREATE TABLE TRIANGLE (ID INTEGER, NAME VARCHAR(50))";
		jdbcTemplate.execute(sql);
	}
	private static final class CircleMapper implements RowMapper<Circle>{

		@Override
		public Circle mapRow(ResultSet resultSet, int rowNum) throws SQLException {
			Circle circle = new Circle();
			circle.setId(resultSet.getInt("ID"));
			circle.setName(resultSet.getString("NAME"));
			return circle;
		}
		
	}
}
