package com.test.powerMockito.basic.finalMock;

public final class EmployeeDao {
	public int getTotal() {
		System.out.println("EmployeeDao->getTotal");
		throw new UnsupportedOperationException();
//		return 5;
	}

	public boolean addEmployee(Employee employee) {
		System.out.println("EmployeeDao->addEmployee");
		throw new UnsupportedOperationException();
	}
}
