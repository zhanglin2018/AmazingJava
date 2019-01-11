package com.test;

import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

import com.sun.org.apache.bcel.internal.generic.F2D;


/**
* @author : zhanglin
* @createDate :Dec 27, 2018 4:25:44 PM
*/

public class TestClass {
	public static void main(String[] args) {
		testClassLoader();
		testConstructor();
		testXYZ();
		testBase();
		testField();
		testProxy();
		
		System.out.println(sumup(1,2,3,4,5,6,7));
		System.out.println(sumup(1,2,3,4,5,6));
		
		
		testClass();
	}

	private static void testClass() {
		Person p1 = new Person();
		Class class1 = p1.getClass();
		System.out.println(class1);
		
		Class class2 = Person.class;
		System.out.println(class2);
		
		try {
			Class class3 = Class.forName("com.test.Person");
			System.out.println(class3);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		
		
		String classNameString = class2.getName();
		System.out.println(classNameString);
		
		System.out.println("start to getFields()-->");
		Field[] fields = class2.getFields();
		for (Field field : fields) {
			System.out.println(field.getName());
		}
		
		System.out.println("start to getDeclaredFields()-->");
		Field[] allFields = class2.getDeclaredFields();
		for (Field field : allFields) {
			System.out.println(field.getName());
		}
		
		System.out.println("start to getMethods()-->");
		Method[] methods = class2.getMethods();
		for (Method method : methods) {
			System.out.println(method.getName());
		}
		
		System.out.println("start to getDeclaredMethods()-->");
		Method[] allMethods = class2.getDeclaredMethods();
		for (Method method : allMethods) {
			System.out.println(method.getName());
		}
		
		System.out.println("start to getField()-->");
		try {
			Field f1 = class2.getField("age");
			System.out.println(f1);
		} catch (NoSuchFieldException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		}
		
		try {
			Field f2 = class2.getDeclaredField("name");
			System.out.println(f2);
			
			Object p2 = class2.newInstance();
			
			f2.set(p2, "I love you");
			
		} catch (NoSuchFieldException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		}
		
		
		
		
		
	}
	
	
	
	
	
	private static int sumup(int... values) {
		int sum = 0;
		for (int i=0; i<values.length; i++) {
			sum += values[i];
		}
		return sum;
	}
	

	private static void testProxy() {
		System.out.println("start to testProxy().->");
		RealObject realObject = new RealObject();
		Interface proxyInterface = (Interface) Proxy.newProxyInstance(Interface.class.getClassLoader(), 
				new Class[] {Interface.class}, new DynamicProxyHandler(realObject));
		
		proxyInterface.doSomething();
		proxyInterface.somethingElse("zhanglin");
	}



	private static void testField() {
		System.out.println("start testPerson()-->");
		Person person = new Person("hanjiaojiao", 27);
		Class<?> class1 = person.getClass();
		System.out.println(class1);
		
		Field[] fields = class1.getDeclaredFields();
		for (Field field : fields) {
			System.out.println(field);
			String key = field.getName();
			try {
				PropertyDescriptor descriptor = new PropertyDescriptor(key, class1);
				Method method = descriptor.getReadMethod();
				Object value = method.invoke(person);
				System.out.println(key + ": " + value);
				
				
			} catch (IntrospectionException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			} catch (IllegalArgumentException e) {
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				e.printStackTrace();
			}
		}
	}



	private static void testBase() {
		System.out.println("testBase()-->");
		Class clazz1 = Base.class;
		System.out.println("----------");
		
		try {
			Class clazz2 = Class.forName("com.test.Base");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void testClassLoader() {
		ClassLoader classLoader = ClassLoader.getSystemClassLoader();
		System.out.println(classLoader);
		
		ClassLoader classLoader2 = classLoader.getParent();
		System.out.println(classLoader2);
		
		ClassLoader classLoader3 = classLoader2.getParent();
		System.out.println(classLoader3);
		
		ClassLoader classLoader4 = TestClass.class.getClassLoader();
		System.out.println(classLoader4);
		
		try {
			System.out.println(Class.forName("java.lang.Object").getClassLoader());
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	
	
	@SuppressWarnings("null")
	private static void testConstructor() {
		String className = "com.test.Person";
		Class<?> personClass = null;
		try {
			personClass = Class.forName(className);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		
		Constructor<?> constructor = null;
		try {
			constructor = personClass.getConstructor(String.class, int.class);
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		}
		
		Person person = null;
		try {
			person = (Person) constructor.newInstance("zhagnlin", 27);
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
		
		System.out.println(person);
	}
	
	private static void testXYZ() {
		System.out.println(XYZ.nameString);
	}
	
}


class XYZ{
	public static String nameString = "zhanglin";
	
	static {
		System.out.println("xyz static section");
	}
	
	public XYZ() {
		System.out.println("xyz constructor invocation");
	}
}

class Base{
	static int num = 1;
	
	static {
		System.out.println("Base " + num);
	}
}

