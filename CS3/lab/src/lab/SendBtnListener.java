package lab;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SendBtnListener implements ActionListener {
	
	private JTextField field;
	private JTextArea area;
	
	public SendBtnListener( JTextField field, JTextArea area) {
		this.field=field;
		this.area=area;
	}
	

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("i got an event");
//		area.append(im.getText());
		area.append("\n");
		
	}
	

}
