/*
 * Andrew Gates
 * 4/20/2015
 * TCES 203
 * Assignment #3
 *
 * This program contains the functions to be used in conjunction with main.cpp and student.h to create an array of students containing a name,
 * hobby and ID. Then it will allow the user to either display one student's info, display all of the students' info, or let them edit a certain
 * student's info (it will only allow them to edit their name and hobby).
 */

#include "Student.h"

//Default class constructor function to initialize student name, hobby and ID to nothing.
Student::Student()
{
	studentName = "";
	studentHobby = "";
	studentID = 0;
}

//Overloaded class constructor function to initialize student name, hobby and ID.
Student::Student(string name, string hobby, int id)
{
	studentName = name;
	studentHobby = hobby;
	studentID = id;
}

//Class function to deep copy a student's info into a new student member.
Student::Student(const Student &origStudent)
{
	studentName = origStudent.studentName;
	studentHobby = origStudent.studentHobby;
	studentID = origStudent.studentID;
}

//Class function to initialize the selected student's name.
void Student::setStudentName(string name)
{
	studentName = name;
}

//Class function to initialize the selected student's hobby.
void Student::setStudentHobby(string hobby)
{
	studentHobby = hobby;
}

//Class function to initialize the selected student's ID.
void Student::setStudentID(int id)
{
	studentID = id;
}

//Class function to get the selected student's name.
string Student::getStudentName()
{
	return studentName;
}

//Class function to get the selected student's hobby.
string Student::getStudentHobby()
{
	return studentHobby;
}

//Class function to get the selected student's ID.
int Student::getStudentID()
{
	return studentID;
}

//Class function to get all of selected student's data.
void Student::getStudentInfo()
{
	cout << "Student's name is: " << studentName << endl;
	cout << "Student's hobby is: " << studentHobby << endl;
	cout << "Student's ID is: " << studentID << endl;
}

//Class function to edit a student's hobby.
void Student::editStudentHobby(string hobby)
{
	studentHobby = hobby;
}

//Class function to edit a student's ID.
void Student::editStudentID(int id)
{
	studentID = id;
}

//Function definition to fill the studentArray with predefined student info.
Student* initializeStudentInfo(Student* studentArray, int arraySize)
{
	//Initializing Student 1.
	string student1Name = "Andrew";
	string student1Hobby = "Coding";
	int student1ID = 12345;

	//Initializing Student 2.
	string student2Name = "Tom";
	string student2Hobby = "Sleeping";
	int student2ID = 54321;

	//Setting the values that were initialized for Student 1.
	studentArray[0].setStudentName(student1Name);
	studentArray[0].setStudentHobby(student1Hobby);
	studentArray[0].setStudentID(student1ID);

	//Setting the values that were initialized for Student 2.
	studentArray[1].setStudentName(student2Name);
	studentArray[1].setStudentHobby(student2Hobby);
	studentArray[1].setStudentID(student2ID);

	return studentArray;
}

//Function definition to print the individual values of studentArray.
void printIndividualArrayValues(Student* studentArray, int arraySize)
{
	int i;

	//Loop to print the values for each student in the array.
	for (i = 0; i < arraySize; i++)
	{
		cout << endl << "Info for Student " << i+1 << " using individual accessor functions (with arrays):" << endl;
		cout << studentArray[i].getStudentName() << endl;
		cout << studentArray[i].getStudentHobby() << endl;
		cout << studentArray[i].getStudentID() << endl;
	}
}

//Function definition to print every value for the students in the array.
void printAllArrayValues(Student* studentArray, int arraySize)
{
	int i;

	for (i = 0; i < arraySize; i++)
	{
		cout << endl << "Info for Student " << i+1 << " using display all function:" << endl;
		studentArray[i].getStudentInfo();
	}
}
//Function definition to print the individual values for Student 3 and Student 4.
void printIndividualStudentValues(Student studentTemp1, Student studentTemp2)
{
	cout << endl << "Info for Student 3 using individual accessor functions" << endl << "(with the overloaded constructor):" << endl;
	cout << studentTemp1.getStudentName() << endl;
	cout << studentTemp1.getStudentHobby() << endl;
	cout << studentTemp1.getStudentID() << endl;

	cout << endl << "Info for Student 4 using individual accessor functions" << endl << "(with the default constructor):" << endl;
	cout << studentTemp2.getStudentName() << endl;
	cout << studentTemp2.getStudentHobby() << endl;
	cout << studentTemp2.getStudentID() << endl;
}

//Function definition to print every value for the individual students.
void printAllStudentValues(Student studentTemp1, Student studentTemp2)
{
	cout << endl << "Info for Student 3 using display all function:" << endl;
	studentTemp1.getStudentInfo();
	cout << endl << "Info for Student 4 using display all function:" << endl;
	studentTemp2.getStudentInfo();
}

//Function definition to change Student 2's info and then editing Student 2's info with the new info.
Student* editStudentArray(Student* studentArray)
{
	string student2Hobby = "Running";
	int student2ID = 13579;
	studentArray[1].editStudentHobby(student2Hobby);
	studentArray[1].editStudentID(student2ID);

	return studentArray;
}
