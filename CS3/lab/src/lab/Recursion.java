package lab;

public class Recursion {
	
	static String reverse(String s) {
		if(s.isEmpty()) {
			return s;
		}
		String askFriend = reverse(s.substring(0, s.length()-1));
		return s.substring(s.length()-1)+askFriend;
	}
//	static int sum(int[] s) {
//		if(s.length==0) {
//			return s[0];
//		}
//		int askFriend = sum(s);
//		return askFriend+s[1];
//	}
	
	static int powerof2(int n) {
//		System.out.println("i got asked 2 the"+n);
		if(n==0) {
			return 1;
		}
		int askFriend = powerof2(n-1);
		return askFriend*2;
	}
	static int fact(int n) {
//		System.out.println("i got asked 2 the"+n);
		if(n==0) {
			return 1;
		}
		int askFriend = fact(n-1);
		return askFriend*n;
	}
//	static int sumALL(int n) {
////		System.out.println("i got asked 2 the"+n);
//		if(n==0) {
//			return 1;
//		}
//		int askFriend = sumAll(n-1);
//		return askFriend+n;
//	}


	public static void main(String[] args) {
	
		System.out.println(reverse(""));
		
	}
	
}
