package lab3;

public class array {
	
	/**
	 * 
	 * @param values
	 * @return
	 */

	static double avg(double[] values) {
		double sum=0;
		for(int i=0; i<values.length; i++){
			sum += values[i];
		}
		return sum / values.length;
	}
	static void curve(String[] values, int amount) {
		for(int i=0; i<values.length;i++) {
			values[i]+=amount;
		}
	}
	
	static void printAll(double[] scores) {
		for( double score :scores) {
			System.out.print(score + " , ");
		}
		System.out.println();
	}
	static void printAll(int[] scores) {
		for( int score :scores) {
			System.out.print(score + " , ");
		}
		System.out.println();
	}
	static void printAll(String[] scores) {
		for( String score :scores) {
			System.out.print(score + " , ");
		}
		System.out.println();
	}
	
	static double[] increaseCapacity(double[] values, int increase) {
		double[] newValues =new double[values.length + increase];
		for(int i=0; i<values.length; i++) {
			newValues[i]=values[i];
		}
		//values =newvalues bad 
		return values;
	}
	
	static void swap(String[] arr, int i, int j){
		String tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
	
	static void reverse(String[] arr) {
		for(int i=0; i<arr.length/2;i++) {
			swap(arr,i,arr.length-i-1);
			
		}
	}
	
	public static void main(String[] args) {
		double[] scores;
		scores =  new double[] {92,100,80};
//		printAll(scores);
//		double result =avg(scores);
//		
//		System.out.println(result);
//		
//		curve(scores, 5);
//		result =avg(scores);
//		System.out.println(result);
		
		scores=increaseCapacity(scores,3);
		printAll(scores);
		
		String[] names= new String[] {"Alice", "Bill", "Bob"};
		reverse(names);
		array.printAll(names);
		
		
	}
	

}
