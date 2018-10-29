package lab;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.InputMismatchException;


public class Exc {
	
	static int min(ArrayList<Integer> values) {
		if(values ==null || values.size()==0) {
			throw new IllegalArgumentException("Your list has no element");
		}
		int minSofar =values.get(0);
		for(Integer i:values) {
			if(i<minSofar) {
			minSofar=i;
			}
		}
		return minSofar;
		
	}
	
	public static void main(String[] arg) {
		
		try {
			ArrayList<Integer>vals=new ArrayList();
			
			int minval= min(vals);
			System.out.println(vals);
			
		
		}catch(IllegalArgumentException e) {
			System.out.println(e.getMessage());
		}
//		vals.add(5);
//		vals.add(2);
//		vals.add(3);
		
		
//		Scanner in = new Scanner(System.in);
//		System.out.println("age?: ");
//		String name=null;
//		System.out.println("Your name has" +name.length()+" Letters");
//		try {
//			int age=in.nextInt();
//			System.out.println("you are"+ age+ " years old.");
//		}catch (InputMismatchException e) {
//			System.out.println("you gave me a bad value");
//		}catch(Exception e) {
//			System.out.println("I catch everything");
//		}
		System.out.println("Bye Bye");
//		in.close();
		int value =Integer.parseInt("234");
		System.out.println(value+1);
	}

}
