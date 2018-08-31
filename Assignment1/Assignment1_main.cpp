/*COMP272 Assignment1 test
*I did question 1, 2, 5, 6 and tested them with the following test cases.
*For detail answers and code, please check corresponding header files. eg. "A1q1a.h" means Assignment 1 Question 1 a
*
*Arthor:
*Date:
*/

#include<iostream>
#include"A1q1a.h"
#include"A1q1b.h"
#include"A1q2a.h"
#include"A1q2bn5.h"
#include"A1q6.h"
using namespace std;


int main()
{
	//test for question 1a
	cout << "-----------TEST_1A----------" << endl;
	PriorityQueue<int> p;
	cout << "add: 21, 42, 17, 23, 0; " << endl;
	p.add(21);
	p.add(42);
	p.add(17);
	p.add(23);
	p.add(0);
	cout << "Print Priority Queue:" << endl;
	p.showQueue();
	cout << "Size: " << p.size() << endl;
	cout << endl << "After deleteMin()" << endl;
	p.deleteMin();
	cout << "Print Priority Queue:" << endl;
	p.showQueue();
	cout << "Size: " << p.size() << endl;

	cout << "----------TEST_1B----------" << endl;
	Stack s; // create a stack "s" for test

	cout << "Push 10" << endl;
	s.push(10);
	cout << "Push 3" << endl;
	s.push(3);
	cout << "Push -2" << endl;
	s.push(-2);
	cout << "Push 11" << endl;
	s.push(11);
	cout << "Push 8" << endl;
	s.push(8);
	cout << "Push 100" << endl;
	s.push(100);
	cout << "Pop" << endl;
	s.pop();
	cout << "Push 5" << endl;
	s.push(5);
	cout << "Push 6" << endl;
	s.push(6);
	cout << "Pop" << endl;
	s.pop();
	cout << "Pop" << endl;
	s.pop();
	cout << "Push 101" << endl;
	s.push(101);
	cout << endl;
	cout << "Test Result: " << endl;
	printStack(s); //print stack from front to back

	//test for question 2a
	cout << "-----------TEST_2A----------" << endl;
	SinglyLinkedList<int> sL;
	sL.addHead(32);
	sL.addHead(453);
	sL.addHead(57);
	sL.addHead(90);
	sL.addHead(12);
	cout << "Singly-linked List Orignial: " << endl;
	sL.printLinkedList();
	sL.swap(2); //swap the second and the third items
	cout << endl << "After swap(2) swaps the index 2 and index 3 items: " << endl;
	sL.printLinkedList();

	//test for question 2b
	cout << "-----------TEST_2B----------" << endl;
	DoublyLinkedList<int> dL;
	dL.add(0, 32);
	dL.add(0, 453);
	dL.add(0, 57);
	dL.add(0, 90);
	dL.add(0, 12);
	/*dL.add(0, 1);
	dL.add(0, 2);
	dL.add(0, 3);
	dL.add(0, 4);
	dL.add(0, 5);
	dL.add(0, 6);
	dL.add(0, 7);
	dL.add(0, 8);*/
	cout << "Doubly-linked List Orignial: " << endl;
	dL.printLinkedList();
	dL.swap(3); //swap the third and the forth items
	cout << endl << "After swap(3) swaps the index 3 and index 4 items: " << endl;
	dL.printLinkedList();

	//test for question 5
	cout << "-----------TEST_5----------" << endl;
	cout << "Orignial: " << endl;
	dL.printLinkedList();
	dL.reverse();
	cout << endl << "After reverse: " << endl;
	dL.printLinkedList();

	//test for question 6
	cout << "-----------TEST_6_NORMAL_STACK----------" << endl;
	LinkedStack<int> lS; //a stack built with a linked list
	lS.push(32);
	lS.push(99);
	lS.push(132);
	lS.push(8);
	lS.push(-2);
	lS.push(12);
	cout << "Orignial: " << endl;
	lS.printStack();
	cout << "Original size:" << lS.size() << endl;
	lS.pop();
	lS.pop();
	cout << endl << "After two pop():" << endl;
	lS.printStack();
	cout << "Current size:" << lS.size() <<endl;

	cout << "-----------TEST_6_MIN_STACK----------" << endl;
	MinStack<int> mS; // declare a special MinStack
	mS.push(32);
	mS.push(99);
	mS.push(132);
	mS.push(8);
	mS.push(-2);
	mS.push(12);
	cout << "Orignial: " << endl;
	mS.printStack();
	cout << "Original Min: " << mS.min() << endl;
	cout << "Original size:" << mS.size() << endl;
	mS.pop();
	mS.pop();
	cout << endl << "After two pop():" << endl;
	mS.printStack();
	cout << "Current min:" << mS.min() << endl;
	cout << "Current size:" << mS.size() << endl;



	return 0;
}
/* sample test output£»
-----------TEST_1A----------
add: 21, 42, 17, 23, 0;
Print Priority Queue:
0
17
21
23
42
Size: 5

After deleteMin()
Print Priority Queue:
17
21
23
42
Size: 4
----------TEST_1B----------
Push 10
Push 3
Push -2
Push 11
Push 8
Push 100
Pop
Push 5
Push 6
Pop
Pop
Push 101

Test Result:
10
3
-2
11
8
101
-----------TEST_2A----------
Singly-linked List Orignial:
12
90
57
453
32

After swap(2) swaps the index 2 and index 3 items:
12
90
453
57
32
-----------TEST_2B----------
Doubly-linked List Orignial:
12
90
57
453
32

After swap(3) swaps the index 3 and index 4 items:
12
90
57
32
453
-----------TEST_5----------
Orignial:
12
90
57
32
453

After reverse:
453
32
57
90
12
-----------TEST_6_NORMAL_STACK----------
Orignial:
12
-2
8
132
99
32
Original size:6

After two pop():
8
132
99
32
Current size:4
-----------TEST_6_MIN_STACK----------
Orignial:
12
-2
8
132
99
32
Original Min: -2
Original size:6

After two pop():
8
132
99
32
Current min:8
Current size:4
*/

