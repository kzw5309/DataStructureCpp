#ifndef _DNODE_H_									//if not defined
#define _DNODE_H_

#include<iostream>

/*
* brief: DNode can construct a doubly-linked list
*/
template <typename T>
struct DNode {
	T data;
	int priority;
	struct DNode<T> *next = NULL;
	struct DNode<T> *prev = NULL;
};


#endif