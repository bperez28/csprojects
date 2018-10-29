package lab;

import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class BasicFrame {
	
	public static void main(String[] args) {
		
		JFrame f =new JFrame();
		JPanel name=new JPanel();
		f.setTitle("Basic Frame");
		
		
		JLabel First =new JLabel("First:");
		JLabel Last =new JLabel("Last:");

		JTextField firstfield = new JTextField(10);
		JTextField lastfield = new JTextField(10);
		JButton  click = new JButton("Click ME");
//		ButtonListener btnlis=new ButtonListener();
//		click.addActionListener(btnlis);
		
		
		name.add(First);
		name.add(firstfield);
		name.add(Last);
		name.add(lastfield);
		name.add(click);
		f.add(name);
		
		f.setPreferredSize(new Dimension(800,600));
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.pack();
		f.setVisible(true);
	}

}
