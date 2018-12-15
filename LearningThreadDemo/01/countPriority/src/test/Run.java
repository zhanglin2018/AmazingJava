package test;

import extthread.ThreadA;
import extthread.ThreadB;

/*
 * 在java中，线程的优先级别分为1-10这10个等级，如果小于1 或者 大于 10， 
 * JDK会抛出异常，throw new IllegalArgumentException()
 * MIN_PRIORITY = 1
 * NORM_PRIORITY = 5
 * MAX_PRIORITY = 10
 * 看谁运行的快：两个线程是异步执行的。优先级别与运行的次数的多少 并不是线性的关系
 * 
 */


public class Run {

	public static void main(String[] args) {

		try {
			ThreadA a = new ThreadA();
			a.setPriority(Thread.NORM_PRIORITY - 3);
			a.start();

			ThreadB b = new ThreadB();
			b.setPriority(Thread.NORM_PRIORITY + 3);
			b.start();

			Thread.sleep(2000);
			a.stop();
			b.stop();

			System.out.println("a=" + a.getCount());
			System.out.println("b=" + b.getCount());
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}

}
