package com.test.powerMockito.verify;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;


import org.junit.Test;
import org.junit.runner.RunWith;
import org.powermock.api.mockito.PowerMockito;
import org.powermock.core.classloader.annotations.PowerMockIgnore;
import org.powermock.core.classloader.annotations.PrepareForTest;
import org.powermock.modules.junit4.PowerMockRunner;
import org.powermock.modules.junit4.legacy.internal.impl.testcaseworkaround.PowerMockJUnit4LegacyTestIntrospector;


/*
 *目的：该测试类用来测试 函数中的局部变量的问题，针对mockito库 函数中的局部变量不能mock的情况
 *总结：
 *1、注意PowerMockRunner.class 的 导入 路径，不然会报错
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeService.class)
public class EmployeeServiceTest {
	
	/*
	 * 局部变量的 mock方式
	 */
	@Test
	public void testGetTotalEmployee() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			Employee employee = new Employee("hanjiaojiao", 26);

			
			PowerMockito.when(employeeDao.getCount(employee)).thenReturn(0);

			EmployeeService employeeService = new EmployeeService();
			employeeService.saveOrUpdate(employee);

			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/*
	 * verify: count > 0
	 */
	@Test
	public void testGetTotalEmployee1() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			Employee employee = new Employee("hanjiaojiao", 26);
			
			
			PowerMockito.when(employeeDao.getCount(employee)).thenReturn(10);
			
			EmployeeService employeeService = new EmployeeService();
			employeeService.saveOrUpdate(employee);
			
			verify(employeeDao).updateEmployee(employee);
			verify(employeeDao, never()).saveEmployee(employee);
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/*
	 * verify: count < 0
	 */
	@Test
	public void testGetTotalEmployee2() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			Employee employee = new Employee("hanjiaojiao", 26);
			
			
			PowerMockito.when(employeeDao.getCount(employee)).thenReturn(0);
			
			EmployeeService employeeService = new EmployeeService();
			employeeService.saveOrUpdate(employee);
			
			verify(employeeDao, never()).updateEmployee(employee);
			verify(employeeDao).saveEmployee(employee);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	
}
