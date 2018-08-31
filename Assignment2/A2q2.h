/*COMP272 Assignment2 Question 2
*Design a recursive linear-time algorithm that tests whether a binary tree satisfies the
*search tree order property at every node.
*
*Arthor:
*Date:
*/


#ifndef _A2Q2_H_									//if not defined
#define _A2Q2_H_

#include<iostream>
#include"BTNode.h"
using namespace std;

bool isBST(BTNode *tree, BTNode *l = NULL, BTNode *r = NULL) {
	//base case
	if (tree == NULL) {
		return true;
	}

	//if the data of a left node is larger than 
	//that of its parent, return false.
	if (l != NULL and (tree->data < l->data)) {
		return false;
	}

	//if the data of a right node is less than 
	//that of its parent, return false.
	if (r != NULL and (tree->data > r->data)) {
		return false;
	}

	//recursively check
	return isBST(tree->left, l, tree) &&
		isBST(tree->right, tree, r);
}


#endif