#include "linkedstack.h"

LinkedStack::LinkedStack()
{
    head = new ListElement();
    tail = head;
    counter = 0;
}

int LinkedStack::top() const
{
    return tail->item;
}

int LinkedStack::pop()
{
    --counter;
    int item = tail->item;
    ListElement* seek = head;
    while (seek->next != tail)
        seek = seek->next;
    delete tail;
    tail = seek;
    return item;
}

void LinkedStack::push(int value)
{
    ++counter;
    ListElement* toAdd = new ListElement();
    toAdd->item = value;
    tail->next = toAdd;
    tail = toAdd;
}

int LinkedStack::size()
{
    return counter;
}
