/*COMP272 Assignment1
*Node for a singly-linked list
*I did question 1, 2, 5, 6 and tested them with the following test cases.
*
*Arthor:
*Date:
*/

#ifndef _NODE_H_									//if not defined
#define _NODE_H_

#include<iostream>

/*
* brief: Node can construct a singly linked list
*/
template <typename T>
struct Node {
	T data;
	int priority;
	struct Node *next = NULL;
};

#endif