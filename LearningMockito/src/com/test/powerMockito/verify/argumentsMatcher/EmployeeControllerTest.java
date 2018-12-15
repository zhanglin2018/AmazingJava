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
 *目的：測試某些函數，在這些函數中，傳入了一些參數，需要通過對輸入的參數不同，模擬輸出不同的結果
 *总结：
 *1、注意PowerMockRunner.class 的 导入 路径，不然会报错
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeControler.class)
public class EmployeeControllerTest {
	
	/*
	 * 局部變量
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
