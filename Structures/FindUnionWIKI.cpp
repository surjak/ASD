#include <iostream>
using namespace std;
const int n = 5, m = 6;

struct point2
{
    int val;
    int rx, ry;
    point2 *rep;
};

void MakeSet(point2 *&item, bool val)
{
    item = new point2;
    item->rep = item;
    item->val = val;
}

point2 *find(point2 *item)
{
    return item->rep;
}

void unionPoint(point2 *item1, point2 *item2, point2 *B[m][n])
{
    point2 *r1 = find(item1);
    point2 *r2 = find(item2);
    if (r1 != r2)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (B[i][j]->rep == r2)
                    B[i][j]->rep = r1;
            }
    }
}

int check(point2 *tab[m][n], int py, int px)
{
    int counter = 0;
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
        {
            if (((y + 1) < m) && tab[y + 1][x]->val && tab[y][x]->val)
                unionPoint(tab[y + 1][x], tab[y][x], tab);
            if (((y - 1) >= 0) && tab[y - 1][x]->val && tab[y][x]->val)
                unionPoint(tab[y - 1][x], tab[y][x], tab);
            if (((x + 1) < n) && tab[y][x + 1]->val && tab[y][x]->val)
                unionPoint(tab[y][x + 1], tab[y][x], tab);
            if (((x - 1) >= 0) && tab[y][x - 1]->val && tab[y][x]->val)
                unionPoint(tab[y][x - 1], tab[y][x], tab);
        }

    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
        {
            if (find(tab[y][x]) == find(tab[py][px]))
                counter++;
        }
    return counter - 1;
}

int main()
{
    int val;
    point2 *tab[m][n];
    bool t[m][n] = {
        {0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}};
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
        {

            MakeSet(tab[y][x], t[y][x]);
        }
    cout << endl;
    cout << check(tab, 0, 2);
}