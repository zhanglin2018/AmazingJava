package com.test.powerMockito.verify.argumentsMatcher;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;


import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.exceptions.verification.SmartNullPointerException;
import org.powermock.api.mockito.PowerMockito;
import org.powermock.core.classloader.annotations.PowerMockIgnore;
import org.powermock.core.classloader.annotations.PrepareForTest;
import org.powermock.modules.junit4.PowerMockRunner;
import org.powermock.modules.junit4.legacy.internal.impl.testcaseworkaround.PowerMockJUnit4LegacyTestIntrospector;


/*
 *Ŀ�ģ��yԇĳЩ���������@Щ�����У�������һЩ��������Ҫͨ�^��ݔ��ą�����ͬ��ģ�Mݔ����ͬ�ĽY��
 *�ܽ᣺
 *1��ע��PowerMockRunner.class �� ���� ·������Ȼ�ᱨ��
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeControler.class)
public class EmployeeControllerTest {
	
	/*
	 * �ֲ�׃��
	 */
	@Test
	public void testGetEmail() {
		EmployeeService employeeService = mock(EmployeeService.class, RETURNS_SMART_NULLS);
		
		try {
			PowerMockito.whenNew(EmployeeService.class).withNoArguments().thenReturn(employeeService);
			EmployeeControler employeeControler = new EmployeeControler();
			String email = employeeControler.getEmail("zhanglin");
			
			assertEquals("", email);
			assertEquals("zhanglin@qq.com", email);
			
			employeeControler.getEmail("error");
			fail("should not process to here.");
			
			
		
		} catch (Exception e) {
			assertTrue(e instanceof RuntimeException);
		}
		
		
		
		
	}
	
}
