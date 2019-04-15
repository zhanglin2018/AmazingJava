package collection.list;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TestList {
	public static void main(String[] args) {
		List<String> list1 = new ArrayList<>();
		list1.add("zhanglin");
		list1.add("hanjiaojiao");
		list1.add("zhangwei");
		
		for (String str : list1) {
			System.out.println(str);
		}
	}
}
