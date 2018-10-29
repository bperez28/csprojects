package lab2;
import java.util.Scanner;

public class stringcompare {
	public static void main(String[] args)
	{
		Scanner input =new Scanner(System.in);
		
		System.out.println("Enter string1:");
		String string1 =input.nextLine();
		
//		System.out.println("Enter String2:");
//		String string2= input.nextLine();
		String ucla="ucla";
		
		boolean within=true;
		
		for(int i=0; i<string1.length();i++) {
			if(string1.charAt(i)!=ucla.charAt(i)) {
				within= true;
				System.out.println("in");
				break;
				
				
			}
			
		}
		
		System.out.println(string1+" and "+ucla );
		if(!within) {
			System.out.println("are the same");
		}
		else {
			System.out.println("are not the same");
			
		}
		
	}

}
