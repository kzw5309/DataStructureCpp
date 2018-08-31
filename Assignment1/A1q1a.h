/*COMP272 Assignment1 Question 1a
*Implement add(x), deleteMin(), size() of the priority queue interface
*
*Arthor:
*Date:
*/

/*Question 1a.1 methods' descriptions
*add(x): add the element x to the priority queue
*deleteMin(): remove the smallest element from the priority queue
*size(): return the size of the priority queue
*/

/*Question 1a.3 methods' running time
*				running time
*add(x)			O(n)
*deleteMin()	O(1)
*size()			O(1)
*/

#ifndef _A1Q1A_H_									//if not defined
#define _A1Q1A_H_

#include <iostream>
#include "Node.h"
using namespace std;



/*
* brief: A class use a singly linked list to define a Priority Queue
*/
template <typename T>
class PriorityQueue {
private:
	Node<T> *minNode; //the smallest element in a priority queue (head)
	int s; //record the size of a priority queue
public:
	/*
	*default constructor
	*/
	PriorityQueue() {
		minNode = NULL;
		s = 0;
	}

	/*add(p):
	*brief: add the element p to the priority queue
	*
	*param p: the priority of the element
	*/
	void add(int p) {
		Node<T> *tmp, *c;
		tmp = new Node<T>;
		tmp->priority = p;
		if (minNode == NULL || p < minNode->priority) {
			tmp->next = minNode;
			minNode = tmp;
		}
		else {
			c = minNode;
			while (c->next != NULL) {
				if (c->next->priority >= p) {
					break;
				}
				c = c->next;
			}
			tmp->next = c->next;
			c->next = tmp;
		}
		s++; //increment the size variable
	}

	/*deleteMin():
	*brief: remove the element with the minimum pripority in a priority queue
	*
	*return the element with the minimum priority
	*/
	int deleteMin() {
		Node<T> *tmp; // tmp node to keep the current minNode
		if (minNode == NULL) {
			cout << "Queue is empty" << endl;
		}
		else {
			tmp = minNode;
			minNode = minNode->next;
			int result = tmp->priority;
			free(tmp);
			s--; //decrement the size variable
			return result;
		}
	}

	/*size():
	*brief: remove the element with the minimum pripority in a priority queue
	*
	*return s: the size of a priority queue
	*/
	int size() {
		return s;
	}

	/*size():
	*brief: print out a priority queue
	*
	*/
	void showQueue() {
		Node<T> *tmp = minNode; // tmp node to keep the current minNode
		while (tmp != NULL) {
			cout << tmp->priority << endl;
			tmp = tmp->next;
		}
	}
};

#endif