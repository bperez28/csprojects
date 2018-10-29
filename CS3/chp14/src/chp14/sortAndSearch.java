package chp14;

import java.util.Arrays;
import java.util.Comparator;

public class sortAndSearch {
	
	public static void main(String[] args) {
		String[] arr = {"Jane","Zalice","Bob","Alice","Edward"};
		Person[] people =new Person[arr.length];
		int count=0;
		for(String s:arr) {
			people[count++]=new Person(arr[count]);
			
		}
		class PersonComparatoByname implements Comparator<Person>{
			@Override 
			public int compare(Person p1, Person p2) {
				return p1.name.length()-p2.name.length();
			}
		}
		class PersonComparatoByNameLenghtTiesAlpha implements Comparator<Person>{
			
			@Override 
			public int compare(Person p1, Person p2) {
				return p1.name.length()-p2.name.length();
			}
		}
		Arrays.sort(arr);
		System.out.println(Arrays.toString(arr));
	}

}
