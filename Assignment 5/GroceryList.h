/*
 * Andrew Gates
 * 5/4/2015
 * TCES 203
 * Assignment #5
 *
 * This program contains the declarations of functions to be used in conjunction with GroceryItemOrder.cpp, GroceryItemOrder.h,
 * GroceryList.cpp and main.cpp to create an object of type GroceryList that will be an array of objects of type GroceryItemOrder
 * as well as create and update the size of the list. It contains the functions to add a new GroceryItemOrder object to the list,
 * calculate the total cost of the list, get all of the information of all of the objects in the list, and get the size of the list.
 */

#ifndef GROCERYLIST_H_
#define GROCERYLIST_H_

#include <iostream>
#include <string>
#include <cstring>
#include "GroceryItemOrder.h"

using namespace std;

//GroceryList class to store an array GroceryItemOrder objects as well as the size of how many objects
//in the array (with a max size of 10). It contains the functions to add an item to the grocery list, get
//the total list cost, get the info of all of the objects in the list and get the size of the list.
class GroceryList
{
	private:
		GroceryItemOrder *itemList;
		int listSize;
	public:
		GroceryList(); //Default constructor.
		~GroceryList(); //Destructor.

		int groceryListAdd(GroceryItemOrder&, GroceryItemOrder*, int); //Function prototype to add an object to the list.

		float getGroceryListCost(); //Function prototype to get the cost of the entire list.
		void getListInfo(int); //Function prototype to get the info of each object in the list.
		int getListSize(); //Function prototype to get the size of the list.
};

#endif /* GROCERYLIST_H_ */
