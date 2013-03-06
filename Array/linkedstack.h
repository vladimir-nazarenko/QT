#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "istack.h"
#include "listelement.h"

class LinkedStack : public IStack
{
public:
    LinkedStack();
    ~LinkedStack();
    int pop();
    int top() const;
    void push(int value);
    int size();

private:
    ListElement* head;
    ListElement* tail;
    int counter;
};

#endif // LINKEDSTACK_H
