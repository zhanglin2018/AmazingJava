package com.test.powerMockito.localVariable;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import java.security.Provider.Service;

import org.junit.Test;
import org.powermock.api.mockito.PowerMockito;


/*
 * �ܽ᣺
 * 1����Ҫ���Ժ����еľֲ����������Ǿֲ������е�ĳЩ������Ҫ����һЩ��Դ���������Ӳ��ϣ���Ҫͨ��
 * �쳣�ķ�ʽ����ģ��
 * 2������mockito�� ����֧�� ������ �ֲ������� mock,���Ժ����е� �ֲ�����Ϊ new ��������ʵ������
 * �������ʵ�ĺ��������Իᱨ�����쳣
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
