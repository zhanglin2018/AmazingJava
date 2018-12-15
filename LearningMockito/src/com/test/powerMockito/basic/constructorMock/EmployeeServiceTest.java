package com.test.powerMockito.basic.constructorMock;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.powermock.api.mockito.PowerMockito;
import org.powermock.core.classloader.annotations.PrepareForTest;
import org.powermock.modules.junit4.PowerMockRunner;

import com.test.powerMockito.basic.constructorMock.EmployeeDao.Dialect;


/*
 * �ܽ᣺
 * 1��mock��ʱ�򣬵��õĺ���������ٵģ�������������ĺ���
 * 2�����Թ��캯����mock: ��Ҫ������withArguments �ķ�ʽ��ӛ�Ԙ��캯���� ��ʼ������
 * 3����ÿ�Μyԇǰ����Ҫ��ǰ�ęz�� prepareForTest�����r
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeService.class)
public class EmployeeServiceTest {
	
	/*
	 * whenNew ��ģ�Mĳ���挍�Č��󣬲���׌�� ���캯�� �{�ã�ֱ�ӷ���ĳ�� ��mock�Č���
	 */
	@Test
	public void testConstructor() {
		EmployeeDao employeeDao = PowerMockito.mock(EmployeeDao.class);
		try {
			PowerMockito.whenNew(EmployeeDao.class).withArguments(false, Dialect.MYSQL).thenReturn(employeeDao);
			
			EmployeeService employeeService = new EmployeeService();
			Employee employee = new Employee("zhanglin", 26);
			
			employeeService.createEmployee(employee);
			verify(employeeDao).addEmployee(employee);
			
		
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	

	

	
	
	
	
}
