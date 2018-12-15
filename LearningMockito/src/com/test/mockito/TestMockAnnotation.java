package com.test.mockito;

import java.util.LinkedList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.Spy;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

/*
 * 目的：该类用来测试mockito中的annotation，如Mock、Spy等注解
 */
public class TestMockAnnotation {
	@SuppressWarnings("rawtypes")
	@Mock
	private List mock;

	@SuppressWarnings("rawtypes")
	@Mock(name = "zhanglin")
	private List mockName;

	@SuppressWarnings("rawtypes")
	@Spy
	private List spy = new LinkedList();

	@Before
	public void initMocks() {
		MockitoAnnotations.initMocks(this);
	}

	@Test
	public void testMethod() {
		when(mock.get(0)).thenReturn("hello");
		System.out.println(mock.get(0));
		assertEquals("hello", mock.get(0));
	}

	@Test
	public void testSpy() {
		// optionally, you can stub some methods.
		// invoke the real method, but return simulate value
		when(spy.size()).thenReturn(100);

		spy.add("one-->hello");
		spy.add("two-->world");

		System.out.println(spy.get(0));
		System.out.println(spy.get(1));
//				System.out.println(spy.get(2));

		verify(spy).add("one-->hello");
//				verify(spy).add("two");

		System.out.println(spy.size());
	}
	
	@Test
	public void testSpy1() {
		// optionally, you can stub some methods.
		// invoke the real method, but return simulate value
		when(spy.size()).thenReturn(100);
		
		spy.add("one");
		spy.add("two");
		
		System.out.println(spy.get(0));
		System.out.println(spy.get(1));
//				System.out.println(spy.get(2));
		
		verify(spy).add("one");
//				verify(spy).add("two");
		
		System.out.println(spy.size());
	}
	
	//test the returns smart null 
	@Test
	public void returnsSmartNullsTest() {
//		List mock = mock(List.class);
		List mock = mock(List.class, RETURNS_SMART_NULLS); //in case of nullPoint exceptions
		System.out.println(mock.get(0));
		System.out.println(mock.toArray().length);
	}
	
	//test the deep stubs
	@Test
	public void deepStubsTest() {
		Account account = mock(Account.class, RETURNS_DEEP_STUBS); //in case of nullPoint exceptions
		when(account.getTicket().getDestination()).thenReturn("Beijing");
		account.getTicket().getDestination();
		verify(account.getTicket()).getDestination();
		
		assertEquals("Beijing", account.getTicket().getDestination());
		
	}
	
	//test the deep stubs
	@Test
	public void deepStubsTest_callRealFuntion() {
		Account account = mock(Account.class, RETURNS_DEEP_STUBS); //in case of nullPoint exceptions
//		when(account.getTicket().getDestination()).thenReturn("Beijing");
		when(account.getTicket().getDestination()).thenCallRealMethod().thenReturn("Beijing");
		
		account.getTicket().getDestination();
		verify(account.getTicket()).getDestination();
		
		assertEquals("Beijing", account.getTicket().getDestination());	
	}
	
	//test the deep stubs
	@Test
	public void deepStubsTest_callRealFuntion1() {
		Account account = mock(Account.class, RETURNS_DEEP_STUBS); //in case of nullPoint exceptions
//		when(account.getTicket().getDestination()).thenReturn("Beijing");n
		
		when(account.getTicket()).thenCallRealMethod();
		when(account.getTicket().getDestination()).thenCallRealMethod().thenReturn("Beijing");
//		when(account.getTicket().getDestination()).thenCallRealMethod().thenReturn("Beijing");
		
		account.getTicket().getDestination();
		verify(account.getTicket()).getDestination();
		
		assertEquals("Beijing", account.getTicket().getDestination());	
	}
	
	
	//test the deep stubs
	@Test
	public void deepStubsTest_spy() {
		RailWayTicket ticket = spy(new RailWayTicket());
		Account account = spy(new Account());
		account.setTicket(ticket);
		
		when(account.getTicket().getDestination()).thenReturn("Beijing");
		
		account.getTicket().getDestination();
		verify(account.getTicket()).getDestination();
		
		assertEquals("Beijing", account.getTicket().getDestination());	
	}
		
	
	
	public class Account{
		private RailWayTicket ticket;

		public RailWayTicket getTicket() {
			System.out.println("getTicket");
			return ticket;
		}

		public void setTicket(RailWayTicket ticket) {
			this.ticket = ticket;
		}
			
	}

	public class RailWayTicket{
		private String destination;

		public String getDestination() {
			System.out.println("getDestination");

			return destination;
		}

		public void setDestination(String destination) {
			this.destination = destination;
		}
		
	}
}
