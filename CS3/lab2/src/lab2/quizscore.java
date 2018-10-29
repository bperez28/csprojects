package lab2;
import java.util.Scanner;

public class quizscore {
	public static void main(String[] args)
	{
		int score=0;
		int count = 0;
		int allsc=0;
		while(score>=0) {
			 allsc=allsc+score;
		System.out.print("Enter Score:");
		Scanner inputScanner = new Scanner(System.in);
		 count++;
		 score=inputScanner.nextInt();
 
	}
		count--;
		System.out.println(count);
		if(count>0) {
		int avg=allsc/count;
		System.out.println("class avg:"+avg);
	}
		
		
	}

}
