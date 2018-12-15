package com.test.powerMockito.basic;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import java.security.Provider.Service;

import org.junit.Test;
import org.powermock.api.mockito.PowerMockito;


/*
 * 总结：
 * 1、mock的时候，调用的函数都是虚假的，不会调用真正的函数
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
	 * 测试mock函数的真假调用
	 * 默认的情况下，返回int形为：0
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
	 * thenCallTealMethod() 会调用真实的函数，返回自定义的值
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
	 * spy是对new出来的对象进行监视，调用的是真实的函数
	 */
	@Test
	public void testGetTotalEmployeeWithMock3() {
		EmployeeDao employeeDao = spy(new EmployeeDao());
		
		EmployeeService service = new EmployeeService(employeeDao);
		int total = service.getTotalEmployee();
		
		assertEquals(10, total);
	}
	
	/*
	 * spy是对new出来的对象进行监视
	 * 利用when模拟函数的调用情况，spy出来的对象，调用的是真实的函数，但是返回值是自定义的值
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
	 * spy是对new出来的对象进行监视
	 * 如何模拟出来虚假的函数呢？
	 * 通过doreturn函数解决,此时不会调用employeeDao里面的函数值了
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
	 * 使用powerMockito进行测试
	 * spy是对new出来的对象进行监视
	 * 如何模拟出来虚假的函数呢？
	 * 通过doreturn函数解决,此时不会调用employeeDao里面的函数值了
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
