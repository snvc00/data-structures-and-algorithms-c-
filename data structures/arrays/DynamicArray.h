/**
 * Dynamic array implementation in C++
 *
 * @author Santiago Valle, snvc00
 */

#pragma once
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    size_t size, capacity;
    T* data;

    //  Time Complexity - O(n)
    void doubleCapacity() {
        capacity *= 2;
        T* newData = new T[capacity];

        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
    }
public:
    //  Time Complexity - O(1)
    DynamicArray()
        :size(0), capacity(2), data(new T[capacity])
    { }

    //  Time Complexity - O(n)
    DynamicArray(DynamicArray<T>& other)
        :size(other.size), capacity(other.capacity), data(new T[capacity])
    {
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    //  Time Complexity - O(1)
    ~DynamicArray() {
        delete[] data;
    }

    //  Time Complexity - O(1)
    constexpr size_t length() const {
        return size;
    }

    //  Time Complexity - O(1)
    const bool isEmpty() const {
        return size == 0;
    }

    //  Time Complexity - O(1)
    T& get(const int index) const {
        if (index < 0 || index >= size)
            throw std::range_error("Index out of bounds");
        return data[index];
    }

    //  Time Complexity - O(1)
    T& set(const int index, const T& element) {
        if (index < 0 || index >= size)
            throw std::range_error("Index out of bounds");
        data[index] = element;
    }

    //  Time Complexity - O(1)
    void clear() {
        delete[] data;
        data = new T[capacity];
        size = 0;
    }

    //  Time Complexity - O(1)
    void add(const T& element) {
        if (size + 1 >= capacity)
            doubleCapacity();

        data[size++] = element;
    }

    //  Time Complexity - O(n)
    bool removeAt(const int index) {
        if (index < 0 || index >= size) return false;

        T* newData = new T[capacity];

        for (int i = 0, j = 0; i < size; ++i, ++j)
            if (i == index) --j;
            else newData[j] = data[i];

        delete[] data;
        data = newData;

        return true;
    }

    //  Time Complexity - O(n)
    bool remove(const T& element) {
        int index = indexOf(element);
        if (index == -1) return false;

        removeAt(index);

        return true;
    }

    //  Time Complexity - O(n)
    const int indexOf(const T& element) const {
        for (int i = 0; i < size; ++i)
            if (data[i] == element)
                return i;

        return -1;
    }

    //  Time Complexity - O(n)
    const int lastIndexOf(const T& element) const {
        for (int i = size - 1; i >= 0; --i)
            if (data[i] == element)
                return i;

        return -1;
    }

    //  Time Complexity - O(n)
    const bool contains(const T& element) const {
        return indexOf(element) != -1;
    }

    //  Time Complexity - O(n)
    std::string toString() const {
        if (size == 0) return "[]";

        std::string array = "[";

        for (int i = 0; i < size; ++i)
            array.append(static_cast<std::string>(data[i] + ", "));

        return array + "]";

    }

    //  Time Complexity - O(1)
    constexpr T& operator[](const int index) const {
        if (index < 0 || index >= size)
            throw std::range_error("Index out of bounds");
        return data[index];
    }

    //  Time Complexity  - O(1)
    T& operator[](const int index) {
        if (index < 0 || index >= size)
            throw std::range_error("Index out of bounds");
        return data[index];
    }

    //  Time Complexity - O(n)
    DynamicArray<T>& operator=(DynamicArray<T>& other) {
        delete[] data;

        capacity = other.capacity;
        size = other.size;
        T* data = new T[capacity];

        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
};