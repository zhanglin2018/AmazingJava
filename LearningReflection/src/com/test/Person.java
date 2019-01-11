package com.test;

import java.io.Serializable;

import com.sun.corba.se.spi.orbutil.threadpool.Work;

/**
* @author :
* @createDate :Dec 27, 2018 4:47:05 PM
*/

public class Person implements Serializable{
	private String name = "zhanglin";
	public int age = 18;
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public Person(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}
	
	public Person() {
	}
	
	private void say() {
		System.out.println("private void say()...");
	}
	
	public void work() {
		System.out.println("public void work()...");
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}
	
	
}
