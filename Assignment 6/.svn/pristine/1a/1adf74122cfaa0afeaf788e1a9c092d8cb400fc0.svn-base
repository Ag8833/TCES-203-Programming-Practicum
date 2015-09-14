/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the functions to be used in conjunction with main.cpp, Node.cpp, Node.h, List.cpp, List.h,
 * Queue.h, Stack.cpp and Stack.h to create objects of type Queue and containing the functions to enqueue, dequeue,
 * and to print the queue.
 */

#include "Queue.h"

//Default constructor.
Queue::Queue()
{
	listFront = NULL;
	listBack = NULL;
	listSize = 0;
}

//Function definition to add enqueue node to the queue.
void Queue::enQueue(Node* newNode)
{
	this->addLast(newNode);
}

//Function definition to dequeue a node from the queue.
void Queue::deQueue()
{
	int test = this->isEmpty();

	if(test == 1)
	{
		cout << "The queue is empty!" << endl;
		return;
	}

	this->removeFirst();
}

//Function definition to print the queue.
void Queue::printQueue()
{
	Node* tempNode = this->listFront;
	int i;

	//If list is empty.
	if (tempNode == NULL)
	{
		cout << "The queue is empty" << endl;
		return;
	}

	if (tempNode != NULL)
	{
		//Print first node.
		cout << "Front -> " << tempNode->getNodeName();

		//Print more nodes if there is more than 1.
		if ((this->getListSize()) > 1)
		{
			for (i = 1; i < this->getListSize(); i++)
			{
				tempNode = tempNode->getNodeNext();
				if (tempNode->getNodeNext() == NULL)
				{
					cout << " -><- " << tempNode->getNodeName() << " <- Back" << endl;
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
			cout << " <- Back" << endl;
		}
	}

		tempNode = NULL;
}

//Function definition to overload <<.
ostream &operator<<(ostream &s, Queue* myQueue)
{
	myQueue->printQueue();

	return s;
}
