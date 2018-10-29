package lab2;
import java.util.Scanner;

public class notsamechar {
	public static void main(String[] args)
	{
		Scanner input =new Scanner(System.in);
		
		System.out.println("Enter String1:");
		String str1=input.nextLine();
		
		System.out.println("Enter String2:");
		String str2=input.nextLine();
		
		String str3="";
		boolean contains =false;
		
		for(int i=0; i<str1.length();i++) {
			
			for(int j=0; j<str2.length();j++) {
				
				if(str1.charAt(i)==str2.charAt(j)) {
					contains=true;
					
				}

				
			}
			if(!contains) {
				str3+=str1.charAt(i);
			}
		}
		System.out.println(str3);
	}

}
