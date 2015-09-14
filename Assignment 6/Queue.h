/*
 * Andrew Gates
 * 5/20/2015
 * TCES 203
 * Assignment #6
 *
 * This program contains the functions to be used in conjunction with main.cpp, Node.cpp, Node.h, List.cpp, List.h,
 * Queue.cpp, Stack.cpp and Stack.h to create objects of type Queue and containing the functions to enqueue, dequeue,
 * and to print the queue.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "List.h"

class Queue : public List
{
	public:
		Queue();//Default constructor.
		void enQueue(Node*);//Function prototype to enqueue a node to the queue.
		void deQueue();//Function prototype to dequeue a node from the queue.
		void printQueue();//Function prototype to print the queue.
		friend ostream &operator<<(ostream &, Queue*);//Function prototype to overload <<.
};

#endif /* QUEUE_H_ */
