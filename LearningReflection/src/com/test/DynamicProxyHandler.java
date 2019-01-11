package com.test;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
* @author :
* @createDate :Dec 27, 2018 5:24:59 PM
*/

public class DynamicProxyHandler implements InvocationHandler{
	private Object proxyed;
	
	public DynamicProxyHandler(Object proxyed) {
		this.proxyed = proxyed;
	}

	@Override
	public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
		System.out.println("proxy start to work.");
		return method.invoke(proxyed, args);
	}
	
}


interface Interface{
	void doSomething();
	void somethingElse(String arg);
}

class RealObject implements Interface{

	@Override
	public void doSomething() {
		System.out.println("doSomething.");
	}

	@Override
	public void somethingElse(String arg) {
		System.out.println("somethingElse: " + arg);
	}
}