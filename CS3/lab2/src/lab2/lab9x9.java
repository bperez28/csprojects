package lab2;

public class lab9x9 {
	public static void main(String[] args)
	{
	
	for(int r=1;r<10;r++) {
		for(int c=1;c<10;c++) {
			System.out.print(r*c);
			
			if(c==9) {
				System.out.println("");
			}
			else {
				
				System.out.print(", ");
			}
	
		}
	}
	}

}
