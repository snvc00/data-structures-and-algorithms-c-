/**
 * Doubly linked list implementation in C++
 *
 * @author Santiago Valle, snvc00
 */

#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;

		//	Time Complexity - O(1)
		Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
			: data(data), next(next), prev(prev) {}
	};

	Node *head, *tail;
	size_t size;
public:
	//	Time Complexity - O(1)
	DoublyLinkedList()
		: head(nullptr), tail(nullptr), size(0) {}

	//	Time Complexity - O(n)
	~DoublyLinkedList() {
		clear();
	}

	//	Time Complexity - O(1)
	const bool isEmpty() const {
		return size == 0;
	}

	//	Time Complexity - O(1)
	const size_t length() const {
		return size;
	}

	//	Time Complexity - O(1)
	void addFirst(const T& data) {
		if (isEmpty()) {
			head = new Node(data);
			tail = head;
			++size;
		}
		else {
			Node* element = new Node(data, head);
			head->prev = element;
			head = element;
			++size;
		}
	}

	//	Time Complexity - O(1)
	void addLast(const T& data) {
		if (isEmpty()) {
			addFirst(data);
		}
		else {
			Node* element = new Node(data, nullptr, tail);
			tail->next = element;
			tail = element;
			++size;
		}
	}

	//?	Time Complexity - O(n)
	void insertAt(const int& index, const T& data) {
		if (index < 0 or index > size) throw std::range_error("Index out of bounds");

		if (index == 0) {
			addFirst(data);
			return;
		}
		if (index == size) {
			addLast(data);
			return;
		}

		Node* current = head;

		for (int i = 0; i < index; ++i)
			current = current->next;

		Node* element = new Node(data, current, current->prev);
		current->prev->next = element;
		current->prev = element;
		++size;
	}

	//	Time Complexity - O(n)
	const int indexOf(const T& data) {
		if (isEmpty()) return -1;

		int elementPosition = -1;
		Node* current = head;
		for (int i = 0; i < size; ++i) {
			if (current->data == data) {
				elementPosition = i;
				break;
			}
			current = current->next;
		}

		return elementPosition;
	}

	//	Time Complexity - O(n)
	const int lastIndexOf(const T& data) {
		if (isEmpty()) return -1;

		int elementPosition = -1;
		Node* current = tail;
		for (int i = size - 1; i >= 0; --i) {
			if (current->data == data) {
				elementPosition = i;
				break;
			}
			current = current->prev;
		}

		return elementPosition;
	}

	//	Time Complexity - O(1)
	bool removeFirst() {
		if (isEmpty()) return false;
		
		if (size == 1) {
			head = nullptr;
			size = 0;
		}
		else {
			Node* temporal = head;
			head = temporal->next;
			delete temporal;
			--size;
		}

		return true;
	}

	//	Time Complexity - O(1)
	bool removeLast() {
		if (isEmpty()) return false;

		if (size == 1) {
			delete head;
			head = nullptr;
			size = 0;
		}
		else {
			Node* temporal = tail;
			tail = temporal->prev;
			delete temporal;
			--size;
		}

		return true;
	}

	//	Time Complexity - O(n)
	bool remove(const T& data) {
		if (isEmpty()) return false;

		int indexOfElement = indexOf(data);
		if (indexOfElement != -1) {
			removeAt(indexOfElement);
		}

		return true;
	}

	//?	Time Complexity - O(n)
	bool removeAt(const int index) {
		if (index < 0 or index >= size) {
			return false;
		} 

		if (index == 0) {
			removeFirst();
		}
		else if (index == size - 1) {
			removeLast();
		}
		else {
			Node* current = head;
			for (int i = 0; i < index; ++i)
				current = current->next;

			current->prev->next = current->next;
			current->next->prev = current->prev;

			delete current;
			--size;
		}

		return true;
	}

	//	Time Complexity - O(n)
	void clear() {
		while (!isEmpty()) {
			removeLast();
		}
	}

	//	Time Complexity - O(1)
	const T& peekFirst() const {
		if (isEmpty()) throw std::range_error("Empty List");
		return head->data;
	}

	//	Time Complexity - O(1)
	const T& peekLast() const {
		if (isEmpty()) throw std::range_error("Empty List");
		return tail->data;
	}

	//	Time Complexity - O(n) /**/
	const bool includes(const T& data) {
		return indexOf(data) != -1;
	}

	//?	Time Complexity - O(n)
	T& operator[](const int& index) const {
		if (index < 0 || index >= size) 
			throw std::range_error("Index out of bounds");
		Node* current = head;
		for (int i = 0; i < index; ++i)
			current = current->next;
		
		return current->data;
	}
};
