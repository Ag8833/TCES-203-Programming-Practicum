/* Andrew Gates
 * 6/5/2015
 * TCES 203	
 * Extra Credit 4
 * 
 * This program contains the main testing method to test the creation of an ArrayList object that holds integer values. It will
 * use the minToFront method to find the smallest value in the array and then move that value to the front of the list.
 */

import java.util.ArrayList;

public class Front 
{
	//Main method for testing.
	public static void main(String[] args)
	{
		//Creating a new ArrayList object and then initializing the various values.
		ArrayList<Integer> myList = new ArrayList<Integer>();
		myList.add(0, 3);
		myList.add(1, 8);
		myList.add(2, 92);
		myList.add(3, 4);
		myList.add(4, 2);
		myList.add(5, 17);
		myList.add(6, 9);
		
		//Displaying the initial ArrayList.
		System.out.print("Original elements of ArrayList are: ");
		for (int i = 0; i < myList.size(); i++)
		{
			if (i+1 == myList.size())
			{
				System.out.print(myList.get(i));
			}
			else
			{
				System.out.print(myList.get(i) + ", ");
			}
		}
		
		//Calling the minToFront method.
		myList = minToFront(myList);
		
		//Displaying the modified ArrayList.
		System.out.println();
		System.out.print("Modified elements of ArrayList are: ");
		for (int i = 0; i < myList.size(); i++)
		{
			if (i+1 == myList.size())
			{
				System.out.print(myList.get(i));
			}
			else
			{
				System.out.print(myList.get(i) + ", ");
			}
		}
	}
	
	//Method to find the smallest value in the ArrayList and to move that value to the front of the ArrayList.
	public static ArrayList<Integer> minToFront(ArrayList<Integer> myList)
	{
		int minItem = 0;
		
		//For loop to find the smallest value in the ArrayList.
		for (int i = 0; i < myList.size(); i++)
		{
			//The initial initialization of minItem to the first value in the list.
			if (minItem == 0)
			{
				minItem = myList.get(i);
			}
			
			//If the current value in ArrayList is smaller than the current value of minItem reassign minItem to the new value.
			else if (myList.get(i) < minItem)
			{
				minItem = myList.get(i);
			}
		}
		
		//Iterate through ArrayList to find where that smallest value occurs and then remove that value from the ArrayList.
		for (int i = 0; i < myList.size(); i++)
		{
			//If the smallest item is found, remove it from the ArrayList and then break.
			if (myList.get(i) == minItem)
			{
				myList.remove(i);
				break;
			}
		}
		
		//Add the smallest item back into the ArrayList at the front of the list.
		myList.add(0, minItem);
		
		return myList;
	}
}
