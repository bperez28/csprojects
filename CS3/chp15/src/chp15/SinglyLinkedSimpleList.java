package chp15;

public class SinglyLinkedSimpleList implements simpleList {
	
	class mode{
		public mode(String string, Object object) {
			
		}

		public mode next;

	}
	@Override
	public void add(String v) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void add(int i, String v) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public String get(int i) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void set(int i, String v) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void remove(int i) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public int size() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	public static void main(String[] args) {
		mode n1 =new mode("i",null);
		mode n2 =new mode("i",null);
		mode n3 =new mode("i",null);
		mode n4 =new mode("i",null);
		
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = new mode("5",null);
		
		mode(cur=n1);
		while(cur!=null) {
			System.out.println(cur.val);
			cur=cur.next;
		}
		
		
				}

}
