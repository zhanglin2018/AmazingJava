package test.run;

import testpackage.MyThread;


/*
 * 可以通过对线程的 Daemon 进行设定，指定的线程对象是否是守护线程。
 * 当非守护线程不存在的时候，守护线程也就自动的销毁了。
 */
public class Run {
	public static void main(String[] args) {
		try {
			MyThread thread = new MyThread();
			thread.setDaemon(true);
			thread.start();
			Thread.sleep(5000);
			System.out.println("我离开thread对象也不再打印了，也就是停止了！");
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
