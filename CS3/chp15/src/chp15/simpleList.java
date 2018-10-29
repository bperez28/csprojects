package chp15;

public interface simpleList {

	/**
	 * 
	 */
	void add(String v);
	
	void add(int i, String v);
	
	String get(int i);
	
	void set(int i, String v);
	
	void remove(int i);
	
	int size();
	
}
