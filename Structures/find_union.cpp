#include <iostream>
using namespace std;
const int n = 5;
const int m = 6;

struct node
{
  bool val;
  node *parent;
  int rank;
};

node *make_set(bool v)
{
  node *r = new node;
  r->parent = r;
  r->val = v;
  r->rank = 0;
  return r;
}

node *find(node *x)
{
  if (x->parent != x)
  {
    node *y = find(x->parent);
    x->parent = y;
    return y;
  }
  else
    return x;
}

void unionPoint(node *p1, node *p2)
{
  node *r1 = find(p1);
  node *r2 = find(p2);
  if (r2->rank < r1->rank)
    r2->parent = r1;
  else
  {
    r1->parent = r2;
    if (r1->rank == r2->rank)
      r1->rank++;
  }
}

int get_rank(bool t[][n], int x, int y)
{
  node *tab[m][n];
  int count = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      tab[i][j] = make_set(t[i][j]);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      if (t[i][j])
      {
        if (j + 1 < n && tab[i][j + 1]->val)
          unionPoint(tab[i][j], tab[i][j + 1]);
        if (j - 1 >= 0 && tab[i][j - 1]->val)
          unionPoint(tab[i][j], tab[i][j - 1]);
        if (i + 1 < m && tab[i + 1][j]->val)
          unionPoint(tab[i][j], tab[i + 1][j]);
        if (i - 1 >= 0 && tab[i - 1][j]->val)
          unionPoint(tab[i][j], tab[i - 1][j]);
      }
    }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (find(tab[i][j]) == find(tab[y][x]))
        count++;

  count--;
  return count;
}

int main()
{

  bool t[m][n] = {
      {0, 1, 1, 0, 0},
      {1, 1, 0, 1, 1},
      {1, 1, 1, 0, 0},
      {0, 1, 0, 0, 0},
      {1, 1, 0, 1, 0},
      {0, 1, 1, 1, 0}};

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << t[i][j] << "  ";
    }
    cout << endl;
  }
  cout << get_rank(t, 2, 0);
  cout << endl;
}
