/*COMP272 Assignment3 Question 2
*Illustrate that via AVL single rotation, any binary search tree T1 can be transformed into another search tree T2 (with the same items) (5 marks). 
*Give an algorithm to perform this transformation using O(N log N) rotation on average (10 marks)
*
*Arthor:
*Date:
*/

/*Question 2a
*We can prove this by induction:
*In a base case, there is only one node in the tree, the only possible BST is a tree with only one node.
*Therefore, this tree can be transformed to any other possible trees (itself) by performing rotation.
*
*In a inductive case, we can assume that we have n nodes in the binary search tree. When we perform an AVL
*rotation to a node, either its left child (right rotation) or right child (left rotation) will become the new
*root of the original subtree, and its height will be increased by one. On the other hand, the height of 
*the rotated node will be decreased by one. As a result, we are able to make any nodes move up or down to any positon
*in the tree. Accordingly, we can transfer a binary search tree to another possible one with the same items.
*
*Question 2b
*I implement the O(nlogn) function "transformation()" below. Detail of how it works also shown below
*/

#ifndef _A3Q2_H_									//if not defined
#define _A3Q2_H_

#include<iostream>
#include<algorithm>
using namespace std;

struct BSTNode {

public:
	int data;
	BSTNode *left;
	BSTNode *right;
	BSTNode *parent;
	int height;

};

/*Insert(BSTNode *&tree, BSTNode *parent, int data):
*brief: insert a BST node
*
*param tree: the root of a binary tree
*param parent: the parent of a root
*param data: input data
*
*return: the pointer to a new or a existing node
*/
BSTNode *insert(BSTNode *&tree, BSTNode *parent, int data) {
	if (tree == NULL) {
		tree = new BSTNode;
		tree->left = NULL;
		tree->right = NULL;
		tree->data = data;
		tree->parent = parent;
		return tree;
	}
	else if (tree->data == data) {
		return tree;
	}
	else if (data < tree->data) {
		return insert(tree->left, tree, data);
	}
	else if (data > tree->data) {
		return insert(tree->right, tree, data);
	}
}

/*rightRotate(AVLNode *z):
*brief: perform right rotation on the BST root at z
*
*param z: the root of a BST
*
*return: the pointer to the new root
*/
BSTNode *rightRotate(BSTNode *z) {
	BSTNode *y = z->left;
	BSTNode *T3 = y->right;

	y->right = z;
	z->left = T3;
	y->parent = z->parent;
	z->parent = y;

	return y;

}

/*leftRotate(BSTNode *z):
*brief: perform left rotation on the BST root at z
*
*param z: the root of a BST
*
*return: the pointer to the new root
*/
BSTNode *leftRotate(BSTNode *z) {
	BSTNode *y = z->right;
	BSTNode *T2 = y->left;

	y->left = z;
	z->right = T2;
	y->parent = z->parent;
	z->parent = y;

	return y;

}

BSTNode *search(BSTNode *tree, int data) {
	if (tree == NULL) {
		return NULL;
	}
	else if (data == tree->data) {
		return tree;
	}
	else if (data < tree->data) {
		return search(tree->left, data);
	}
	else if (data > tree->data) {
		return search(tree->right, data);
	}
}

/*transformation(BSTNode *z, BSTNode *reference):
*brief: perform left rotation on the BST root at z
*
*param z: the root of a BST
*
*return: the pointer to the new root
*/
BSTNode *transformation(BSTNode *tree, BSTNode *reference) {
	if (tree == NULL || reference == NULL) { //if get the leaf node of one a tree
		return NULL;
	}
	
	// post order traversal to transfer
	transformation(tree->left, reference->left);
	transformation(tree->right, reference->right);
	BSTNode *target = search(tree, reference->data); //find the corresponding target node in original tree
	BSTNode *treeParent = tree->parent; // use the original parent to record the target position for the target node
	while (target->parent != treeParent) { //if the target node not at the correct position (parents not match), continue to rotate
		if (target->parent->left == target) {// if target is the left child of parent
			return rightRotate(target->parent); //return new root after rotation
		}
		else { // if target is the right child of parent
			return leftRotate(target->parent); //return new root after rotation
		}
	}


}

/*printTreeUtil(BTNode *tree, int space):
*brief: Utility function to print a binary tree on the console
*
*param tree: a node in a binary tree
*param space: space between each level
*
*/
void printBSTTreeUtil(BSTNode *tree, int space) {
	if (tree == NULL) {
		return;
	}

	space += 10;

	//in-order traversal from the right node
	printBSTTreeUtil(tree->right, space);
	cout << endl;
	for (int i = 10; i < space; i++) //print 10 white space
		cout << " ";
	cout << tree->data << endl; //print x

	printBSTTreeUtil(tree->left, space);
}

/*printTree(BTNode *tree):
*brief: A function to print a binary tree on the console (call the utility function)
*
*/
void printBSTTree(BSTNode *tree) {
	printBSTTreeUtil(tree, 0);
}


#endif