// the linked list
// TODO: it's missing one node, either in the printing or the append, for some reason


#include "iostream"

using namespace std;

class Node {

public:
	int value;
	Node *next;

	Node::Node() {
		value = NULL;
		next = NULL;
	}

	Node::Node(int initValue) {
		value = initValue;
		next = NULL;
	}
} ;



class LinkedList {

public:
	Node *start;

	LinkedList::LinkedList() {
	}

	void Append(int newValue)
	{
		Node* newNode = new Node(newValue);
		if ( start == NULL )
		{
			start = newNode;
		} else {
			Node* currentNode = start;
			while ( currentNode->next != NULL) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;

		}

	}
	
	void Traverse()
	{
		Node* currentNode = start;
		while ( currentNode->next != NULL)
		{
			cout << currentNode->value << endl;
			currentNode = currentNode->next;	
		}
		//fucking fenceposts
		cout << currentNode->value << endl;
		return *currentNode;
	}

} ;



int main()
{
	LinkedList myList;
	int N = 5;

	for (int i = 0; i < N; ++i)
	{
		myList.Append(i);
	}

	myList.Traverse();

	return 0;
}