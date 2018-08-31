/*COMP272 Assignment2 main
*I did question 1, 2, 3, 4, 5 and tested them with the following test cases.
*For detail answers and code, please check corresponding header files. eg. "A1q1a.h" means Assignment 1 Question 1 a
*
*Arthor:
*Date:
*/

#include"A2q1.h"
#include"A2q2.h"
#include"A2q3.h"
#include"A2q4.h"
#include"A2q5.h"
#include"BTNode.h"
#include"SGNode.h"
#include<iostream>
using namespace std;

int main() {
	cout << "------------------------TEST_Q1------------------------"<<endl;
	//code and worst-case running time analysis in A2q1.h

	BTNode *tree = NULL;
	incrementOrInsert(tree, NULL, 120);
	incrementOrInsert(tree, NULL, 130);
	BTNode *Node70 = incrementOrInsert(tree, NULL, 70);
	incrementOrInsert(tree, NULL, 80);
	incrementOrInsert(tree, NULL, 90);
	BTNode *Node100 = incrementOrInsert(tree, NULL, 100);
	BTNode *Node60 = incrementOrInsert(tree, NULL, 60);
	BTNode *Node125 = incrementOrInsert(tree, NULL, 125);
	cout << "Print Binary Tree:" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree);
	cout << endl <<"Preorder Test:" << endl;
	BTNode *PreNode100 = preorderNext(Node100);
	BTNode *PreNode60 = preorderNext(Node60);
	BTNode *PreNode125 = preorderNext(Node125);
	BTNode *PreNode70 = preorderNext(Node70);

	//if the next one in a certain order is NULL, print 0 (NULL)
	cout << "(If the next one is NULL, print 0)" << endl;
	cout << "preorderNext(100): "<< ((PreNode100 == NULL)? NULL : PreNode100->data) <<endl;
	cout << "preorderNext(60): " << ((PreNode60 == NULL) ? NULL : PreNode60->data) << endl;
	cout << "preorderNext(70): " << ((PreNode70 == NULL) ? NULL : PreNode70->data) << endl;
	cout << "preorderNext(125): " << ((PreNode125 == NULL) ? NULL : PreNode125->data) << endl;

	cout << endl << "Inorder Test:" << endl;
	BTNode *InNode100 = inorderNext(Node100);
	BTNode *InNode60 = inorderNext(Node60);
	BTNode *InNode70 = inorderNext(Node70);
	BTNode *InNode125 = inorderNext(Node125);

	//if the next one in a certain order is NULL, print 0 (NULL)
	cout << "(If the next one is NULL, print 0)" << endl;
	cout << "inorderNext(100): " << ((InNode100 == NULL) ? NULL : InNode100->data) << endl;
	cout << "inorderNext(60): " << ((InNode60 == NULL) ? NULL : InNode60->data) << endl;
	cout << "inorderNext(70): " << ((InNode70 == NULL) ? NULL : InNode70->data) << endl;
	cout << "inorderNext(125): " << ((InNode125 == NULL) ? NULL : InNode125->data) << endl;

	cout << endl << "Postorder Test:" << endl;
	BTNode *PostNode100 = postorderNext(Node100);
	BTNode *PostNode60 = postorderNext(Node60);
	BTNode *PostNode70 = postorderNext(Node70);
	BTNode *PostNode125 = postorderNext(Node125);

	//if the next one in a certain order is NULL, print 0 (NULL)
	cout << "(If the next one is NULL, print 0)" << endl;
	cout << "postorderNext(100): " << ((PostNode100 == NULL) ? NULL : PostNode100->data) << endl;
	cout << "postorderNext(60): " << ((PostNode60 == NULL) ? NULL : PostNode60->data) << endl;
	cout << "postorderNext(70): " << ((PostNode70 == NULL) ? NULL : PostNode70->data) << endl;
	cout << "postorderNext(125): " << ((PostNode125 == NULL) ? NULL : PostNode125->data) << endl;

	cout << endl << "------------------------TEST_Q2------------------------" << endl;
	//code in A2q2.h

	cout << "Test if a binary tree is a BST: " << endl;
	cout << "1. Print Binary Tree:" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree);

	//check if tree2 is BST
	//print out corresponding result
	if (isBST(tree)) {
		cout << "Yes, this binary tree is a BST." << endl;
	}
	else {
		cout << "No, this binary tree is not a BST." << endl;
	}

	BTNode *tree2 = new BTNode(3, NULL);
	tree2->left = new BTNode(2, tree2);
	tree2->right = new BTNode(5, tree2);
	tree2->left->left = new BTNode(1, tree2);
	tree2->left->right = new BTNode(4, tree2);
	cout << endl << "2. Print Binary Tree:" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree2);

	//check if tree2 is BST
	//print out corresponding result
	if (isBST(tree2)) {
		cout << "Yes, this binary tree is a BST." << endl;
	}
	else {
		cout << "No, this binary tree is not a BST." << endl;
	}

	cout << endl << "------------------------TEST_Q3------------------------" << endl;
	// short Anwser in A2q3.h

	SGTree sgTree2;
	cout << endl <<"Acording to the question, insert 1,5,2,4,3 to a scapegoatTree" << endl;
	cout << "Print Scapegoat Tree with Credits in ()" << endl;
	sgTree2.insert(1);
	cout << endl << "Insert(1):" << endl;
	cout << "root------------------------->" << endl;
	printSGTree(sgTree2.getRoot(), true);

	sgTree2.insert(5);
	cout << endl << "Insert(5):" << endl;
	cout << "root------------------------->" << endl;
	printSGTree(sgTree2.getRoot(), true);

	sgTree2.insert(2);
	cout << endl << "Insert(2):" << endl;
	cout << "root------------------------->" << endl;
	printSGTree(sgTree2.getRoot(), true);

	sgTree2.insert(4);
	cout << endl << "Insert(4):" << endl;
	cout << "root------------------------->" << endl;
	printSGTree(sgTree2.getRoot(), true);

	sgTree2.insert(3);
	cout << endl << "Insert(3):" << endl;
	cout << "root------------------------->" << endl;
	printSGTree(sgTree2.getRoot(), true);

	cout << endl << "------------------------TEST_Q4------------------------" << endl;
	// code in A2q4.h
	cout << "Store  {1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146} to a hash table" << endl;
	HashTable<int> ht(20, 13);
	int testArr[] = { 1,5,21,26,39,14,15,16,17,18,19,20,111,145,146 };
	for (int i : testArr) {
		ht.insert(i);
	}
	//print hash table
	cout << endl << "Print Hash Table: " << endl;
	ht.printHashTableIntKey();
	
	cout << endl << "------------------------TEST_Q5------------------------" << endl;
	// code in A2q5.h
	SubBTNode *tree3 = NULL;
	incrementOrInsert(tree3, NULL, 120);
	incrementOrInsert(tree3, NULL, 130);
	SubBTNode *SubNode70 = incrementOrInsert(tree3, NULL, 70);
	incrementOrInsert(tree3, NULL, 80);
	incrementOrInsert(tree3, NULL, 90);
	SubBTNode *SubNode100 = incrementOrInsert(tree3, NULL, 100);
	SubBTNode *SubNode60 = incrementOrInsert(tree3, NULL, 60);
	SubBTNode *SubNode125 = incrementOrInsert(tree3, NULL, 125);

	//print binary trees with pre-order, in-order and post-order numbers
	tree3->preOrderNumber();
	cout << "Print Binary Tree with preorder number in ():" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree3, PREORDER);

	tree3->inOrderNumber();
	cout << endl <<"Print Binary Tree with inorder number in ():" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree3, INORDER);

	tree3->postOrderNumber();
	cout << endl << "Print Binary Tree with postorder number in ():" << endl;
	cout << "root------------------------->" << endl;
	printTree(tree3, POSTORDER);
	





}

/*Sample Output:
------------------------TEST_Q1------------------------
Print Binary Tree:
root------------------------->

          130

                    125

120

                                        100

                              90

                    80

          70

                    60

Preorder Test:
(If the next one is NULL, print 0)
preorderNext(100): 130
preorderNext(60): 80
preorderNext(70): 60
preorderNext(125): 0

Inorder Test:
(If the next one is NULL, print 0)
inorderNext(100): 120
inorderNext(60): 70
inorderNext(70): 80
inorderNext(125): 130

Postorder Test:
(If the next one is NULL, print 0)
postorderNext(100): 90
postorderNext(60): 100
postorderNext(70): 125
postorderNext(125): 130

------------------------TEST_Q2------------------------
Test if a binary tree is a BST:
1. Print Binary Tree:
root------------------------->

          130

                    125

120

                                        100

                              90

                    80

          70

                    60
Yes, this binary tree is a BST.

2. Print Binary Tree:
root------------------------->

          5

3

                    4

          2

                    1
No, this binary tree is not a BST.

------------------------TEST_Q3------------------------

Acording to the question, insert 1,5,2,4,3 to a scapegoatTree
Print Scapegoat Tree with Credits in ()

Insert(1):
root------------------------->

1(0)

Insert(5):
root------------------------->

          5(0)

1(1)

Insert(2):
root------------------------->

          5(1)

                    2(0)

1(2)

Insert(4):
root------------------------->

          5(2)

                              4(0)

                    2(1)

1(3)

Insert(3):
root------------------------->

                    5(2)

          4(1)

                    3(0)

                              2(2)

1(4)

------------------------TEST_Q4------------------------
Store  {1, 5, 21, 26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146} to a hash table

Print Hash Table:
Index      Key
------------------------
0          26
1          1
2          39
3          14
4          15
5          5
6          16
7          17
8          21
9          18
10         19
11         20
12         111
13         145
14         146
15         NULL
16         NULL
17         NULL
18         NULL
19         NULL

------------------------TEST_Q5------------------------
Print Binary Tree with preorder number in ():
root------------------------->

          130(7)

                    125(8)

120(1)

                                        100(6)

                              90(5)

                    80(4)

          70(2)

                    60(3)

Print Binary Tree with inorder number in ():
root------------------------->

          130(8)

                    125(7)

120(6)

                                        100(5)

                              90(4)

                    80(3)

          70(2)

                    60(1)

Print Binary Tree with postorder number in ():
root------------------------->

          130(7)

                    125(6)

120(8)

                                        100(2)

                              90(3)

                    80(4)

          70(5)

                    60(1)
Press any key to continue . . .


*/