#ifndef AVLTREE_H
#define AVLTREE_H

#include "avl-tree_global.h"
#include "node.h"

class AVLTREESHARED_EXPORT AVLtree
{
    
public:
    AVLtree();
    void includeKey(int key, Node *node, bool& bBecameHigher);
    void excludeKey(int key, Node *node, bool &h);
private:
    void del(Node* r, bool &heightChanged);
    void balanceL(Node* node, bool &bBecameLower);
    void balanceR(Node* node, bool &bBecameLower);
    Node* root, head;
    Node* arrayOfItems;
    int numberOfItems;

};

#endif // AVLTREE_H
