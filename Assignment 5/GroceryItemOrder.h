/*
 * Andrew Gates
 * 5/4/2015
 * TCES 203
 * Assignment #5
 *
 * This program contains the declarations of functions to be used in conjunction with GroceryItemOrder.cpp, GroceryList.cpp,
 * GroceryList.h and main.cpp to create objects of type GroceryItemOrder and containing the functions to calculate the
 * cost of an object, change the quantity of an object, get all of the info for an object or get individual information
 * of said object.
 */

#ifndef GROCERYITEMORDER_H_
#define GROCERYITEMORDER_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//GroceryItemOrder class to store the name, quantity and price per unit of an item. It contains the functions to
//calculate the total cost of one item, change the quantity of one item, get all of the info for one item or
//get individual information.
class GroceryItemOrder
{
	private:
		char* itemName;
		int itemQuantity;
		float pricePerUnit;
	public:
		GroceryItemOrder(); //Default constructor.
		GroceryItemOrder(char*, int, float); //Overloaded constructor.
		~GroceryItemOrder(); //Destructor.

		float calculateTotalCost(); //Function prototype to return the total price based on quantity and price per unit.

		void setItemName(char*); //Function prototype to change the name of the selected object.
		void setQuantity(int); //Function prototype to change the quantity of the selected object.
		void setPricePerUnit(float); //Function prototype to change the price per unit of the selected object.

		void getItemInfo(); //Function prototype to get all of the info from the selected object.
		char* getItemName(); //Function prototype to get the name of the selected object.
		int getItemQuantity(); //Function prototype to get the quantity of the selected object.
		float getPricePerUnit(); //Function prototype to get the price per unit of the selected object.
};

#endif /* GROCERYITEMORDER_H_ */
