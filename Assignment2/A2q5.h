/*COMP272 Assignment2 Question 5
*Create a subclass of BinaryTree whose nodes have fields for storing
*preorder, post-order, and in-order numbers. Write methods preOrderNumber(),
*inOrderNumber(), and postOrderNumbers() that assign these numbers correctly. These
*methods should each run in O(n) time.
*
*Arthor:
*Date:
*/

#ifndef _A2Q5_H_									//if not defined
#define _A2Q5_H_

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

#include<iostream>
#include"BTNode.h"
using namespace std;

//SubBTNode is a sub class of BTNode
//introduing three more filed to record:
//pre-order number, in-order number and post-order number
class SubBTNode : public BTNode {
public:
	int preOrderNum; //record pre-order number
	int inOrderNum; //record in-order number
	int postOrderNum; //record post-order number
	SubBTNode *left;
	SubBTNode *right;

	SubBTNode() {
		BTNode();
		preOrderNum = 0;
		inOrderNum = 0;
		postOrderNum = 0;
	}

	SubBTNode(int data, SubBTNode *parent) {
		this->data = data;
		this->parent = parent;
		preOrderNum = 0;
		inOrderNum = 0;
		postOrderNum = 0;
	}

	/*preorderNumber():
	*brief: assign pre-order number to each node in a binary tree
	*
	*return: a binary tree node
	*/
	void preOrderNumber() {
		int counter = 1;
		preOrderNumberUtility(this, counter);
	}

	void inOrderNumber() {
		int counter = 1;
		inOrderNumberUtility(this, counter);
	}

	void postOrderNumber() {
		int counter = 1;
		postOrderNumberUtility(this, counter);
	}

	void preOrderNumberUtility(SubBTNode *node, int &counter) {
		if (node == NULL) { //base case
			return;
		}

		node->preOrderNum = counter; //pre-order traverse mid node first 
		counter++;
		if (node->left != NULL) {
			preOrderNumberUtility(node->left, counter); // then left
		}
		if (node->right != NULL) {
			preOrderNumberUtility(node->right, counter); //then right
		}
	}

	void inOrderNumberUtility(SubBTNode *node, int &counter) {
		if (node == NULL) { // base case
			return;
		}

		if (node->left != NULL) {//then left
			inOrderNumberUtility(node->left, counter);
		}
		node->inOrderNum = counter;
		counter++;
		if (node->right != NULL) {//then right
			inOrderNumberUtility(node->right, counter);
		}
	}

	void postOrderNumberUtility(SubBTNode *node, int &counter) {
		if (node == NULL) {//base case
			return;
		}

		if (node->left != NULL) { //go to left first
			postOrderNumberUtility(node->left, counter);
		}
		if (node->right != NULL) {//then go to right
			postOrderNumberUtility(node->right, counter);
		}
		node->postOrderNum = counter;
		counter++;
	}


};

/*incrementOrInsert(SubBTNode *&tree, SubBTNode *parent, int data):
*brief: insert a binary tree node or increment the count of a existing node containing the same data
*
*param tree: the root of a binary tree
*param parent: the parent of a root
*param data: input data
*
*return: the pointer to a new or a existing node
*/
SubBTNode *incrementOrInsert(SubBTNode *&tree, SubBTNode *parent, int data) {
	if (tree == NULL) { //base case
		tree = new SubBTNode(data, parent);
		tree->count = 1;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	else if (tree->data == data) {//data is same, incremment count field
		tree->count++;
	}
	else if (data < tree->data) {//new data is less than that stored in the node
		return incrementOrInsert(tree->left, tree, data);//search and add to left tree
	}
	else if (data > tree->data) {//new data is larger than that stored in the node
		return incrementOrInsert(tree->right, tree, data); // search and add to right tree
	}
}

/*printTreeUtil(BTNode *tree, int space):
*brief: Utility function to print a binary tree on the console
*
*param tree: a node in a binary tree
*param space: space between each level
*
*/
void printTreeUtil(SubBTNode *tree, int space, int traversal) {
	if (tree == NULL) {
		return;
	}

	space += 10;

	//in order right-first traversel print the binary tree
	printTreeUtil(tree->right, space, traversal);
	cout << endl;
	for (int i = 10; i < space; i++) //print 10 white space
		cout << " ";
	//print data and correponding traverse number
	if(traversal == PREORDER)
		cout << tree->data << "(" << tree->preOrderNum << ")" << endl;
	else if (traversal == INORDER)
		cout << tree->data << "(" << tree->inOrderNum << ")" << endl;
	else if (traversal == POSTORDER)
		cout << tree->data << "(" << tree->postOrderNum << ")" << endl;

	printTreeUtil(tree->left, space, traversal);
}

/*printTree(BTNode *tree):
*brief: A function to print a binary tree on the console (call the utility function)
*
*/
void printTree(SubBTNode *tree, int traversal) {
	printTreeUtil(tree, 0, traversal);
}


#endif
