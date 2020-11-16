#ifndef DLINKED_LST
#define DLINKED_LST

#include<iostream>

template <typename T>
class DLList
{
private:
    struct Node;
    class Iterator;

    Node* front, *back;

    void deleteList();

public:
    DLList();
    DLList(const DLList&) = delete;
    DLList& operator=(const DLList&) = delete;

    // Root of LinkedList wrapped in Iterator type
    Iterator begin()
    {
        return Iterator(front);
    }

    // End of LInkedList wrapped in Iterator type
    Iterator end()
    {
        return Iterator(back);
    }

    bool isEmpty() const;
    int size() const;
    T getFront() const;
    T getBack() const;
    void pushFront(const T&);
    void pushBack(const T&);
    T popFront();
    T popBack();
    void assign(size_t, T);
    void insert(size_t, T);
    void erase(size_t);
    void clear();
    void reverse();
    void removeIf(bool(*pred)(T elem));
    void map(T(*func)(T elem));
    void print()const;
};

#endif

