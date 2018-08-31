/*COMP272 Assignment2
*Node for a binary tree
*
*
*Arthor:
*Date:
*/
#ifndef _SGNODE_H_									//if not defined
#define _SGNODE_H_

#include<iostream>
using namespace std;

struct SGNode {
	double data; //record value stored in the node
	int credits; //record rebuild credits
	SGNode *left; //the pointer to the left node
	SGNode *right; //the pointer to the right node
	SGNode *parent; //the pointer to the parent node
};


SGNode *newSGNode(double data) { //create and initialize a new scapegoat node
	SGNode *tmpN = new SGNode;
	tmpN->data = data;
	tmpN->credits = 0;
	tmpN->left = NULL;
	tmpN->right = NULL;
	tmpN->parent = NULL;
	return tmpN;
}

#endif