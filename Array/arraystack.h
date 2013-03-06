#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "istack.h"

class ArrayStack : public IStack
{
public:
    ArrayStack();
    ~ArrayStack();
    int pop();
    int top() const;
    void push(int value);
    int size();

private:
    int* values;
    int edgeOfStack;
    int counter;
};

#endif // ARRAYSTACK_H
