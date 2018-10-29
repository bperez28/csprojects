package lab;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;

public class ButtonListener implements ActionListener{
	private JPanel panel;
	
	@Override
	public void actionPerformed(ActionEvent e) {
//		System.out.println("i got called");
//		panel.setBackground(Color.blackBLACK);
	}
	
	public ButtonListener(JPanel actone) {
		panel=actone;
	}
	

}
