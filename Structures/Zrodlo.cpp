#include <iostream>
using namespace std;

struct queue
{
	int start, end, size;
	int elements[];
};

/****************************
* implement functions below *
****************************/

void put(queue *q, int value)
{

	q->elements[q->end] = value;
	q->end++;
	if (q->end == q->size)
		q->end = 0;
	if (q->end == q->start)
	{
		cout << "przepelniona";
		q->end = q->size - 1;
	}
}
int get(queue *q)
{

	q->start++;
	if (q->start == q->size)
	{
		q->start = 0;
		return q->elements[q->size - 1];
	}
	return q->elements[q->start - 1];
}

bool is_empty(queue *q)
{
	return (q->start == q->end);
}

int main()
{
	queue *Q = new queue;
	Q->size = 100;
	Q->start = 0;
	Q->end = 0;
	put(Q, 12);
	put(Q, 13);

	put(Q, 11);

	put(Q, 3);
	put(Q, 2);
	put(Q, 12);
	for (size_t i = 0; i < 10; i++)
	{
		/* code */ cout << get(Q) << " ";
	}
}