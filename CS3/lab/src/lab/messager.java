package lab;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class messager {
	public static void main(String[] args) {
		final int WIDTH=500;
		final int HEIGHT=560;
		JFrame frame=new JFrame();
		frame.setTitle("instant messager");
		
		JButton find= new JButton("Find");
		JButton open= new JButton("Open");
		JButton save= new JButton("Save");
		JButton replace= new JButton("Replace");
		
		JTextField text =new JTextField();
		
		JTextField Findtext =new JTextField();
		JTextField replacetext =new JTextField();
		Findtext.setPreferredSize(new Dimension(WIDTH-400,20));
		replacetext.setPreferredSize(new Dimension(WIDTH-400,20));
		JPanel controls = new JPanel();
		
		JPanel LeftButtons =new JPanel();
		LeftButtons.setLayout(new GridLayout(2, 1));
		JPanel RightButtons =new JPanel();
		RightButtons.setLayout(new GridLayout(2, 1));
		JPanel twotext = new JPanel();
		twotext.setLayout(new GridLayout(2,1));
		LeftButtons.add(open);
		LeftButtons.add(save);
		RightButtons.add(find);
		RightButtons.add(replace);
		twotext.add(Findtext);
		twotext.add(replacetext);	
		controls.add(LeftButtons);
		controls.add(twotext);
		controls.add(RightButtons);
		
		JTextArea area=new JTextArea();
		JScrollPane pane =new JScrollPane(area);
		pane.setPreferredSize(new Dimension(WIDTH-10,HEIGHT-200));
		JPanel outer= new JPanel();
		outer.add(pane);
		outer.add(controls, BorderLayout.SOUTH);
		
		ActionListener btnlisF= new SendBtnListener(Findtext,area);
//		SendBtnListener btnlisR= new SendBtnListener(replacetext,area);
//		SendBtnListener btnlisO= new SendBtnListener();
//		SendBtnListener btnlisS= new SendBtnListener();
		find.addActionListener(btnlisF);
//		replace.addActionListener(btnlisR);
	
		
//		open.addActionListener(btnlisO);
//		save.addActionListener(btnlisS);
		
		frame.add(outer);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setPreferredSize(new Dimension(WIDTH,HEIGHT));
		frame.setResizable(true);
		frame.pack();
		frame.setVisible(true);
		
		 class SendBtnListener implements ActionListener {
			
			private JTextField field;
			private JTextArea area;
		
			
			public SendBtnListener( JTextField field, JTextArea area) {
				this.field=field;
				this.area=area;
			}

			

			@Override
			public void actionPerformed(ActionEvent e) {
				
				System.out.println("find");
				System.out.println(field.getText());
				area.append(field.getText());
				area.append("\n");
				
			
				
				
			}
	}
	

}
}

