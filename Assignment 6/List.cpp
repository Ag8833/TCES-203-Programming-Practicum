/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the functions to be used in conjunction with main.cpp, Node.cpp, Node.h, List.h, Queue.cpp,
 * Queue.h, Stack.cpp and Stack.h to create objects of type List and containing the functions to add to the front,
 * add to the back, remove from the front, remove from the back, check if the list is empty, get the list front,
 * back and list size, and to print the list.
 */

#include "List.h"

//Default constructor.
List::List()
{
	listFront = NULL;
	listBack = NULL;
	listSize = 0;
}

//No dynamic memory allocation in the List class itself, unneeded destructor.
List::~List()
{

}

//Function definition to add a node at the front.
void List::addFirst(Node* newNode)
{
	//If list is empty.
	if (listFront == NULL)
	{
		listFront = newNode;
		listBack = newNode;
	}

	//If list is not empty.
	else
	{
		newNode->setNodeNext(listFront);
		listFront->setNodePrev(newNode);
		listFront = newNode;
	}
	listSize++;
}

//Function definition to add a node at the back.
void List::addLast(Node* newNode)
{
	//If list is empty.
	if (listBack == NULL)
	{
		listFront = newNode;
		listBack = newNode;
	}

	//If list is not empty.
	else
	{
		(this->getListBack())->setNodeNext(newNode);
		newNode->setNodePrev(listBack);
		listBack = newNode;
		newNode->setNodeNext(NULL);
	}
	listSize++;
}

//Function definition to remove a node from the front.
void List::removeFirst()
{
	//If list is empty.
	if (listFront == NULL)
	{
		cout << "The list is empty!";
		return;
	}

	//If there is one node.
	else if ((listFront->getNodeNext()) == NULL)
	{
		listFront = NULL;
		listBack = NULL;
	}

	//If there is multiple nodes.
	else
	{
		(listFront->getNodeNext())->setNodePrev(NULL);
		listFront = (listFront->getNodeNext());
	}
	listSize--;
}

//Function definition to remove a node from the back.
void List::removeLast()
{
	//If list is empty.
	if (listBack == NULL)
	{
		cout << "The list is empty!";
		return;
	}

	//If there is one node.
	else if ((listBack->getNodePrev()) == NULL)
	{
		listBack = NULL;
		listFront = NULL;
	}

	//If there is multiple nodes.
	else
	{
		(listBack->getNodePrev())->setNodeNext(NULL);
		listBack = (listBack->getNodePrev());
	}
	listSize--;
}

//Function definition to check if the list is empty.
int List::isEmpty()
{
	if (listFront == NULL || listBack == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Getter for listSize.
int List::getListSize()
{
	return listSize;
}

//Getter for listFront.
Node* List::getListFront()
{
	return listFront;
}

//Getter for listBack.
Node* List::getListBack()
{
	return listBack;
}

//Function definition to print the list.
void List::printList()
{
	Node* tempNode = this->listFront;
	int i;

	//If list is empty.
	if (tempNode == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	if (tempNode != NULL)
	{
		//Print first node.
		cout << "NULL -> " << tempNode->getNodeName();

		//Print more nodes if there is more than 1.
		if ((this->getListSize()) > 1)
		{
			for (i = 1; i < this->getListSize(); i++)
			{
				tempNode = tempNode->getNodeNext();
				if (tempNode->getNodeNext() == NULL)
				{
					cout << " -><- " << tempNode->getNodeName() << " <- NULL" << endl;
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
			cout << " <- NULL" << endl;
		}
	}

	tempNode = NULL;
}

//Function definition to overload <<.
ostream &operator<<(ostream &s, List* myList)
{
	myList->printList();

	return s;
}
