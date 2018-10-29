import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.geom.Dimension2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.Timer;

import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.Rectangle;

/**
 * 
 * @author Bryan perez
 * CS3b
 *
 */

public class GameFrame extends JFrame 
{
	public static int FrameWidth=700;
	public static int FrameHeight=700;
	public BrickBreaker run;
	public static JFrame frame;

	static class Viewer{

		public  static void main(String[] args)throws FileNotFoundException
		{  
			frame= new GameFrame();
			frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
			frame.setTitle("Brick Breaker");
			frame.setVisible(true);


		}

	}

	/**
	 * frame calls this 
	 * @throws FileNotFoundException
	 */
	GameFrame() throws FileNotFoundException{  
		setResizable(true);
		setBackground(Color.black); 

		//this catches if the file cant be read
		//its trying to read the highscore created when 
		//game beats highscore
		try {
			//BrickBreaker class extends JPanel 
			run = new BrickBreaker();
			add(run);  

		} catch (FileNotFoundException e) {
			//catches if file not read when trying to get highscore
			e.printStackTrace();
		}


		//this is when trying to close the window
		addWindowListener(new WindowAdapter(){
			@Override
			public void windowClosing(WindowEvent we)
			{	
				//this will pause the game to ask if you want to close the game
				((BrickBreaker) run).stoptime();
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

		pack();


	}

	/**
	 * 
	 * @author Bryan
	 *
	 */
	class BrickBreaker extends JPanel implements ActionListener, MouseMotionListener, MouseListener{

		private Timer time;
		private int sec=0;
		private int min=0;
		private PrintWriter file;
		private BufferedImage img;
		private BufferedImage blue;
		private BufferedImage green;
		private BufferedImage red;
		private BufferedImage white;
		private Scanner in ;
		private String highScore;
		private String name;
		public Font font;
		public String str="";
		private int viewtime=0;
		private int totalbricks;
		private  int  rowblocks=5;
		private int  colblocks=5;
		private int ball=20;
		private int posx=FrameWidth/2;
		private int posy=FrameHeight-70;
		private int barx =FrameWidth/2-40;
		private int bary= FrameHeight-40;
		private int barHeight =FrameHeight/100;
		private int barWidth =FrameWidth/7;
		private int hold=8;
		private boolean play= false;
		private int direcx=-1;
		private int direcy=-2;
		public brickgen bricks;




		/**
		 * This is called in the main by the frame
		 * it calles the brickcreaters and actionlisteners
		 * and starts the timer
		 */
		public BrickBreaker() throws FileNotFoundException
		{ 
			//calls brickgen class that creates the array of bricks
			bricks=new brickgen(rowblocks,colblocks);
			add(bricks,BorderLayout.CENTER);

			//adding mouse actionlisteners
			addMouseListener(this);
			addMouseMotionListener(this);
			setFocusable(true);
			setPreferredSize(new Dimension(FrameWidth,FrameHeight));
			try {
				//this scans file created once a winner wins 
				img= ImageIO.read(new File("img.png"));
				white= ImageIO.read(new File("white.png"));
				red= ImageIO.read(new File("red.png"));
				green= ImageIO.read(new File("green.png"));
				blue= ImageIO.read(new File("blue.png"));
				in = new Scanner(new File("HighScore.txt"));
				name=in.next();
				highScore=in.next();
			}catch(FileNotFoundException e) {
				System.out.println(e.getMessage());
			}catch(NoSuchElementException e) {
				System.out.println(e.getMessage());
			} catch (IOException e) {

				e.printStackTrace();
			}

			time=new Timer(hold,this);
			time.start();


		}

		/**
		 * this is a function that restarts the game 
		 * to normal settings
		 * this is called when someone wins the game 
		 */
		private void restartgame() {

			posx=FrameWidth/2;
			posy=FrameHeight-70;
			barx =FrameWidth/2-40;
			bary= FrameHeight-40;
			barHeight =FrameHeight/100;
			barWidth =FrameWidth/7;
			ball=20;
			hold=7;
			direcx=-1;
			direcy=-2;
			viewtime=0;
			time.start();
			bricks=new brickgen(rowblocks,colblocks);


		}
		/**
		 * this paints the bricks, the time, score and pause 
		 *  
		 */
		public void paintComponent(Graphics s) {

			//when frame is resized
			FrameWidth=frame.getWidth();
			FrameHeight=frame.getHeight();
			bary= FrameHeight-40;


			//background
			if(str.equals("Pause")) {
				s.setColor(Color.gray);
				s.fillRect(0, 0, FrameWidth,FrameHeight);
			}else {
				s.drawImage(img, 0, 0, FrameWidth, FrameHeight, null);


			}
			//edge
			s.setColor(Color.DARK_GRAY);
			s.fillRect(0, 0, 0, FrameHeight-8);
			s.fillRect(0, 0, FrameWidth-8, 0);
			s.fillRect(FrameWidth-8, 0, 0, FrameHeight-8);

			//this calls the brickgen class to paint the bricks
			((brickgen) bricks).paintComponent((Graphics2D)s,str,white,blue,green,red);


			//ball 
			if(str.equals("Pause")) {
				s.setColor(Color.PINK);
				s.fillOval(posx, posy, ball, ball);
			}else {
				s.setColor(Color.RED);

				s.fillOval(posx, posy, ball, ball);
			}

			//bar
			s.setColor(Color.white);
			s.fillRect(barx, bary, barWidth, barHeight);

			//Title
			font = new Font("Arial", Font.PLAIN, FrameWidth/30);
			s.setFont(font);
			s.drawString("Brick Breaker", (FrameWidth/2)-80 , 30);

			//paused
			s.drawString(str, (FrameWidth/2)-40, FrameHeight/2);

			//Score 
			font = new Font("Arial", Font.PLAIN, FrameWidth/30);
			s.setFont(font);

			//			
			//time
			sec =viewtime/100;
			if(sec>=60) {
				viewtime=0;
				min++;
			}
			if(sec<10) {
				s.drawString("Time: "+min+":0"+sec, 3, 30);
			}else {
				s.drawString("Time: "+min+":"+sec, 3, 30);
			}

			//totalbricks
			s.drawString("Hits: "+totalbricks, 13, 65 );

			//HighScore
			s.drawString("BestTime:", FrameWidth-(FrameWidth/6), 30);
			s.drawString(name+" "+highScore, FrameWidth-(FrameWidth/6), 65);


			s.dispose();
		}


		@Override
		public void actionPerformed(ActionEvent e) { 

			//if game is not paused (paused when clicked or when pressed to close tab)
			if(play) {

				time.start();
				viewtime++;
				//str is cleared when game is not paused when its paused it holds pause
				str="";

				//if the ball intersects the bar
				if(new Rectangle(posx,posy,ball,ball).intersects(new Rectangle(barx,bary,barWidth,barHeight))) {

					//this add more control for user when ball is hit on the edge of bar make the ball go that
					//direction
					if(new Rectangle(posx,posy,ball,ball).intersects(new Rectangle(barx,bary,barWidth/5,barHeight))) {
						if(direcx>0) {
							direcx=-direcx;
						}

					}else if(new Rectangle(posx,posy,ball,ball).intersects(new Rectangle(barx+barWidth-barWidth/5,bary,barWidth/5,barHeight))) {
						if(direcx<0) {
							direcx=-direcx;
						}
					}
					direcy=-direcy;
				}

				posx+=direcx;
				posy+=direcy;

				//if ball hit the edges
				if(posx<0) {

					direcx=-direcx;
				}
				if(posy<0) {

					direcy=-direcy;
				}
				if(posx>FrameWidth-30) {

					direcx=-direcx;
				}
				//if ball falls down
				if(posy>FrameHeight-20) {
					time.stop();

					String Buttons[] = {"Quit","Play Again"};
					int Result = JOptionPane.showOptionDialog(null, 
							"GameOver", "Confirm Exist", 
							JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, 
							Buttons,Buttons[1]);
					if(Result==0)
					{
						System.exit(1); 

					}else {

						//setting are back to original 
						restartgame();


					}


				}

				//this checks if the ball intersects a brick than destroys it or changes the 
				//value of the brick -1
				((brickgen) bricks).brickdestroyer(posx, direcx, posy, direcy); 
				//keeps score of hits left

				totalbricks=((brickgen) bricks).getBrickTotal();

				//if a brick is destroyed
				if(((brickgen) bricks).isdestroyed()) {
					direcx=-direcx;
					direcy=-direcy;
					((brickgen) bricks).setdestroytofalse();


				}
				//if there are no bricks to hit
				if(totalbricks<=0) {

					time.stop();
					String OldTime[]=highScore.split(":");

					int OldMin=Integer.valueOf(OldTime[0]);
					int OldSec=Integer.valueOf(OldTime[1]);
					if(min<=OldMin) {
						if(sec<=OldSec) {

							name = JOptionPane.showInputDialog(null, "Enter Name:", "Winner",
									JOptionPane.DEFAULT_OPTION);

							if(sec<10) {
								highScore=min+":"+"0"+String.valueOf(sec);
							}else {
								highScore=min+":"+String.valueOf(sec);
							}
							try {
								file= new PrintWriter("HighScore.txt");
								file.println(name+" "+highScore);
								file.close();
							} catch (FileNotFoundException e1) {

								e1.printStackTrace();
							}

							String Buttons[] = {"Quit","Play Again"};
							int Result = JOptionPane.showOptionDialog(null, 
									"Winner!!!", "", 
									JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, 
									Buttons,Buttons[1]);
							if(Result==0)
							{

								System.exit(1); 
							}else {

								//resets all setting to original form
								restartgame();

							}


						}
					}else {
						String Buttons[] = {"Quit","Play Again"};
						int Result = JOptionPane.showOptionDialog(null, 
								"Lost", "", 
								JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, null, 
								Buttons,Buttons[1]);
						if(Result==0)
						{

							System.exit(1); 
						}else {

							//resets all setting to original form
							restartgame();

						}

					}
				}

				//if clicked to pause or trying to close
			}else if(!play) {

				time.stop();
				str="Pause";	
			}

			repaint();
		}

		@Override
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub

		}

		@Override
		public void mouseReleased(MouseEvent e) {
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
		public void mouseDragged(MouseEvent e) {
			// TODO Auto-generated method stub

		}


		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			//if running and clicked
			if(time.isRunning()) {
				play=false;

			}else {
				//clicked again to start
				time.start();
			}


		}

		@Override
		public void mouseMoved(MouseEvent e) {
			// TODO Auto-generated method stub

			if(barx>=550) {
				barx=550;
			}
			else {
				play=true;
				barx=e.getX();
			}
			if(barx<10) {
				barx=10;
			}
			else {
				play=true;
				barx=e.getX();

			}

		}

		/**
		 * this is called when the user presses the exist to stop the 
		 *game
		 */
		public void stoptime() {
			play=false;

		}



	}
	/**
	 * this creats the brick array , paints bricks, destroys bricks, gets score 
	 * @author Bryan
	 *
	 */
	class brickgen extends Component 
	{
		private int bluebrickrow1;
		private int bluebrickcol1;
		private int bluebrickrow2;
		private int bluebrickcol2;
		private int bluebrickrow3;
		private int bluebrickcol3;
		private int greenbrickrow;
		private int greenbrickcol;
		private int redbrickrow;
		private int redbrickcol;
		public int brick[][];
		private int brickWidth =FrameWidth/2+150;;
		private int brickHeight=FrameHeight/4+30;;
		private int brickWidthGap=FrameWidth/6;
		private int brickHeightGap=FrameHeight/100+80;
		private int ball=20;
		private int row;
		private int col;
		private int brickTotal;
		private boolean destroyed=false;

		/**
		 * this sets rows and col creats a random block
		 * that needs extra hitd to break, this calles the
		 * block maker 
		 *  
		 * @param row1
		 * @param col1
		 */
		brickgen(int row1, int col1){
			//this generates random spots for the different colored bricks
			row=row1;
			col=col1;
			double rowvalue=Math.random()*row;
			bluebrickrow1=(int)rowvalue;		
			double colvalue=Math.random()*col;
			bluebrickcol1=(int)colvalue;

			rowvalue=Math.random()*row;
			bluebrickrow2=(int)rowvalue;		
			colvalue=Math.random()*col;
			bluebrickcol2=(int)colvalue;

			rowvalue=Math.random()*row;
			bluebrickrow3=(int)rowvalue;		
			colvalue=Math.random()*col;
			bluebrickcol3=(int)colvalue;

			rowvalue=Math.random()*row;
			greenbrickrow=(int)rowvalue;		
			colvalue=Math.random()*col;
			greenbrickcol=(int)colvalue;

			rowvalue=Math.random()*row;
			redbrickrow=(int)rowvalue;		
			colvalue=Math.random()*col;
			redbrickcol=(int)colvalue;


			brick= new int[row][col];
			//fills the array 
			brickmaker(row*col,0,0,brick);

			//this is used for the paint & destroyer
			brickWidth=brickWidth/col;
			brickHeight=brickHeight/row;

		}
		/**
		 * recursion helper this is called in the paintcomponent of brickbreaker
		 * also updates frame width and height for bricks to change when 
		 * resized 
		 * @param s
		 */
		public void paintComponent(Graphics s,String str,BufferedImage white, BufferedImage blue, 
				BufferedImage green, BufferedImage red ) {

			FrameWidth=frame.getWidth();
			FrameHeight=frame.getHeight();	
			brickWidth =FrameWidth/2+150;
			brickHeight=FrameHeight/4+30;
			brickWidthGap=FrameWidth/6;
			brickHeightGap=FrameHeight/100+80;
			brickWidth=brickWidth/col;
			brickHeight=brickHeight/row;

			paintComponent(row*col,0,0,brick,(Graphics2D) s,str,white,blue,green,red);

		}


		/**
		 * recursion will start from row and col 0
		 * this will draw the blocks till i is 0
		 * @param i = row*col
		 * @param row2=0
		 * @param col2=0
		 * @param brick2=bricks
		 * @param s
		 * @return
		 */
		private int paintComponent(int i,int row2, int col2, int[][] brick2,  Graphics2D s,String str,BufferedImage white, 
				BufferedImage blue, BufferedImage green, BufferedImage red ) {
			if(i<=0) {
				return 0;
			}
			if(str.equals("Pause")) {
				if(brick2[row2][col2]==1) {

					s.drawImage(white, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.gray);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);


				}
				if(brick2[row2][col2]==2) {
					s.drawImage(blue, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.gray);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}
				if(brick2[row2][col2]==3) {
					s.drawImage(green, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.gray);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}
				if(brick2[row2][col2]==4) {
					s.drawImage(red, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.gray);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}

			}else {
				if(brick2[row2][col2]==1) {
					s.drawImage(white, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.black);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}else if(brick2[row2][col2]==2) {
					s.drawImage(blue, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.black);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}else if(brick2[row2][col2]==3) {
					s.drawImage(green, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.black);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);
				}else if(brick2[row2][col2]==4) {

					s.drawImage(red, col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight, null);
					s.setStroke(new BasicStroke(3));
					s.setColor(Color.black);
					s.drawRect(col2*brickWidth+brickWidthGap, row2*brickHeight+brickHeightGap, brickWidth, brickHeight);

				}
			}
			col2++;
			if(col2==col) {
				col2=0;
				row2++;
			}

			return paintComponent(i-1,row2,col2,brick2,s,str,white,blue,green,red);
		}
		/**
		 * recursion  fills int array will numbers 
		 * indicating how many hits it need to destroy them 
		 * and what color they will be paint it 
		 * @param i
		 * @param row1
		 * @param col1
		 * @param brick2
		 * @return
		 */
		private int brickmaker(int i, int row1, int col1, int[][] brick2) {
			if(i<=0) {
				return 0;
			}

			if(row1==bluebrickrow1 && col1==bluebrickcol1) {
				brickTotal=brickTotal+2;
				brick2[row1][col1]=2;
			}else if(row1==bluebrickrow2 && col1==bluebrickcol2) {
				brickTotal=brickTotal+2;
				brick2[row1][col1]=2;
			}else if(row1==bluebrickrow3 && col1==bluebrickcol3) {
				brickTotal=brickTotal+2;
				brick2[row1][col1]=2;
			}else if(row1==greenbrickrow && col1==greenbrickcol) {
				brickTotal=brickTotal+3;
				brick2[row1][col1]=3;
			}else if(row1==redbrickrow && col1==redbrickcol) {
				brickTotal=brickTotal+4;
				brick2[row1][col1]=4;
			}else {
				brickTotal++;
				brick2[row1][col1]=1;
			}



			col1++;
			if(col1==col) {
				row1++;
				col1=0;
			}

			return brickmaker(i-1,row1,col1,brick2);
		}
		/**
		 * recursion helper
		 * @param posx this is the ball position of x
		 * @param direcx this is direction of the ball
		 * @param posy this is direction of the ball
		 * @param direcy
		 * @return
		 */
		public int brickdestroyer(int posx,int direcx, int posy, int direcy) {
			return brickdestroyer(0,0,posx,direcx,posy,direcy);
		}
		/**
		 * recursion
		 * @param i = 0 
		 * @param j =0 
		 * @param posx
		 * @param direcx
		 * @param posy
		 * @param direcy
		 * @return
		 */
		private int brickdestroyer(int i, int j, int posx, int direcx, int posy, int direcy) {
			if(i>=row) {
				return 0;
			}

			if(brick[i][j]>0) {

				int bricksx=j*brickWidth +brickWidthGap;
				int bricksy=i*brickHeight+brickHeightGap;

				Rectangle bricksrec= new Rectangle(bricksx, bricksy, brickWidth, brickHeight);
				Rectangle ballrec= new Rectangle(posx, posy, ball, ball);


				if(ballrec.intersects(bricksrec)) {	
					//this subtracts the value in the array
					subValofBrick(i,j);
					brickTotal--;
					destroyed=true;


				}

			}

			j++;
			if(j==col) {
				i++;
				j=0;
			}
			return brickdestroyer(i,j,posx,direcx,posy,direcy);
		}

		/**
		 * this is called when a brick is hit it will subtract one to 
		 * the exsiting brick 
		 * @param i
		 * @param j
		 */
		private void subValofBrick(int i, int j) {
			if(brick[i][j]==1) {
				brick[i][j]=-4;
			}else {
				brick[i][j]=brick[i][j]-1;
			}

		}

		/**
		 * lets the brickbreaker know how many bricks are left
		 * to hit
		 * @return
		 */
		public int getBrickTotal() {

			return brickTotal;
		}
		/**
		 * is called in actionpreformed to let it know a brick was hit
		 * @return
		 */
		boolean isdestroyed() {

			return destroyed;
		}
		/**
		 * this is to set the boolean to false once the if statement in
		 * actionpreformed changes direction of the ball  
		 */
		public void setdestroytofalse() {
			destroyed=false;

		}

	}

}

