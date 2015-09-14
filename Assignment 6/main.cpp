/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the declarations of functions and testing to be used in conjunction with Node.cpp, Node.h, List.cpp,
 * List.h, Queue.cpp, Queue.h, Stack.cpp and Stack.h to initialize and manipulate the objects of type Node, List, Stack and Queue.
 */

#include "Node.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

#define MAXSIZE 4

void nodeTesting();//Function prototype to test the node class.

void listTesting();//Function prototype to test the list class.
Node* listCreate(List*);//Function prototype to create a list.
void listProcess(List*);//Function prototype to delete nodes and print the list.
void listDelete(List*, Node*);//Function prototype to delete dynamically allocated memory.

void stackTesting();//Function prototype to test the stack class.
Node* stackCreate(Stack*);//Function prototype to create a stack.
void stackProcess(Stack*);//Function prototype to delete nodes and print the stack.
void stackDelete(Stack*, Node*);//Function prototype to delete dynamically allocated memory.

void queueTesting();//Function prototype to test the queue class.
Node* queueCreate(Queue*);//Function prototype to create a queue.
void queueProcess(Queue*);//Function prototype to delete nodes and print the queue.
void queueDelete(Queue*, Node*);//Function prototype to delete dynamically allocated memory.

int main()
{
	//Node class testing.
	cout << "----------------------------------" << endl;
	cout << "NODE TESTING" << endl << endl;
	nodeTesting();

	//List class testing.
	cout << "----------------------------------" << endl;
	cout << "LIST TESTING" << endl << endl;
	listTesting();

	//Stack class testing.
	cout << endl << "----------------------------------" << endl;
	cout << "STACK TESTING" << endl << endl;
	stackTesting();

	//Queue class testing.
	cout << endl << "----------------------------------" << endl;
	cout << "QUEUE TESTING" << endl << endl;
	queueTesting();

	cin.get();
	cin.get();
	return 0;
}

//Function definition to test the node class.
void nodeTesting()
{
	//Allocating my first node for testing using overloaded constructor.
	Node* firstNode = new Node("Andrew");

	cout << "First node's name is: " << firstNode->getNodeName() << endl;
	cout << "First node's next is: " << firstNode->getNodeNext() << endl;
	cout << "First node's previous is: " << firstNode->getNodePrev() << endl;

	//Allocating my second node for testing using default constructor.
	Node* secondNode = new Node;
	secondNode->setNodeName("Bob");

	cout << "Second node's name is: " << secondNode->getNodeName() << endl;
	cout << "Second node's next is: " << secondNode->getNodeNext() << endl;
	cout << "Second node's previous is: " << secondNode->getNodePrev() << endl;

	//Linking the first node to second and the second node to the first.
	//Andrew -> Bob and Andrew <- Bob
	firstNode->setNodeNext(secondNode);
	secondNode->setNodePrev(firstNode);
	cout << endl << "After linking first node to second and second to first -" << endl;
	cout << "First node's next is: " << (firstNode->getNodeNext())->getNodeName() << endl;
	cout << "Second node's previous is: " << (secondNode->getNodePrev())->getNodeName() << endl << endl;

	//Deleting my allocated nodes.
	delete firstNode;
	delete secondNode;
}

//Function definition to test the list class.
void listTesting()
{
	List* myList = new List();
	Node* nodeArray = listCreate(myList);
	cout << "List size is: " << myList->getListSize() << endl << endl;

	//Error with 1 node left in list.

	listProcess(myList);

	//Deleting my allocated nodes and list.
	listDelete(myList, nodeArray);
}

//Function definition to create a list.
Node* listCreate(List* myList)
{
	//Allocating my 4 nodes for testing.
	Node* nodeArray = new Node[MAXSIZE];
	nodeArray[0].setNodeName("Andrew");
	nodeArray[1].setNodeName("Bob");
	nodeArray[2].setNodeName("Tom");
	nodeArray[3].setNodeName("Ron");

	//Assigning my 4 nodes in random order.
	myList->addFirst(&nodeArray[0]);
	myList->addLast(&nodeArray[1]);
	myList->addLast(&nodeArray[2]);
	myList->addFirst(&nodeArray[3]);

	//Returning the nodeArray so that it can be deleted after the list is done being used.
	return nodeArray;
}

//Function definition to delete nodes and print the list.
void listProcess(List* myList)
{
	//Printing the list after adding my 4 nodes in a random order.
	//listFront -> Ron -> Andrew -> Bob -> Tom <- listBack
	cout << myList;

	//Removing the first node and then reprinting the list.
	//listFront -> Andrew -> Bob -> Tom <- listBack
	myList->removeFirst();
	cout << endl <<"After removing the first node the list is - " << endl ;
	cout << myList;

	//Removing the last node and then reprinting the list.
	//listFront -> Andrew -> Bob <- listBack
	myList->removeLast();
	cout << endl << "After removing the last node the list is - " << endl;
	cout << myList;

	//Removing the first node and then reprinting the list.
	//listFront -> Andrew <- listBack
	myList->removeLast();
	cout << endl << "After removing the first node the list is - " << endl;
	cout << myList;

	//Removing the remaining nodes and then reprinting the list.
	//listFront -> NULL <- listBack
	myList->removeFirst();
	cout << endl << "After removing the remaining nodes the list is - " << endl;
	cout << myList;
}

//Function definition to delete dynamically allocated memory.
void listDelete(List* myList, Node* nodeArray)
{
	delete myList;
	delete [] nodeArray;
}

//Function definition to test the stack class.
void stackTesting()
{
	Stack* myStack = new Stack();
	Node* nodeArray = stackCreate(myStack);
	cout << "Stack size is: " << myStack->getListSize() << endl << endl;

	stackProcess(myStack);

	//Deleting my allocated nodes and stack.
	stackDelete(myStack, nodeArray);
}

//Function definition to create a stack.
Node* stackCreate(Stack* myStack)
{
	//Allocating my 4 nodes for testing.
	Node* nodeArray = new Node[MAXSIZE];
	nodeArray[0].setNodeName("Andrew");
	nodeArray[1].setNodeName("Bob");
	nodeArray[2].setNodeName("Tom");
	nodeArray[3].setNodeName("Ron");

	//Assigning my 4 nodes in random order.
	myStack->pushStack(&nodeArray[0]);
	myStack->pushStack(&nodeArray[1]);
	myStack->pushStack(&nodeArray[2]);
	myStack->pushStack(&nodeArray[3]);

	//Returning the nodeArray so that it can be deleted after the stack is done being used.
	return nodeArray;
}

//Function definition to delete nodes and print the stack.
void stackProcess(Stack* myStack)
{
	//Printing the list after pushing my 4 nodes onto the stack.
	//listFront -> Ron -> Tom -> Bob -> Andrew <- listBack
	cout << myStack;

	//Popping the first node and then reprinting the list.
	//listFront -> Tom -> Bob -> Andrew <- listBack
	myStack->popStack();
	cout << endl <<"After popping the first node the list is - " << endl ;
	cout << myStack;

	//Popping the first node and then reprinting the list.
	//listFront -> Bob -> Andrew <- listBack
	myStack->popStack();
	cout << endl << "After popping the first node the list is - " << endl;
	cout << myStack;

	//Popping the first node and then reprinting the list.
	//listFront -> Andrew <- listBack
	myStack->popStack();
	cout << endl << "After popping the first node the list is - " << endl;
	cout << myStack;

	//Popping the remaining nodes and then reprinting the list.
	//listFront -> NULL <- listBack
	myStack->popStack();
	cout << endl << "After popping the remaining nodes the list is - " << endl;
	cout << myStack;
}

//Function definition to delete dynamically allocated memory.
void stackDelete(Stack* myStack, Node* nodeArray)
{
	delete myStack;
	delete [] nodeArray;
}

//Function definition to test the queue class.
void queueTesting()
{
	Queue* myQueue = new Queue();
	Node* nodeArray = queueCreate(myQueue);
	cout << "Queue size is: " << myQueue->getListSize() << endl << endl;

	queueProcess(myQueue);

	//Deleting my allocated nodes and queue.
	queueDelete(myQueue, nodeArray);
}

//Function definition to create a queue.
Node* queueCreate(Queue* myQueue)
{
	//Allocating my 4 nodes for testing.
	Node* nodeArray = new Node[MAXSIZE];
	nodeArray[0].setNodeName("Andrew");
	nodeArray[1].setNodeName("Bob");
	nodeArray[2].setNodeName("Tom");
	nodeArray[3].setNodeName("Ron");

	//Assigning my 4 nodes in random order.
	myQueue->enQueue(&nodeArray[0]);
	myQueue->enQueue(&nodeArray[1]);
	myQueue->enQueue(&nodeArray[2]);
	myQueue->enQueue(&nodeArray[3]);

	//Returning the nodeArray so that it can be deleted after the queue is done being used.
	return nodeArray;
}

//Function definition to delete nodes and print the queue.
void queueProcess(Queue* myQueue)
{
	//Printing the list after enqueueing my 4 nodes into the queue.
	//listFront -> Andrew -> Bob -> Tom -> Ron <- listBack
	cout << myQueue;

	//Dequeueing the first node and then reprinting the list.
	//listFront -> Bob -> Tom -> Ron <- listBack
	myQueue->deQueue();
	cout << endl <<"After dequeueing the first node the list is - " << endl ;
	cout << myQueue;

	//Dequeueing the first node and then reprinting the list.
	//listFront -> Tom -> Ron <- listBack
	myQueue->deQueue();
	cout << endl << "After dequeueing the first node the list is - " << endl;
	cout << myQueue;

	//Dequeueing the first node and then reprinting the list.
	//listFront -> Ron <- listBack
	myQueue->deQueue();
	cout << endl << "After dequeueing the first node the list is - " << endl;
	cout << myQueue;

	//Dequeueing the remaining node and then reprinting the list.
	//listFront -> NULL <- listBack
	myQueue->deQueue();
	cout << endl << "After dequeueing the remaining nodes the list is - " << endl;
	cout << myQueue;
}

//Function definition to delete dynamically allocated memory.
void queueDelete(Queue* myQueue, Node* nodeArray)
{
	delete myQueue;
	delete [] nodeArray;
}
