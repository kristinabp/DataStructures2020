#include"DoubleLinkedList.h"

template<typename T>
struct DLList<T>:: Node
{
	T data;
	Node* next, * prev;
};

template<typename T>
class DLList<T>::Iterator
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
DLList<T>::DLList() : front(nullptr), back(nullptr) {}

template<typename T>
bool DLList<T>::isEmpty() const
{
    return front==nullptr;
}

template<typename T>
int DLList<T>::size() const
{
    Node* temp = front;
    int counter = 0;
    while (temp != nullptr)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

template<typename T>
T DLList<T>::getFront() const
{
    if (front != nullptr)
        return front->data;
    else
        return T();
}

template<typename T>
T DLList<T>::getBack() const
{
    if (back != nullptr)
        return back->data;
    else
        return T();
}

template<typename T>
void DLList<T>::pushFront(const T& elem)
{
    Node* temp = front;
    front = new Node { elem, temp, nullptr };
    if (temp != nullptr)
        temp->prev = front;
    else
        back = front;
}

template<typename T>
void DLList<T>::pushBack(const T& elem)
{
    Node* temp = back;
    back = new Node{ elem,nullptr,temp };
    if (temp != nullptr)
        temp->next = back;
    else
        front = back;
}

template<typename T>
T DLList<T>::popFront()
{
    if (front != nullptr)
    {
        Node* saver = front;
        T result = front->data;
        front = front->next;
        delete saver;
        front->prev = nullptr;
        return result;
    }

    return T();
}

template<typename T>
T DLList<T>::popBack()
{
    if (back != nullptr)
    {
        Node* saver = back;
        T result = back->data;
        back = back->prev;
        delete saver;
        back->next = nullptr;
        return result;
    }

    return T();
}

template<typename T>
void DLList<T>::assign(size_t n, T elem)
{
    size_t counter = n;
    if (front == nullptr)
    {
        front = new Node{ elem, nullptr, nullptr };
        front = back;
        counter--;
    }

    Node* temp = front;
    while (counter != 0)
    {
        temp->next = new Node{ elem, nullptr, temp };
        temp = temp->next;
        if (counter == 1)
        {
            back = temp;
        }
        counter--;
    }
}

template<typename T>
void DLList<T>::insert(size_t n, T elem)
{
    size_t currPos = 0;
    Node* temp = front;
    while (temp && currPos != n)
    {
        temp = temp->next;
        currPos++;
    }

    if (temp == nullptr)
        pushBack(elem);
    else if (temp->prev == nullptr)
        pushFront(elem);
    else
    {
        Node* saver = new Node{ elem, temp, temp->prev };
        temp->prev->next = saver;
        temp->prev = saver;
    }
}

template<typename T>
void DLList<T>::erase(size_t n)
{
    size_t currentPosition = 0;
    Node* index = front;
    while (index && currentPosition != n)
    {
        index = index->next;
        currentPosition++;
    }
    if (index != nullptr)
    {
        if (index->next == nullptr)
        {
            popBack();
        }
        else if (index->prev == nullptr)
        {
            popFront();
        }
        else
        {
            index->next->prev = index->prev;
            index->prev->next = index->next;
            delete index;
        }
    }
}

template<typename T>
void DLList<T>::clear()
{
    if (front != nullptr)
    {
        Node* saver;
        while (front != nullptr)
        {
            saver = front;
            front = front->next;
            delete saver;
        }
        back = nullptr;
    }
}

template<typename T>
void DLList<T>::reverse()
{
    Node* end = back;
    Node* saver = front = back;
    while (end != nullptr)
    {
        saver->next = end->prev;
        saver->prev = end->next;
        end = end->prev;
        saver = saver->next;
    }
}

template<typename T>
void DLList<T>::removeIf(bool(*pred)(T elem))
{
    Node* temp = front;

    while (temp != nullptr)
    {
        if (pred(temp))
        {
            if (temp->next == nullptr)
                popBack();
            else
            {
                Node* saver = temp;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
                delete saver;
            }
        }
        else temp = temp->next;
    }
}

template<typename T>
void DLList<T>::map(T(*func)(T elem))
{
    Node* first = front;
    while (first != nullptr)
    {
        first->data=func(first->data);
        first = first->next;
    }
}

template<typename T>
void DLList<T>::print() const
{
    if (isEmpty())
        std::cout << "Empty list.\n";
    Node* temp = front;
    while (temp != nullptr)
    {
        if (temp->next == nullptr)
        {
            std::cout << temp->data << '\n';
        }
        else
        {
            std::cout << temp->data << "->";
        }
        temp = temp->next;
    }
}
