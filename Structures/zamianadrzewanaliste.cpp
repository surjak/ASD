#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

struct node
{
    int val;
    node *parent;
    node *left;
    node *right;
};

struct listNode
{
    node *Node;
    listNode *prev;
    listNode *next;
};

listNode *treetoList(node *root)
{
    if (root->parent == NULL)
    {
        listNode *Node = new listNode;
        Node->next = NULL;
        Node->prev = NULL;
        Node->Node = root;
        listNode *prev = treetoList(root->left);
        prev->next = Node;
        Node->prev = prev;
        listNode *next = treetoList(root->right);
        next->prev = Node;
        Node->next = next;
        return Node;
    }
    else
    {
        listNode *result = new listNode;
        result->next = result->prev = NULL;
        result->Node = root;
        if (root->right != NULL || root->left != NULL)
        {
            if (root->right != NULL)
            {
                listNode *next = treetoList(root->right);
                next->prev = result;
                result->next = next;
            }
            if (root->left != NULL)
            {
                listNode *prev = treetoList(root->left);
                prev->next = result;
                result->prev = prev;
            }
            return result;
        }
        else
        {
            listNode *Node = new listNode;
            Node->next = Node->prev = NULL;
            Node->Node = root;
            return Node;
        }
    }
}