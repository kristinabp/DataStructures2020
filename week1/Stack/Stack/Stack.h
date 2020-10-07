#ifndef STACK
#define STACK

#include <iostream>

template <typename T>
class Stack
{
private:
    static const int INITIAL_SIZE = 2;
    T* data;
    int size;
    int capacity = INITIAL_SIZE;

    void copy(const Stack& other);
    void resize();
    void decrease();

public:
    Stack(int size = INITIAL_SIZE);
    Stack(const Stack& other);
    Stack<T>& operator=(const Stack& other);
    /*
        push resizes the array if full
    */
    void push(const T& elem);
    /*
        pop returns the element and removes it from the array,
        if empty print an appropriate message and exit the program
    */
    T& pop();
    /*
        utility function, returns the top element
    */
    T peek();
    /*
        utility function, checks if the stack is empty
    */
    bool isEmpty();
    ~Stack();
};

#endif


