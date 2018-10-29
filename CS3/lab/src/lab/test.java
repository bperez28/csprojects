package lab;

public class test {
	
	public static void main(String[] arg) {
		
		String highScore= "03:15";
		String OldTime[]=highScore.split(":");
		
		int t=Integer.valueOf(OldTime[0]);
		System.out.println(t);
	}

}
