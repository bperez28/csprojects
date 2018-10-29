package lab4;

public class dice {
	private int val;
	public void roll() {
		int i=0;
		double value=1+Math.random()*6;
		 val=(int)value;
		 i++;
		System.out.println(value);
	}
	public int getval() {
		return val;
	}
	public static void main(String[] arg) {
//		dice.roll();
	}

}
