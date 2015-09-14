/*
 * Andrew Gates
 * 4/20/2015
 * TCES 203
 * Assignment #3
 *
 * This program contains the execution of functions to be used in conjunction with student.cpp and student.h. It will initialize the variables
 * that will be returned and sent to the functions in student.cpp. It will call all of the functions in student.cpp based on the input that
 * the user enters at the main menu.
 */

#include "student.h"

//Main function to call the corresponding functions based on the user's menu input.
int main()
{
	int response, arraySize, index = 0;
	Student *studentArray;

	//Loop to call the corresponding function depending on what response is received from the function printMenu.
	while (response != 0)
	{
		response = printMenu();
		if (response == 1)
		{
			arraySize = getSize();
			studentArray = createStudents(arraySize);
		}
		else if (response == 2)
			printStudentInfo(studentArray, arraySize, index);
		else if (response == 3)
			printStudentInfo(studentArray, arraySize);
		else if (response == 4)
			editStudentInfo(studentArray, arraySize, index);
	}

	//Calls freeStudentInfo to delete the dynamically allocated structure created earlier in the program.
	freeStudentInfo(studentArray);

	cin.get();
	cin.get();
	return 0;
}
