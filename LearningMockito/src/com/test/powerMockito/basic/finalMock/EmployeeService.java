package com.test.powerMockito.basic.finalMock;

public class EmployeeService {
	private EmployeeDao employeeDao;

	public EmployeeService(EmployeeDao employeeDao) {
		super();
		this.employeeDao = employeeDao;
	}
	
	public int getTotalEmployee() {
		return employeeDao.getTotal();
	}
	
	public boolean createEmployee(Employee employee) {
		return employeeDao.addEmployee(employee);
	}
}
