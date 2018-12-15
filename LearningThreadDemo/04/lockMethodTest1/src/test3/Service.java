package test3;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Service {

	public ReentrantLock lock = new ReentrantLock();
	public Condition newCondition = lock.newCondition();

	public void waitMethod() {
		try {
			lock.lock();
			newCondition.await();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			lock.unlock();
		}
	}

	public void notityMethod() {
		try {
			lock.lock();
			System.out.println(" " + lock.getWaitQueueLength(newCondition)
					+ " -> newCondition");
			newCondition.signal();
//			newCondition.signalAll();
			System.out.println(" " + lock.getWaitQueueLength(newCondition)
			+ " -> newCondition");
		} finally {
			lock.unlock();
		}
	}

}
