#include <iostream> 
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include <ostream>
using namespace std;
void bfs(int& n, int s)
{
	int elem;
	bool* visiter = new bool[n];
	int* d = new int[n];

	ifstream in("input.txt");
	list<int>* v = new list <int> [n];
	if (in.is_open()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				in >> elem;
				if(elem == 1)
					v[i].push_back(j);
			}
		}
	}
	else
		cout << "Файл не найден" << endl;
	in.close();

	
	queue <int> Q;
	for (int u = 0; u < n; u++) {
		visiter[u] = false;
		d[u] = -1;
	}

	d[s] = 0;
	visiter[s] = true;
	Q.push(s);
	int u = 0;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (auto i = v[u].begin(); i != v[u].end(); i++) {
			if (!visiter[*i]) {
				visiter[*i] = true;
				d[*i] = d[u] + 1;
				Q.push(*i);
			}
		}
	}
	ofstream out("out.txt");
	for (int i = 0; i < n; i++) {
		out << i << ": " << d[i] << endl;
	}
	delete[] visiter;
	delete[] d;
	delete[] v;
} 


int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите порядок матрицы ";
	cin >> n;
	bfs(n, 0);
	return 0;
}