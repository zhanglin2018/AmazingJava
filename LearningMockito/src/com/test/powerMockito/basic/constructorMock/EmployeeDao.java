package com.test.powerMockito.basic.constructorMock;

public class EmployeeDao {
	public enum Dialect{
		MYSQL,
		ORACLE
	}
	
	public EmployeeDao(boolean lazy, Dialect dialect) {
		System.out.println("EmployeeDao->constructor");

		throw new UnsupportedOperationException();
	}


	public void addEmployee(Employee employee) {
		System.out.println("EmployeeDao->addEmployee");
		
		throw new UnsupportedOperationException();
	}
}
