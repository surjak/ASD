#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment
{
	int town, travel_time;
} Segment;

typedef struct Line
{
	Segment *segments;
	int number, length, start_town;
} Line;

Line *newLine(int number, int length, int start_town)
{
	Line *l = new Line;
	l->number = number;
	l->length = length;
	l->start_town = start_town;
	l->segments = new Segment[length];
	return l;
}

typedef struct Node
{
	int town, id;
	vector<pair<Node *, int>> neighbours;
} Node;

int **calculateTimesMatrix(Line **lines, int lines_no, int towns)
{

	int **d = new int *[towns];

	for (int i = 0; i < towns; i++)
	{
		d[i] = new int[towns];
	}

	for (int i = 0; i < towns; i++)
	{
		for (int j = 0; j < towns; j++)
		{
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < lines_no; i++)
	{
		int u = lines[i]->start_town;
		for (int j = 0; j < lines[i]->length; j++)
		{
			int v = lines[i]->segments[j].town;
			if (d[u][v] > lines[i]->segments[j].travel_time)
				d[u][v] = lines[i]->segments[j].travel_time;
			if (d[v][u] > lines[i]->segments[j].travel_time)
				d[v][u] = lines[i]->segments[j].travel_time;
			u = v;
		}
	}

	for (int u = 0; u < towns; u++)
		for (int v1 = 0; v1 < towns; v1++)
			for (int v2 = 0; v2 < towns; v2++)
			{
				if (d[v1][v2] > d[v1][u] + d[u][v2])
					d[v1][v2] = d[v1][u] + d[u][v2];
			}
	return d;
}

int main()
{
	int towns, lines_no, queries;
	cin >> towns >> lines_no >> queries;
	Line **lines = new Line *[lines_no];
	for (int i = 0; i < lines_no; i++)
	{
		int len, start;
		cin >> len >> start;
		lines[i] = newLine(i, len - 1, start);
		for (int j = 0; j < len - 1; j++)
		{
			int next, time;
			cin >> time >> next;
			lines[i]->segments[j].town = next;
			lines[i]->segments[j].travel_time = time;
		}
	}

	int **times = calculateTimesMatrix(lines, lines_no, towns);

	for (int i = 0; i < queries; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << times[u][v] << endl;
	}

	for (int i = 0; i < towns; i++)
		delete[] times[i];
	delete[] times;
	for (int i = 0; i < lines_no; i++)
	{
		delete[] lines[i]->segments;
		delete lines[i];
	}
	delete[] lines;
}
