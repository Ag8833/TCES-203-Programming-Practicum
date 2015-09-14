/* Andrew Gates
 * 6/4/2015
 * TCES 203	
 * Extra Credit 2
 * 
 * This program contains the main method for testing and the method minGap to calculate the smallest gap between 2 adjacent
 * elements and it will return that gap between those 2 elements.
 */

public class Gap 
{
	//Main method for testing.
	public static void main(String[] args) 
	{
		int [] firstArray = {1, 3, 6, 7, 12};
		int [] secondArray = {3, 5, 11, 4, 8};
		int [] thirdArray = {1};
		int smallestGap;
		
		smallestGap = minGap(firstArray);
		System.out.println("The smallest gap for first array is: " + smallestGap);
		
		smallestGap = minGap(secondArray);
		System.out.println("The smallest gap for second array is: " + smallestGap);
		
		smallestGap = minGap(thirdArray);
		System.out.println("The smallest gap for third array is: " + smallestGap);
	}
	
	//Method to return the smallest gap between 2 adjacent elements in the array.
	public static int minGap(int [] myArray)
	{
		int smallestGap = 0;
		
		//Check to see if the array has less than 2 elements.
		if (myArray.length < 2)
		{
			return 0;
		}
		
		//For loop to iterate through the array for the length of the array.
		for (int i = 1; i < myArray.length; i++)
		{
			//If minGap does not have a value yet.
			if (smallestGap == 0)
			{
				smallestGap = myArray[i] - myArray[i-1];
			}
			
			//If the newest gap is smaller than the previous minGap value.
			if ((myArray[i] - myArray[i-1]) < smallestGap)
			{
				smallestGap = myArray[i] - myArray[i-1];
			}
		}
		
		return smallestGap;
	}
}
