/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the functions to be used in conjunction with main.cpp, Node.cpp, Node.h, List.cpp, List.h,
 * Queue.cpp, Queue.h and Stack.h to create objects of type Queue and containing the functions to pop, push,
 * and to print the queue.
 */

#include "Stack.h"

//Default constructor.
Stack::Stack()
{
	listFront = NULL;
	listBack = NULL;
	listSize = 0;
}

//Function definition to push a node to the stack.
void Stack::pushStack(Node* newNode)
{
	this->addFirst(newNode);
}

//Function definition to pop a node from the stack.
void Stack::popStack()
{
	int test = this->isEmpty();

	if(test == 1)
	{
		cout << "The stack is empty!" << endl;
		return;
	}

	this->removeFirst();
}

//Function definition to print the stack.
void Stack::printStack()
{
	Node* tempNode = this->listFront;
	int i;

	if (tempNode == NULL)
	{
		cout << "The stack is empty" << endl;
		return;
	}

	if (tempNode != NULL)
	{
		cout << "Top -> " << tempNode->getNodeName();

		if ((this->getListSize()) > 1)
		{
			for (i = 1; i < this->getListSize(); i++)
			{
				tempNode = tempNode->getNodeNext();
				if (tempNode->getNodeNext() == NULL)
				{
					cout << " -><- " << tempNode->getNodeName() << " <- Bottom" << endl;
					break;
				}
				else
				{
					cout << " -><- " << tempNode->getNodeName();
				}
			}
		}
		else
		{
			cout << " <- Bottom" << endl;
		}
	}

	tempNode = NULL;
}

//Function definition to overload <<.
ostream &operator<<(ostream &s, Stack* myStack)
{
	myStack->printStack();

	return s;
}
