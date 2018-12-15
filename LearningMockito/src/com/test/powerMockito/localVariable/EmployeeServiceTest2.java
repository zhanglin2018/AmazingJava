package com.test.powerMockito.localVariable;

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
@PrepareForTest(EmployeeService.class)
public class EmployeeServiceTest2 { 
	
	@Test
	public void testGetTotalEmployee() {
		final EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * ����mockito ģ��ֲ������Ļ����÷�, û��whenNew���÷�
	 */
	@Test
	public void testMockito_localVariable() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		
		final EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * ����powerMockito ģ��ֲ������Ļ����÷�
	 * 1��ͨ��powerMockito.mock() ����mock����
	 * 2��ͨ��PowerMockito.whenNew() �ķ�ʽ ������ʹ�� �� new ʵ������ʱ�򣬽�mock�����Ķ����������
	 */
	@Test
	public void testPowerMockito_localVariable() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			PowerMockito.when(employeeDao.getTotal()).thenReturn(10);
			
			EmployeeService service = new EmployeeService();
			int total = service.getTotalEmployee();
			
			assertEquals(10, total);
			
		} catch (Exception e) {
			fail("����ʧ��");
		}
	}

	/*
	 * ����powerMockito ģ��ֲ������Ļ����÷�-->���� void �ķ���
	 * 1��ͨ��powerMockito.mock() ����mock����
	 * 2��ͨ��PowerMockito.whenNew() �ķ�ʽ ������ʹ�� �� new ʵ������ʱ�򣬽�mock�����Ķ����������
	 */
	@Test
	public void testPowerMockito_localVariable1() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			PowerMockito.when(employeeDao.getTotal()).thenReturn(10);
			
			EmployeeService service = new EmployeeService();
			int total = service.getTotalEmployee();
			
			assertEquals(10, total);
			
		} catch (Exception e) {
			fail("����ʧ��");
		}
	}
	
	/*
	 * ���� createEmployee ����
	 */
	@Test
	public void testCreateEmployee() {
		EmployeeService service = new EmployeeService();
		Employee employee = new Employee("zhanglin", 26);
		service.createEmployee(employee);
	}
	
	/*
	 * ���� createEmployee ����
	 * ʹ��PowerMockito�ķ�ʽ:
	 * whenNew: ����PowerMockito¼��һ���������Ϊ���Ȼ�Ҫ�õ�ʱ��ֱ��ʹ��֮ǰmock�Ķ���
	 * @PrepareForTest:��ǰ׼��һ���Ѿ�����ĳ��Ԥ�ڸı����class, ��EmployeeService��
	 * �����й����У�����һ���µ��࣬���������˴���EmployeeDao��ʱ�򣬾ͻ���ǰ¼�ƺõ���Ϊ�ز�������
	 * ����һ��Mock����
	 */
	@Test
	public void testCreateEmployeeWithPowerMockito() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		try {
			PowerMockito.whenNew(EmployeeDao.class).withNoArguments().thenReturn(employeeDao);
			EmployeeService service = new EmployeeService();
			Employee employee = new Employee("zhanglin", 26);
			service.createEmployee(employee);
			
			verify(employeeDao).addEmployee(employee);
	
		} catch (Exception e) {
			fail("����ʧ��");
		}
	}	
	
	
	
	
}
