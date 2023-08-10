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
	Graph(int& n) 
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
	void dfs(int u, vector<int>* Q_m)
	{
		visiter[u] = true;
		for (auto i = v[u].begin(); i != v[u].end(); i++) {
			if (!visiter[*i])
				dfs(*i,Q_m);
		}
		Q_m->push_back(u);
	}
	void find_graph(int n)
	{
		
		for (int u = 0; u < n; u++)
			visiter[u] = false;


		vector<int> time_queue;
		for (int u = 0; u < n; u++)
		{
			if (!visiter[u])
				dfs(u, &time_queue);

			Q.push_back(time_queue);
			time_queue.clear();
		}
	}
	void printGraph(int n)
	{
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}

		ofstream out("output.txt");
		out << "Компонент связности: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				out << i << ": ";
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
	G.find_graph(n);
	G.printGraph(n);
	return 0;
}