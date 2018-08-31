/*COMP272 Assignment2 Question 4
*Implement a commonly used hash table in a program that handles collision using linear
*probing. Using (K mod 13) as the hash function, store the following elements in the table: {1, 5, 21,
*26, 39, 14, 15, 16, 17, 18, 19, 20, 111, 145, 146}.
*
*Arthor:
*Date:
*/

#ifndef _A2Q4_H_									//if not defined
#define _A2Q4_H_

#include<iostream>
using namespace std;

//HashItem class
template<typename K>
class HashItem {
public:
	K key; //hashkey
	
	HashItem(K k) {
		key = k;
	}
};

//HashTable class
template<typename K>
class HashTable {
private:
	HashItem<K> **hArr; //hash item array
	int size; //the current size of hash table 
	int capacity;//the maximum size
	int modN; //mod number
	HashItem<K> *dummy; //place holder for deleted items
public:
	//default constructor
	HashTable() {
		capacity = 20;
		size = 0;
		modN = 13;
		hArr = new HashItem<K> *[capacity];
		for (int i = 0; i < capacity; i++) //initialize the hash table
			hArr[i] = NULL;

		dummy = new HashItem<K>(-1); // initialize dummy hashtime with -1 key
	}

	//constructor
	HashTable(int capacity, int modN) {
		this->capacity = capacity;
		size = 0;
		this->modN = modN;
		hArr = new HashItem<K> *[capacity];
		for (int i = 0; i < capacity; i++) //initialize the hash table
			hArr[i] = NULL;

		dummy = new HashItem<K>(-1); // initialize dummy hashtime with -1 key
	}

	/*hashKey(K key)
	*brief: get hashed key
	*
	*param key: the key to be hashed
	*/
	int hashKey(K key) {
		return key % modN;
	}

	/*insert(K key)
	*brief: insert a hash item with key
	*
	*param key: the key of a new hash item.
	*/
	void insert(K key) {
		if (size >= capacity) { //size cannot be larger than capacity
			cout << "Error: the hash table is full!" << endl;
			return;
		}

		HashItem<K> *tmp = new HashItem<K>(key);
		//get the index in the hash map
		int hIndex = hashKey(key);

		//search for next avaliable slot 
		//(dummy or NULL or update current item)
		while (hArr[hIndex] != NULL && hArr[hIndex]->key != key 
			&& hArr[hIndex]->key != dummy->key) {
			hIndex = ++hIndex % capacity;
		}

		//if it ocuppys a new slot or replaces a dummy slot
		//increase size
		if (hArr[hIndex] == NULL || hArr[hIndex]->key == dummy->key) {
			size++;
		}
		hArr[hIndex] = tmp;

	}

	/*deleteAndReturnKey(K key)
	*brief: delete a hash item and return its key
	*
	*param key: the key of the target item.
	*/
	K deleteAndReturnKey(int key) {
		int hIndex = hashKey(key);
		bool found = false;
		K deletedKey = -2; //record the key of deleted item
		int i = 0;
		//while not in the end of table and not found and not iterate more than once
		while (hArr[hIndex] != NULL && !found && i < capacity) {
			if (hArr[hIndex]->key == key) {
				HashItem<K> *tmp = hArr[hIndex];
				deletedKey = tmp->key;
				//replace original node with the dummy item
				hArr[hIndex] = dummy; 
				//decrement size
				size--;
				free(tmp);
				found = true;
			}
			hIndex = ++hIndex % capacity;
			i++;
		}
		return deletedKey;
	}

	/*get(K key)
	*brief: retur the hash item with the input key
	*
	*param key: the key of the target hash item.
	*/
	HashItem<K> *get(K key) {
		HashItem<K> *temp = NULL;
		int hIndex = hashKey(key);
		bool found = false;
		int i = 0;
		//while not in the end of table and not found and not iterate more than once
		while (hArr[hIndex] != NULL && !found && i<capacity) {
			if (hArr[hIndex]->key == key) {
				temp = hArr[hIndex];
				found = true;
			}
			hIndex = ++hIndex % capacity;
			i++;
		}

		return temp;
	}

	/*isEmpty()
	*brief: check if the hash table is empty.
	*/
	bool isEmpty() {
		return size == 0;
	}

	/*getSize()
	*brief: return the current size of the hash table.
	*/
	int getSize() {
		return size;
	}

	/*printHashTable()
	*brief: print the Hash Table on the console
	*/
	void printHashTableIntKey() {
		printf("%-10s %-10s\n", "Index", "Key");
		printf("------------------------\n");
		for (int i = 0; i < capacity; i++) { //iterate through the table
			if (hArr[i] != NULL) { //print non-null items
				printf("%-10d %-10d\n", i, hArr[i]->key);
			}
			else { //print null items
				printf("%-10d %-10s\n", i, "NULL");
			}
		}
	}

};

#endif
