package p1;
import java.util.Scanner;

/**
 * 
 * @author BRYAN PEREZ
 * 
 * I have tested my program and it has no issues.

 * This program is designed to help students choose their school and major of choice. It notifys 
 * the student if he or she major or school is in the program data base. It also lets student input 
 * their GPA and the program will display if they qualify to transfer at school with their major. If 
 * student doesn't not meet the GPA the program will let them know how much they need to improve. 
 *                         
 */
public class p1 {
	public static void main(String[] args)
	{
		// to get out of program
		boolean done=false;
		
		while(!done) {
			int s=0;//saves school on number of row 
			Scanner input =new Scanner(System.in);

			//displays user to enter school
			System.out.print("Enter school name:");
			String School =input.nextLine();
			//get users school they entered and cap
			School = School.toUpperCase();
			

			//enter done in school to exist out of program
			if(School.equals("DONE")) {
				done=true;
				s=-1;
				System.out.println("Bye, bye");
			}
			
			//the row user inputed as school
			if(School.equals("UCLA")) {
				s=1;

			}
			if(School.equals("UCB")) {
				s=2;
			}
			if(School.equals("UCI")) {
				s=3;
			}
			if(School.equals("UCSD")) {
				s=4;
			}
			// end of school on chart
			
			//if school is not on chart
			
			if(s==0) {
				System.out.println(School+" is not a school system.");

			}
			
		//this only allows if school is in chart and doesnt want to exist
			if(!done && s>0) {
			
			//displays user to enter major 
			System.out.print("Enter Major:");
			String Major =input.nextLine();
			//make its major cap 
			Major = Major.toUpperCase();
			
			//to organize major into number of row 
			int m=0;
			
			//if major is in chart make m its row number
			if(Major.equals("CS")) {
				m=1;
				if(School.equals("UCSD"))
				{
					m=0;
				}

			}
			if(Major.equals("EE")) {
				m=2;
				if(School.equals("UCI"))
				{
					m=0;
				}
			}
			if(Major.equals("ECON")) {
				m=3;
				if(School.equals("UCB"))
				{
					m=0;
				}
			}
			if(Major.equals("ENGLISH")) {
				m=4;
			}
			//end of in chart major
		
			//filters only if major is on grid and of course a school in grid

			if(m==0) {
				System.out.println("There is no " + Major + " major at " + School);
			}
			if(m>0) {
				//displays to user to input gpa
				System.out.print("Enter GPA:");
				double Gpa= input.nextDouble();
				
				//this switch uses the row and col to see what gpa is need to transfer there
				//it subtracts the gpa provided with gpa needed
				switch(s) {
				case 1: switch(m) {
						case 1:   Gpa=Gpa-3.7;
								break;
						case 2:  Gpa=Gpa-3.65;
								break;
						case 3: Gpa=Gpa-3.2;
							break;
						case 4: Gpa=Gpa-3.4;
						break;
				}
					break;
					
				case 2: switch(m) {
						case 1:   Gpa=Gpa-3.8;
							break;
						case 2:  Gpa=Gpa-3.7;
							break;

						case 4: Gpa=Gpa-3.4;
							break;
							default:
								
								break;
				}
					break;
			
				case 3: switch(m) {
					case 1:   Gpa=Gpa-3.6;
						break;

					case 3:  Gpa=Gpa-3.4;
						break;

					case 4: Gpa=Gpa-3.3;
						break;
					default:
						
						break;
				}
				break;
				
				case 4: switch(m) {

					case 2:   Gpa=Gpa-3.6;
						break;
					case 3:  Gpa=Gpa-3.0;
						break;

					case 4: Gpa=Gpa-3.45;
						break;
					default: 
						
						break;
				}
				break;
					
				}
				//end of switch
				
				if(Gpa>=0) {
					//if gpa is equal to or greater than gpa needed
					//than let user know he can transfer there 
					System.out.println("You could transfer to " + School + " to study " + Major);
				}
				else {
					//after the switch if gpa is need the user will get notified in this if statement
					//this gives an abs value to gpa needed
					Gpa=Math.abs(Gpa);

					//lets user know what they need to improve to qualify to go there to study their major
					System.out.print("You need to improve your GPA by ");
					System.out.format( "%.2f", Gpa);
					System.out.println(" to transfer to " + School + " to study " + Major);
				}	
			
		}
		}
			
		
	}
}
}








