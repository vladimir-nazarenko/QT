#include "arraystack.h"

ArrayStack::ArrayStack()
{
    values = new int[100];
    edgeOfStack = 0;
    counter = 0;
}

int ArrayStack::pop()
{
    --counter;
    return values[edgeOfStack--];
}

void ArrayStack::push(int value)
{
    ++counter;
    values[++edgeOfStack] = value;
}

ArrayStack::~ArrayStack()
{
    delete[] values;
}

int ArrayStack::top() const
{
    return values[edgeOfStack];
}

int ArrayStack::size()
{
    return counter;
}
