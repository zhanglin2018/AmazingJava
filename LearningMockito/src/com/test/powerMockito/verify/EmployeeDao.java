package com.test.powerMockito.verify;

public class EmployeeDao {
	public void saveEmployee(Employee employee) {
		System.out.println("EmployeeDao-->saveEmployee");

		throw new UnsupportedOperationException();
	}
	
	public void updateEmployee(Employee employee) {
		System.out.println("EmployeeDao-->updateEmployee");
		
		throw new UnsupportedOperationException();
	}
	
	public int getCount(Employee employee) {
		System.out.println("EmployeeDao-->getCount");
		
		throw new UnsupportedOperationException();
	}
}
