/* Andrew Gates
 * 6/5/2015
 * TCES 203	
 * Extra Credit 3
 * 
 * This program contains the methods to be used by LineTest that will crete a Line that contains 2 different points of type
 * Point class. It will contain the method to construct a line, to get the first point, to get the second point, or to 
 * convert the line into a string for printing.
 */

import java.awt.Point;

public class Line 
{
	//2 private data types that are Point class object that will represent the 2 ends of the line.
	private Point P1;
	private Point P2;
	
	//Constructor.
	public Line(Point p1, Point p2)
	{
		P1 = p1;
		P2 = p2;
	}
	
	//Getter for point 1.
	public Point getP1()
	{
		return P1;
	}
	
	//Getter for point 2.
	public Point getP2()
	{
		return P2;
	}
	
	//Overloaded toString method to convert the Line into a string.
	public String toString()
	{
		return("[(" + P1.x + ", " + P1.y + "), (" + P2.x + ", " + P2.y + ")]");
	}
}
