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

#include "Student.h"

int main()
{
	int arraySize;
	Student *studentArray;
	do
	{
		cout << "Enter the number of students that you want to enter data for (enter 2): ";
		cin >> arraySize;
	}
	while (arraySize != 2);
	//Dynamically allocating the array that will contain all of the data for the amount of students that the user enters.
	studentArray = new Student [arraySize];

	//Function call to fill the studentArray with predefined student info.
	studentArray = initializeStudentInfo(studentArray, arraySize);
	//Initializing and setting the values for Student 3.
	Student student3("Bob","Eating",56789);
	//Initializing and setting the values (which are nothing) for Student 4.
	Student student4;

	//Function call to print the individual values of studentArray.
	printIndividualArrayValues(studentArray, arraySize);
	//Function call to print the individual values for Student 3 and Student 4.
	printIndividualStudentValues(student3, student4);

	//Function call to print every value for the students in the array.
	printAllArrayValues(studentArray, arraySize);
	//Function call to print every value for the individual students.
	printAllStudentValues(student3, student4);

	//Function call to change Student 2's info and then editing Student 2's info with the new info.
	studentArray = editStudentArray(studentArray);

	//Printing out the post edit info for Student 2.
	cout << endl << "Info for Student 2 after editing Student 2's hobby and id:" << endl;
	studentArray[1].getStudentInfo();

	//Copying the info stored in Student 3 to Student 5.
	Student student5 = student3;

	//Printing out the copied info stored at Student 5.
	cout << endl << "Info for Student 5 after copying Student 5 from Student 3:" << endl;
	student5.getStudentInfo();

	delete [] studentArray;
	cin.get();
	cin.get();
	return 0;
}
