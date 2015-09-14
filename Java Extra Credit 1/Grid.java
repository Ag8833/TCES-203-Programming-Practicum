/* Andrew Gates
 * 6/1/2015
 * TCES 203	
 * Extra Credit 1
 * 
 * This program will prompt the user to enter 2 numbers, 1 for rows and 1 for columns and will then output that many values in a
 * grid in column-major order. It will then allow the user to enter another combination of columns and rows until they hit n.
 */

import java.util.*;

public class Grid
{
	//Main method for testing.
	public static void main(String [ ] args)
	{
		//Creating a scanner to check input.
		Scanner console = new Scanner(System.in);
		String response = "y";
		
		while (response.equals("y"))
		{
			System.out.print("Enter a number for rows: ");
			int rows = console.nextInt();
			System.out.print("Enter a number for columns: ");
			int columns = console.nextInt();
		
			int temp = 1;
			
			//For loop to manage the number of rows that print.
			for (int i = 0; i < rows; i++)
			{
				//For loop to manage the number of columns that print.
				for (int j = 0; j < columns; j++)
				{
					//Printing temp which is set to 1 at first.
					System.out.print(temp);
					
					if (j < columns-1)
					{
						System.out.print(", ");
					}
					
					//Incrementing temp by the number of rows.
					temp += rows;		
				}
				//Reassigning temp to i+2.
				temp = i+2;
				System.out.println();
			}
			System.out.print("Do you want to enter another set? (y or n): ");
			response = console.next();
		}
		
		//Closing the scanner if it was not already closed.
		if (console != null)
		{
			console.close();
		}
	}
}
