/*
 * Andrew Gates
 * 4/8/2015
 * TCES 203
 * Assignment #2
 * This code takes a file that has a name and corresponding 70 digit Keirsey personality test
 * response. It then takes that 70 digit string and converts those responses into the amount of
 * A and B responses in each corresponding category. Once it has those number of responses it will
 * then calculate the percentage of B answers, and using that determine which personality the person
 * falls into. It will then create a file named personality.out and input all of that data to the
 * file for the user to see.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream infile;
ofstream outfile;

#define STRINGSIZE 70

string getName(string);
string getData(string);
void putData(string, int*, char*);
int* processData(string, int*);
int* calculateData(int*, int*);
char* calculatePersonality(int*, char*);
void clearData(int*, int*, char*);

int main()
{
	string persInfo;
	string persName;
	string newLine;
	int* responseInfo = NULL;
	int* calculatedPercentage = NULL;
	char* calculatedInfo = NULL;

	//Allocates the arrays to be passed and used in the various functions
	int* processHelper = new int[8];
	int* dataHelper = new int[4];
	char* calculateHelper = new char[4];

	//Opens both files for inputting and outputting
	infile.open("personality.txt", ios::in);
	outfile.open("personality.out", ios::out);

	//Loop to read the various names and data until it hits end of file
	while(infile.eof() == false)
	{
		persName = getName(persName);
		persInfo = getData(persInfo);

		//Deletes the newline character at the end of the name
		int stringSize = persName.size();
		persName.erase(stringSize-1,1);

		responseInfo = processData(persInfo, processHelper);
		calculatedPercentage = calculateData(responseInfo, dataHelper);
		calculatedInfo = calculatePersonality(calculatedPercentage, calculateHelper);

		putData(persName, calculatedPercentage, calculatedInfo);

		//Clears the arrays so that they can be reused in the next iterations of the loop
		clearData(processHelper, dataHelper, calculateHelper);
	}

	//Deletes and deallocates the allocated arrays
	delete processHelper;
	delete dataHelper;
	delete calculateHelper;

	infile.close();
	outfile.close();

	return 0;
}

//Takes a string and gets the person's name from the file and returns that string
string getName(string persName)
{
	getline(infile, persName);
	return persName;
}

//Takes a string and gets the person's info from the file and returns that string
string getData(string persInfo)
{
	getline(infile, persInfo);
	return persInfo;
}

//Takes the string of person info and iterates through each response and assigns it to the corresponding
//array location depending on whether it was A or B
int* processData(string persInfo, int* processHelper)
{
	int i=0, j=0, questionNumber=0;

	for(i=0;i<10;i++)
	{
		for(j=0;j<7;j++)
		{
			if(j==0)
			{
				if(persInfo[questionNumber]=='A'||persInfo[questionNumber]=='a')
				{
					processHelper[0]++;
				}
				else if(persInfo[questionNumber]=='B'||persInfo[questionNumber]=='b')
				{
					processHelper[1]++;
				}
			}

			if(j==1||j==2)
			{
				if(persInfo[questionNumber]=='A'||persInfo[questionNumber]=='a')
				{
					processHelper[2]++;
				}
				else if(persInfo[questionNumber]=='B'||persInfo[questionNumber]=='b')
				{
					processHelper[3]++;
				}
			}

			if(j==3||j==4)
			{
				if(persInfo[questionNumber]=='A'||persInfo[questionNumber]=='a')
				{
					processHelper[4]++;
				}
				else if(persInfo[questionNumber]=='B'||persInfo[questionNumber]=='b')
				{
					processHelper[5]++;
				}
			}

			if(j==5||j==6)
			{
				if(persInfo[questionNumber]=='A'||persInfo[questionNumber]=='a')
				{
					processHelper[6]++;
				}
				else if(persInfo[questionNumber]=='B'||persInfo[questionNumber]=='b')
				{
					processHelper[7]++;
				}
			}
			questionNumber++;
		}
	}

	return processHelper;
}

//Takes the response information and calculates the percentage of B responses and then assigns those values
//to an array that will contain the percentage of B values for each category
int* calculateData(int* responseInfo, int* dataHelper)
{
	int i=0, j=0, percent=0;
	float percentageTemp=0;

	for(i=0;i<8;i+=2)
	{
		percentageTemp = ((responseInfo[i+1] / (static_cast<float>(responseInfo[i]) + responseInfo[i+1]))*100);
		percent = static_cast<int>(percentageTemp + .5);
		dataHelper[j] = percent;
		j++;
	}

	return dataHelper;
}

//Based on the percentage of B values in the array this function will assign the corresponding letter value
//depending on what personality that percentage of B values corresponds to
char* calculatePersonality(int* calculatedPercentage, char* calculateHelper)
{
	int i=0, j=0;

	if(calculatedPercentage[i]<50)
	{
		calculateHelper[j] = 'E';
	}
	else if(calculatedPercentage[i]>50)
	{
		calculateHelper[j] = 'I';
	}
	else
	{
		calculateHelper[j] = 'X';
	}

	i++;
	j++;

	if(calculatedPercentage[i]<50)
	{
		calculateHelper[j] = 'S';
	}
	else if(calculatedPercentage[i]>50)
	{
		calculateHelper[j] = 'N';
	}
	else
	{
		calculateHelper[j] = 'X';
	}

	i++;
	j++;

	if(calculatedPercentage[i]<50)
	{
		calculateHelper[j] = 'T';
	}
	else if(calculatedPercentage[i]>50)
	{
		calculateHelper[j] = 'F';
	}
	else
	{
		calculateHelper[j] = 'X';
	}

	i++;
	j++;

	if(calculatedPercentage[i]<50)
	{
		calculateHelper[j] = 'J';
	}
	else if(calculatedPercentage[i]>50)
	{
		calculateHelper[j] = 'P';
	}
	else
	{
		calculateHelper[j] = 'X';
	}

	return calculateHelper;
}

//Outputs all of the data to the file in the correct format
void putData(string persName, int* calculatedPercentage, char* calculatedInfo)
{
	int i=0;

	outfile << persName << ": [";

	for(i=0;i<3;i++)
	{
		outfile << calculatedPercentage[i] << ", ";
	}

	outfile << calculatedPercentage[i++] << "] = ";

	for(i=0;i<4;i++)
	{
		outfile << calculatedInfo[i];
	}

	outfile << endl;
}

//Clears the arrays to be used in the next iteration of the file reading
void clearData(int* processHelper, int* dataHelper, char* calculateHelper)
{
	int i=0;

	for(i=0;i<8;i++)
	{
		processHelper[i]=0;
	}

	for(i=0;i<4;i++)
	{
		dataHelper[i]=0;
		calculateHelper[i]=0;
	}
}
