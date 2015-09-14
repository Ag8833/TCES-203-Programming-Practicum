/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the function prototypes to be used in conjunction with main.cpp, Node.cpp, List.cpp, List.h, Queue.cpp,
 * Queue.h, Stack.cpp and Stack.h to create objects of type Node and containing the functions to get and set the nodeName,
 * nodePrev and nodeNext data types in the class.
 */


#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>

using namespace std;

class Node
{
	protected:
		string nodeName;
		Node* nodeNext;
		Node* nodePrev;
	public:
		Node();//Default constructor.
		Node(string);//Overloaded constructor.
		string getNodeName();//Getter for nodeName.
		Node* getNodeNext();//Getter for nodeNext.
		Node* getNodePrev();//Getter for nodePrev.
		void setNodeName(string);//Setter for nodeName.
		void setNodeNext(Node*);//Setter for nodeNext.
		void setNodePrev(Node*);//Setter for nodePrev.
};

#endif /* NODE_H_ */
