#include <C:\Users\surja\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\mingw32\bits\stdc++.h>

using namespace std;

struct node
{
    double val;
    node *next;

};

void push(node *&head, double key)
{
    node *tmp = new node;
    tmp->val = key;
    tmp->next = head;
    head = tmp;
}

void printL(node *head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
}

void sortedInsert(node *&head, node *list)
{
    node *current;
    if (head == nullptr or head->val >= list->val)
    {
        list->next = head;
        head = list;
    }
    else
    {
        current = head;
        while (current->next != nullptr and current->next->val < list->val)
            current = current->next;

        list->next = current->next;
        current->next = list;
    }
}

node *sortList(node *L)
{
    int n = 0;
    node *tmp = L;
    while (tmp != nullptr)
    {
        n++;
        tmp = tmp->next;
    }
    node *arr[4 * n];
    for (int i = 0; i < 4 * n; i++)
        arr[i] = nullptr;

    tmp = L;
    while (tmp != nullptr)
    {
        int idx = n * tmp->val;
        if (!arr[idx])
        {
            arr[idx] = tmp;
            tmp = tmp->next;
            arr[idx]->next = nullptr;
        }
        else
        {
            node *ptr = tmp->next;
            sortedInsert(arr[idx], tmp);
            tmp = ptr;
        }
    }

    L = nullptr;
    tmp = nullptr;
    for (int i = 0; i < 4 * n; i++)
    {
        if (arr[i] != nullptr)
        {
            if (L == nullptr)
            {
                L = arr[i];
                tmp = L;
            }
            else
            {
                tmp->next = arr[i];
            }
            while (tmp->next != nullptr)
                tmp = tmp->next;
        }
    }

    return L;
}

int main()
{
    node *list = new node;
    list->val = 0.45;
    list->next = nullptr;

    push(list, 0.34);
    push(list, 2.12);
    push(list, 3.56);
    push(list, 3.76);
    push(list, 2.78);
    push(list, 1.34);
    push(list, 1.89);
    printL(list);
    cout << "\n";
    list = sortList(list);
    printL(list);

    return 0;
}