package com.test.powerMockito.staticMock;

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
@PrepareForTest(EmployeeUtils.class)
public class EmployeeServiceTest2 {
	
	@Test
	public void testGetTotalEmployee() {
		EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	
	
	@Test
	public void testCreateEmployee() {
		EmployeeService service = new EmployeeService();
		Employee employee = new Employee("zhanglin", 26);
		service.createEmployee(employee);
		assertTrue(true);
	}
	
	/*
	 * 测试使用 PowerMockito是否能够进行 静态函数的mock
	 * 1、首先需要使用mockStatic函数，进行模拟
	 */
	@Test
	public void testGetTotalEmployeeWithPowerMockito() {
		PowerMockito.mockStatic(EmployeeUtils.class);
		PowerMockito.when(EmployeeUtils.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	@Test
	public void testCreateEmployeeWithPowerMockito() {		
		PowerMockito.mockStatic(EmployeeUtils.class);
//		PowerMockito.spy(EmployeeUtils.class);
		PowerMockito.doNothing().when(EmployeeUtils.class);

		EmployeeService service = new EmployeeService();
		Employee employee = new Employee("zhanglin", 26);
		service.createEmployee(employee);
		assertTrue(true);
	}
	
	
	

	
	
	
	
}
