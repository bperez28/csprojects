package chp13;

public class recplay {
	static int area(int side) {
		if(side ==0) {
			return 0;
		}
		return area(side-1)+side;
	}

	static boolean ispali(String s) {
		if(s.isEmpty() || s.length() ==1) {
			return true;
		}
		if(s.charAt(0)!=s.charAt(s.length()-1)) {
			return false;
		}
		return ispali(s.substring(1, s.length()-1));
	}
	public static int sum(int[] arr) {
		
		return sum(arr, arr.length-1);
	}
	
	private static int sum(int[] arr, int end) {
		if(end<0) {
			return 0;
		}
		//there is no way to do recursive an array with out a helper like using end or start
		//this in the bottom is bad to use it would be really slow for the computer to 
		//make a new array everytime 
//		int[] arrfriend = new int[arr.length-1];
//		for(int i=1; i<arr.length; i++) {
//			arrfriend[i-1]=arr[i];
//		}
		
		int friend = sum(arr, end-1);
		return arr[end]+friend;
		
	}
	public static int greatest(int[] arr) {
		
		return greatest(arr, arr.length-1);
	}
	
	private static int greatest(int[] arr, int end) {
		if(end<0) {
			return 0;
		}
		//there is no way to do recursive an array with out a helper like using end or start
		//this in the bottom is bad to use it would be really slow for the computer to 
		//make a new array everytime 
//		int[] arrfriend = new int[arr.length-1];
//		for(int i=1; i<arr.length; i++) {
//			arrfriend[i-1]=arr[i];
//		}
		
		int friend = greatest(arr, end-1);
//		if(arr[end]>friend) {
		return arr[end];
		
		
	}
	public static int fib(int n) {
		if(n<=2)
			return 1;
		return fib(n-1)+fib(n-2);
	}
	
	public static int bs(int[] arr, int val) {
		return bs(arr, 0, arr.length-1, val);
		
	}
  static int bs(int[] arr, int start, int end, int val) {
		if(start>end) {
			return -1;
		}
		int mid=(start+end)/2;
		if(arr[mid]==val) {
			return mid;
		}else if(arr[mid]<val) {
			return bs(arr,mid+1,end,val);
		}
		return bs(arr,start,mid-1,val);
		
	}
	
	
	public static void main(String[] args) {
//		system.out.println(area(4));
//		System.out.println(ispali("abba"));
//		System.out.println(sum(new int[] {2,3,1,5}));
//		System.out.println(fib(9));
		System.out.println(sum(new int[] {2,3,1,5}));
	}
}
