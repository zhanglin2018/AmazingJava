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
 *目的：该测试类用来测试 函数中的局部变量的问题，针对mockito库 函数中的局部变量不能mock的情况
 *总结：
 *1、注意PowerMockRunner.class 的 导入 路径，不然会报错
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
	 * 测试mockito 模拟局部变量的基本用法, 没有whenNew的用法
	 */
	@Test
	public void testMockito_localVariable() {
		EmployeeDao employeeDao = mock(EmployeeDao.class);
		
		final EmployeeService service = new EmployeeService();
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * 测试powerMockito 模拟局部变量的基本用法
	 * 1、通过powerMockito.mock() 将类mock出来
	 * 2、通过PowerMockito.whenNew() 的方式 可以在使用 到 new 实例化的时候，将mock出来的对象进行引用
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
			fail("测试失败");
		}
	}

	/*
	 * 测试powerMockito 模拟局部变量的基本用法-->测量 void 的方法
	 * 1、通过powerMockito.mock() 将类mock出来
	 * 2、通过PowerMockito.whenNew() 的方式 可以在使用 到 new 实例化的时候，将mock出来的对象进行引用
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
			fail("测试失败");
		}
	}
	
	/*
	 * 测试 createEmployee 方法
	 */
	@Test
	public void testCreateEmployee() {
		EmployeeService service = new EmployeeService();
		Employee employee = new Employee("zhanglin", 26);
		service.createEmployee(employee);
	}
	
	/*
	 * 测试 createEmployee 方法
	 * 使用PowerMockito的方式:
	 * whenNew: 利用PowerMockito录制一个构造的行为，等会要用的时候，直接使用之前mock的对象
	 * @PrepareForTest:提前准备一个已经根据某种预期改变过的class, 如EmployeeService，
	 * 在运行过程中，产生一个新的类，但凡碰到了创建EmployeeDao的时候，就会提前录制好的行为重播出来，
	 * 给出一个Mock对象。
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
			fail("测试失败");
		}
	}	
	
	
	
	
}
