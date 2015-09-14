/*
 * Andrew Gates
 * 4/20/2015
 * TCES 203
 * Assignment #3
 *
 * This program contains the declarations of functions and structure to be used in conjunction with student.cpp and main.cpp. It initializes the
 * class Student with studentName, studentHobby and studentID and the functions to set info and print info.
 */

#ifndef STUDENT_H_
#define STUDENT_H_

//Includes initiated in student.h and then sent to main.cpp and student.cpp.
#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		string studentName;
		string studentHobby;
		int studentID;
	public:
		Student();
		Student(string, string, int);
		Student(const Student&);

		void setStudentName(string);
		void setStudentHobby(string);
		void setStudentID(int);

		string getStudentName();
		string getStudentHobby();
		int getStudentID();

		void getStudentInfo();

		void editStudentHobby(string);
		void editStudentID(int);
};

//Test functions to call the individual class functions.
Student* initializeStudentInfo(Student*, int);
void printIndividualArrayValues(Student*, int);
void printAllArrayValues(Student*, int);
void printIndividualStudentValues(Student, Student);
void printAllStudentValues(Student, Student);
Student* editStudentArray(Student*);

#endif /* STUDENT_H_ */
