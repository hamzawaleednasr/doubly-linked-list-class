#pragma once

#include <iostream>

using namespace std;

template <class t>
class doubleLinkedList
{
protected:
	int _size = 0;

public:
	struct node
	{
		node *prev;
		node *next;
		t value;
	};

	node *head = nullptr;

	void insertAtBegining(t value)
	{
		node *new_node = new node();

		new_node->value = value;
		new_node->prev = nullptr;
		new_node->next = head;

		if (head != nullptr)
			head->prev = new_node;

		head = new_node;
		_size++;
	}

	node *find(t value)
	{
		node *current = head;
		
		while (current != nullptr)
		{
			if (current->value == value)
				return current;
			current = current->next;
		}

		return nullptr;
	}

	node* getNode(int index)
	{
		int counter = 0;

		if (index > _size - 1 || index < 0 || head == nullptr)
			return nullptr;

		node* current = head;
		while (counter != index)
		{
			current = current->next;
			counter++;
		}

		return current;
	}

	void insertAfter(node *&targetNode, t value)
	{
		node *new_node = new node();

		new_node->value = value;
		new_node->prev = targetNode;
		new_node->next = targetNode->next;

		if (targetNode->next != nullptr)
			targetNode->next->prev = new_node;

		targetNode->next = new_node;
		_size++;
	}

	void insertAfter(int index, t value)
	{
		node* beforeNode = getNode(index);
		insertAfter(beforeNode, value);
	}

	void insertAtEnd(t value)
	{
		node *new_node = new node();

		new_node->value = value;
		new_node->next = nullptr;

		if (head == nullptr)
		{
			new_node->prev = nullptr;
			head = new_node;
			_size++;
			return;
		}

		node *current = head;
		while (current->next != nullptr)
			current = current->next;

		new_node->prev = current;
		current->next = new_node;
		_size++;
	}

	void deleteNode(t value)
	{
		if (head == nullptr)
			return;

		if (head->value == value)
		{
			node *temp = head;
			head = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = nullptr;

			delete temp;
			temp = nullptr;
			return;
		}

		node *current = head;
		while (current->next != nullptr && current->value != value)
			current = current->next;

		if (current->next == nullptr)
			return;

		current->prev->next = current->next;
		if (current->next != nullptr)
			current->next->prev = current->prev;

		delete current;
		current = nullptr;
		_size--;
	}

	void deleteFirstNode()
	{
		if (head == nullptr)
			return;

		node *temp = head;
		head = head->next;

		if (head != nullptr)
			head->prev = nullptr;

		delete temp;
		temp = nullptr;
		_size--;
	}

	void deleteLastNode()
	{
		if (head == nullptr)
			return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		node *current = head;
		while (current->next != nullptr)
			current = current->next;

		current->prev->next = nullptr;
		delete current;
		current = nullptr;
		_size--;
	}

	int size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return !_size;
	}

	void clear()
	{
		while (head != nullptr)
			deleteFirstNode();
		_size = 0;
	}

	void reverse()
	{
		if (head == nullptr || head->next == nullptr)
			return;

		node *current = head;
		node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}

		if (temp != nullptr)
			head = temp->prev;
	}

	t at(int index)
	{
		node* item = getNode(index);
		return ((item == nullptr) ? (NULL) : (item->value));
	}

	bool updateItem(int index, t value)
	{
		node* item = getNode(index);

		if (item != nullptr)
		{
			item->value = value;
			return true;
		}
		else
			return false;
	}

	void print()
	{
		node *current = head;

		while (current != NULL)
		{
			cout << current->value << " ";
			current = current->next;
		}
	}
};
