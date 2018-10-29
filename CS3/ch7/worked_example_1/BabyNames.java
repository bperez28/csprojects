import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
   This program displays the most common baby names. Half of boys and girls in
   the United States were given these names in the 1990s.
*/
public class BabyNames
{
   public static final int LIMIT = 50;

   public static void main(String[] args) throws FileNotFoundException
   {  
      Scanner in = new Scanner(new File("babynames.txt"));
         
      double boyTotal = 0;
      double girlTotal = 0;
      
      while (boyTotal < LIMIT || girlTotal < LIMIT)
      {
         int rank = in.nextInt();
         System.out.print(rank + " ");

         boyTotal = processName(in, boyTotal);
         girlTotal = processName(in, girlTotal);

         System.out.println();
      }

      in.close();
   }

   /**
      Reads name information, prints the name if total >= 0, and adjusts the total.
      @param in the input stream
      @param total the total percentage that should still be processed
      @return the adjusted total
   */
   public static double processName(Scanner in, double total)
   {
      String name = in.next();
      int count = in.nextInt();
      double percent = in.nextDouble();
      
      if (total < LIMIT) { System.out.print(name + " "); }
      total = total + percent;
      return total;
   }
}	
