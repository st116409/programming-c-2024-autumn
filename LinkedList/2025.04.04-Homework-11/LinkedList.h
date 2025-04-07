#pragma once

struct Node {
	int data;
	Node* next;

	Node(int data = 0, Node* next = nullptr): data(data), next(next)
	{}
	~Node() {
		data = 0;
		next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
	void clear();
	void InsertHeadNode(Node* node);
	void InsertTailNode(Node* node);
	void InsertNode(Node* node, int index);
	Node* ExtractHeadNode();
	Node* ExtractTailNode();
	Node* ExtractNode(int index);
public:
	LinkedList();
	~LinkedList();
	bool IsEmpty();
	int length();
	void swap(int ind1, int ind2);
	int Get(int index);
	void sort();
	void Insert(int element, int index);
	void InsertHead(int element);
	void InsertTail(int element);
	int Extract(int index);
	int ExtractHead();
	int ExtractTail();
	void Print();
};

