package chp15;

public class collection {
	
	public static void main(String[] args) {
		simpleList list = new ArrSimpleList();
		list.add("a");
		list.add("b");
		list.add("c");
		list.add("d");
		list.add("e");
		list.add("f");
//		list.add(0,"d");
//		list.add(1,"c");
		for(int i=0; i<list.size(); i++) {
			System.out.println(list.get(i));
		}
		System.out.println();
		System.out.println("done");
	}

}
