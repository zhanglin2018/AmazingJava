package com.io.input;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class TestInput {
	public static void main(String[] args) throws IOException {
		readOneStr();
		readOneStrArr();
		readOneStrArrLen();
		
		StringBuffer stringBuffer = readFileToString();
		System.out.println(stringBuffer);
		String string = stringBuffer.toString();
		
		System.out.println("Start change neirong");
		
		String compare = "val UnsignedLong AddressLength = 32;";
		System.out.println("is contains: " + string.contains(compare));
		string = string.replaceFirst(compare, "val UnsignedLong AddressLength = 1000;");
		
		
		
		String destFilePathString = "/home/linzhang/workspace/sw_mockito/IOStream/src/generate.txt";
		
		writeFile(destFilePathString, string);
//	    val UnsignedLong AddressLength = 32;
//	    val UnsignedLong DefaultDataLength = 32;
	    
	    
	}
	
	//public int read() throws IOException
	public static void readOneStr() throws IOException{
	    InputStreamReader isr=new InputStreamReader(new FileInputStream("/home/linzhang/workspace/sw_mockito/IOStream/src/JTAG32.prot"));
	    int ch=0;
	    while((ch=isr.read())!=-1){
	        System.out.print((char)ch);
	    }
	    isr.close();
	}
	//public int read(char[] cbuf) throws IOException
	public static void readOneStrArr() throws IOException{
	    InputStreamReader isr=new InputStreamReader(new FileInputStream("/home/linzhang/workspace/sw_mockito/IOStream/src/JTAG32.prot"));
	    char [] ch=new char[1024];
	    int len=0;
	    while((len=isr.read(ch))!=-1){
	        System.out.print(new String(ch,0,len));
	    }
	    isr.close();
	}
	//public int read(char[] cbuf) throws IOException
	public static void readOneStrArrLen() throws IOException{
	    InputStreamReader isr=new InputStreamReader(new FileInputStream("/home/linzhang/workspace/sw_mockito/IOStream/src/JTAG32.prot"));
	    char [] ch=new char[1024];
	    int len=0;
	    while((len=isr.read(ch,0,ch.length))!=-1){
	        System.out.print(new String(ch,0,len));
	    }
	    isr.close();
	}
	
	//public int read(char[] cbuf) throws IOException
		public static StringBuffer readFileToString() throws IOException{
		    InputStreamReader isr=new InputStreamReader(new FileInputStream("/home/linzhang/workspace/sw_mockito/IOStream/src/JTAG32.prot"));
		    char [] ch=new char[1024];
		    int len=0;
		    
		    StringBuffer stringBuffer = new StringBuffer();
		    while((len=isr.read(ch))!=-1){
//		    	stringBuffer.append(ch);
		    	stringBuffer.append(ch, 0, len);
//		    	stringBuffer.append(new String(ch, 0, len));
//		    	System.out.println(stringBuffer);
		    }
		    
		    isr.close();
			return stringBuffer;
		}
		
		
		
		public static void writeFile(String destFilePath, String text) throws IOException {
			OutputStreamWriter writer = new OutputStreamWriter(new FileOutputStream(destFilePath));
			writer.write(text);
			writer.flush();
			writer.close();
			
		}
}


