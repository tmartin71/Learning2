// the linked list
//TODO: reverse method, use a header file, fix memory leak
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
	//is this how you're supposed to do it?
	Node::~Node() {
		delete next;
	};
} ;



class LinkedList {

public:
	Node* start;
	Node* currentNode;

	LinkedList::LinkedList() {
		start = NULL;
		currentNode = NULL;
	}
		
	void traverse( int index = 0 )
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

	void printLinkedList()
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

	void append(int newValue)
	{
		Node* newNode = new Node(newValue);
		if ( start == NULL )
		{
			start = newNode;
		} else {
			traverse();
			currentNode->next = newNode;
		}

	}

	void insert(int newValue, int index) 
	{
		Node* newNode = new Node(newValue);
		if ( start == NULL )
		{
			start = newNode;
		} else if ( currentNode->next == NULL ) {
			append( newValue );
		} else {
			traverse( index );
			//point the new node at the node following currentNode
			newNode->next = currentNode->next;

			//point the currentNode to the new Node
			currentNode->next = newNode;
		}
	}

	//TODO: fix memory leak (need to use a destructor?)
	void removeByValue( int Remove )
	{
		//there may be duplicates at the beginning
		while ( start->value == Remove )
			start = start->next;

		currentNode = start;

		while ( currentNode->next != NULL )
		{
			while ( (currentNode->next)->value == Remove )
			{
				//the last node we to remove is at the end of the list, set currentNode->next to NULL and break
				if ( (currentNode->next)->next == NULL )
				{
					currentNode->next = NULL;
					break;
				}
				currentNode->next = (currentNode->next)->next;
			}
			// need an extra check here since we might set currentNode->next = NULL above
			if ( currentNode->next != NULL )
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
		myList.append(i);
		myList.append(i);
		myList.append(i);
	}
	myList.insert(4, 5);

	myList.printLinkedList();

	myList.removeByValue(4);

	myList.printLinkedList();

	return 0;
}