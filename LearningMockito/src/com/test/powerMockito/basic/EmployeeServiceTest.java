package com.test.powerMockito.basic;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import java.security.Provider.Service;

import org.junit.Test;
import org.powermock.api.mockito.PowerMockito;


/*
 * �ܽ᣺
 * 1��mock��ʱ�򣬵��õĺ���������ٵģ�������������ĺ���
 */
public class EmployeeServiceTest {
	
	@Test
	public void testGetTotalEmployee() {
		final EmployeeDao employeeDao = new EmployeeDao();
		final EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	@Test
	public void testGetTotalEmployeeWithMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * ����mock��������ٵ���
	 * Ĭ�ϵ�����£�����int��Ϊ��0
	 */
	@Test
	public void testGetTotalEmployeeWithMock1() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		//when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * thenCallTealMethod() �������ʵ�ĺ����������Զ����ֵ
	 */
	@Test
	public void testGetTotalEmployeeWithMock2() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		when(employeeDao.getTotal()).thenCallRealMethod().thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * spy�Ƕ�new�����Ķ�����м��ӣ����õ�����ʵ�ĺ���
	 */
	@Test
	public void testGetTotalEmployeeWithMock3() {
		EmployeeDao employeeDao = spy(new EmployeeDao());
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * spy�Ƕ�new�����Ķ�����м���
	 * ����whenģ�⺯���ĵ��������spy�����Ķ��󣬵��õ�����ʵ�ĺ��������Ƿ���ֵ���Զ����ֵ
	 */
	@Test
	public void testGetTotalEmployeeWithMock4() {
		EmployeeDao employeeDao = spy(new EmployeeDao());
		when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * spy�Ƕ�new�����Ķ�����м���
	 * ���ģ�������ٵĺ����أ�
	 * ͨ��doreturn�������,��ʱ�������employeeDao����ĺ���ֵ��
	 */
	@Test
	public void testGetTotalEmployeeWithMock5() {
		EmployeeDao employeeDao = spy(new EmployeeDao());
		doReturn(10).when(employeeDao).getTotal();
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * ʹ��powerMockito���в���
	 * spy�Ƕ�new�����Ķ�����м���
	 * ���ģ�������ٵĺ����أ�
	 * ͨ��doreturn�������,��ʱ�������employeeDao����ĺ���ֵ��
	 */
	@Test
	public void testGetTotalEmployeeWithMock6() {
		EmployeeDao employeeDao = PowerMockito.spy(new EmployeeDao());
		
		PowerMockito.doReturn(10).when(employeeDao).getTotal();
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	@Test
	public void testGetTotalEmployeeWithPowerMock() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		PowerMockito.when(employeeDao.getTotal()).thenReturn(10);
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}

	@Test
	public void testCreateEmployeeWithMock() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		Employee employee = new Employee("zhanglin", 26);
		
		doNothing().when(employeeDao).addEmployee(employee);
		
		EmployeeService employeeService = new EmployeeService(employeeDao);
		employeeService.createEmployee(employee);
		
		verify(employeeDao).addEmployee(employee);
		
	}
	
	@Test
	public void testCreateEmpoyeeWithPowerMock() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		Employee employee = new Employee("zhanglin", 26);
		
		PowerMockito.doNothing().when(employeeDao).addEmployee(employee);
		
		EmployeeService employeeService = new EmployeeService(employeeDao);
		employeeService.createEmployee(employee);
		
		verify(employeeDao).addEmployee(employee);
	}
	
	
	
	
	
	
}
