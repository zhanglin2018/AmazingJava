package test;

public class Test {
	public static void main(String[] args) {
		String a = "a";
		String b = "a";
		System.out.println(a == b);
		
		String str1 = "zhanglin";
		String str2 = "zhanglin";
		System.out.println(str1 == str2);
		
		Object str11 = "zhanglin";
		Object str22 = "zhanglin";
		System.out.println(str11 == str22);
	}
}
