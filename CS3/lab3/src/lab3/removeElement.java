package lab3;

public class removeElement {
	
	static String[] removeit(String[] array, String remove) {
		
		String[] temp= new String[array.length-1];
		int index=0;
		for(int i=0; i<array.length;i++) {
			
			if(!array[i].equals(remove)) {
				temp[index++]=array[i];
				
			}				
		}
		return temp;
	}
	
	
	public static void main(String[] arg) {
		String[] names= new String[] {"Alice", "Bill", "Jay"};
		String remove="Bill";
		names=removeit(names,remove);
		array.printAll(names);
	}

}
