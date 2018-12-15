package com.test.powerMockito.verify;

public class EmployeeService {
	public void saveOrUpdate(Employee employee) {
		System.out.println("EmployeeService->saveOrUpdate");	
		
		EmployeeDao employeeDao = new EmployeeDao();
		int count = employeeDao.getCount(employee);
		
		if (count > 0) {
			employeeDao.updateEmployee(employee);
		} else {
			employeeDao.saveEmployee(employee);
		}
	}
}
