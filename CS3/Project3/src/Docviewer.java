import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.FileNotFoundException;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Docviewer {
	
		   public  static void main(String[] args)throws FileNotFoundException
		   {  
		      JFrame frame = new DocFrame();
		      frame.setTitle("Text Editor");
		      frame.setVisible(true);
		      frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		      frame.addWindowListener(new WindowAdapter(){
		    	  @Override
		    	  public void windowClosing(WindowEvent we)
		    	  {
		    	    String Buttons[] = {"Cancel","Ok"};
		    	    int Result = JOptionPane.showOptionDialog(null, 
		    	        "Are you sure you want to close this Application?", "Confirm Exist", 
		    	        JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, 
		    	        Buttons,Buttons[1]);
		    	    if(Result==1)
		    	    {
		    	      System.exit(1);          
		    	    }
		    	  }
		    	  
		      });
		      
		    
		     
		   }
		   
		 		  
}
 

		


