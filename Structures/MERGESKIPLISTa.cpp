#include <iostream>
#include <ctime>
#include <limits>
#include <cstdlib>
using namespace std;
const int min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();
int find_level(int max)
{
	int level = 1;
	int i = rand() % 10000;
	while (i <= 5000)
	{
		level++;
		i = rand() % 10000;
	}
	if (level > max)
		return max;
	else
		return level;
}
struct SLnode
{
	int val;
	SLnode **next;
	int lvl;
};
struct skiplist
{
	SLnode *first;
	int max_level;
};

skiplist create_skiplist(int max_level)
{
	skiplist S;
	S.max_level = max_level;
	S.first = new SLnode;
	S.first->val = min_int;
	S.first->lvl = S.max_level;
	S.first->next = new SLnode *[S.max_level];
	SLnode *tmp = new SLnode;
	tmp->lvl = max_level;
	tmp->val = max_int;
	tmp->next = new SLnode *[S.max_level];
	for (int i = S.max_level - 1; i >= 0; i--)
	{
		S.first->next[i] = tmp;
		tmp->next[i] = NULL;
	}
	return S;
}

void add(skiplist S, int n)
{
	SLnode *tmp = new SLnode;
	tmp->lvl = find_level(S.max_level);
	tmp->next = new SLnode *[tmp->lvl];
	tmp->val = n;
	for (int p = S.max_level - 1; p >= 0; p--)
	{
		while (S.first->next[p]->val < n)
			S.first = S.first->next[p];
		if (tmp->lvl > p)
		{
			tmp->next[p] = S.first->next[p];
			S.first->next[p] = tmp;
		}
	}
}
skiplist merge(skiplist A, skiplist B)
{
	if (A.first->next[0]->val == max_int)
		return B;
	if (B.first->next[0]->val == max_int)
		return A; // warunki konca moze kiedys przyda sie do merge sorta
	skiplist F = create_skiplist(A.max_level);
	SLnode **tmp = new SLnode *[F.max_level];
	SLnode *tmp2;
	for (int i = F.max_level - 1; i >= 0; i--)
		tmp[i] = F.first; // ustawiam tablice wskazniczkow na poczatek
	while (A.first->next[0] != NULL && B.first->next[0] != NULL)
	{ // na koncu jest + nsk wybierajac zawsze mniejsza badz rowna wartosc wkoncu przepniemy jedna nieskonczonosc i zostanie nam NULL
		if (A.first->next[0]->val < B.first->next[0]->val)
		{ // wybieram mniejsza wartosc
			for (int i = F.max_level - 1; i >= 0; i--)
			{
				if (A.first->next[0]->lvl > i)
				{ // i tutaj lece od g�ry i jesli nalezy przepi�� dany poziom aktualizuje wskazniczek w tablicy na konkretnym poziomie
					tmp2 = A.first->next[0];
					A.first->next[i] = A.first->next[i]->next[i];
					tmp2->next[i] = tmp[i]->next[i];
					tmp[i]->next[i] = tmp2;
					tmp[i] = tmp[i]->next[i];
				}
			}
		}
		else
		{ // to samo
			for (int i = F.max_level - 1; i >= 0; i--)
			{
				if (B.first->next[0]->lvl > i)
				{
					tmp2 = B.first->next[0];
					B.first->next[i] = B.first->next[i]->next[i];
					tmp2->next[i] = tmp[i]->next[i];
					tmp[i]->next[i] = tmp2;
					tmp[i] = tmp[i]->next[i];
				}
			}
		}
	}
	return F;
}

skiplist mergee(skiplist A, skiplist B)
{
	if (A.first->next[0]->val == max_int)
		return B;
	if (B.first->next[0]->val == max_int)
		return A;
	skiplist F = create_skiplist(A.max_level);

	SLnode **tmp = new SLnode *[F.max_level];

	SLnode *tmp2;

	for (int i = F.max_level - 1; i >= 0; i--)

		tmp[i] = F.first;
	while (A.first->next[0] != NULL && B.first->next[0] != NULL)
	{
		if (A.first->next[0]->val < B.first->next[0]->val)
		{
			for (int i = F.max_level - 1; i >= 0; i--)
			{
				if (A.first->next[0]->lvl > i)
				{
					tmp2 = A.first->next[0];
					A.first->next[i] = A.first->next[i]->next[i];
					tmp2->next[i] = tmp[i]->next[i];
					tmp[i]->next[i] = tmp2;
					tmp[i] = tmp[i]->next[i];
				}
			}
		}
		else
		{ // to samo
			for (int i = F.max_level - 1; i >= 0; i--)
			{
				if (B.first->next[0]->lvl > i)
				{
					tmp2 = B.first->next[0];
					B.first->next[i] = B.first->next[i]->next[i];
					tmp2->next[i] = tmp[i]->next[i];
					tmp[i]->next[i] = tmp2;
					tmp[i] = tmp[i]->next[i];
				}
			}
		}
	}

	return F;
}

int main()
{
	srand(time(NULL));
	skiplist A = create_skiplist(5);
	skiplist B = create_skiplist(5);
	add(A, 23);
	add(A, 3);
	add(A, 16);
	add(A, 0);
	add(A, 13);
	add(A, 234);
	add(A, 3);
	add(A, 2);
	add(B, 9);
	add(B, 9324);
	add(B, 9857);
	add(B, 9473);
	add(B, 93);
	add(B, 1);
	add(B, 4);
	add(B, 43);
	add(B, 5);
	cout << "A" << endl;
	SLnode *tmp3, *tmp4;
	tmp3 = A.first;
	tmp4 = B.first;
	while (A.first->next[0]->val != max_int)
	{
		A.first = A.first->next[0];
		for (int i = A.first->lvl - 1; i >= 0; i--)
			cout << A.first->val << ";";
		cout << endl;
	}
	cout << endl
		 << "B" << endl;
	while (B.first->next[0]->val != max_int)
	{
		B.first = B.first->next[0];
		for (int i = B.first->lvl - 1; i >= 0; i--)
			cout << B.first->val << ";";
		cout << endl;
	}
	A.first = tmp3;
	B.first = tmp4;
	skiplist C = mergee(A, B);
	cout << endl
		 << "C" << endl;
	while (C.first->next[0]->val != max_int)
	{
		C.first = C.first->next[0];
		for (int i = C.first->lvl - 1; i >= 0; i--)
			cout << C.first->val << ";";
		cout << endl;
	}
}
