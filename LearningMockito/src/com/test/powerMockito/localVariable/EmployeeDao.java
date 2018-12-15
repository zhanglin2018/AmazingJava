package com.test.powerMockito.localVariable;

public class EmployeeDao {
	public int getTotal() {
		System.out.println("EmployeeDao-->getTotal");
		
		throw new UnsupportedOperationException();
	}

	public void addEmployee(Employee employee) {
		System.out.println("EmployeeDao-->addEmployee");

		throw new UnsupportedOperationException();
	}
}
