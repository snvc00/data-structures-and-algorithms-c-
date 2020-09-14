/**
 * Array implementation in C++
 *
 * @author Santiago Valle, snvc00
 */

#pragma once
#include <stdexcept>

template<typename T, size_t SIZE>
class Array {
private:
    T data[SIZE];
public:
    //  Time Complexity - O(1)
    Array() {}

    //  Time Complexity - O(n)
    Array(T& value) {
        for (size_t i = 0; i < S; ++i)
            data[i] = value;
    }

    //  Time Complexity - O(n)
    Array(Array& other) {
        for (int i = 0; i < other.size(); ++i)
            data[i] = other.data[i];
    }

    //  Time Complexity - O(1)
    constexpr size_t size() const {
        return SIZE;
    }

    //  Time Complexity - O(1)
    constexpr T& back() const {
        if (SIZE <= 0)
            throw std::out_of_range("Empty array");
        return data[0];
    }

    //  Time Complexity - O(1)
    constexpr T& front() const {
        if (SIZE <= 0)
            throw std::out_of_range("Empty array");
        return data[SIZE - 1];
    }

    //  Time Complexity - O(1)
    void initAtZero() {
        memset(data, 0, sizeof(T) * SIZE);
    }

    //  Time Complexity - O(n)
    void fill(const T& value) {
        for (int i = 0; i < SIZE; ++i)
            data[i] = value;
    }

    //  Time Complexity - O(1)
    const bool empty() const {
        return SIZE == 0;
    }

    //  Time Complexity - O(1)
    constexpr T& at(const int& index) const {
        if (index < 0 || index >= SIZE)
            throw std::range_error("Index out of bounds");
        return data[index];
    }

    //  Time Complexity - O(1)
    T& operator[](const int& index) {
        if (index < 0 || index >= SIZE)
            throw std::range_error("Index out of bounds");
        return data[index];
    }

    //  Time Complexity - O(1)
    constexpr T& operator[](const int& index) const {
        if (index < 0 || index >= SIZE)
            throw std::range_error("Index out of bounds");
        return data[index];
    }
};