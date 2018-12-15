package com.test.powerMockito.basic;

public class EmployeeDao {
	public int getTotal() {
		System.out.println("EmployeeDao->getTotal");
		throw new UnsupportedOperationException();
//		return 5;
	}

	public void addEmployee(Employee employee) {
		System.out.println("EmployeeDao->addEmployee");
		throw new UnsupportedOperationException();
	}
}
