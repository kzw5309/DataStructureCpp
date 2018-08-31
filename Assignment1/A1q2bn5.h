/*COMP272 Assignment1 Question 2b & 5
*Implement a linked list, witch can swap two adjacent elements in a list by adjusting only the links
*Use a doubly-linked list
*
*Arthor:
*Date:
*/

#ifndef _A1Q2BN5_H_									//if not defined
#define _A1Q2BN5_H_


#include <iostream>
#include "DNode.h"
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
	DNode<T> *dummy;
	int size;
public:

	//constructor
	DoublyLinkedList() {
		dummy = new DNode<T>;
		dummy->next = dummy;
		dummy->prev = dummy;
		size = 0;
	}

	/*getNode(int index):
	*brief: add a new node containing data to the head of a doubly-linked list
	*
	*param index: the index of a node to be found
	*/
	DNode<T> *getNode(int index) {
		DNode<T> *p = NULL;
		if (index < 0) {
			cout << "Index cannot be negative!" << endl;
			return p;
		}
		else if (index > size ) {
			cout << "Index is out of bound" << endl;
			return p;
		}

		if (index < size / 2) {
			p = dummy->next;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
		}
		else {
			p = dummy;
			for (int j = size; j > index; j--) {
				p = p->prev;
			}
		}
		return p;
	}

	/*get(int index):
	*brief:get the data of a node with a certain index in the doubly-linked list
	*
	*param i: the index of a node
	*
	*return: the data of the node
	*/
	T get(int index) {
		return getNode(index)->data;
	}

	/*set(int index, T x):
	*brief:set a node with a certain index in the doubly-linked list
	*
	*param i: the index of a node to be set
	*param x: the data to be set to the node
	*
	*return: old data
	*/
	T set(int index, T x) {
		DNode<T> *u = getNode(index);
		T y = u->data;
		u->data = x;
		return y;
	}

	/*addBefore(DNode<T> w, T data):
	*brief: add a new node containing data to a doubly-linked list
	*
	*param data: the data in the new node
	*param w: the target node, before which the new node is added
	*
	*return: added node
	*/
	DNode<T> *addBefore(DNode<T> *w, T data) {
		DNode<T> *tmpN = new DNode<T>;
		tmpN->data = data;
		tmpN->prev = w->prev;
		tmpN->next = w;
		w->prev = tmpN;
		tmpN->prev->next = tmpN;
		size++;
		return tmpN;
	}

	/*add(int index):
	*brief:add a node with a certain index from the doubly-linked list
	*
	*param i: the index of the node to be added
	*/
	void add(int index, T x) {
		addBefore(getNode(index), x);
	}
	/*remove(DNode<T> w):
	*brief:remove a node in the doubly-linked list
	*
	*param index: the node to be removed
	*/
	void remove(DNode<T> *w) {
		w->prev->next = w->next;
		w->next->prev = w->prev;
		size--;
	}

	/*remove(int index):
	*brief:remove a node with a certain index from the doubly-linked list
	*
	*param i: the index of the node to be removed
	*
	*return: removed data
	*/
	T remove(int index) {
		DNode<T> *w = getNode(index);
		remove(w);
		return w->data;
	}

	/*swap(int index):
	*brief:swap two consecutive nodes from the node with index
	*
	*param index: the index of the node to be swaped with the one next to it
	*/
	void swap(int index) {
		//check if the index is invalid
		if (index < 0) {
			cout << "Index cannot be negative!" << endl;
			return;
		}
		else if (index == 0 || index > size - 1) {
			cout << "Index is invalid for swap" << endl;
			return;
		}

		DNode<T> *prevN, *tmpN, *nextN;
		tmpN = getNode(index);
		prevN = tmpN->prev;
		nextN = tmpN->next;
		//change the link around and between the two consecutive node
		prevN->next = nextN;
		tmpN->prev = nextN;
		tmpN->next = nextN->next;
		nextN->prev = prevN;
		nextN->next->prev = tmpN;
		nextN->next = tmpN;

	}

	/*reverse():
	*brief: reverses the order of elements in a DLList.
	*/
	void reverse() {
		//if the list is empty return warning
		if (size == 0) {
			cout << "Warning: Linked List is empty" << endl;
			return;
		}
		DNode<T> *tmpN = new DNode<T>; //temporary node
		DNode<T> *current = getNode(0);
		for(int i = 0; i < size+1; i++) { //switch prev and next for each node
			//save the pointer to original prev node
			tmpN = current->prev;
			current->prev = current->next;
			current->next = tmpN;
			//move forward (the prev now is the next node in the original linked list)
			current = current->prev;
		}
		//cout << "dummy:" << dummy->data << endl;
	}


	/*printLinkedList():
	*brief: print the doubly linked list on the console
	*/
	void printLinkedList() {
		DNode<T> *tmp;
		int i = 0;
		tmp = dummy;
		while (i < size) {
			tmp = tmp->next;
			cout << tmp->data << endl;
			i++;
		}
	}

};

#endif