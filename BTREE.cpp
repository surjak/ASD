#include <iostream>
using namespace std;
const int N = 2;
struct node
{
    int n;
    int key[N];
    node *child[N + 1];
    bool leaf;
};

void isB(node *node, int minKey, int maxKey)
{
    if (node == NULL)
        return;

    for (int i = 0; i < N; i++)
    {

        if (node->key[i] < minKey || node->key[i] > maxKey || (i < N - 1 && node->key[i] > node->key[i + 1]))
            cout << "NIE DA SIE " << endl;
    }

    isB(node->child[0], minKey, node->key[0]);
    for (int i = 1; i < N; i++)
    {
        isB(node->child[i], node->key[i - 1], node->key[i]);
    }
    isB(node->child[N], node->key[N - 1], maxKey);
}

int main()
{
    node *p = new node;
    p->key[0] = 2;
    p->key[1] = 7;
    node *p1 = new node;
    p1->key[0] = 0;
    p1->key[1] = 1;
    node *p2 = new node;
    p2->key[0] = 3;
    p2->key[1] = 5;
    node *p3 = new node;
    p3->key[0] = 8;
    p3->key[1] = 9;
    p->child[0] = p1;
    p->child[1] = p2;
    p->child[2] = p3;
    p1->child[0] = NULL;
    p1->child[1] = NULL;
    p1->child[2] = NULL;
    p2->child[0] = NULL;
    p2->child[1] = NULL;
    p2->child[2] = NULL;
    p3->child[0] = NULL;
    p3->child[1] = NULL;
    p3->child[2] = NULL;
    isB(p, -10000, 10000);
}