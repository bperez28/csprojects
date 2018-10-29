package chp14;

import java.util.Comparator;

public class Person implements Comparator<Person>{ 

	String name;
	Person(String name ){
		this.name=name;
	}
	
	@Override
	public String toString() {
		return name;
	}
	
	@Override
public int compareto(Person other) {
	return name.length()-
	}
}
