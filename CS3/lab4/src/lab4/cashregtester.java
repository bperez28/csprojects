package lab4;

public class cashregtester {

	   public static void main(String[] args)
	   {
	      cashreg register2 = new cashreg(7.5);
	      register2.addItem(3.95, false);
	      register2.addItem(19.95, true);
	      System.out.println(register2.getCount());
	      System.out.println("Expected: 2");
	      System.out.printf("%.2f\n", register2.getTotal());
	      System.out.println("Expected: 25.40");
	   }
	}



