#include <iostream> 
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include <ostream>
using namespace std;
class Graph
{
public:
	Graph(int n) 
	{
		visiter = new bool[n];
		d = new int[n];
		v = new list <int>[n];
		ifstream in("input.txt");
		int elem;
		if (in.is_open()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					in >> elem;
					if (elem == 1)
						v[i].push_back(j);
				}
			}
		}
		else
			cout << "Файл не найден" << endl;
		in.close();
	}
	~Graph() 
	{
		delete[] visiter;
		delete[] d;
		delete[] v;
	}
	void bfs(int s, vector<int>* Q_m)
	{
		queue <int> Q;
		Q.push(s);
		int u = 0;
		while (!Q.empty())
		{
			u = Q.front();
			visiter[u] = true;
			Q_m->push_back(Q.front());
			Q.pop();
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (!visiter[*i])
				{
					visiter[*i] = true;
					Q.push(*i);
				}
		}
		ofstream out("out.txt");
		for (int i = 0; i < n; i++) {
			out << i << ": " << d[i] << endl;
		}
	}
	void bfs_graph(int& n)
	{
		for (int u = 0; u < n; u++) {
			visiter[u] = false;
		}
		vector<int> time_queue;
		for (int u = 0; u < n; u++) {
			if (!visiter[u]) {
				bfs(u, &time_queue);
			}
			Q.push_back(time_queue);
			time_queue.clear();
		}
		ofstream out("out.txt");
		for (int i = 0; i < Q.size(); i++) {
			if (!Q.empty()) {
				out << i + 1 << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(out, " "));
				out << endl;
			}

		}
	}
private:
	int n;
	bool* visiter;
	int* d;;
	list<int>* v;
	vector<vector<int>> Q;
};



int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите порядок матрицы ";
	int n; cin >> n;
	Graph G(n);
	G.bfs_graph(n);
	return 0;
}