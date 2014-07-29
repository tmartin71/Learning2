// the linked list
// TODO: it's missing one node, either in the printing or the append, for some reason


#include "iostream"

using namespace std;

class Node {

public:
	int value;
	Node* next;

	Node::Node() {
		value = NULL;
		next = NULL;
	}

	Node::Node(int initValue) {
		value = initValue;
		next = NULL;
	}
	/*
	Node::~Node() {
		delete value;
		delete next;
	}; */
} ;



class LinkedList {

public:
	Node* start;
	Node* currentNode;

	LinkedList::LinkedList() {
		start = NULL;
		currentNode = NULL;
	}
		
	void Traverse( int index = 0 )
	{
		currentNode = start;
		int count = 0;

		while ( currentNode->next != NULL )
		{
			++count;

			if ( index == count )
				break;

			currentNode = currentNode->next;
		}
	}

	void PrintLinkedList()
	{
		Node* printNode = start;
		cout << "START" << endl;
		while ( printNode->next != NULL )
		{
			cout << printNode->value << endl;
			printNode = printNode->next;
		}

		//fucking fenceposts
		cout << printNode->value << endl;
		cout << "END \n" << endl;

	}

	void Append(int newValue)
	{
		Node* newNode = new Node(newValue);
		if ( start == NULL )
		{
			start = newNode;
		} else {
			Traverse();
			currentNode->next = newNode;
		}

	}

	void Insert(int newValue, int index) 
	{
		Node* newNode = new Node(newValue);
		if ( start == NULL )
		{
			start = newNode;
		} else if ( currentNode->next == NULL ) {
			Append( newValue );
		} else {
			Traverse( index );
			//point the new node at the node following currentNode
			newNode->next = currentNode->next;

			//point the currentNode to the new Node
			currentNode->next = newNode;
		}
	}

	//TODO: deal with the duplicates case; fix memory leak (need to use a destructor); and it doesn't like the endpoints
	void RemoveByValue( int Remove )
	{

		// loop through the list and look for the value to remove
		while ( currentNode->next != NULL ) {
			// if the next next node's value matches Remove, remove it
			if ( (currentNode->next)->value == Remove ) {
				// save the node we're going to delete because we need its pointer
				Node* temp = currentNode->next;
				//remove the next node
				//currentNode->next = NULL;
				// point the current node at the node after the one being removed
				currentNode->next = temp->next;
			}
			//step forward
			currentNode = currentNode->next;
		}
		
	}
} ;



int main()
{
	//create an empty list
	LinkedList myList;

	int N = 5;

	for (int i = 0; i < N; ++i)
	{
		myList.Append(i);
	}

	myList.PrintLinkedList();

	//myList.Insert(500, 200);

	//myList.PrintLinkedList();

	myList.RemoveByValue(4);

	myList.PrintLinkedList();

	

	return 0;
}