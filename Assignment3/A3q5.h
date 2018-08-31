/*COMP272 Assignment3 Question 5
*Given the graph shown below, answer the following questions:
*
*Arthor:
*Date:
*/
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
class Graph {
	map<char, vector<char>> neighbors;
	map<char, bool> visted;
	map<pair<char, char>, bool> edge_traversed;

public:
	/*addV(char v, vector<char> n):
	*brief: add vertex v and its neighbor vector to the graph
	*
	*param v: char represent a vertex v
	*param n: neighbor vector of vertex v
	*/
	void addV(char v, vector<char> n) {
		neighbors[v] = n;
		visted[v] = false;
		for (vector<char>::iterator it = n.begin(); it != n.end(); it++) { // initialize visit status for each newly added node
			pair<char, char> edge;
			edge.first = v;
			edge.second = *it;
			edge_traversed[edge] = false;
		}
	}

	/*resetVisited():
	*brief: reset visited flag of each vertex
	*
	*/
	void resetVisted() {
		for (map<char, bool>::iterator it = visted.begin(); it != visted.end(); it++) {
			it->second = false;
		}
	}

	/*DFSAndPrintSequence(char v):
	*brief: DFS traverse the graph and print out sequence
	*
	*param v: char represent a start vertex v
	*/
	void DFSAndPrintSequence(char start) {
		resetVisted(); 
		stack<char> s;
		s.push(start); //push the start char to the stack
		while (!s.empty()) { //check if the stack is not empty
			char temp = s.top();
			s.pop(); //pop the end char in the stack
			if (!visted[temp]) { //if not visited, update the visited flag
				visted[temp] = true;
				cout << temp << " "; //print out the char
			}
			for (vector<char>::iterator it = neighbors[temp].end(); it != neighbors[temp].begin(); it--) {//stack all neighbors of the current node
				if (!visted[*(it - 1)]) {
					s.push(*(it - 1)); //push unvisited char to the stack
				}
			}
		}
	}

	/*BFSAndPrintSequence(char v):
	*brief: BFS traverse the graph and print out sequence
	*
	*param v: char represent a start vertex v
	*/
	void BFSAndPrintSequence(char start) {
		resetVisted(); //reset the visited flags
		queue<char> q;
		q.push(start); //push the start pointer to the queue
		visted[start] = true;
		while (!q.empty()) {
			char temp = q.front();
			q.pop(); //pop the head char
			cout << temp << " "; //print out the node
			for (vector<char>::iterator it = neighbors[temp].begin(); it != neighbors[temp].end(); it++) {//stack all neighbors of current node
				if (!visted[*it]) {
					visted[*it] = true; // set visited flag
					q.push(*it);
				}
			}
		}
	}

	/*findAllEdgesPath(char v):
	*brief: DFS traverse the graph to find a path go each eage in each direaction exactly once
	*
	*param v: char represent a start vertex v
	*/
	void findAllEdgesPath(char start) {
		resetVisted();
		findAllEdgesPathUtil(NULL, start);
	}

	/*findAllEdgesPathUtil(char prev, char v):
	*brief: Utility recursive function for DFS traverse the graph to find a path go each eage in each direaction exactly once
	*
	*param v: char represent a start vertex v
	*/
	void findAllEdgesPathUtil(char prev, char v) {
		if (prev != NULL) { //if it is not the start vertex
			edge_traversed[make_pair(prev, v)] = true;
			cout << v << " ";
		}
		else {//if its a start 
			cout << v << " ";
		}
		for (vector<char>::iterator it = neighbors[v].begin(); it != neighbors[v].end(); it++) { //check all neighbors of current node
			if (!edge_traversed[make_pair(v, *(it))] && !edge_traversed[make_pair(*(it), v)]) { //if the edge is not traveled at all, travel that edge
				findAllEdgesPathUtil(v, *(it));
			}
		}
		for (vector<char>::iterator it = neighbors[v].begin(); it != neighbors[v].end(); it++) { //check all neighbors of current node
			if (!edge_traversed[make_pair(v, *(it))]) {//if the edge is only traveled once
				findAllEdgesPathUtil(v, *(it));
			}
		}

	}


};

