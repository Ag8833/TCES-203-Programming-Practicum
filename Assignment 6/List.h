/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the function prototypes to be used in conjunction with main.cpp, Node.cpp, Node.h, List.cpp, Queue.cpp,
 * Queue.h, Stack.cpp and Stack.h to create objects of type List and containing the functions to add to the front, add to the back,
 * remove from the front, remove from the back, check if the list is empty, get the list front, back and list size, and to
 * print the list.
 */

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"

class List : public Node
{
	protected:
		Node* listFront;
		Node* listBack;
		int listSize;
	public:
		List();//Default constructor.
		~List();//Destructor.
		void addFirst(Node*);//Function prototype to add a node at the front.
		void addLast(Node*);//Function prototype to add a node at the back.
		void removeFirst();//Function prototype to remove a node from the front.
		void removeLast();//Function prototype to remove a node from the back.
		int isEmpty();//Function prototype to check if the list is empty.
		int getListSize();//Getter for listSize.
		Node* getListFront();//Getter for listFront.
		Node* getListBack();//Getter for listBack.
		void printList();//Function prototype to print the list.
		friend ostream &operator<<(ostream &,List*);//Function prototype to overload <<.
};

#endif /* LIST_H_ */
