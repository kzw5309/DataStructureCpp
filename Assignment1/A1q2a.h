/*COMP272 Assignment1 Question 2a
*Swap two adjacent elements in a list by adjusting only the links
*Use a singly-linked list
*
*Arthor:
*Date:
*/

#ifndef _A1Q2A_H_									//if not defined
#define _A1Q2A_H_


#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
	Node<T> *head; // head node pointer of the linked list
	int size; //current size of the linked list
public:

	SinglyLinkedList() {
		head = NULL;
		size = 0;
	}

	/*addHead(data):
	*brief: add the data to the singly-linked list
	*
	*param data: the data will be stored in the new head node
	*/
	void addHead(int data) {
		Node<T> *tmp = new Node<T>; //assign space to a temporary node
		tmp->data = data;
		tmp->next = head;
		head = tmp; //update new head
		size++; 
	}

	/*remove(index):
	*brief:remove a node with a certain index from the singly-linked list
	*
	*param index: the index of the node to be removed
	*
	*return: data stored in the certain index.
	*/
	int get(int index) {
		if (index < 0) {
			cout << "Index cannot be negative!" << endl;
			return 0;
		}
		else if (index > size - 1) {
			cout << "Index is out of bound" << endl;
			return;
		}

		Node<T> *tmp; //temporary node pointer
		int i = 0;
		tmp = head;
		//find the targt node
		while (i < index) {
			tmp = tmp->next;
			i++;
		}
		//return stored data
		return tmp->data;
	}

	/*remove(index):
	*brief:remove a node with a certain index from the singly-linked list
	*
	*param index: the index of the node to be removed
	*/
	void remove(int index) {
		//check if the index is invalid
		if (index < 0) {
			cout << "Index cannot be negative!" << endl;
			return;
		}
		else if (index > size - 1) {
			cout << "Index is out of bound" << endl;
			return;
		}

		Node<T> *prevN, *tmpN; //temporary nodes pointer
		if (index == 0) {
			tmpN = head;
			head = head->next;
		}
		else {
			int i = 0;
			tmpN = head;
			prevN = tmpN;
			//find the target node and the node before it
			while (i < index) {
				prevN = tmpN;
				tmpN = tmpN->next;
				i++;
			}
			//update the next pointer of previous node
			prevN->next = tmpN->next;
		}
		free(tmpN);
		size--;
	}

	/*swap(index):
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
		else if (index > size - 2) {
			cout << "Index is invalid for swap" << endl;
			return;
		}

		Node<T> *prevN, *tmpN, *nextN;
		int i = 0;
		tmpN = head;
		prevN = tmpN;
		//find the target node and the node before it
		while (i < index) {
			prevN = tmpN;
			tmpN = tmpN->next;
			i++;
		}
		nextN = tmpN->next;
		if (index != 0) { //if target node is not a head node
			prevN->next = nextN;
		}
		//swap the node with the node next to it
		tmpN->next = nextN->next;
		nextN->next = tmpN;
		if (index == 0) { //if the target node is the head node, update the head
			head = nextN;
		}

	}

	/*printLinkedList():
	*brief:print the linked list on the console
	*/
	void printLinkedList() {
		Node<T> *tmp;
		int i = 0;
		tmp = head;
		while (i < size) { //travelsal the linked list
			cout << tmp->data << endl;
			tmp = tmp->next;
			i++;
		}
	}

};

#endif