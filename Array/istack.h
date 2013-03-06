#ifndef ISTACK_H
#define ISTACK_H

class IStack
{
public:
    virtual int pop() = 0;
    virtual void push(int value) = 0;
    virtual int top() const = 0;
    virtual int size() = 0;
};

#endif // ISTACK_H
