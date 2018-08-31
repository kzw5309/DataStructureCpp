/*COMP272 Assignment3 Question 4
*Given sequence 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, sort the sequence using the following
*algorithms, and illustrate the details of the execution of the algorithms:
*
*Arthor:
*Date:
*/

/*Question 4a
*merge-sort algorithm is in A3q3.h
*Execution Details:
*3  1  4  1  5  9  2  6  5  3  5
*
*1,3  1,4  5,9  2,6  3,5  5
*
*1,1,3,4  2,5,6,9  3,5,5
*
*1,1,2,3,4,5,6,9  3,5,5
*
*1,1,2,3,3,4,5,5,5,6,9
*
*Question 4b
*quick-sort algorithm is coded below
*I choose the last element in the sequence as a pivot. The average running time is O(nlogn£©
*However, if the sequence has already been sorted, the time complexity will be O(n^2).
*If I can pick a pivot that is close to the middle in each partition, we can guarantee O(nlogn).
*
*A better way is to pick the first, last and middle elements
*and take the median of these three elements as the pivot.
*
*Execution Details (last element as the pivot):
*3  1  4  1  5  9  2  6  5  3  5
*(p is pviot position)
*1st partition: 3  1  4  1  5  2  5  3  p5  6  9
*
*2nd partition: 3  1  1  2  p3  4  5  5  5  6  p9
*
*3rd partition: 1  1  p2  3  3  4  5  p5  5  6  9
*
*Q4a merge-sort algorithm result:
*1 1 2 3 3 4 5 5 5 6 9
*Q4b quick-sort algorithm result:
*1 1 2 3 3 4 5 5 5 6 9
*/

#include<iostream>
#include<fstream>
using namespace std;

/*swap(int *a, int b, int c):
*brief: swap two elements in an int array
*
*param a: dynamic allocated array
*param b: index for swap
*param c: index for swap
*/
void swap(int *a, int b, int c) {
	int temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

/*TPartition(int *a, int p, int q):
*brief: Quick sort utility function
*
*param a: dynamic allocated array
*param b: start index
*param c: end index
*
*return current pivot position
*/
int TPartition(int *a, int s, int m) {
	int i = s;
	for (int j = s; j < m; j++) { //partiiotn at the last element
		if (a[j] <= a[m]) {
			swap(a, j, i); //swap the larger element at i with j
			i++;
		}
	}
	swap(a, m, i);
	return i;
}

/*QuickSort(int *a, int p, int q):
*brief: Quicksort algorithm for an integer array
*
*param a: dynamic allocated array
*param b: start index
*param c: end index
*/
void quickSort(int *a, int s, int m) {
	if (m - s > 0) {
		int p = TPartition(a, s, m);
		quickSort(a, s, p - 1);
		quickSort(a, p + 1, m);
	}
}