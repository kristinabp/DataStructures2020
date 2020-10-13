#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack
{
private:
    static const int INITIAL_SIZE = 2;
    T* data;
    int size;
    int capacity;

    void copy(const Stack& other);
    void resize(int size);
    void erase();

public:
    Stack(int size = INITIAL_SIZE);
    Stack(const Stack& other);
    Stack<T>& operator=(const Stack& other);
    ~Stack();

    void push(const T& elem);
    T pop();
    T peek() const;
    bool isEmpty()const;
    void print() const;

};

#endif // !STACK_H


