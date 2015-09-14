/*
 * Andrew Gates
 * 5/4/2015
 * TCES 203
 * Assignment #5
 *
 * This program contains the functions to be used in conjunction with GroceryItemOrder.h, GroceryList.cpp, GroceryList.h and
 * main.cpp to create objects of type GroceryItemOrder and containing the functions to calculate the cost of an object, change
 * the name, quantity or price or unit of an object, get all of the info for an object or get individual information of said object.
 */

#include "GroceryItemOrder.h"

//Default constructor.
GroceryItemOrder::GroceryItemOrder()
{
	itemName = 0;
	itemQuantity = 0;
	pricePerUnit = 0;
}

//Overloaded constructor.
GroceryItemOrder::GroceryItemOrder(char* itemName, int itemQuantity, float pricePerUnit)
{
	this->itemName = new char[strlen(itemName)+1];
	strcpy(this->itemName, itemName);
	this->itemQuantity = itemQuantity;
	this->pricePerUnit = pricePerUnit;
}

//Destructor.
GroceryItemOrder::~GroceryItemOrder()
{
	//Error here, when I leave this commented I get no errors but I get a memory loss missing 11 frees (presumably from the 11
	//items that I create). When I remove the comment I go over by 11 frees and have errors saying invalid delete. I am not sure
	//where this is coming from so any help would be appreciated!

	//delete [] itemName;
	itemName = 0;
}

//Function definition to return the total price based on quantity and price per unit.
float GroceryItemOrder::calculateTotalCost()
{
	float totalCost;
	totalCost = (itemQuantity * pricePerUnit);
	return totalCost;
}

//Function definition to change the name of the selected object.
void GroceryItemOrder::setItemName(char* itemName)
{
	this->itemName = itemName;
}

//Function definition to change the quantity of the selected object.
void GroceryItemOrder::setQuantity(int itemQuantity)
{
	this->itemQuantity = itemQuantity;
}

//Function definition to change the price per unit of the selected object.
void GroceryItemOrder::setPricePerUnit(float pricePerUnit)
{
	this->pricePerUnit = pricePerUnit;
}

//Function definition to get all of the info from the selected object.
void GroceryItemOrder::getItemInfo()
{
	cout << "Item name is: " << itemName << endl;
	cout << "Item quantity is: " << itemQuantity << endl;
	cout << "Item price per unit is: " << pricePerUnit << endl;
}

//Function definition to get the name of the selected object.
char* GroceryItemOrder::getItemName()
{
	return itemName;
}

//Function definition to get the quantity of the selected object.
int GroceryItemOrder::getItemQuantity()
{
	return itemQuantity;
}

//Function definition to get the price per unit of the selected object.
float GroceryItemOrder::getPricePerUnit()
{
	return pricePerUnit;
}
