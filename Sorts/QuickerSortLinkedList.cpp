#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *QuickerSort(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *lesser, *equal, *greater, *l, *e, *g, *ret, *retTail;
    lesser = new Node;
    equal = new Node;
    greater = new Node;
    lesser->next = equal->next = greater->next = NULL;
    l = lesser;
    e = equal;
    g = greater;
    int c = head->val;

    while (head != NULL)
    {
        if (head->val == c)
        {
            e->next = head;
            head = head->next;
            e = e->next;
            e->next = NULL;
        }
        else
        {
            if (head->val < c)
            {
                l->next = head;
                head = head->next;
                l = l->next;
                l->next = NULL;
            }
            else
            {
                g->next = head;
                head = head->next;
                g = g->next;
                g->next = NULL;
            }
        }
    }

    lesser->next = QuickerSort(lesser->next);
    greater->next = QuickerSort(greater->next);
    ret = new Node;
    ret->next = NULL;
    retTail = ret;

    ret->next = lesser->next;
    while (retTail->next != NULL)
    {
        retTail = retTail->next;
    }

    retTail->next = equal->next;
    while (retTail->next != NULL)
    {
        retTail = retTail->next;
    }

    retTail->next = greater->next;

    retTail = ret->next;
    delete lesser;
    delete equal;
    delete greater;
    delete ret;
    return retTail;
}
void addNode(Node *h, int val)
{
    Node *tmp = new Node;
    tmp->next = h->next;
    tmp->val = val;
    h->next = tmp;
}

//Dla listy z straznikiem
Node *buildList(int i, int range)
{
    Node *head = new Node;
    head->next = NULL;
    srand(time(NULL));
    for (i; i >= 0; i--)
    {
        addNode(head, rand() % range);
    }
    return head;
}

void print(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "  ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *a = buildList(10, 50);
    print(a);
    a = QuickerSort(a);
    print(a);
}