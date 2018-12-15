package com.test.powerMockito.basic.constructorMock;

import com.test.powerMockito.basic.constructorMock.EmployeeDao.Dialect;

public class EmployeeService {
	
	public void createEmployee(Employee employee) {
		EmployeeDao employeeDao = new EmployeeDao(false, Dialect.MYSQL);
		employeeDao.addEmployee(employee);
	}
}
