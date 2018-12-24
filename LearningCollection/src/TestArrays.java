package javaLearning;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;

/**
* @author :
* @createDate :Nov 30, 2018 5:48:04 PM
*/

public class TestArrays {
	public static void main(String[] args) {
		List<Integer> list =  Arrays.asList(1,3,2,8,4,6,7,3,1);
		List<Integer> list1 =  Arrays.asList(1,2,3,4,5,6,7,8);
		System.out.println(list);
		
		for (Integer value : list) {
			System.out.println(value);
		}
		
		System.out.println(list.equals(list1));
		
		List<String> listStrings = Arrays.asList("zhanglin", "hanjiaojiao", "zhangwei");
		List<String> listStrings1 = Arrays.asList("zhanglin", "hanjiaojiao", "zhangwei");
		
		System.out.println(listStrings.equals(listStrings1));
		
		System.out.println(Arrays.equals(list.toArray(), list1.toArray()));
		
		Integer[] tmp = (Integer[]) list.toArray();
		Arrays.sort(tmp);
		for (Integer valueInteger : tmp) {
			System.out.println(valueInteger);
		}
		
		try {
			StringBuilder stringBuilder = new StringBuilder();
			OutputStreamWriter stream = new OutputStreamWriter(new FileOutputStream(new File("zhanglin.txt")));
			for (int i = 0; i <10 ; i++) {
				stringBuilder.append("name is : " + i);
			}
			
			stream.write(stringBuilder.toString());
			
			
		} catch ( IOException e) {
			e.printStackTrace();
		}
		
	}
}
