package com.test.powerMockito.basic.finalMock;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import java.security.Provider.Service;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.powermock.api.mockito.PowerMockito;
import org.powermock.core.classloader.annotations.PrepareForTest;
import org.powermock.modules.junit4.PowerMockRunner;


/*
 * 总结：
 * 1、mock的时候，调用的函数都是虚假的，不会调用真正的函数
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeDao.class)
public class EmployeeServiceTest {
	
	@Test
	public void testGetTotalEmployee() {
		EmployeeDao employeeDao = new EmployeeDao();
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * Mockito 不能够对final class 类 进行mock
	 */
	@Test
	public void testGetTotalEmployeeWithMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * 使用PowerMockito 对final class类进行mock
	 */
	@Test
	public void testGetTotalEmployeeWithPowerMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * 使用PowerMockito 对final class类进行mock
	 */
	@Test
	public void testGetTotalEmployeeWithPowerMock1() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		Employee employee = new Employee("zhanglin", 26);
		
		PowerMockito.when(employeeDao.addEmployee(employee)).thenReturn(true);
		
		EmployeeService service = new EmployeeService(employeeDao);
		service.createEmployee(employee);
		
		verify(employeeDao).addEmployee(employee);
	}
	

	
	
	
	
}
