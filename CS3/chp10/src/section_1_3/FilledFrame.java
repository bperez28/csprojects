package section_1_3;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;


/**
   A frame that is filled with two components.
*/
public class FilledFrame extends JFrame
{
   private JButton multi;
   private JButton add;
   private JButton sub;
   private JButton divid;
   private JLabel label;
   private JLabel num1;
   private JLabel num2;
   private JTextField text1;
   private JTextField text2;
   private int result;
  
   

   private static final int FRAME_WIDTH = 300;
   private static final int FRAME_HEIGHT = 100;

   public FilledFrame()
   {
      createComponents();
      setSize(FRAME_WIDTH, FRAME_HEIGHT);
   }
   class ClickListener implements ActionListener{
	   public void actionPerformed(ActionEvent event) {
		   Object source = event.getSource();
//		   if(source   ) {
//			   JButton btnSource = (JButton)
//		   }
		   
//		   this writes out which was clicked
		   int value1 =Integer.parseInt(text1.getText());
		   int value2 =Integer.parseInt(text2.getText());
		   
		   if(source == add) {
			   result = value1+value2;
			   System.out.println(result);
			    
		   }
		   else if(source==sub) {
			   result = value1-value2;
		   }
		   else if(source==multi) {
			    result = value1*value2;
			    
		   }
		   else if(source==divid) {
			   result = value1/value2;
		   }
		   
	   }
   }
   
   private void createComponents()
   {

	   text1 =new JTextField(10);
	   text2 =new JTextField(10);
	   
	   num1 = new JLabel("number:");
	   num2 = new JLabel("Result:");
	  
	      
	      add = new JButton("+");
	      sub= new JButton("-");
	      multi= new JButton("*");
	      divid= new JButton("/");
   
      
	      ActionListener listener = new ClickListener();
		   add.addActionListener(listener);
		      sub.addActionListener(listener);
		      multi.addActionListener(listener);
		      divid.addActionListener(listener);
     
      label = new JLabel("Result:");

      JPanel panel = new JPanel();
      JPanel ButtonPanel= new JPanel();
      ButtonPanel.setLayout(new GridLayout(1, 4));
      
      panel.add(num1);
      panel.add(text1);
      panel.add(num2);
      panel.add(text2);
      
      ButtonPanel.add(add);
      ButtonPanel.add(sub);
      ButtonPanel.add(multi);
      ButtonPanel.add(divid);
      
      panel.add(ButtonPanel);
     
      add(panel);
    
   }
}
