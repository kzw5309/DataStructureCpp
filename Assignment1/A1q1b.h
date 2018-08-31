//Assignment1 Question 1b
//Implement methods push(x) and pop() in Stack Class with 2 queues
//
//Author:
//Date:


/*Question 1b.2 methods' running time
*				running time
*push(x)		O(1)
*pop()			O(n)
*/

#ifndef _A1Q1B_H_									//if not defined
#define _A1Q1B_H_


#include<iostream>
#include<queue>
using namespace std;

class Stack {
private:
	queue<int> q1, q2; //a stack contains two queues
	int size;// the size of a stack
public:
	//default constructor
	Stack() {
		size = 0;
	}

	/*push(x)
	*brief: add a value x at the top of a stack
	*
	*param x: input value
	*/
	void push(int x) {
		q1.push(x); //enqueue x to the first queue
		size++;
	}

	/*pop()
	*brief: delete the value at the top of a stack
	*/
	void pop() {
		if (q1.empty()) {
			cout << "Pop from an empty stack!" << endl;
		}

		while (q1.size() != 1) { //transfer values until only one value in the first queue
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop(); //delete the last value in the first queue
		size--;

		while (!q2.empty()) { //push values back to q1 from q2
			q1.push(q2.front());
			q2.pop();
		}

	}

	/*size()
	*brief: return the size of a stack
	*/
	int getSize() {
		return size;
	}

	/*getBack()
	*brief: return the Back of a stack
	*/
	int getBack() {
		return q1.back();
	}
};

/*printStack()
*brief: print the stack on the console.
*
*param s: a stack need to be printed on the console.
*/
void printStack(Stack s) {
	if (s.getSize() == 0) {
		return;
	}
	else {
		int b = s.getBack();
		s.pop();
		printStack(s);
		cout << b << endl;
	}
}

#endif