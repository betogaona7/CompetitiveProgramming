
#include <iostream>

using namespace std;
/*
	An array (vector) is a data structure that can hold elements in a container.
*/

// Declare and initilize an empty vector
#include <vector>

vector <int> myVector;
// Initialize a vector that holds 100 bool values, and initialize 100 elements
vector<bool> myVector2(100, true);

// add elements to myVector
myVector.push_back(5);
myVector.push_back(2);
myVector.push_back(7);
myVector.push_back(10);

// Remove elements to myVector
myVector.erase(myVector.begin()+1) // Erases 2 since it is at index 1

// Remove a consecutive list of elementes between index i and index j
int i, j = 1, 3;
myVector.erase(myVector.begin()+i, myVector.begin()+j);

// Know the size of a vector
cout << myVector.size() << endl;

//To sort in ascending order (in a O(n Log n) time import algorithm class)
#include <algorithm>

sort(myVector.begin(), myVector.end());

// To sort in descending order we need to crate a comparator class
class comparator{
	public:
		bool operator()(const int& lhs, const int& rhs){
			return lhs > rhs;
		}
};

sort(myVector.begin(), myVector.end(), comparator);

// Create a comparator class for any class 
class Student{
private:
	int StudentNumber;
public:
	Student(int n){
		this->StudentNumber = n;
	}
	int get StudentNumber() const{
		return this->StudentNumber;
	}
};

class comparator{
public:
	bool operator()(const Student& lhs, const Student& rhs){
		return lhs.getStudentNumber() < rhs.getStudentNumber();
	}
};

sort(myVector.begin(), myVector.end(), comparator);

// To represent a collection of charaters a, its often much more useful to use String
#include <string>

string s, r, t;
s = "Hello";
r = "World";
t = s + " " + s;

sort(t.begin(), t.end()) //Can sort strings based on alphabetica order (ASCCI)

// Search an element in a sorted vector (in O(log n) time using binary search)
cout << binary_search(myVector.begin(), myVector.end(), 2) << endl;

/******************************* Stacks *******************************************/
#include <stack>

// Create the stack
stack <int> mystack;

// Add elements to the stack
mystack.push(5);
mystack.push(4);
mystack.push(1);


cout << mystack.size() << endl;
cout << mystack.empty() << endl; // False, since we have three elements
cout << mystack.top() << endl; // 5 

// Remove a elment, always the top
mystack.pop(); // removes 5

cout << mystack.top() << endl; //4

/************************** Hash table *********************************************/
#include <unordered_map>

unordered_map <string, int> hash_table;

// Search an element 
hash_table.find(names[i]) == hash_table.end() //if true, it didn't find it.

// Insert 
hash_table.insert(make_pair(names[i], 1));

// Access to the element
hash_table[names[i]]

//Hash map includes the names and the frequencies in which they happen
// output those frequencies 
for(auto it = hash_table.begin(); it != hash_table.end(); it++){
	cout << it->first << it->second << endl;
	// first is the name, second is the frequency
}

/*********************** Heap (priority queue) ************************************/

// It is a special case of balnced binary tree where the root-node key is compared
// with its children and arranged accordingly. if a has child node b then key(a) >= key(b)

priority_queue <int> heap;

heap.push(5);
heap.push(1); 
heap.push(10); 
heap.push(30); 
heap.push(20); 

while(heap.empty() == false){
	cout << heap.top() << endl; //30 20 10 5 1
	heap.pop();
}


/********************** Binary tree ************************************************/
class Node{
public:
	int value;
	Node* left;
	Node* right;
	Node(int x){
		this->value = x;
		left = NULL;
		right = NULL;
	}
};

int main(){
	Node* root = new Node(5):
	Node* leftChild = new Node(10);
	Node* rightChild = new Node(3);

	root->left = leftChild;
	root->right = rightChild;

	delete root;
	delete leftChild;
	delete rightChild;
}