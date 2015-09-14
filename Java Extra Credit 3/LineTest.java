/* Andrew Gates
 * 6/5/2015
 * TCES 203	
 * Extra Credit 3
 * 
 * This program contains the testing of the methods that are in Line.java. It will construct 2 different lines from 4 points of
 * type Point class. It will then print the 2 lines using the toString method.
 */

import java.awt.Point;

public class LineTest 
{
	//Main method for testing.
	public static void main(String[] args) 
	{
		//Constructing the 2 Points of the first line.
		Point p1 = new Point(1, 2);
		Point p2 = new Point(3, 4);
		Line firstLine = new Line(p1, p2);
		
		//Constructing the 2 points of the second line.
		Point p3 = new Point (-5, -66);
		Point p4 = new Point (-777, -8888);
		Line secondLine = new Line(p3, p4);
		
		//Outputting the 2 lines using the toString method.
		System.out.println(firstLine.toString());
		System.out.println(secondLine.toString());
	}
}
