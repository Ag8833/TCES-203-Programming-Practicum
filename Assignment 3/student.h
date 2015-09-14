/*
 * Andrew Gates
 * 4/20/2015
 * TCES 203
 * Assignment #3
 *
 * This program contains the declarations of functions and structure to be used in conjunction with student.cpp and main.cpp. It initializes the
 * structure with studentName, studentHobby and studentID and.
 */

#ifndef STUDENT_H_
#define STUDENT_H_

//Includes initiated in student.h and then sent to main.cpp and student.cpp.
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

//Initialization of the structure named Student, and the strings studentName, studentHobby and the integer studentID.
struct Student
{
	string studentName;
	string studentHobby;
	int studentID;
};

//Declaration of the functions called in main.cpp and defined in student.cpp.
int printMenu (void);
int getSize (void);
Student* createStudents (int);
void printStudentInfo (Student *, int, int);
void printStudentInfo (Student *, int);
void editStudentInfo (Student *, int, int);
int findStudent (Student *, int, int);
void freeStudentInfo (Student *);

#endif /* STUDENT_H_ */
