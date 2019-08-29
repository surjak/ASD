

#include <iostream>
using namespace std;

struct node_t
{
    int data;
    int lCount;
    node_t *parent;
    node_t *left;
    node_t *right;
};

node_t *insert_node(node_t *root, node_t *node)
{
    node_t *pTraverse = root;
    node_t *currentParent = root;

    while (pTraverse)
    {
        currentParent = pTraverse;

        if (node->data < pTraverse->data)
        {
            pTraverse->lCount++;
            pTraverse = pTraverse->left;
        }
        else
        {
            pTraverse = pTraverse->right;
        }
    }

    if (!root)
    {
        root = node;
    }
    else if (node->data < currentParent->data)
    {
        currentParent->left = node;
        node->parent = currentParent;
    }
    else
    {
        currentParent->right = node;
        node->parent = currentParent;
    }

    return root;
}

node_t *binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for (iterator = 0; iterator < size; iterator++)
    {
        new_node = new node_t;

        new_node->data = keys[iterator];
        new_node->lCount = 0;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = NULL;

        root = insert_node(root, new_node);
    }

    return root;
}

int k_smallest_element(node_t *root, int k)
{
    int ret = -1;

    if (root)
    {
        node_t *pTraverse = root;

        while (pTraverse)
        {
            if ((pTraverse->lCount + 1) == k)
            {
                ret = pTraverse->data;
                break;
            }
            else if (k > pTraverse->lCount)
            {
                k = k - (pTraverse->lCount + 1);
                pTraverse = pTraverse->right;
            }
            else
            {
                pTraverse = pTraverse->left;
            }
        }
    }

    return ret;
}

void Element(node_t *root, node_t *el)
{
    if (el == NULL)
    {
        cout << "NIE MA TAKIEGO ELEMENTU W DRZEWIE BST!" << endl;
        return;
    }
    int a = el->data;
    if (root == el)
    {
        cout << "Element " << a << " to " << el->lCount + 1 << "-ty element w drzewie" << endl;
        return;
    }

    int counter = el->lCount + 1;

    node_t *prev = el->parent;

    while (el->parent != NULL)
    {
        if (prev->left == el)
        {
            el = prev;
            prev = prev->parent;
        }

        else if (prev->right == el)
        {
            el = prev;
            prev = prev->parent;
            counter++;
            counter += el->lCount;
        }
        else
            cout << "ERROR!";
    }

    cout << "Element " << a << " to " << counter << "-ty element w drzewie" << endl;
}

int main()
{
    const int N = 21;
    int ele[N] = {30, 15, 10, 5, 7, 12, 13, 20, 19, 23, 21, 50, 40, 35, 45, 43, 41, 60, 70, 65, 67};
    int i;
    node_t *root = NULL;

    root = binary_search_tree(root, ele, N);

    Element(root, root->left->left->left->left);
    cout << endl;
    for (i = 1; i <= N; i++)
    {
        cout << " kth smallest elment for k = " << i << " is " << k_smallest_element(root, i) << endl;
    }

    return 0;
}
