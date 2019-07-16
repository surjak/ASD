#include <bits\stdc++.h>
using namespace std;

struct node
{
    double val;
    node *next;
};

node *getTail(node *head)
{
    while (head != nullptr and head->next != nullptr)
        head = head->next;
    return head;
}

node *partition(node *head, node *end, node **newHead, node **newEnd)
{

    node *pivot = end;
    node *prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->val < pivot->val)
        {
            if (*newHead == nullptr)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            node *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (*newHead == nullptr)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

node *quicksortRec(node *head, node *end)
{

    if (!head or head == end)
        return head;

    node *newHead = nullptr, *newEnd = nullptr;
    node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quicksortRec(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quicksortRec(pivot->next, newEnd);

    return newHead;
}

void quicksort(node **head)
{
    *head = quicksortRec(*head, getTail(*head));
    return;
}

void push(node *&head, double key)
{
    node *tmp = new node;
    tmp->val = key;
    tmp->next = head;
    head = tmp;
}

void push_back(node *&head, int key)
{
    node *p = new node;
    p->val = key;
    p->next = nullptr;
    if (head == nullptr)
    {
        head = p;
        return;
    }
    node *tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = p;
}

node *reverse(node *list)
{

    node *prev = nullptr;
    node *curr = list;
    node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printL(node *head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}

void swap(node *head, node *one, node *two)
{

    node *prev1 = head;
    node *prev2 = head;
    while (prev1->next != one)
        prev1 = prev1->next;
    while (prev2->next != two)
        prev2 = prev2->next;
    node *tmp = one->next;
    one->next = two->next;
    two->next = tmp;
    prev1->next = two;
    prev2->next = one;
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

node *insertionSort(node *head)
{
    node *sorted = nullptr;
    node *current = head;
    while (current != nullptr)
    {
        node *next = current->next;
        sortedInsert(sorted, current);
        current = next;
    }
    return sorted;
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
            tmp->next = arr[idx];
            arr[idx] = tmp;
            tmp = ptr;
        }
    }

    for (int i = 0; i < 4 * n; i++)
    {
        if (arr[i] != nullptr)
            arr[i] = insertionSort(arr[i]);
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
    list = sortList(list);
    printL(list);
    /*printL(list);
    swap(list, p1, p2);
    cout<<"\n";
    printL(list);
    
    list = reverse(list);
    
    cout << "\n";
    
    printL(list);
    quicksort(&list);
    cout << "\n";
    printL(list);*/
    return 0;
}