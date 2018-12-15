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
 *Ŀ�ģ��ò������������� �����еľֲ����������⣬���mockito�� �����еľֲ���������mock�����
 *�ܽ᣺
 *1��ע��PowerMockRunner.class �� ���� ·������Ȼ�ᱨ��
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeService.class)
public class EmployeeServiceTest {
	
	/*
	 * �ֲ������� mock��ʽ
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
