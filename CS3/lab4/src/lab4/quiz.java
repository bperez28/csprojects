package lab4;


public class quiz {
	 static int reverse(int num) {
		int rev=0;
		while(num!=0) {
			int digit;
			digit=num%10;
			num=num/10;
			rev=rev*10+digit;
			
		}
		return rev;
	}
	public static void main(String[] args) {
		int test=210;
		System.out.println(reverse(test));
		
	}
		

}

