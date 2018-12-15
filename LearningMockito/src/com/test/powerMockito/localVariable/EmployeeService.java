package com.test.powerMockito.localVariable;

public class EmployeeService {

	public int getTotalEmployee() {
		System.out.println("EmployeeService->getTotalEmployee");
		EmployeeDao employeeDao = new EmployeeDao();
		return employeeDao.getTotal();
	}
	
	public void createEmployee(Employee employee) {
		System.out.println("EmployeeService->createEmployee");
		EmployeeDao employeeDao = new EmployeeDao();
		employeeDao.addEmployee(employee);
	}
}
