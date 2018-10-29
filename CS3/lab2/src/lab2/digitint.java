package lab2;
import java.util.Scanner;

public class digitint {
	
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter int:");
		int num =input.nextInt();
		
		int count=0;
		int newnum=num;
		
		while(num!=0) {
		num=num/10;
		count++;
		}
		System.out.println("The Count for "+newnum +" is " + count);
	}

}
