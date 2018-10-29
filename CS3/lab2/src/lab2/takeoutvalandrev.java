package lab2;
import java.util.Scanner;

public class takeoutvalandrev {
	public static void main(String[] args)
	{
		Scanner input= new Scanner(System.in);
		System.out.println("Enter string: ");
		String str= input.nextLine();
		String str2="";
		
		for(int i=str.length()-1; i>=0;i--) {
			char temp=str.charAt(i);
			if(temp!='a' && temp!='e'
					&& temp!='i'&& temp!='o'
					&& temp!='u') {
				str2+=str.charAt(i);
				
			}
		}
		
		System.out.println(str2);
		
		
	}

}
