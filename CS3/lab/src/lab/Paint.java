package lab;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;


public class Paint extends JPanel {
	
	
	ArrayList<Integer> point= new ArrayList<Integer>();
	
	
	Paint() {
		setPreferredSize(new Dimension(200, 200));
		setBackground(Color.CYAN);
		
		this.addMouseListener(new MouseListener() {

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mousePressed(MouseEvent e) {
				
				
				point.add(e.getX());
				point.add(e.getY());
				repaint();
				
				
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			
		});
	}
	
	@Override
	public void paintComponent(Graphics gr) {
		
		super.paintComponent(gr);
		Graphics2D g = (Graphics2D) gr;

		if(!point.isEmpty()) {

			for(int i=0; i<=(point.size()/2)-1; i++) {
				
				g.fillOval(point.get(i*2), point.get((i*2)+1), 10, 10);
			
				if(point.size()>3 && i>0) {
					
					g.drawLine(point.get(((i-1)*2))+5, point.get(((i-1)*2)+1)+5,point.get((i*2))+5, point.get((i*2)+1)+5);
					
				}
				

			}
		}
		
		
	}

	public static void main(String[] args) {
		JFrame f = new JFrame("Paint");

		
		
		f.add(new Paint());
		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.pack();
		f.setVisible(true);
		
	}

}
