package com.test.powerMockito.staticMock;

public class EmployeeService {

	public int getTotalEmployee() {
		System.out.println("EmployeeService->getTotalEmployee");
		return EmployeeUtils.getTotal();
	}
	
	public void createEmployee(Employee employee) {
		System.out.println("EmployeeService->createEmployee");
		EmployeeUtils.addEmployee(employee);
	}
}
