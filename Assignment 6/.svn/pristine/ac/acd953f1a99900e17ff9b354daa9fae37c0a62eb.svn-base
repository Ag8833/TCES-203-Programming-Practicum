/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the functions to be used in conjunction with main.cpp, Node.h, List.cpp, List.h, Queue.cpp, Queue.h,
 * Stack.cpp and Stack.h to create objects of type Node and containing the functions to get and set the nodeName, nodePrev and
 * nodeNext data types in the class.
 */

#include "Node.h"

//Default constructor.
Node::Node()
{
	nodeName = '0';
	nodeNext = NULL;
	nodePrev = NULL;
}

//Overloaded constructor.
Node::Node(string name)
{
	if (name.length() < 3)
	{
		cout << "The name is not valid please enter a new name" << endl;
		return;
	}

	nodeName = name;
	nodeNext = NULL;
	nodePrev = NULL;
}

//Getter for nodeName.
string Node::getNodeName()
{
	return nodeName;
}

//Getter for nodeNext.
Node* Node::getNodeNext()
{
	return nodeNext;
}

//Getter for nodePrev.
Node* Node::getNodePrev()
{
	return nodePrev;
}

//Setter for nodeName.
void Node::setNodeName(string newName)
{
	if (newName.length() < 3)
	{
		cout << "The name is not valid please enter a new name" << endl;
		return;
	}

	nodeName = newName;
}

//Setter for nodeNext.
void Node::setNodeNext(Node* newNode)
{
	nodeNext = newNode;
}

//Setter for nodePrev.
void Node::setNodePrev(Node* newNode)
{
	nodePrev = newNode;
}
