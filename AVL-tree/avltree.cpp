#include "avltree.h"


AVLtree::AVLtree()
{

}

void AVLtree::includeKey(int key, Node *node, bool &bBecameHigher)
{
    if (node == NULL)
    {
        node = new Node();
        bBecameHigher = true;
        node->value = key;
        node->left = NULL;
        node->right = NULL;
        node->balance = 0;
    }

    else
    {
        if (key < node->key)
        {
            includeKey(key, node->left, bBecameHigher);

            if (bBecameHigher)
            {
                switch(node->balance)
                {
                case +1:
                    node->balance = 0;
                    bBecameHigher = false;
                    break;
                case 0:
                    node->balance = -1;
                    bBecameHigher = true;
                    break;
                case -1:
                    Node* oldLeft = node->left;
                    if (oldLeft->balance == -1)
                    {
                        node->left = oldLeft->right;
                        oldLeft->right = node;
                        node->balance = 0;  //why?
                        node = oldLeft;
                    }
                    else
                    {
                        Node* oldLeftRight = oldLeft->right;
                        oldLeft->right = oldLeftRight->left;
                        oldLeftRight->left = oldLeft;
                        node->left = oldLeftRight->right;
                        oldLeftRight->right = node;

                        if (oldLeftRight->balance == -1)//whyyyy?
                            node->balance = 1;
                        else
                            node->balance = 0;

                        if (oldLeftRight->balance == 1)
                            oldLeft>balance = -1;
                        else
                            oldLeft->balance = 0;
                    }

                    node->balance = 0;
                    bBecameHigher = false;
                    break;
                }

            }
        }
        else
        {
            if (key > node->value)
            {
                includeKey(key, node, bBecameHigher);

                if (bBecameHigher)
                {
                    switch(node->balance)
                    {
                    case -1:
                        node->balance = 0;
                        bBecameHigher = false;
                        break;
                    case 0:
                        node->balance = 1;
                        bBecameHigher = true;
                    case 1:
                        Node* oldRight = node->right;
                        if (oldRight->balance == 1)
                        {
                            node->right = oldRight->left;
                            oldRight->left = node;
                            node->balance = 0;
                            node = oldRight;
                        }
                        else
                        {
                            Node* oldRightLeft = oldRight->left;
                            oldRight->left = oldRightLeft->right;
                            oldRightLeft->right = oldRight;
                            node->right = oldRightLeft->left;
                            oldRightLeft->left = node;

                            if (oldRightLeft->balance == +1)
                                node->balance = -1;
                            else
                                node->balance = 0;
                            if (oldRightLeft->balance == -1)
                                oldRight->balance = 1;
                            else
                                oldRight->balance = 0;
                        }

                        node->balance = 0;
                        bBecameHigher = false;
                    }
                }
            }
        }
    }
}

void AVLtree::excludeKey(int key, Node *node, bool &bBecameLower)
{
    if (node == NULL)
        return;

    if (key < node->value)
    {
        excludeKey(key, node->left, bBecameLower);

        if (bBecameLower)
            BalanceL(node, bBecameLower);
    }
    else
    {
        if (x > node->value)
        {
            excludeKey(key, node->right, bBecameLower);
            if (bBecameLower)
                BalanceR(node, bBecameLower);
        }
        else
        {
            Node* toDelete = node;

            if(toDelete->right == NULL)
            {
                node = toDelete->left;
                bBecameLower = true;
            }
            else
            {
                if (toDelete->left == NULL)
                {
                    node = toDelete->right;
                    bBecameLower = true;
                }
                else
                {
                    toDelete = del(toDelete->left);
                    if (bBecameLower)
                        BalanceL(node, bBecameLower);
                }
            }

            delete toDelete;
        }
    }
}

//
Node* AVLtree::del(Node *r, bool &heightChanged)
{
    if (r->right != NULL)
    {
        del(r->right, heigthChanged);

        if (heigthChanged)
            balanceR(r, heigthChanged);
    }
    else
    {
        Node* q = new Node();
        int temp = q->value;
        q->value = r->value;
        r->value = temp;
        q = r;
        r = r->left;
        heightChanged = true;
        return q;
    }
    return NULL;
}

void AVLtree::balanceL(Node *node, bool &bBecameLower)
{
    switch(node->balance)
    {
    case -1:
        node->balance = 0;
        break;
    case 0:
        node->balance = 1;
        bBecameLower = false;
        break;
    case 1:
        Node* oldRight = node->right;
        short oldBalance = oldRight->balance;
        if (oldBalance >= 0)
        {

        }
    }
}






