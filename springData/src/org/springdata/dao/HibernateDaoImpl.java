package org.springdata.dao;

import org.hibernate.SessionFactory;

public class HibernateDaoImpl {
	private SessionFactory sessionFactory;
	
	
	public SessionFactory getSessionFactory() {
		return sessionFactory;
	}


	public void setSessionFactory(SessionFactory sessionFactory) {
		this.sessionFactory = sessionFactory;
	}


	public int getCircleCount(){
		String sql = "SELECT COUNT(*) FROM CIRCLE";
		return 0;
	}
}
