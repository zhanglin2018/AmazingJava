package com.test.powerMockito.verify.argumentsMatcher;

public class EmployeeService {
	public String findEmailByUserName(String userName) {
		System.out.println("EmployeeService-->findEmailByUserName");
		throw new UnsupportedOperationException();
	}
}
