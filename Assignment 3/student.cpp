/*
 * Andrew Gates
 * 4/20/2015
 * TCES 203
 * Assignment #3
 *
 * This program contains the functions to be used in conjunction with main.cpp and student.h to create an array of students containing a name,
 * hobby and ID. It will allow the user to specify how many students they want to enter info for, and prompts them to enter the info for each
 * student. Then it will allow the student to either display one student's info, display all of the students' info, or let them edit a certain
 * student's info by entering their ID (it will only allow them to edit their name and hobby).
 */

#include "student.h"

//This function prints the main menu to the user and prompts them to choose an option that they want to use, or 0 if they want to quit.
//It also checks to make sure that the option they chose is a valid option.
int printMenu(void)
{
	int response;

	//Prints the menu in a loop until it receives proper input.
	do
	{
		cout << "----------------------MAIN MENU----------------------" << endl;
		cout << "1) Create Student Info." << endl;
		cout << "2) Display One Student's Info." << endl;
		cout <<	"3) Display All Student's Info." << endl;
		cout <<	"4) Edit Student's Info." << endl;
		cout << "-----------------------------------------------------" << endl << endl;
		cout << "Please choose an option (Press 0 to quit): ";
		cin >> response;
		cout << endl;

		//Checks to see if it is a valid option that the user entered.
		if (response < 0 || response > 4)
			cout << endl << "Please enter a valid option" << endl << endl;
	}
	while (response < 0 || response > 4);

	return response;
}

//Function to prompt the user to enter the amount of students that they want to enter info for. Checks to see if their response is greater than
//0 to avoid invalid input.
int getSize (void)
{
	int response;

	//Prints the prompt in a loop until it receives proper input.
	do
	{
		cout << "How many students do you want to enter info for?: ";
		cin >> response;
		if (response < 1)
			cout << endl << "Please enter a valid number of students" << endl;
		cout << endl;
	}
	while (response < 1);

	return response;
}

//Function to prompt the user to input all of the data for the number of students that they chose.
Student* createStudents (int arraySize)
{
	//Dynamically allocates an array of students based on the number of students that they chose in getSize function.
	Student *studentArray = new Student [arraySize];
	string idTemp;

	cin.get();

	//Loop to prompt the user to input a name, hobby and ID for the number of students that they chose.
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Please enter student " << i+1 << "'s name: ";
		getline (cin, studentArray[i].studentName);

		cout << "Please enter student " << i+1 << "'s hobby: ";
		getline (cin, studentArray[i].studentHobby);

		cout << "Please enter student " << i+1 << "'s ID: ";
		getline (cin, idTemp);

		//Takes the string idTemp and converts it into the same type as studentID (string -> integer).
		stringstream(idTemp) >> studentArray[i].studentID;
		cout << endl;
	}
	return studentArray;
}

//Function to print one student's info. It prompts the user to enter the ID of the student's info that they want to print, then it calls
//findStudent to search for a matching studentID which will return the index of that student, or return an error if it was not found. Then
//using that index it will print the info of the student at that index.
void printStudentInfo (Student *studentArray, int arraySize, int index)
{
	int studentID;

	//Prints the prompt or error in a loop until it finds a matching student ID that the user entered.
	do
	{
		cout << "Please enter the ID of the student's info that you want to display: ";
		cin >> studentID;

		//Calls findStudent and returns -1 if the ID was not found, or a number of where the ID was if it was found.
		index = findStudent (studentArray, arraySize, studentID);
		if (index == -1)
			cout << endl << "The student ID that you entered was not found, please try again" << endl;
		cout << endl;
	}
	while(index < 0);

	cout << "The info of the student that you chose is:" << endl << endl;
	cout << "Student's name: " << studentArray[index].studentName << endl;
	cout << "Student's hobby: " << studentArray[index].studentHobby << endl;
	cout << "Student's ID: " << studentArray[index].studentID << endl << endl;

}

//Overloaded function to print all of the students info using the arraySize.
void printStudentInfo (Student *studentArray, int arraySize)
{
	//Loop to print out each every student's info from 0 until it reaches the amount of students in the array.
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Student's name: " << studentArray[i].studentName << endl;
		cout << "Student's hobby: " << studentArray[i].studentHobby << endl;
		cout << "Student's ID: " << studentArray[i].studentID << endl << endl;
	}
}

//Function to edit one student's info. It prompts the user to enter the ID of the student's info that they want to edit, then it calls
//findStudent to search for a matching studentID which will return the index of that student, or return an error if it was not found. Then
//using that index it will prompt the user to enter the info of the student at that index.
void editStudentInfo (Student *studentArray, int arraySize, int index)
{
	int studentID;

	//Prints the prompt or error in a loop until it finds a matching student ID that the user entered.
	do
	{
		cout << "Please enter the ID of the student's info that you want to modify: ";
		cin >> studentID;

		//Calls findStudent and returns -1 if the ID was not found, or a number of where the ID was if it was found.
		index = findStudent (studentArray, arraySize, studentID);
		if (index == -1)
			cout << endl << "The student ID that you entered was not found, please try again" << endl;
		cout << endl;
	}
	while(index < 0);

	//Display's the current info of the student at the ID that was chosen.
	cout << "The current info of the student that you chose to modify is:" << endl << endl;
	cout << "Student's name: " << studentArray[index].studentName << endl;
	cout << "Student's hobby: " << studentArray[index].studentHobby << endl;
	cout << "Student's ID: " << studentArray[index].studentID << endl << endl;

	//Prompts the user to edit and input a new student name and a new student hobby.
	cout << "Enter a new name for student number " << studentID << ": ";
	cin >> studentArray[index].studentName;
	cout << "Enter a new hobby for student number " << studentID << ": ";
	cin >> studentArray[index].studentHobby;
}

//Function used by printStudentInfo and editStudentInfo to find the ID that the user inputs.
int findStudent (Student *studentArray, int arraySize, int studentID)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (studentArray[i].studentID == studentID)
			return i;
	}
	return -1;
}

//Function to delete the dynamically allocated structure that was initialized earlier in the program.
void freeStudentInfo (Student *studentArray)
{
	delete [] studentArray;
	studentArray = NULL;
}
