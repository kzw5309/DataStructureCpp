/*COMP272 Assignment3 main
*I did question 1, 2, 3, 4, 5£¬6£¬7£¬ 8 and tested them with the following test cases.
*For detail answers and code, please check corresponding header files. eg. "A1q1a.h" means Assignment 1 Question 1 a
*Answers for Question 6 and 8 in "Question6.docx" and "Question8.docx"
*Arthor:
*Date:
*/

#include<iostream>
#include<map>
#include<queue>
#include"A3q1.h"
#include"A3q2.h"
#include"A3q3.h"
#include"A3q4.h"
#include"A3q5.h"
#include"A3q7.h"
using namespace std;

int main() {
	cout << "------------------------TEST_Q1------------------------" << endl;
	//code for an AVL tree and illustration in A3q1.h

	AVLNode *tree = NULL;

	//test case: insert 11, 21, 30, 40, 50, 26
	tree = insert(tree, 'A');
	tree = insert(tree, 'L');
	tree = insert(tree, 'G');
	tree = insert(tree, 'O');
	tree = insert(tree, 'R');
	tree = insert(tree, 'I');
	tree = insert(tree, 'T');
	tree = insert(tree, 'H');
	tree = insert(tree, 'M');
	cout << endl << "Print AVL tree with heights in ():" << endl;
	cout << "root------------------------->" << endl;
	printAVLTree(tree);
	cout << "To convert an AVL tree to a red-black tree, we assign the node in ood level to black, even level to red" << endl;

	cout << "------------------------TEST_Q2------------------------" << endl;
	//code and answers for question 2a in A3q2.h
	cout << endl << "Test Case 1: " << endl;
	BSTNode *tree1 = NULL;
	tree1 = insert(tree1, NULL, 120);
	insert(tree1, NULL, 70);
	insert(tree1, NULL, 130);
	insert(tree1, NULL, 60);
	insert(tree1, NULL, 125);
	insert(tree1, NULL, 80);
	insert(tree1, NULL, 90);
	insert(tree1, NULL, 100);
	insert(tree1, NULL, 25);
	insert(tree1, NULL, 75);
	insert(tree1, NULL, 35);
	cout << "Print Original BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(tree1);

	BSTNode *tree2 = NULL;
	tree1 = insert(tree2, NULL, 80);
	insert(tree2, NULL, 70);
	insert(tree2, NULL, 25);
	insert(tree2, NULL, 100);
	insert(tree2, NULL, 60);
	insert(tree2, NULL, 90);
	insert(tree2, NULL, 35);
	insert(tree2, NULL, 130);
	insert(tree2, NULL, 125);
	insert(tree2, NULL, 120);
	insert(tree2, NULL, 75);
	cout << endl << "Print Reference BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(tree2);

	BSTNode	*newRoot = transformation(tree1, tree2);
	cout << endl << "Print Transfered BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(newRoot);

	cout << endl << "Test Case 2: " << endl;
	BSTNode *tree3 = NULL;
	tree3 = insert(tree1, NULL, 12);
	insert(tree3, NULL, 2);
	insert(tree3, NULL, 7);
	insert(tree3, NULL, 6);
	insert(tree3, NULL, 10);
	insert(tree3, NULL, 3);
	insert(tree3, NULL, 9);
	cout << "Print Original BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(tree3);

	BSTNode *tree4 = NULL;
	tree4 = insert(tree4, NULL, 3);
	insert(tree4, NULL, 7);
	insert(tree4, NULL, 2);
	insert(tree4, NULL, 10);
	insert(tree4, NULL, 6);
	insert(tree4, NULL, 9);
	insert(tree4, NULL, 12);
	cout << endl << "Print Reference BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(tree4);

	BSTNode	*newTree = transformation(tree3, tree4);
	cout << endl << "Print Transfered BST: " << endl;
	cout << "root------------------------->" << endl;
	printBSTTree(newTree);

	cout << "------------------------TEST_Q3------------------------" << endl;
	//code in A3q3.h
	cout << endl;
	cout << "Test Case 1 (same size, same elements):" << endl;
	cout << endl;
	cout << "Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 8, 7}" << endl;
	cout << "Array 2: {7, 5, 9, 10, 5, 10, 4, 8, 3, 9}" << endl;
	int n = 10;
	int *a = new int[n] { 3, 4, 9, 10, 3, 5, 9, 9, 8, 7};

	int *b = new int[n] {7, 5, 9, 10, 5, 10, 4, 8, 3, 9};
	Node *list1 = removeDuplicate(a, n); // remove duplicates in array a
	Node *list2 = removeDuplicate(b, n); // remove duplicates in array b
	Node *tmp = list1;
	cout << "Distinct Elements in Array 1: ";//print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;

	tmp = list2;
	cout << "Distinct Elements in Array 2: ";//print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	if (compareLinkedList(list1, list2)) { //compare two sets (linked list)
		cout << "Yes! Two arrays contain the same elements" << endl;
	}
	else {
		cout << "No! Two arrays contain different elements" << endl;
	}

	cout << endl;
	cout << "Test Case 2 (same size, different elements):" << endl;
	cout << "Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7}" << endl;
	cout << "Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}" << endl;
	n = 11;
	a = new int[n] { 3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7};

	b = new int[n] {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13};
	list1 = removeDuplicate(a, n); //removeDuplicates in array a
	list2 = removeDuplicate(b, n); //removeDuplicates in array b
	tmp = list1;
	cout << "Distinct Elements in Array 1: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;

	tmp = list2;
	cout << "Distinct Elements in Array 2: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	if (compareLinkedList(list1, list2)) { //compare two sets (linked list)
		cout << "Yes! Two arrays contain the same elements" << endl;
	}
	else {
		cout << "No! Two arrays contain different elements" << endl;
	}

	cout << endl;
	cout << "Test Case 3 (different size, same elements):" << endl;
	cout << "Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 3, 8, 7, 13, 8, 2}" << endl;
	cout << "Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}" << endl;
	int n1 = 14;
	int n2 = 11;
	a = new int[n1] {3, 4, 9, 10, 3, 5, 9, 9, 3, 8, 7, 13, 8, 2};

	b = new int[n2] {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13};
	list1 = removeDuplicate(a, n1); //removeDuplicates in array a
	list2 = removeDuplicate(b, n2); //removeDuplicates in array b
	tmp = list1;
	cout << "Distinct Elements in Array 1: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;

	tmp = list2;
	cout << "Distinct Elements in Array 2: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	if (compareLinkedList(list1, list2)) { //compare two sets (linked list)
		cout << "Yes! Two arrays contain the same elements" << endl;
	}
	else {
		cout << "No! Two arrays contain different elements" << endl;
	}
	cout << endl;
	cout << "Test Case 4 (different size, different elements):" << endl;
	cout << "Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7, 15, 8, 6}" << endl;
	cout << "Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}" << endl;
	n1 = 14;
	n2 = 11;
	a = new int[n1] {3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7, 15, 8, 6};

	b = new int[n2] {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13};
	list1 = removeDuplicate(a, n1); //removeDuplicates in array a
	list2 = removeDuplicate(b, n2); //removeDuplicates in array b
	tmp = list1;
	cout << "Distinct Elements in Array 1: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;

	tmp = list2;
	cout << "Distinct Elements in Array 2: "; //print distinct elements
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	if (compareLinkedList(list1, list2)) { //compare two sets (linked list)
		cout << "Yes! Two arrays contain the same elements" << endl;
	}
	else {
		cout << "No! Two arrays contain different elements" << endl;
	}

	cout << "------------------------TEST_Q4------------------------" << endl;
	// code and excution details in A3q4
	int *a4 = new int[11]{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
	mergeSort(a4, 0, 10);
	cout << "Q4a merge-sort algorithm result:" << endl;
	for (int i = 0; i < 11; i++) {
		cout << a4[i] << " ";
	}
	cout << endl;
	delete[] a4;


	int *a5 = new int[11]{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
	quickSort(a5, 0, 10);
	cout << "Q4b quick-sort algorithm result:" << endl;
	for (int i = 0; i < 11; i++) {
		cout << a5[i] << " ";
	}
	cout << endl;

	cout << "------------------------TEST_Q5A------------------------" << endl;
	//detail illustration and subquestion c are in the Questoin5_Details.docx
	Graph g;
	//adjacency list (char vector) for each node
	vector<char> aa{ 'b', 'e', 'f' };
	vector<char> bb{ 'a', 'c' };
	vector<char> c{ 'b', 'd', 'f' };
	vector<char> d{ 'c', 'g' };
	vector<char> e{ 'a', 'i' };
	vector<char> f{ 'a', 'c', 'j' };
	vector<char> gg{ 'd', 'h', 'j', 'k' };
	vector<char> h{ 'g', 'o' };
	vector<char> i{ 'e', 'j', 'm', 'n' };
	vector<char> j{ 'f', 'g', 'i' };
	vector<char> k{ 'g', 'o' };
	vector<char> l{ 'p' };
	vector<char> m{ 'i' };
	vector<char> nn{ 'i', 'o' };
	vector<char> o{ 'h', 'k', 'n', 'p' };
	vector<char> p{ 'l', 'o' };
	
	g.addV('a', aa);
	g.addV('b', bb);
	g.addV('c', c);
	g.addV('d', d);
	g.addV('e', e);
	g.addV('f', f);
	g.addV('g', gg);
	g.addV('h', h);
	g.addV('i', i);
	g.addV('j', j);
	g.addV('k', k);
	g.addV('l', l);
	g.addV('m', m);
	g.addV('n', nn);
	g.addV('o', o);
	g.addV('p', p);
	cout << endl << "DFS Search traversal sequence: ";
	g.DFSAndPrintSequence('g'); //DFS traverse starting from g
	cout << endl;
	
	cout << "------------------------TEST_Q5B------------------------" << endl;
	g.resetVisted(); //reset visted flag to false

	cout << endl <<"BFS Search traversal sequence: ";
	g.BFSAndPrintSequence('b'); //BFS traverse starting from b
	cout << endl;

	cout << "------------------------TEST_Q5D------------------------" << endl;
	g.resetVisted(); //reset visted flag to false

	//DFS traverse the graph to find a path go each eage in each direaction exactly once
	cout << endl << "Modified DFS traverse the graph to find a path traveling each edge in each direction exactly once: "<<endl;
	g.findAllEdgesPath('g'); //traverse starting from g
	cout << endl;

	cout << "------------------------TEST_7------------------------" << endl;
	// code in A3q7.h
	cout << endl << "Test Case 1: " << endl;
	MeldableHeap<int> h1;
	h1.add(4);
	h1.add(9);
	h1.add(8);
	h1.add(17);
	h1.add(26);
	h1.add(19);
	h1.add(50);
	h1.add(16);
	cout << endl << "Original MeldableHeap: " << endl;
	cout << "root------------------------->" << endl;
	h1.printMeldableHeap();
	cout << "call remove(): " << h1.remove() << endl; //perform two remove() on the heap
	cout << "call remove(): " << h1.remove() << endl;

	cout << endl << "Current MeldableHeap: " << endl;
	cout << "root------------------------->" << endl;
	h1.printMeldableHeap();
	
	cout << endl << "Test Case 2: " << endl;
	MeldableHeap<int> h2;
	h2.add(-4);
	h2.add(98);
	h2.add(18);
	h2.add(27);
	h2.add(6);
	h2.add(11);
	h2.add(52);
	h2.add(7);
	cout << endl << "Original MeldableHeap: " << endl;
	cout << "root------------------------->" << endl;
	h2.printMeldableHeap();
	cout << "call remove(): " << h2.remove() << endl; //perform three remove() on the heap
	cout << "call remove(): " << h2.remove() << endl;
	cout << "call remove(): " << h2.remove() << endl;

	cout << endl << "Current MeldableHeap: " << endl;
	cout << "root------------------------->" << endl;
	h1.printMeldableHeap();
}

/*Sample Output:
------------------------TEST_Q1------------------------

Print AVL tree with heights in ():
root------------------------->

                    11(0)

          21(1)

                    26(0)

30(2)

          40(1)

                    50(0)
To convert an AVL tree to a red-black tree, we assign the node in ood level to black, even level to red
------------------------TEST_Q2------------------------
Print Original BST:
root------------------------->

          130

                    125

120

                                        100

                              90

                    80

                              75

          70

                    60

                                        35

                              25

Print Reference BST:
root------------------------->

                    130

                              125

                                        120

          100

                    90

80

                    75

          70

                              60

                                        35

                    25

Print Transfered BST:
root------------------------->

                    130

                              125

                                        120

          100

                    90

80

                    75

          70

                              60

                                        35

                    25
------------------------TEST_Q3------------------------

Test Case 1 (same size, same elements):

Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 8, 7}
Array 2: {7, 5, 9, 10, 5, 10, 4, 8, 3, 9}
Distinct Elements in Array 1: 3 4 5 7 8 9 10
Distinct Elements in Array 2: 3 4 5 7 8 9 10
Yes! Two arrays contain the same elements

Test Case 2 (same size, different elements):
Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7}
Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}
Distinct Elements in Array 1: 3 4 5 7 8 9 10 11
Distinct Elements in Array 2: 2 3 4 5 7 8 9 10 13
No! Two arrays contain different elements

Test Case 3 (different size, same elements):
Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 3, 8, 7, 13, 8, 2}
Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}
Distinct Elements in Array 1: 2 3 4 5 7 8 9 10 13
Distinct Elements in Array 2: 2 3 4 5 7 8 9 10 13
Yes! Two arrays contain the same elements

Test Case 4 (different size, different elements):
Array 1: {3, 4, 9, 10, 3, 5, 9, 9, 11, 8, 7, 15, 8, 6}
Array 2: {7, 5, 9, 10, 2, 10, 4, 8, 3, 9, 13}
Distinct Elements in Array 1: 3 4 5 6 7 8 9 10 11 15
Distinct Elements in Array 2: 2 3 4 5 7 8 9 10 13
No! Two arrays contain different elements
------------------------TEST_Q4------------------------
Q4a merge-sort algorithm result:
1 1 2 3 3 4 5 5 5 6 9
Q4b quick-sort algorithm result:
1 1 2 3 3 4 5 5 5 6 9
------------------------TEST_Q5A------------------------

DFS Search traversal sequence: g d c b a e i j f m n o h k p l
------------------------TEST_Q5B------------------------

BFS Search traversal sequence: b a c e f d i j g m n h k o p l
------------------------TEST_Q5D------------------------

Mordified DFS traverse the graph to find a path: g d c b a e i j f a b c f c d g h o k g j g k o n i m i e a f j i n o p l p o h g
------------------------TEST_7------------------------

Original MeldableHeap:
root------------------------->

                    16

          8

                    9

                              26

4

                    50

          17

                    19
call remove(): 4
call remove(): 8

Current MeldableHeap:
root------------------------->

                              50

                    17

                              19

          16

9

          26
*/