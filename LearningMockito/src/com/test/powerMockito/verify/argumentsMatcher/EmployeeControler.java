package com.test.powerMockito.verify.argumentsMatcher;

public class EmployeeControler {

	public String getEmail(String userName) {
		System.out.println("EmployeeControler-->getEmail");
		
		EmployeeService employeeService = new EmployeeService();
		String email = employeeService.findEmailByUserName(userName);
		return email;
	}
}
