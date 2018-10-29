package lab4;

public class line {
	private points s;
	private points e;
	double l;
	
	public line(int x1, int y1, int x2, int y2) {
		s= new points(x1, y1);
		e= new points(x2, y2);
	}
	public line(points p1, points p2) {
		s= p1;
		e= p2;
	}
	public points getstart() {
		return s;
	}
	public points getend() {
		return e;
	}
	public double getlenght() {
		int h= s.getx() - e.getx();
		int v= s.gety() - e.gety();
		return Math.sqrt(h*h*v*v);
	}


}
