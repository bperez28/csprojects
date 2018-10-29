package lab2;
import java.util.Scanner;

public class dart {
	public static void main(String[] args)
	{
		final int TOTAL=1000;
		int countInside =0;
		
		for(int i=0; i<TOTAL; i++) {
			double x=Math.random();
			double y=Math.random();
//			System.out.println(x + " , " + y);
			if(Math.sqrt(x*x + y*y)<=1) {
				countInside++;
			}
	}
		System.out.println((double)countInside/TOTAL*4);
	}

}
