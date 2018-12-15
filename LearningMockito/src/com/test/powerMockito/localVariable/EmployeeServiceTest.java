package com.test.powerMockito.localVariable;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import java.security.Provider.Service;

import org.junit.Test;
import org.powermock.api.mockito.PowerMockito;


/*
 * 总结：
 * 1、需要测试函数中的局部变量，但是局部变量中的某些函数需要连接一些资源，但是连接不上，需要通过
 * 异常的方式进行模拟
 * 2、由于mockito库 并不支持 函数内 局部变量的 mock,所以函数中的 局部变量为 new 出来的真实变量，
 * 会调用真实的函数，所以会报出来异常
 *
 */
public class EmployeeServiceTest {
	
	@Test
	public void testGetTotalEmployee() {
		final EmployeeDao employeeDao = new EmployeeDao();
		final EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	@Test
	public void testGetTotalEmployeeWithMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	@Test
	public void testGetTotalEmployeeWithPowerMock() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		PowerMockito.when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}

	@Test
	public void testCreateEmployeeWithMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		Employee employee = new Employee("zhanglin", 26);
		
		doNothing().when(employeeDao).addEmployee(employee);
		
		EmployeeService employeeService = new EmployeeService();
		employeeService.createEmployee(employee);
		
		verify(employeeDao).addEmployee(employee);
		
	}
	
	@Test
	public void testCreateEmpoyeeWithPowerMock() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		Employee employee = new Employee("zhanglin", 26);
		
		PowerMockito.doNothing().when(employeeDao).addEmployee(employee);
		
		EmployeeService employeeService = new EmployeeService();
		employeeService.createEmployee(employee);
		
		verify(employeeDao).addEmployee(employee);
	} 
	
	
}
