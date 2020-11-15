#include"CyclicDoubleLinkedList.h"

template<typename T>
struct CDLList<T>:: Node
{
	T data;
	Node* next, * prev;
};

template<typename T>
class CDLList<T>::Iterator
{
private:
	const Node* currentNode;
public:
    Iterator() noexcept : currentNode(front) {}

    Iterator(const Node* node) noexcept : currentNode(node) {}

    Iterator& operator=(Node* node)
    {
        this->currentNode = node;
        return *this;
    }

    Iterator& operator++()
    {
        if (currentNode)
            currentNode = currentNode->next;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator iterator = *this;
        ++* this;
        return iterator;
    }

    Iterator& operator--()
    {
        if (currentNode)
            currentNode = currentNode->prev;
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator iterator = *this;
        --* this;
        return iterator;
    }

    bool operator!=(const Iterator& iterator)
    {
        return currentNode != iterator.currentNode;
    }

    int operator*()
    {
        return currentNode->item;
    }
};


template<typename T>
CDLList<T>::CDLList() : front(nullptr), back(nullptr) {}

template<typename T>
bool CDLList<T>::isEmpty() const
{
    return front==nullptr;
}

template<typename T>
int CDLList<T>::size() const
{
    Node* temp = front;
    int counter = 1;
    temp = temp->next;
    while (temp != front)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

template<typename T>
T CDLList<T>::getFront() const
{
    return front;
}

template<typename T>
T CDLList<T>::getBack() const
{
    return back;
}

template<typename T>
void CDLList<T>::pushFront(T elem)
{
    Node* newElem=new Node();
    if (isEmpty())
    {
        newElem->data = elem;
        newElem->next = newElem;
        newElem->prev = newElem;
        front = newElem;
        back = newElem;
        return;
    }
    newElem->data = elem;
    newElem->next = front;
    newElem->prev = back;
    front->prev = newElem;
    back->next = newElem;
    front = newElem;
}

template<typename T>
void CDLList<T>::pushBack(T elem)
{
    Node* newElem = new Node();
    if (isEmpty())
    {
        newElem->data = elem;
        newElem->next = newElem;
        newElem->prev = newElem;
        front = newElem;
        back = newElem;
        return;
    }
    newElem->data = elem;
    newElem->next = front;
    newElem->prev = back;
    front->prev = newElem;
    back->next = newElem;
    back = newElem;
}

template<typename T>
T CDLList<T>::popFront()
{
    Node* temp = front;
    T result = front->data;
    front = front->next;
    back->next = front;
    front->prev = back;
    delete temp;

    return result;
}

template<typename T>
T CDLList<T>::popBack()
{
    Node* temp = back;
    T result = back->data;
    back = temp->prev;
    back->next = front;
    front->prev = back;
    delete temp;

    return result;
}

template<typename T>
void CDLList<T>::assign(size_t n, T elem)
{
    int counter = 0;
    while (counter < n)
    {
        counter++;
        pushFront(elem);
    }
}

template<typename T>
void CDLList<T>::insert(size_t n, T elem)
{
    if (n == 0)
    {
        pushFront(elem);
        return;
    }

    if (n == size())
    {
        pushBack(elem);
        return;
    }

    int counter = 0;
    Node* newElem = new Node();
    Node* temp = front;
    newElem->data = elem;
    while (counter < n - 1)
    {
        temp = temp->next;
        counter++;
    }
    newElem->next = temp->next;
    newElem->prev = temp;
    newElem->next->prev = newElem;
    temp->next = newElem;
}

template<typename T>
void CDLList<T>::erase(size_t n)
{
    if (n == 0)
    {
        popFront();
        return;
    }

    if (n == size())
    {
        popBack();
        return;
    }

    Node* temp = front;
    int counter = 0;
    while (counter < n );
    {
        counter++;
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

template<typename T>
void CDLList<T>::clear()
{
    while (front->next != nullptr)
    {
        Node* saver = front;
        front = front->next;
        back->next = front;
        front->prev = back;
        delete saver;
    }

}

template<typename T>
void CDLList<T>::map(T(*func)(T elem))
{
    Node* first = front;
    front->data=func(front->data);
    front = front->next;
    while (first != front)
    {
        front->data=func(front->data);
        front = front->next;
    }
}

template<typename T>
void CDLList<T>::print() const
{
    if (isEmpty())
        std::cout << "Empty list.\n";
    Node* temp = front;
    std::cout << temp->data << " ";
    temp = temp->next;
    while (temp != front)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
