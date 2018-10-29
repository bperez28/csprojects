import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.Highlighter;
import javax.swing.text.Highlighter.Highlight;
import javax.swing.text.Highlighter.HighlightPainter;




	public class DocFrame extends JFrame
	
	{  
		 private ArrayList<String> str=new ArrayList<String>();
		 private JComboBox<Object> sizebox;
		 private JComboBox<Object> Fontbox;
		 private Font font;
		 private int fontsize;
		 private int fontstyle;
	  private JTextArea display;
	   private JTextField Findtext;
	   private JTextField replacetext;
	   private BufferedReader br;
	   private JFileChooser fileChooser;
	   private File file;
	   String line;
	   int returnval;
	   private static final int FRAME_WIDTH = 800;
	   private static final int FRAME_HEIGHT = 700;
		static class viewer {
			
			   public  static void main(String[] args)throws FileNotFoundException
			   {  
				   
					   
				   
			      JFrame frame = new DocFrame();
			      frame.setTitle("Text Editor");
			      frame.setResizable(true);
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
	  
		

	   public DocFrame()
	   {
		   
		   setSize(FRAME_WIDTH, FRAME_HEIGHT);
			display = new JTextArea();
			 JScrollPane pane =new JScrollPane(display);
			 pane.setPreferredSize(new Dimension(FRAME_WIDTH-20, FRAME_HEIGHT-100));	
			 
		      add(pane);
			createControlPanel();
				
				
	   }
	      

	/**
	      Creates the control panel with the text field 
	      and buttons on the frame.
	   */
	   private void createControlPanel()
	   {      

		   JPanel Control = new JPanel();
		   
		   JPanel leftbuttonPanel = new JPanel();
		   leftbuttonPanel.setLayout(new GridLayout(2, 0));
		   JPanel RightbuttonPanel = new JPanel();
		   RightbuttonPanel.setLayout(new GridLayout(2, 0));
		   leftbuttonPanel.add(makeButton("Open"));
		   leftbuttonPanel.add(makeButton("Save"));
		   RightbuttonPanel.add(makeButton("Find"));
		   RightbuttonPanel.add(makeButton("Replace"));
		   RightbuttonPanel.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/7));
		   leftbuttonPanel.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/7));
		   
		   
		   JPanel boxes = new JPanel();
		   boxes.setLayout(new GridLayout(2,0));
		   sizebox = new JComboBox<Object>();
		   Fontbox = new JComboBox<Object>();
		   sizebox.addItem(makesize("9"));
		   sizebox.addItem(makesize("12"));
		   sizebox.addItem(makesize("16"));
		   sizebox.addItem(makesize("20"));
		  Fontbox.addItem(makefont("Plain"));
		  Fontbox.addItem(makefont("Bold"));
		  Fontbox.addItem(makefont("Italics"));
		  boxes.add(sizebox);
		  boxes.add(Fontbox);
		   
		   boxes.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/7));

			JPanel Text = new JPanel();
			Text.setLayout(new GridLayout(2,0));
			Findtext =new JTextField();
			 replacetext =new JTextField();
//			 ActionListener btnlisF= new SendBtnListener(Findtext,display);
//			 Findtext.addActionListener(btnlisF);
//			 ActionListener btnlisr= new SendBtnListener(replacetext,display);
//			 replacetext.addActionListener(btnlisr);
			 Text.add(Findtext);
			 Text.add(replacetext);
			
			
			Text.setPreferredSize(new Dimension(FRAME_WIDTH/5, FRAME_HEIGHT/7));
		
			
			  Control.add(leftbuttonPanel);
			   Control.add(boxes);
			   Control.add(Text);
			   Control.add(RightbuttonPanel);
		   

	      add(Control, BorderLayout.SOUTH);
	   }
	      
	   class SendBtnListener implements ActionListener
	   {
	   	private JTextField f;
	   	private JTextArea a;
	   	
	   	 public SendBtnListener(JTextField field,JTextArea area)
	        {
	   		
	           f=field;
	           a=area;
	        }
	   	 
	   	
	   	 public void actionPerformed(ActionEvent event) 
	        { 
	   		String myWord = f.getText();
            Highlighter h = display.getHighlighter();
              Pattern pattern = Pattern.compile("\\b"+myWord+"\\b");
                
               Matcher matcher = pattern.matcher(myWord);
					
					boolean matchFound = matcher.matches(); // false
            
            
            
               if (!matchFound){
               
                  while( matcher.find() )
                  {
                     int start = matcher.start();
                     int end = matcher.end();
                  
                     try {
                        Font font = new Font("Verdana", Font.BOLD,40);
                     
                        h.addHighlight(start, end, DefaultHighlighter.DefaultPainter);
                     } 
                        catch (BadLocationException e1) {
                        
                           e1.printStackTrace();
                        }
                  }
               
               }
               
               else
               {
                  JOptionPane.showMessageDialog(null,"No Match Found"); 
               }
            
	   		
	   		 
	        
	   }
	   }


public Object makesize(String string) {
		// TODO Auto-generated method stub
	ActionListener listener= new comboListener();
	sizebox.addActionListener(listener);
		return string;
	}
public Object makefont(String string) {
	// TODO Auto-generated method stub
ActionListener listener= new fontListener();
Fontbox.addActionListener(listener);
	return string;
}

class fontListener implements ActionListener
{
	private String str;
	 public fontListener()
     {

     }
	 
	 public void actionPerformed(ActionEvent event) 
     { 
		 str = (String) Fontbox.getSelectedItem();
		 
		 if(str.equals("Plain")) {
			 fontstyle=1;
			 creatfont();
			 
		
			 
		 }else if(str.equals("Bold")) {
			 fontstyle=2;
			 creatfont();
		        
			 
		 }else if(str.equals("Italics")) {
			 fontstyle=3;
			 creatfont();
			 
		 }
		 
     }
	 private void creatfont() {
			// TODO Auto-generated method stub
			switch(fontstyle) {
			case 1: font = new Font("Arial", Font.PLAIN, fontsize);
	        display.setFont(font);
	        break;
			case 2:  font = new Font("Arial", Font.BOLD, fontsize);
	        display.setFont(font);
	        break;
			case 3:  font = new Font("Arial", Font.ITALIC, fontsize);
	        display.setFont(font);
	        break;
	        default:  font = new Font("Arial", Font.PLAIN, fontsize);
	        display.setFont(font);
	        break;
			}
		}
}

class comboListener implements ActionListener
{
	 String str;
	 public comboListener()
     {
     }
	 
	 public void actionPerformed(ActionEvent event) 
     { 
		 str = (String) sizebox.getSelectedItem();
		
		 if(str.equals("9")) {
			 fontsize=9;
			 creatfont(); 
			 
		 }else if(str.equals("12")) {
			 
			 fontsize=12;
			 creatfont(); 
			
			 
		 }else if(str.equals("16")) {
			 
			 fontsize=16;
			 creatfont(); 
			 
		 }else if(str.equals("20")) {
			 fontsize=20;
			 creatfont(); 
			 
		 }
		 
     }

	private void creatfont() {
		// TODO Auto-generated method stub
		switch(fontstyle) {
		case 1: font = new Font("Arial", Font.PLAIN, fontsize);
        display.setFont(font);
        break;
		case 2:  font = new Font("Arial", Font.BOLD, fontsize);
        display.setFont(font);
        break;
		case 3:  font = new Font("Arial", Font.ITALIC, fontsize);
        display.setFont(font);
        break;
        default:  font = new Font("Arial", Font.PLAIN, fontsize);
        display.setFont(font);
        break;
		}
	}
}

	   
	   class ButtonListener implements ActionListener
	   {
	      private String button;
	      
	      /**
	         Constructs a listener whose actionPerformed method adds a digit
	         to the display.
	         @param aDigit the digit to add
	      */
	      public ButtonListener(String name)
	      {
	         button = name;
	      }
	      
	      public void actionPerformed(ActionEvent event) 
	      {  
	        if(button.equals("Open")) {
	        	fileChooser = new JFileChooser();
	       
	       returnval=fileChooser.showOpenDialog(null);
	       if(returnval== JFileChooser.APPROVE_OPTION) {
	    	   file = fileChooser.getSelectedFile();
	       }
	     
	     
	       try {
	    	   br = new BufferedReader(new FileReader (file));
	    	   while((line = br.readLine()) != null){
	    		  str.add(line+"\n");
	    		  String text= str.toString();
	    		  display.setText(text);
	    		
	    		   
	    		  
	    	   }
	       }catch(Exception e) {
	    	   e.printStackTrace();
	       }
	       
	       
	       
	        			    
	        	
	        }else if(button.equals("Save")) {
	        	
	        	fileChooser = new JFileChooser();
	        	fileChooser.setDialogTitle("Save Document");
	        	returnval=fileChooser.showSaveDialog(null);
	        	if(returnval== JFileChooser.APPROVE_OPTION) {
	        		String inside =display.getText();
	        		File in = fileChooser.getSelectedFile();
	        	
	        	try {
	        		FileWriter fileWriter = new FileWriter(in.getPath());
	        		fileWriter.write(inside);
	        		fileWriter.flush();
	        		fileWriter.close();
	        	}catch(Exception e) {
	        		
	        	}
	        	}
	 	       
	        	
	        }else if(button.equals("Find")) {
	        	
	        	String Word = Findtext.getText();
	            Highlighter h = display.getHighlighter();
	           
	              Pattern pattern = Pattern.compile("\\b"+Word+"\\b");
	                
	               Matcher matcher = pattern.matcher(display.getText());
						
						boolean matchFound=matcher.matches(); //false
	            
	            
	               if (!matchFound){

	               
	                  while(matcher.find())
	                  {
	                	  
	                     int start = matcher.start();
	                     int end = matcher.end();
	                     
	                    
	                  
	                     try {

	                        h.addHighlight(start, end, DefaultHighlighter.DefaultPainter);
	                        
	                     } 
	                        catch (BadLocationException e1) {
	                        
	                           e1.printStackTrace();
	                        }
	                  }
	                  
	               
	               }
	               else{
	            	   		JOptionPane.showMessageDialog(null, Word+" was not found in Document", "Text not found",JOptionPane.INFORMATION_MESSAGE);

	               }
	            
	        
	        	
	        }else if(button.equals("Replace")) {
	        	
	        	
	         	String foundWord = Findtext.getText();
	        String replaceWord=	replacetext.getText();
	        Pattern pattern = Pattern.compile("\\b"+foundWord+"\\b");
            
            Matcher matcher = pattern.matcher(display.getText());
					
					boolean match = matcher.matches(); // false
					
					if (!match){
					
			               
		                  while( matcher.find() )
		                  {
		                     int start = matcher.start();
		                     int end = matcher.end();
		                     display.replaceRange(replaceWord, start, end);
		                  
		                  }
		               
		               }
	        	
	        }
	      }

		

		        
	   }

	   /**
	      Makes a button representing a digit of a calculator.
	      @param digit the digit of the calculator
	      @return the button of the calculator
	   */
	   public JButton makeButton(String name)
	   {
	      JButton button = new JButton(name);      
	      ActionListener listener = new ButtonListener(name);
	      button.addActionListener(listener);  
	      return button;    
	   } 
	   
	}
	
	



