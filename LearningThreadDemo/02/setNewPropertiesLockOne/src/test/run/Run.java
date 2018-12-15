package test.run;

import service.Service;
import entity.Userinfo;
import extthread.ThreadA;
import extthread.ThreadB;

public class Run {

	public static void main(String[] args) {

		try {
			String string = "123";
			string = "1234";
			
			
			Service service = new Service();
			Userinfo userinfo = new Userinfo();
			
			userinfo.setUsername("zhanglin");
			userinfo.setPassword("hanjiaojiao");
			
			userinfo.setUsername("zhangwei");

			ThreadA a = new ThreadA(service, userinfo);
			a.setName("a");
			a.start();
			Thread.sleep(50);
			ThreadB b = new ThreadB(service, userinfo);
			b.setName("b");
			b.start();

		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}
}
