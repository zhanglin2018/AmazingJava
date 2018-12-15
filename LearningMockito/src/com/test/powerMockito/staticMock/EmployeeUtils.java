package com.test.powerMockito.staticMock;

public class EmployeeUtils {
	public static int getTotal() {
		System.out.println("EmployeeUtils-->getTotal");
		
		throw new UnsupportedOperationException();
	}

	public static void addEmployee(Employee employee) {
		System.out.println("EmployeeUtils-->addEmployee");

		throw new UnsupportedOperationException();
	}
}
