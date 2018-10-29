package lab2;
import java.util.Scanner;

import java.util.Scanner;

public class mostusedlet {
	public static void main(String[] args)
	{
	Scanner input =new Scanner(System.in);
	
	System.out.println("Enter String1:");
	String str1=input.nextLine();
	char letter;
	int count=0;
	int maxcount=0;
	
	for(int i=0; i>str1.length();i++) {
		for(int j=0; j>str1.length();j++) {
			if(str1.charAt(i)==str1.charAt(j)) {
				count++;
			}
			
		}
		if(count>maxcount) {
			maxcount=count;
		}
		
	}
	
	System.out.println(str1.charAt(maxcount));
	
	}
}
