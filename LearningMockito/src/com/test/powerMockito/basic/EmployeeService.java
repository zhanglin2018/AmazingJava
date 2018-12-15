package com.test.powerMockito.basic;

public class EmployeeService {
	private EmployeeDao employeeDao;

	public EmployeeService(EmployeeDao employeeDao) {
		super();
		this.employeeDao = employeeDao;
	}
	
	public int getTotalEmployee() {
		return employeeDao.getTotal();
	}
	
	public void createEmployee(Employee employee) {
		employeeDao.addEmployee(employee);
	}
}
