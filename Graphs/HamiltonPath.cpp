#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int val;
    node *next;
};
const int N = 4;
node *G[N];
bool used[N];
stack<int> S;

bool DFS(int v, node **G, int counter, int N)
{
    if (counter == N)
        return true;

    for (node *p = G[v]; p != NULL; p = p->next)
        if (!used[p->val])
        {
            used[p->val] = true;
            if (DFS(p->val, G, counter + 1, N))
                return true;
            used[p->val] = false;
        }
    return false;
}

bool checkPath(node **G, int N)
{
    for (int i = 0; i < N; i++)
        used[i] = false;

    for (int i = 0; i < N; i++)
    {
        used[i] = true;
        if (DFS(i, G, 1, N))
            return true;
        used[i] = false;
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        node *e = new node;
        e->val = i;
        e->next = NULL;
        G[i] = e;
    }
    node *a = new node;

    a->val = 1;

    a->next = NULL;

    G[0]->next = a;
    node *c = new node;
    c->val = 3;
    c->next = NULL;
    node *b = new node;
    b->val = 2;
    b->next = NULL;
    G[1]->next = b;

    G[1]->next->next = c;
    G[3]->next = NULL;

    cout << checkPath(G, N);
}