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
 * �ܽ᣺
 * 1��mock��ʱ�򣬵��õĺ���������ٵģ�������������ĺ���
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
	 * Mockito ���ܹ���final class �� ����mock
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
	 * ʹ��PowerMockito ��final class�����mock
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
	 * ʹ��PowerMockito ��final class�����mock
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
