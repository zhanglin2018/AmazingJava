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
 *Ŀ�ģ��ò������������� �����еľֲ����������⣬���mockito�� �����еľֲ���������mock�����
 *�ܽ᣺
 *1��ע��PowerMockRunner.class �� ���� ·������Ȼ�ᱨ��
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
	 * ����ʹ�� PowerMockito�Ƿ��ܹ����� ��̬������mock
	 * 1��������Ҫʹ��mockStatic����������ģ��
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
