/*
 * Andrew Gates
 * 5/4/2015
 * TCES 203
 * Assignment #5
 *
 * This program contains the functions to be used in conjunction with GroceryItemOrder.cpp, GroceryItemOrder.h, GroceryList.h and
 * main.cpp to create an object of type GroceryList that will be an array of objects of type GroceryItemOrder as well as create
 * and update the size of the list. It contains the functions to add a new GroceryItemOrder object to the list, calculate the
 * total cost of the list, get all of the information of all of the objects in the list, and get the size of the list.
 */

#include "GroceryList.h"

const int MAXLIST = 10;

//Default constructor.
GroceryList::GroceryList()
{
	itemList = new GroceryItemOrder[10];
	listSize = 0;
}

//Destructor.
GroceryList::~GroceryList()
{
	delete [] itemList;
	itemList = 0;
}

//Function definition to add an object to the list.
int GroceryList::groceryListAdd(GroceryItemOrder &tempItem, GroceryItemOrder* tempItem2, int itemNumber)
{
	if(itemNumber > MAXLIST-1)
	{
		cout << "There are already " << itemNumber+1 << " items in your list, item: " << tempItem.getItemName() << " was not added." << endl;
		return 0;
	}

	//Filling our temporary GroceryItemOrder object tempItem2
	tempItem2->setItemName(tempItem.getItemName());
	tempItem2->setQuantity(tempItem.getItemQuantity());
	tempItem2->setPricePerUnit(tempItem.getPricePerUnit());

	//Assigning the values of our dynamically allocated GroceryItemOrder object, tempItem2 onto our GroceryList object.
	itemList[itemNumber] = *tempItem2;
	listSize++;

	return 1;
}

//Function definition to get the cost of the entire list.
float GroceryList::getGroceryListCost()
{
	float totalSum = 0;
	int i;

	for (i = 0; i < MAXLIST; i++)
	{
		totalSum += itemList[i].calculateTotalCost();
	}

	return totalSum;
}

//Function definition to get the info of each object in the list.
void GroceryList::getListInfo(int index)
{
	int i;

	for (i = 0; i < index; i++)
	{
		itemList[i].getItemInfo();
	}
}

//Function definition to get the size of the list.
int GroceryList::getListSize()
{
	return listSize;
}
