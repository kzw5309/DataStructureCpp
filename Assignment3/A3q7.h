/*COMP272 Assignment3 Question 7
*Exercise 10.8. Implement the remove(u) method, that removes the HNode u from a
*MeldableHeap. This method should run in O(log n) expected time.
*
*Arthor:
*Date:
*/

#include<iostream>
using namespace std;

//class for HNode in the meldableheap
template <typename T>
class HNode {

public:
	T data;
	HNode *left;
	HNode *right;
	HNode *parent;

	//constructor
	HNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

};

template <typename T>
class MeldableHeap {
private:
	HNode<T> *root;
	int n;
public:

	//default constructor
	MeldableHeap() {
		root = NULL;
		n = 0;
	}

	/*merge(HNode<T> h1, HNode<T> h2):
	*brief: take two heap HNodes h1 and h2 and merges them
	*
	*param h1: a heap HNode
	*param h2: a heap HNode
	*/
	HNode<T> *merge(HNode<T> *h1, HNode<T> *h2) {
		if (h1 == NULL)//if the first HNode is null
			return h2; //return the second one
		if (h2 == NULL)//if the second HNode is null
			return h1;//return the first one
		if (h2->data < h1->data) {
			return merge(h2, h1); //the first HNode data must be less than that of the second
		}
		if (rand() % 2 == 0) { //randomly choose the left or right pointer as the next merging subtree
			h1->left = merge(h1->left, h2); //merge with left
			h1->left->parent = h1; //update parent
		}
		else {
			h1->right = merge(h1->right, h2); //merge with right
			h1->right->parent = h1;//update parent
		}

	}


	/*add(T x):
	*brief: add a new data x to the heap
	*
	*param x: the new data need to be added to the heap
	*
	*return true if the HNode added
	*/
	bool add(T x) {
		HNode<T> *u = new HNode<T>(x);
		root = merge(u, root);//merge the new HNode with heap
		root->parent = NULL;//update the root parent
		n++;//
		return true;
	}

	/*remove():
	*brief: remove the root of heap and rebuild the heap
	*
	*return the removed number
	*/
	T remove() {
		T data = root->data;
		root = merge(root->left, root->right); //merge left and right children
		if (root != NULL) { //if the heap is not empty
			root->parent = NULL; //update the parent of the root to NULL
		}
		n--;
		return data;
	}

	/*printMeldableHeapUtil(AVLNode *tree, int space):
	*brief: Utility function to print an AVL binary tree on the console
	*
	*param tree: a node in a binary tree
	*param space: space between each level
	*
	*/
	void printMeldableHeapUtil(HNode<T> *tree, int space) {
		if (tree == NULL) {
			return;
		}

		space += 10;
		//in-order traversal from the right node
		printMeldableHeapUtil(tree->right, space);
		cout << endl;
		for (int i = 10; i < space; i++) //print 10 white space
			cout << " ";
		cout << tree->data << endl; //print x 

		printMeldableHeapUtil(tree->left, space);
	}

	/*printMeldableHeap(BTNode *tree):
	*brief: A function to print a AVL binary tree on the console (call the utility function)
	*
	*/
	void printMeldableHeap() {
		printMeldableHeapUtil(root, 0);
	}

};




