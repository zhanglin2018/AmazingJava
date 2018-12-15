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
 * 总结：
 * 1、mock的时候，调用的函数都是虚假的，不会调用真正的函数
 * 2、测试构造函数的mock: 主要是利用withArguments 的方式，記性構造函數的 初始化操作
 * 3、在每次測試前，需要提前的檢查 prepareForTest中類的情況
 */

@RunWith(PowerMockRunner.class)
@PrepareForTest(EmployeeService.class)
public class EmployeeServiceTest {
	
	/*
	 * whenNew 是模擬某個真實的對象，不是讓其 構造函數 調用，直接返回某個 被mock的對象
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
