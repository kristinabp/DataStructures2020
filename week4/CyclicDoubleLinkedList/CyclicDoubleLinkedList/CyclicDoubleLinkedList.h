#ifndef CDLINKED_LST
#define CDLINKED_LST

#include<iostream>

template <typename T>
class CDLList
{
private:
    struct Node;
    class Iterator;

    Node* front, *back;

    void deleteList();

public:
    CDLList();
    CDLList(const CDLList&) = delete;
    CDLList& operator=(const CDLList&) = delete;

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
    void pushFront(T);
    void pushBack(T);
    T popFront();
    T popBack();
    void assign(size_t, T);
    void insert(size_t, T);
    void erase(size_t);
    void clear();
    void unique();
    void reverse();
    void removeIf(bool(*pred)(T elem));
    void map(T(*func)(T elem));
    void print()const;
};

#endif

