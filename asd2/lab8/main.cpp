#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INF INT_MAX

int find_min(int dist[], bool sptSet[], int num) // минимальное расстояние от а до u
{
	int min = INF;
	int min_index = -1;

	for (int v = 0; v < num; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void Dijkstra(int** x, int num, int src)
{

	int* dist = new int[num];

	bool* sptSet = new bool[num];
	for (int i = 0; i < num; i++) {
		dist[i] = INF;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int j = 0; j < num - 1; j++)
	{
		int u = find_min(dist, sptSet,num);
		sptSet[u] = true;
		for (int v = 0; v < num; v++)
		{
			if (!sptSet[v] && x[u][v] && dist[u] != INT_MAX
				&& dist[u] + x[u][v] < dist[v])
			{
				dist[v] = dist[u] + x[u][v];
				cout << "w2w2w- " << dist[v] << endl;
			}
		}

	}

	cout << "Решение:" << endl;
	for (int i = 0; i < num; i++)
		cout << i << " " << dist[i] << endl;

	delete[] dist;
	delete[] sptSet;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt");
	int num = 0, elem = 0;
	if (!in)
	{
		return 2;
	}
	else
	{
		while (in >> elem)
			num++;
	}
	in.close();
	num = sqrt(num);
	int** graph = new int* [9];
	for (int i = 0; i < num; i++)
		graph[i] = new int[num];
	in.open("input.txt");
	for (int i = 0; i < num; i++)
	{
		for(int j = 0; j < num;j++)
		{ 
			in >> elem;
			graph[i][j] = elem;
		}
	}
	in.close();
	cout << "Вершины (v,u) v - u = Вес" << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	Dijkstra(graph, num,0);

	for (int i = 0; i < num; i++)
		delete graph[i];

	delete[] graph;
	return 0;
}