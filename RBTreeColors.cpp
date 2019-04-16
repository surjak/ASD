#include<iostream>
#include <algorithm>
using namespace std;



struct node{
    int key;
    node* left;
    node* right;
};

node *newNode(int key)
{
    node *kode = new node;
    kode->key = key;
    kode->left = kode->right = NULL;
    return (kode);
}

bool is_Balanced(node* root, int &maxh, int &minh)
{
    if( root == NULL)
    {
        maxh=0;
        minh=0;
        return true;
    }

    int minlewy, maxlewy, minprawy, maxprawy;

    if(is_Balanced(root->left, maxlewy, minlewy)==false)
    return false;
    if (is_Balanced(root->right, maxprawy, minprawy) == false)
        return false;
    maxh=max(maxprawy, maxlewy)+1;
    minh=min(minprawy, minlewy)+1;

    if(maxh<=2*minh)
    return true;
    return false;
}

bool isBalanced(node *root)
{
    int maxh, minh;
    return is_Balanced(root, maxh, minh);
}

int main()
{
    node *root = newNode(7);
    root->left = newNode(2);
    root->left->left=newNode(1);
    root->left->right=newNode(4);
    // root->left->right->left = newNode(3);
    // root->left->right->right = newNode(5);

    // root->right = newNode(8);
    // root->right->right = newNode(89);
    // root->right->left == newNode(17);

    //root->right->left = newNode(7);
    // root->right->right = newNode(150);
    // root->right->left->left = newNode(40);
    isBalanced(root) ? cout << "Balanced" : cout << "Not Balanced";

    return 0;
}