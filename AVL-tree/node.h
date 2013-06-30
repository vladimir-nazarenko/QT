#ifndef NODE_H
#define NODE_H

struct Node
{
public:
    int value;
    Node* left;
    Node* right;
    //height of the right subtree minus one of the left subtree
    short balance;
};

#endif // NODE_H
