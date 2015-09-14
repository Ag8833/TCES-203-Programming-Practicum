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

template <class T>
class Node
{
	private:
		T nodeName;
		Node<T>* nodeNext;
		Node<T>* nodePrev;
	public:
		Node();//Default constructor.
		Node(T);//Overloaded constructor.
		T getNodeName();//Getter for nodeName.
		Node<T>* getNodeNext();//Getter for nodeNext.
		Node<T>* getNodePrev();//Getter for nodePrev.
		void setNodeName(T);//Setter for nodeName.
		void setNodeNext(Node<T>*);//Setter for nodeNext.
		void setNodePrev(Node<T>*);//Setter for nodePrev.
};

//Default constructor.
template <class T>
Node<T>::Node()
{
	nodeName = '0';
	nodeNext = NULL;
	nodePrev = NULL;
}

//Overloaded constructor.
template <class T>
Node<T>::Node(T name)
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
template <class T>
T Node<T>::getNodeName()
{
	return nodeName;
}

//Getter for nodeNext.
template <class T>
Node<T>* Node<T>::getNodeNext()
{
	return nodeNext;
}

//Getter for nodePrev.
template <class T>
Node<T>* Node<T>::getNodePrev()
{
	return nodePrev;
}

//Setter for nodeName.
template <class T>
void Node<T>::setNodeName(T newName)//Setter for nodeName.
{
	if (newName.length() < 3)
	{
		cout << "The name is not valid please enter a new name" << endl;
		return;
	}

	nodeName = newName;
}

//Setter for nodeNext.
template <class T>
void Node<T>::setNodeNext(Node* newNode)
{
	nodeNext = newNode;
}

//Setter for nodePrev.
template <class T>
void Node<T>::setNodePrev(Node* newNode)
{
	nodePrev = newNode;

}

#endif /* NODE_H_ */
