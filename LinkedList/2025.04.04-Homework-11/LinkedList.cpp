#include <iostream>
#include "LinkedList.h"

void LinkedList::clear()
{
	Node* temp = head;
	while (temp != nullptr) {
		Node* t = temp;
		temp = temp->next;
		t->data = 0;
		delete t;
	}
}

void LinkedList::InsertHeadNode(Node* node)
{
	node->next = head;
	head = node;
}

void LinkedList::InsertTailNode(Node* node)
{
	Node* temp = head;
	if (temp == nullptr) {
		head = node;
		return;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = node;
}

void LinkedList::InsertNode(Node* node, int index)
{
	if (index == 0) {
		return InsertHeadNode(node);
	}
	Node* temp = head;
	for (int i = 1; i < index && temp != nullptr; ++i) {
		temp = temp->next;
	}
	if (temp != nullptr) {
		node->next = temp->next;
		temp->next = node;
	}
	else {
		delete node;
	}
}

Node* LinkedList::ExtractHeadNode()
{
	if (IsEmpty()) {
		return nullptr;
	}
	Node* res = head;
	head = head->next;
	return res;
}

Node* LinkedList::ExtractTailNode()
{
	if (IsEmpty())
	{
		return nullptr;
	}
	if (head->next == nullptr)
	{
		return ExtractHeadNode();
	}
	Node* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	Node* res = temp->next;
	temp->next = nullptr;
	return res;
}

Node* LinkedList::ExtractNode(int index)
{
	if (index == 0)
	{
		return ExtractHeadNode();
	}
	Node* temp = head;
	for (int i = 0; i < index - 1 && temp->next != nullptr; ++i)
	{
		temp = temp->next;
	}
	if (temp->next == nullptr)
	{
		return nullptr;
	}
	Node* res = temp->next;
	temp->next = temp->next->next;
	res->next = nullptr;
	return res;
}

LinkedList::LinkedList() : head(nullptr)
{
}

LinkedList::~LinkedList()
{
	clear();
}

bool LinkedList::IsEmpty()
{
	return (head == nullptr);
}

int LinkedList::length()
{
	int res = 0;
	Node* temp = head;
	while (temp != nullptr) {
		temp = temp->next;
		++res;
	}
	return res;
}

void LinkedList::swap(int ind1, int ind2)
{
	if (ind2 == ind1)
	{
		return;
	}
	if (ind2 < ind1)
	{
		return swap(ind2, ind1);
	}
	Node* node2 = ExtractNode(ind2);
	Node* node1 = ExtractNode(ind1);
	InsertNode(node2, ind1);
	InsertNode(node1, ind2);
}

int LinkedList::Get(int index)
{
	int res = 0;
	Node* temp = head;
	for (int i = 0; i < index; ++i) {
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList::sort()
{
	for (int i = 0; i < length(); ++i)
	{
		for (int j = 0; j < length(); ++j)
		{
			if (Get(i) > Get(j))
			{
				swap(i, j);
			}
		}
	}
}

void LinkedList::Insert(int element, int index)
{
	return InsertNode(new Node(element), index);
}

void LinkedList::InsertHead(int element)
{
	return InsertHeadNode(new Node(element));
}

void LinkedList::InsertTail(int element)
{
	return InsertTailNode(new Node(element));
}

int LinkedList::Extract(int index)
{
	Node* res = ExtractNode(index);
	int data = res->data;
	res->data = 0;
	delete res;
	return data;
}

int LinkedList::ExtractHead()
{
	Node* res = ExtractHeadNode();
	int data = res->data;
	res->data = 0;
	delete res;
	return data;
}

int LinkedList::ExtractTail()
{
	Node* res = ExtractTailNode();
	int data = res->data;
	res->data = 0;
	delete res;
	return data;
}

void LinkedList::Print()
{
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

