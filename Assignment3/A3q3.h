/*COMP272 Assignment3 Question 3
*Illustrate that via AVL single rotation, any binary search tree T1 can be transformed into another search tree T2 (with the same items) (5 marks).
*Give an algorithm to perform this transformation using O(N log N) rotation on average (10 marks)
*
*Arthor:
*Date:
*/

/*Question 3b
*First, we use mergesort algorithm to sort two arrays. 
*First step time complexity: O(nlogn).
*
*Second, we remove duplicates in these two arrays by inserting them to to a linked list.
*Second step time complexity: O(n).
*
*Third, we compare each node in two linked list to check if two sets contain same elements.
*Third step time complexity: O(n).
*
*Therefore, the running time for my algorithm is O(nlogn).
*/

#ifndef _A3Q3_H_									//if not defined
#define _A3Q3_H_

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *next = NULL;
};

/*Merge(int *a, int p, int q):
*brief: Merge Sort utility function
*/
void Merge(int *a, int p, int m, int q) {
	int *firstHalf = new int[m + 1];
	int *lastHalf = new int[q - m + 1];
	int k = p;
	int i;
	int j;
	for (i = 0; k <= m; i++) { //put first half in an array
		firstHalf[i] = a[k];
		k++;
	}
	for (j = 0; k <= q; j++) {//put second half in an array
		lastHalf[j] = a[k];
		k++;
	}
	k = p;
	int x = 0;
	int y = 0;
	while ((x<i) && (y<j)) { //merge two arrays
		if (firstHalf[x] <= lastHalf[y]) {
			a[k] = firstHalf[x];
			k++;
			x++;
		}
		else {
			a[k] = lastHalf[y];
			k++;
			y++;
		}
	}
	while (x < i) { //put the left elemetns to array a
		a[k] = firstHalf[x];
		x++;
		k++;
	}
	while (y < j) { //put the left elements to array a
		a[k] = lastHalf[y]; 
		y++;
		k++;
	}
	delete[] firstHalf;
	delete[] lastHalf;
}


/*MergeSort(int *a, int p, int q):
*brief: Merge Sort an integer array
*/
void mergeSort(int *a, int p, int q) {
	if (q - p > 0) {
		int mid = (p + q) / 2;
		mergeSort(a, p, mid); //divided by 2
		mergeSort(a, mid + 1, q);
		Merge(a, p, mid, q); // merge two parts
	}
}

/*removeDuplicate(int *a, int size):
*brief: remove duplicates in an array and outout results to a linked list
*
*param a: the target array
*param size: the size of the array
*
*return: the pointer to the linked list
*/
Node *removeDuplicate(int *a, int size) {
	mergeSort(a, 0, size-1); //sort the array first
	Node *root = new Node;
	root->data = a[0];
	Node *tmp = root;
	//output distinct elements in an array to a linked list
	for (int i = 1; i < size; i++) {
		if (a[i - 1] != a[i]) { // check if duplicates
			tmp->next = new Node;
			tmp->next->data = a[i];
			tmp = tmp->next;
		}
	}
	return root;
}

/*compareLinkedList(Node *a, Node *b)
*brief: comparing two linked lists and check if two linked lists contain the same elements
*
*param a: the pointer to the first linked list
*param b: the pointer to the second linked list
*
*return true if they contain the same elements
*/
bool compareLinkedList(Node *a, Node *b) {
	while (a != NULL && b != NULL) {//iterate through two lists 
		if (a->data != b->data) {//if there is a different element 
			return false;
		}
		a = a->next;
		b = b->next;
	}
	if (a != NULL || b != NULL) { //if any list contains still have elements left
		return false;
	}

	return true;
}



#endif