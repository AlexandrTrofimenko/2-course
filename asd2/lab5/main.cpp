#include <iostream>
#include <fstream>
#include <list>
#include <time.h>
#include <vector>

using namespace std;
class Graph
{
public:
	Graph(int n) // инициализация
	{
		num = n;
		v = new vector<int>[n];
		visited = new bool[n];
		v1 = new vector<int>[n];
		for (int i = 0; i < n; i++)
		{
			t.push_back(0);
		}
	}
	~Graph()
	{
		delete[] v;
		delete[] visited;
		delete[] v1;
	} 
	void addEdge()  // чтение из файла 
	{
		int tmp;
		ifstream in("input.txt");
		if (in.is_open()) {
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					in >> tmp;
					v[i].push_back(tmp);
				}
			}
		}
		else
			cout << "Файл не найден" << endl;
		in.close();
	}
	void printGraph() // запись в файл, вывод
	{
		for (int i = 0; i < num; i++) {
			cout << i << ":";
			copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		ofstream out("output.txt");
		for (int i = 0; i < num; i++) {
			out << i << ":";
			copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			out << endl;
		}
	}
	// поиск dfs
	void find(int u) 
	{
		visited[u] = true;
		t[u] = ++time;
		for (auto i = v[u].begin(); i != v[u].end(); i++) {
			if (!visited[*i]) {
				find(*i);
			}
		}
		t[u] = time++;
	}
	void DFS()
	{
		for (int u = 0; u < num; u++)
			visited[u] = false;

		for (int u = 0; u < num; u++)
		{
			if (!visited[u])
			{
				find(u);
			}
		}
	}
	// Инвертирование ребер
	void Invers()
	{
		int** mas = new int* [num];
		for (int i = 0; i < num; i++)
			mas[i] = new int[num];

		int element;
		ifstream in("input.txt");
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				in >> mas[j][i];
		in.close();

		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				if (mas[i][j] == 1)
					v1[i].push_back(j);

		cout << " Inversion vers: \n";
		for (int i = 0; i < num; i++)
		{
			cout << i << ": "; copy(v1[i].begin(), v1[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}

		for (int i = 0; i < num; i++)
			delete[] mas[i];
		delete[] mas;
	}
	int MAXX(vector<int> mas)
	{
		int maxs = -1;
		for (int i = 0; i < mas.size(); i++)
			if (mas[i] > maxs)
				maxs = mas[i];
		return maxs;
	}
	// поиск в глубину с учитыванием таймера ( по убыванию ) 
	void Find_for_DFSwM(int u, vector<int>* Q_m)
	{
		visited[u] = true;
		for (int i = 0; i < v1[u].size(); i++)
			if (!visited[v1[u][i]])
				Find_for_DFSwM(v1[u][i], Q_m);
		Q_m->push_back(u);

		t[u] = 0;
	}
	// поиск в глубину с учётом времени выхода по убыванию 
	void DFS_with_max()
	{
		vector<vector<int>> Q;
		for (int u = 0; u < num; u++)
			visited[u] = false;

		vector<int> time_queue;

		for (int i = 0; i < num; i++)
			for (int u = 0; u < num; u++)
			{
				if (!visited[u] && t.at(u) == MAXX(t))
					Find_for_DFSwM(u, &time_queue);

				Q.push_back(time_queue);
				time_queue.clear();
			}

		ofstream out("output.txt");
		out << "Сильно связанные компоненты: \n";
		cout << "Сильно связанные компоненты: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				for (int j = 0; j < Q[i].size(); j++)
				{
					out << Q[i][j] << " ";
					cout << Q[i][j] << " ";
				}
				out << endl;
				cout << endl;
			}
		}
	}
	void Kosaradju()
	{
		DFS();
		Invers();
		DFS_with_max();
	}
	
private:
	vector<int> *v;
	vector<int>* v1;
	int num;
	bool* visited;
	int time = 0;
	vector<int> t;
	vector<vector<int>> Q;
};




int main()
{
	setlocale(LC_ALL, "Rus");
	Graph g(8);
	g.addEdge();
	g.Kosaradju();
	return 0;
}