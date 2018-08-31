/*COMP272 Assignment1 Question 6
*Implement a minStack, witch can pop(), push(x), size() and min()
*All operations should be O(1)
*
*Arthor:
*Date:
*/

#ifndef _A1Q6_H_
#define _A1Q6_H_

#include<iostream>
#include"Node.h"
using namespace std;

template <typename T>
class LinkedStack { //implement Stack using a singly-linked list
private:
	Node<T> *head;// head(top) of a stack
	int n;//the size of a stack
public:
	LinkedStack() {
		head = NULL;
		n = 0;
	}

	/*push(T x)
	*brief: add a value x at the top of a stack and update min value stack
	*
	*param x: input value
	*/
	void push(T x) {
		Node<T> *tmpN = new Node<T>;
		tmpN->data = x;
		tmpN->next = head;
		head = tmpN;
		n++;
	}

	/*pop()
	*brief: delete the value at the top of a stack and update min value stack
	*
	*return: the value poped
	*/
	T pop() {
		if (n <= 0) {
			cout << "Pop from an empty stack" << endl;
			abort();
		}
		Node<T> *tmpN = head;
		head = tmpN->next;
		T removedData = tmpN->data;
		free(tmpN);
		n--;
		return removedData;
	}

	/*size()
	*brief: return the size of a stack
	*/
	int size() {
		return n;
	}

	/*top()
	*brief: return the top of a stack
	*/
	T top() {
		return head->data;
	}

	/*printStack()
	*brief: print the stack on the console.
	*
	*param s: a stack to be printed on the console.
	*/
	void printStack() {
		Node<T> *tmpN = head;
		while (tmpN != NULL) {
			cout << tmpN->data << endl;
			tmpN = tmpN->next;
		}
	}
};

template <typename T>
class MinStack {
private:
	LinkedStack<T> minS, stack; //two stacks: the one stacking input values, the other one recording min values
public:
	MinStack() {};

	/*push(T x)
	*brief: add a value x at the top of a stack and update min value stack
	*
	*param x: input value
	*/
	void push(T x) {
		stack.push(x);
		if (minS.size() == 0 || x < minS.top())
			minS.push(x);
		else
			minS.push(minS.top());
	}

	/*pop()
	*brief: delete the value at the top of a stack and update min value stack
	*
	*return: the value poped
	*/
	T pop() {
		minS.pop();
		return stack.pop();
	}

	int size() {
		return stack.size();
	}

	T min() {
		return minS.top();
	}

	void printStack() {
		stack.printStack();
	}
};


#endif // !_A1Q6_H_


