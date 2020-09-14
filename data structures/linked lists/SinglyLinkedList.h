/**
 * Single linked list implementation in C++
 *
 * @author Santiago Valle, snvc00
 */

#pragma once
#include <stdexcept>
#include <string>

template <typename T>
class SinglyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(const T &data = nullptr, Node *next = nullptr)
            : data(data), next(next) {}
    };

    Node *head, *tail;
    size_t size;

public:
    //  Time Complexity - O(1)
    SinglyLinkedList()
        : head(nullptr), tail(nullptr), size(0) {}

    //  Time Complexity - O(n)
    ~SinglyLinkedList() {
        clear();
    }

    //  Time Complexity - O(1)
    constexpr size_t length() const {
        return size;
    }

    //  Time Complexity - O(1)
    const bool isEmpty() const {
        return size == 0;
    }

    //  Time Complexity - O(n)
    void clear() {
        for (int i = 0; i < size; ++i)
            removeFirst();
    }

    //  Time Complexity - O(1)
    void addFirst(const T &data) {
        if (size == 0) {
            head = new Node(data);
            tail = head;
        }
        else {
            Node *node = new Node(data, head);
            head = node;
        }

        ++size;
    }

    //  Time Complexity - O(1)
    void addLast(const T &data) {
        if (size == 0) {
            head = new Node(data);
            tail = head;
        }
        else {
            Node *node = new Node(data);
            tail->next = node;
            tail = node;
        }

        ++size;
    }

    //  Time Complexity - O(1)
    const T& peekFirst() const {
        if (size == 0)
            throw std::out_of_range("Empty list");
        return head->data;
    }

    //  Time Complexity - O(1)
    const T& peekLast() const {
        if (size == 0)
            throw std::out_of_range("Empty list");
        return tail->data;
    }

    //  Time Complexity - O(n)
    const int indexOf(const T &element) {
        Node *current = head;
        for (int i=0; i<size; ++i) {
            if (current->data == element)
                return i;
            current = current->next;
        }

        return -1;
    }

    //  Time Complexity - O(1)
    const bool removeFirst() {
        if (size == 0)
            throw std::out_of_range("Empty list");
        Node *first = head;
        head = head->next;
        delete first;
        --size;

        return true;
    }

    //  Time Complexity - O(n)
    const bool removeLast() {
        if (size == 0)
            throw std::out_of_range("Empty list");
        Node *current = head;
        while (current->next != tail)
            current = current->next;
        delete tail;
        tail = current;
        --size;

        return true;
    }

    //  Time Complexity - O(n)
    const bool removeAt(const int &index) {
        if (index < 0 || index >= size)
            return false;
        if (index == 0)
            return removeFirst();
        if (index == size - 1)
            return removeLast();

        Node *current = head;
        for (int i = 0; i < index - 1; ++i)
            current = current->next;
        Node *remove = current->next;
        current->next = remove->next;
        delete remove;

        return true;
    }

    //  Time Complexity - O(n)
    const bool contains(const T &element) {
        return indexOf(element) != -1;
    }

    //  Time Complexity - O(n) // ! Make this faster
    std::string toString() const {
        if (size == 0)
            return "[]";

        std::string list = "[";

        Node *current = head;

        for (int i = 0; i < size; ++i) {
            list.append(std::to_string(current->data) + ", ");
            current = current->next;
        }

        list.append("\b\b]");

        return list;
    }

    //  Time Complexity - O(n)
    T& at(const int &index) {
        if (index < 0 || index >= size)
            throw std::range_error("Index out of bounds");
        if (size == 0)
            throw std::out_of_range("Empty list");

        Node *current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        
        return current->data;

    }

    //  Time Complexity - O(n)
    T& operator[](const int &index) {
        return at(index);
    }

    // TODO: Implement iterators
};
