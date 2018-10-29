package chp15;

public class ArrSimpleList implements simpleList {

	String[] data;
	int size=0;
	
	ArrSimpleList(){
		data = new String[2];
	}
	@Override
	public void add(String v) {
		// TODO Auto-generated method stub
		ensureCapacity();
		data[size++]=v;
	}


	@Override
	public void add(int i, String v) {
		ensureCapacity();
		
	}

	@Override
	public String get(int i) {
		// TODO Auto-generated method stub
		return data[i];
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
		return size;
	}
	
	private void ensureCapacity() {
		if(data.length==size) {
			String[]  newArr =new String[size*2];
			for(int i=0; i<data.length;i++) {
				newArr[i]=data[i];
			}
			data = newArr;
		}
	}
	

}
