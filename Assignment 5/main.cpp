/*
 * Andrew Gates
 * 5/4/2015
 * TCES 203
 * Assignment #5
 *
 * This program contains the declarations of functions and testing to be used in conjunction with GroceryItemOrder.cpp,
 * GroceryItemOrder.h, GroceryList.cpp and GroceryList.h to initialize and manipulate the objects of type GroceryItemOrder
 * in the array of type GroceryList.
 */

#include <iostream>
#include <string>
#include <cstring>
#include "GroceryItemOrder.h"
#include "GroceryList.h"

using namespace std;

void firstThreeItems(GroceryList*, GroceryItemOrder*); //Function prototype to initialize the first three items in the list.
void fourthItem(GroceryList*, GroceryItemOrder*); //Function prototype to initialize the fourth items in the list.
void lastSixItems(GroceryList*, GroceryItemOrder*); //Function prototype to initialize the last six items in the list.
void eleventhItem(GroceryList*, GroceryItemOrder*); //Function prototype to initialize the eleventh item in the list, which will error.

const int STRINGSIZE = 25; //Constant value to manage the size of the string input.

int main()
{
	//Dyanmically allocating an object of GroceryList to be used in conjunction with GroceryItemOrder objects.
	GroceryList* myList = new GroceryList;

	GroceryItemOrder* tempItem2 = new GroceryItemOrder();

	//Initialize the first three items.
	firstThreeItems(myList, tempItem2);
	cout << "The cost of the whole list is: " << myList->getGroceryListCost() << " Dollars" << endl;

	//Initialize the fourth item
	fourthItem(myList, tempItem2);

	//Initialize the last six items
	lastSixItems(myList, tempItem2);
	cout << "The whole list after initializing 10 items is: " << endl << endl;
	myList->getListInfo(myList->getListSize());

	//Display to show the total cost before and after attempting to go past the limit of the list.
	cout << endl << "The cost of the whole list after initializing 10 items is: " << myList->getGroceryListCost() << " Dollars" << endl << endl;
	eleventhItem(myList, tempItem2);
	cout << endl << "The cost of the whole list after trying to add item 11 is: " << myList->getGroceryListCost() << " Dollars" << endl << endl;

	//Deleting the dynamically allocated GroceryList and GroceryItemOrder objects.
	delete myList;
	delete tempItem2;
	tempItem2 = 0;
	myList = 0;

	cin.get();
	cin.get();
	return 0;
}

//Function definition to initialize the first three items in the list.
void firstThreeItems(GroceryList* myList, GroceryItemOrder* tempItem2)
{
	string tempItemName;
	char itemName[STRINGSIZE];

	cout << "The first three items are: " << endl << endl;

	//Sets the tempItemName to a certain value, converts that into a c string and then copies it onto itemName.
	//Then calls the overloaded constructor using that value and preset values for quantity and price per unit.
	tempItemName = "Pears";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item1(itemName,1,1.5);
	tempItemName = "Apples";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item2(itemName,2,2.5);
	tempItemName = "Oranges";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item3(itemName,3,3.5);

	//Adds the created objects to my list.
	myList->groceryListAdd(item1, tempItem2, myList->getListSize());
	myList->groceryListAdd(item2, tempItem2, myList->getListSize());
	myList->groceryListAdd(item3, tempItem2, myList->getListSize());

	//Outputs all of the information that is in the list.
	myList->getListInfo(myList->getListSize());

	cout << endl << "The cost of " << item1.getItemName() << " is: " << item1.calculateTotalCost() << " Dollars" << endl;
	cout << "The cost of " << item2.getItemName() << " is: " << item2.calculateTotalCost() << " Dollars" << endl;
	cout << "The cost of " << item3.getItemName() << " is: " << item3.calculateTotalCost() << " Dollars" << endl;
}

void fourthItem(GroceryList* myList, GroceryItemOrder* tempItem2)
{
	string tempItemName;
	char itemName[STRINGSIZE];

	//Sets the tempItemName to a certain value, converts that into a c string and then copies it onto itemName.
	//Then calls the overloaded constructor using that value and preset values for quantity and price per unit.
	tempItemName = "Bananas";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item4(itemName,4,4.5);

	//Adds the created objects to my list.
	myList->groceryListAdd(item4, tempItem2, myList->getListSize());

	cout << endl << "The fourth item is: " << item4.getItemName() << endl;
	cout << "It's quantity is: " << item4.getItemQuantity() << endl;
	cout << "And it's total cost is: " << item4.calculateTotalCost() << endl;

	//Changes the quantity of the selected object to 10.
	item4.setQuantity(10);

	//Redisplays the total cost of the object to show that the change of quantity occured.
	cout << "After changing the quantity to " << item4.getItemQuantity() << " the total cost of " <<
			item4.getItemName() << " is: " << item4.calculateTotalCost() << " dollars" << endl << endl;
}

void lastSixItems(GroceryList* myList, GroceryItemOrder* tempItem2)
{
	string tempItemName;
	char itemName[STRINGSIZE];

	//Sets the tempItemName to a certain value, converts that into a c string and then copies it onto itemName.
	//Then calls the overloaded constructor using that value and preset values for quantity and price per unit.
	tempItemName = "Grapes";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item5(itemName,5,5.5);
	tempItemName = "Peaches";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item6(itemName,6,6.5);
	tempItemName = "Mango";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item7(itemName,7,7.5);
	tempItemName = "Lemons";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item8(itemName,8,8.5);
	tempItemName = "Blueberries";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item9(itemName,9,9.5);
	tempItemName = "Strawberries";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item10(itemName,10,10.5);

	//Adds the created objects to my list.
	myList->groceryListAdd(item5, tempItem2, myList->getListSize());
	myList->groceryListAdd(item6, tempItem2, myList->getListSize());
	myList->groceryListAdd(item7, tempItem2, myList->getListSize());
	myList->groceryListAdd(item8, tempItem2, myList->getListSize());
	myList->groceryListAdd(item9, tempItem2, myList->getListSize());
	myList->groceryListAdd(item10, tempItem2, myList->getListSize());
}

void eleventhItem(GroceryList* myList, GroceryItemOrder* tempItem2)
{
	string tempItemName;
	char itemName[STRINGSIZE];

	//Sets the tempItemName to a certain value, converts that into a c string and then copies it onto itemName.
	//Then calls the overloaded constructor using that value and preset values for quantity and price per unit.
	tempItemName = "Watermelon";
	strcpy(itemName, tempItemName.c_str());
	GroceryItemOrder item11(itemName,11,11.5);

	//Adds the created objects to my list which will not be added since it is over 10 objects already.
	myList->groceryListAdd(item11, tempItem2, myList->getListSize());
}
