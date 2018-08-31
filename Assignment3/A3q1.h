/*COMP272 Assignment3 Question 1
*Illustrate that the nodes of any AVL tree T can be colored ¡°red¡± and ¡°black¡± so that T
*becomes a red-black tree
*
*Arthor:
*Date:
*/

/*Question 1
* For an AVLTree, if the maximum path from an internal node to its leaf descendants is k, the shortest possible minimum path is k/2
* 
* For a Red-Black Tree, the the maximum path cannot be twice larger than the minimum path:
* Max_Path <= 2 * Min_Path
*	
* Therefore, when Path >= 0, an AVL Tree can be considered as a Red-Black Tree even in the worse case.
* In order to color nodes in an AVL Tree with "black" and "red", we need to make sure that the longest path has the same number of 
* black nodes with that in the shortest path. Other nodes should be red.
* 
*/

#ifndef _A3Q1_H_									//if not defined
#define _A3Q1_H_

#include<iostream>
#include<algorithm>
using namespace std;

class AVLNode {

public:
	int data;
	AVLNode *left;
	AVLNode *right;
	int height;

	//constructor
	AVLNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		int height = 0; //default height is 0
	}

	
};

/*height(AVLNode *tree):
*brief: get the height of the node
*
*param tree: an AVL binary tree node
*
*return: the height of node
*/
int height(AVLNode *tree) {
	if (tree == NULL) { //NULL node height is -1
		return -1;
	}
	else {
		return tree->height;
	}
}

/*rightRotate(AVLNode *z):
*brief: perform right rotation on the AVL tree root at z
*
*param z: the root of a AVL binary tree
*
*return: the pointer to the new root
*/
AVLNode *rightRotate(AVLNode *z) {
	AVLNode *y = z->left;
	AVLNode *T3 = y->right;

	//change pointer position
	y->right = z;
	z->left = T3;
	//update heights
	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;

}

/*leftRotate(AVLNode *z):
*brief: perform left rotation on the AVL tree root at z
*
*param z: the root of a AVL binary tree
*
*return: the pointer to the new root
*/
AVLNode *leftRotate(AVLNode *z) {
	AVLNode *y = z->right;
	AVLNode *T2 = y->left;

	//change position
	y->left = z;
	z->right = T2;

	//update height
	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;


}

/*getBalanceFactor(AVLNode *tree):
*brief: get the balance factor at the tree node
*
*param tree: the root of a AVL binary tree
*
*return: the balance factor of the tree node
*/
int getBalanceFactor(AVLNode *tree) {
	if (tree == NULL) {
		return 0;
	}
	return height(tree->right) - height(tree->left);
}

/*Insert(AVLNode *&tree, int data):
*brief: insert a binary tree node
*
*param tree: the root of a binary tree
*param parent: the parent of a root
*param data: input data
*
*return: the pointer to a new or a existing node
*/
AVLNode *insert(AVLNode *tree, int data) {

	//BST insertion
	if (tree == NULL) { //base case
		tree = new AVLNode(data);
		return tree;
	}
	else if (data > tree->data) { //new data is smaller than the node data
		tree->left = insert(tree->left, data);//go to left
	}
	else if (data < tree->data) {//new data is larger than the node data
		tree->right = insert(tree->right, data);//go to left
	}
	else {
		return tree;
	}

	//change the height of the node
	tree->height = 1 + max(height(tree->left), height(tree->right));

	//get the balance factor
	int bf = getBalanceFactor(tree);

	//two cases if the tree is not AVL tree
	//if right-heavy
	if (bf > 1) {
		//if right child is right-heavy or balance
		int bfRight = getBalanceFactor(tree->right);
		if (bfRight == 1 || bfRight == 0) {
			return leftRotate(tree);
		}
		//if not
		else {
			tree->right = rightRotate(tree->right);
			return leftRotate(tree);
		}
	}
	//if left-heavy
	else if (bf < -1) {
		int bfLeft = getBalanceFactor(tree->left);
		//if left child is left-heavy or balance
		if (bfLeft == -1 || bfLeft == 0) {
			return rightRotate(tree);
		}
		//if not
		else {
			tree->left = leftRotate(tree->left);
			return rightRotate(tree);
		}
	}

	return tree;

}

/*printAVLTreeUtil(AVLNode *tree, int space):
*brief: Utility function to print an AVL binary tree on the console
*
*param tree: a node in a binary tree
*param space: space between each level
*
*/
void printAVLTreeUtil(AVLNode *tree, int space) {
	if (tree == NULL) {
		return;
	}

	space += 10;
	//in-order traversal from the right node
	printAVLTreeUtil(tree->right, space);
	cout << endl;
	for (int i = 10; i < space; i++) //print 10 white space
		cout << " ";
	cout << tree->data << "(" << tree->height << ")" << endl; //print x with height in the brackets

	printAVLTreeUtil(tree->left, space);
}

/*printAVLTree(BTNode *tree):
*brief: A function to print a AVL binary tree on the console (call the utility function)
*
*/
void printAVLTree(AVLNode *tree) {
	printAVLTreeUtil(tree, 0);
}

#endif

