package com.test.mockito;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.junit.Test;
import org.mockito.ArgumentMatcher;
import org.mockito.InOrder;
import org.mockito.invocation.InvocationOnMock;
import org.mockito.stubbing.Answer;

import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

/*
 * mockito introduction
 * https://wenku.baidu.com/view/252309b7a26925c52dc5bf62
 * 2018-11-9
 * 总结：
 * 1、该类用来测试mockito的 基本用法
 */

public class SimpleTest {

	// Mock object and stubbing
	@Test
	public void testMockInterface() {
		Iterator<String> iter = mock(Iterator.class, "struggling");

		when(iter.next()).thenReturn("hello").thenReturn("world");

		String result = iter.next() + " " + iter.next();

		verify(iter, times(2)).next();

		assertEquals("hello world", result);

		System.out.println("zhanglin " + iter.toString());
	}

	// Mock object and stubbing --> thenReturn(String, String)
	@Test
	public void testMockInterface1() {
		Iterator<String> iter = mock(Iterator.class, "struggling");

		when(iter.next()).thenReturn("hello", "world");

		String result = iter.next() + " " + iter.next();

		verify(iter, times(2)).next();

		assertEquals("hello world", result);

		System.out.println("zhanglin " + iter.toString());
	}

	// Mock object and stubbing --> doReturn
	@Test
	public void testMockInterface2() {
		Iterator<String> iter = mock(Iterator.class, "struggling");

		doReturn("hello").doReturn("world").when(iter).next();

		String result = iter.next() + " " + iter.next();

		verify(iter, times(2)).next();

		assertEquals("hello world", result);

		System.out.println("zhanglin " + iter.toString());
	}

	// Mock object and stubbing --> doThrow
	@Test
	public void testMockInterface3() {
		Iterator<String> iter = mock(Iterator.class, "struggling");

		doReturn("hello").when(iter).next();
//		doThrow(new RuntimeException()).when(iter).next();

		String result = iter.next();

		verify(iter, times(1)).next();

		System.out.println("zhanglin " + iter.toString());
	}

	// Mock object and stubbing --> doThrow
	@Test
	public void argumentMatchers() {
		List<String> mock = mock(List.class, "hanjiaojiao");
		when(mock.get(anyInt())).thenReturn("hello").thenReturn("world");
		
		String result = mock.get(0) + " " + mock.get(200);
		
		verify(mock, times(2)).get(anyInt());
		
		assertEquals("hello world", result);

		
		System.out.println("zhanglin " + mock.toString());
	}
	
	// Mock object and stubbing --> map matchers
	@Test
	public void argumentMatchersMap() {
		Map mapMock = mock(Map.class);
		when(mapMock.put(anyInt(), anyString())).thenReturn("world");
		
		mapMock.put(1, "hello");
		
		verify(mapMock).put(anyInt(), eq("hello"));
		verify(mapMock).put(anyInt(), anyString());
		verify(mapMock).put(1, "hello");
		
		assertEquals("world", mapMock.put(100, "zhanglin"));
		
		System.out.println("zhanglin " + mapMock.toString());
	}

	
	//Mock object and actions
	@Test
	public void mockActions() {
		List<String> mock = mock(List.class);
		List<String> mock2 = mock(List.class);
		
		when(mock.get(0)).thenReturn("hello");
		
		mock.get(0);
		mock.get(2);
		mock.get(100);
		
		mock2.get(0);
		
		verify(mock).get(0);
		verify(mock).get(2);
		verify(mock).get(100);
//		verify(mock).get(200);
		verify(mock, never()).get(200);
		verifyNoMoreInteractions(mock);
//		verifyZeroInteractions(mock2);
		
		verify(mock, timeout(100).times(1)).get(0);
		
	}
	
	//Mock object and actions
	@Test
	public void mockInvoke() {
		List<String> firstMock = mock(List.class);
		List<String> secondMock = mock(List.class);
		
		firstMock.add("was called first");
		firstMock.add("was called first");
		secondMock.add("was called second");
		secondMock.add("was called third");
		
		InOrder inOrder = inOrder(secondMock, firstMock);
		
		inOrder.verify(firstMock,times(2)).add("was called first");
		inOrder.verify(secondMock).add("was called second");
//		inOrder.verifyNoMoreInteractions();
	}
	
	//Mock object and actions
	@Test
	public void mockInvoke1() {
		List<String> firstMock = mock(List.class);
		List<String> secondMock = mock(List.class);
		
		firstMock.add("was called first");
		firstMock.add("was called first");
		secondMock.add("was called second");
		secondMock.add("was called third");
		
		InOrder inOrder = inOrder(secondMock, firstMock);
		
		inOrder.verify(firstMock,times(2)).add("was called first");
		inOrder.verify(secondMock).add("was called third");
		inOrder.verifyNoMoreInteractions();
	}
	
	//Mock object and actions
	@Test
	public void mockAnswer() {
		List<String> mock = mock(List.class);
		when(mock.get(4)).thenAnswer(new CustomAnswer());
		
		assertEquals("yes", mock.get(4));
//		assertEquals("yes", mock.get(10));
//		assertEquals("yes", mock.get(1000));
//		assertEquals("yes", mock.get(2));
		
		
		
		
	}
	
	//Mock object and actions
	@Test(expected=RuntimeException.class)
	public void mockAnswer1() {
		List<String> mock = mock(List.class);
		doAnswer(new CustomAnswer()).when(mock).get(anyInt());
		
		assertEquals("yes", mock.get(4));
		assertEquals("yes", mock.get(10));
		assertEquals("yes", mock.get(1000));
		assertEquals("yes", mock.get(2));
		
	}
	
	//Mock object and actions
	@Test
	public void mockAnswer3() {
		List<String> mock = mock(List.class);
		
		when(mock.get(4)).thenAnswer(new Answer<String>() {

			@Override
			public String answer(InvocationOnMock invocation) throws Throwable {
				Object[] args = invocation.getArguments();
				Integer numInteger = (Integer)args[0];
				
				if (numInteger > 3) {
					return "yes";
				}
				throw new RuntimeException();
			}
		});
	
		assertEquals("yes", mock.get(4));
//		assertEquals("yes", mock.get(10));
//		assertEquals("yes", mock.get(2));	
	}
	
	//Mock object and actions
	@Test(expected=RuntimeException.class)
	public void mockAnswer4() {
		List<String> mock = mock(List.class);
		
		when(mock.get(anyInt())).thenAnswer(new Answer<String>() {
			
			@Override
			public String answer(InvocationOnMock invocation) throws Throwable {
				Object[] args = invocation.getArguments();
				Integer numInteger = (Integer)args[0];
				
				if (numInteger > 3) {
					return "yes";
				}
				throw new RuntimeException();
			}
		});
		
		assertEquals("yes", mock.get(4));
		assertEquals("yes", mock.get(10));
		assertEquals("yes", mock.get(2));	
	}
	
//	//Mock object and actions
//	@SuppressWarnings("boxing")
//	@Test
//	public void mockArgumentTest() {
//		List mock = mock(List.class);
//		when(mock.addAll(argThat(new IsListOfTwoElements()))).thenReturn(true);
//		
//		mock.addAll(Arrays.asList("one", "two", "three"));
//		
//		verify(mock).addAll(argThat(new IsListOfTwoElements()));
//		
//		
//	}
	
	//test spy
	@Test(expected=IndexOutOfBoundsException.class)
	public void spyTest() {
		List spy = spy(new LinkedList());
		when(spy.get(0)).thenReturn("foo");  //invoke the real method
		
		
	}
	
	//test spy
	@Test
	public void spyTest1() {
		List spy = spy(new LinkedList());
		doReturn("foo").when(spy).get(0);
		
		assertEquals("foo", spy.get(0));
//		assertEquals("foo", spy.get(1));
		
	}
	
	//test spy
	@Test
	public void spyTest2() {
		List list = new LinkedList();
		List spy = spy(list);
		
		//optionally, you can stub some methods.   
		//invoke the real method, but return simulate value
		when(spy.size()).thenReturn(100);
		
		spy.add("one-->hello");
		spy.add("two-->world");
		
		
		System.out.println(spy.get(0));
		System.out.println(spy.get(1));
//		System.out.println(spy.get(2));
		
		verify(spy).add("one-->hello");
//		verify(spy).add("two");
		
		System.out.println(spy.size());	
	}

	
	
	
	
	public class CustomAnswer implements Answer<String>{

		@SuppressWarnings("boxing")
		@Override
		public String answer(InvocationOnMock invocation) throws Throwable {
			Object[] args = invocation.getArguments();
			Integer numInteger = (Integer)args[0];
			if (numInteger > 3) {
				return "yes";
			}
			throw new RuntimeException();
		}
	}
	
	public class IsListOfTwoElements implements ArgumentMatcher<List>{

		@Override
		public boolean matches(List arg0) {
			return ((List)arg0).size() ==  2;
			}

//		@Override
//		public boolean matches(Object argument) {
//			
//			
//		}
		
	}
}
