/*COMP272 Assignment2 Question 1
*Implement a binary tree class 
*and design operations for preorderNext(x), postorderNext(x) and inorderNext(x).
*
*Arthor:
*Date:
*/

/*Question 1.2 methods' worset case running time
*						running time
*preorderNext(x)		O(n)
*inorderNext(x)			O(n)
*postorderNext(x)		O(n)
*/

#ifndef _A2Q1_H_									//if not defined
#define _A2Q1_H_

#include"BTNode.h"
#include<iostream>
using namespace std;

/*incrementOrInsert(BTNode *&tree, BTNode *parent, int data):
*brief: insert a binary tree node or increment the count of a existing node containing the same data
*
*param tree: the root of a binary tree
*param parent: the parent of a root
*param data: input data
*
*return: the pointer to a new or a existing node
*/
BTNode *incrementOrInsert(BTNode *&tree, BTNode *parent, int data) {
	if (tree == NULL) { // base case: create a new BTNode, and return the pointer
		tree = new BTNode(data);
		tree->count = 1;
		tree->parent = parent;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	else if (tree->data == data) { //data is same, incremment count field
		tree->count++;
	}
	else if (data < tree->data) { //new data is less than that stored in the node
		return incrementOrInsert(tree->left, tree, data); //search and add to left tree
	}
	else if (data > tree->data) { //new data is larger than that stored in the node
		return incrementOrInsert(tree->right, tree, data); //search and add to left tree
	}
}

/*isIternal(BTNode *tree):
*brief: Check if a node is an internal node
*
*param tree: a node in a binary tree
*
*return: if it is an internal node, the function will return true otherwise false.
*/
bool isInternal(BTNode *tree) {
	if (tree->left != NULL || tree->right != NULL) { // if a node has a child, it is an internal node
		return true;
	}
	else {
		return false;
	}
}


/*preorderNext(BTNode *tree):
*brief: return the node visited after node x in a pre-order traversal of BT.
*
*param tree: a node in a binary tree
*
*return: a binary tree node
*/
BTNode *preorderNext(BTNode *tree) {
	if (isInternal(tree)) { // check if an node is an internal node
		if (tree->left != NULL) //if it has a left child, return the left child
			return tree->left;
		else
			return tree->right; // else return right child
	}
	else { // it is a leaf node
		BTNode *p = tree->parent;
		if (tree == p->left && p->right != NULL) { //if it is the left child of its parent and its parent has a right child, return the right child of its parent
			return p->right;
		}
		else { //tree is a right child or the right sibling is NULL
			while (tree != p->left || p->right == NULL) { //backtracking until a ancestor is a left node and has a right sibling
				tree = p;
				p = p->parent;
				if (tree == NULL || tree->parent == NULL) { //if back to root £¨the end of traversal), return NULL
					return NULL;
				}
			}
			return p->right;
		}
	}
}

/*inorderNext(BTNode *tree):
*brief: return the node visited after node x in a in-order traversal of BT.
*
*param tree: a node in a binary tree
*
*return: a binary tree node
*/
BTNode *inorderNext(BTNode *tree) {
	if (tree->right != NULL) { //check if node has a right child
		BTNode *tmpN = tree->right;
		while (tmpN->left != NULL) { //find the left most node in the right subtree of the root
			tmpN = tmpN->left;
		}
		return tmpN; //return pointer
	}
	else { //the node does not have a right child
		BTNode *p = tree->parent;
		while (p != NULL && tree != p->left) { //backtracking until a parent is a left child
			tree = p;
			p = p->parent;
		}
		return p; //return the pointer to that ancestor 

	}
}

/*postderNext(BTNode *tree):
*brief: return the node visited after node x in a post-order traversal of BT.
*
*param tree: a node in a binary tree
*
*return: a binary tree node
*/
BTNode *postorderNext(BTNode *tree) {
	BTNode *p = tree->parent;
	if (tree == p->left && p->right != NULL) { //if the node is a left child and has a right sibling
		BTNode *tmpN = p->right;
		while (isInternal(tmpN)) { //it is an internal node
			if(tmpN->left != NULL) //go to the left most node in the subtree
				tmpN = tmpN->left;
			else if (tmpN->right != NULL) // if it has right child, go to right
				tmpN = tmpN->right;
		}
		return tmpN;
	}
	else { //if not, return the parent of the node
		return p;
	}
}

/*printTreeUtil(BTNode *tree, int space):
*brief: Utility function to print a binary tree on the console
*
*param tree: a node in a binary tree
*param space: space between each level
*
*/
void printTreeUtil(BTNode *tree, int space) {
	if (tree == NULL) {
		return;
	}
	
	space += 10;
	 //in order right-first traversel print the binary tree
	printTreeUtil(tree->right, space);
	cout << endl;
	for (int i = 10; i < space; i++)//print 10 spaces
		cout << " ";
	cout << tree->data << endl;

	printTreeUtil(tree->left, space);
}

/*printTree(BTNode *tree):
*brief: A function to print a binary tree on the console (call the utility function)
*
*/
void printTree(BTNode *tree) {
	printTreeUtil(tree, 0);
}
#endif