/*COMP272 Assignment2
*Node for a binary tree
*
*
*Arthor:
*Date:
*/
#ifndef _BTNODE_H_									//if not defined
#define _BTNODE_H_

#include<iostream>
using namespace std;

/*struct BTNode {
	int data;
	int count;
	BTNode *left;
	BTNode *right;
	BTNode *parent;
};


BTNode *newBTNode(BTNode *parent, int data) {
	BTNode *tmpN = new BTNode;
	tmpN->count = 0;
	tmpN->data = data;
	tmpN->left = NULL;
	tmpN->right = NULL;
	tmpN->parent = parent;
	return tmpN;
}*/

class BTNode {
public:
	int data;
	int count;
	BTNode *left;
	BTNode *right;
	BTNode *parent;

	BTNode() {
		this->count = 0;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

	BTNode (int data) {
		this->count = 0;
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

	BTNode (int data, BTNode *parent) {
		this->count = 0;
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = parent;
	}
};









#endif