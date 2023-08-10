#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct Edge {
	int left, right, weight;
	Edge(int m_left, int m_right, int m_weight) {
		left = m_left;
		right = m_right;
		weight = m_weight;
	}
};
vector<int>* v;
vector<Edge> edge;
int num = 0;
int* mass;

void read() {

	ifstream in("input.txt");
	int elem;
	if (!in) {
		cout << "Smth wrong with file";
		exit(1);
	}
	else {
		while (in >> elem) {
			num++;
		}
	}
	in.close();
	num = sqrt(num);
	v = new vector<int>[num];
	in.open("input.txt");
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			in >> elem;
			if (elem != 0) {
				v[i].push_back(j);
				edge.push_back(Edge(i, j, elem));
			}
		}
	}
	in.close();
	cout << endl << "Вершины смежные с ней" << endl;
	for (int i = 0; i < num; i++) {
		cout << i << ":";
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < edge.size(); i++) {
		cout << "<" << edge[i].left << ", " << edge[i].right << ";" << edge[i].weight << ">" << endl;
	}
}

void Quick_sort(int left, int right, vector<Edge>& x) {
	if (left >= right)
		return;
	int m = (left + right) / 2 + 1;
	int k = x[m].weight;
	int l = left - 1;
	int r = right + 1;
	while (1)
	{
		do
		{
			l++;
		} while (x[l].weight < k);
		do
		{
			r--;
		} while (x[r].weight > k);
		if (l >= r)
		{
			break;
		}
		swap(x[l], x[r]);
	}
	r = l;
	l--;
	Quick_sort(left, l, x);
	Quick_sort(r, right, x);
}

void Union(int u, int v) {
	mass[u] = mass[v];
}

int Find_Set(int item) {
	if (item == mass[item]) {
		return item;
	}
	else {
		return Find_Set(mass[item]);
	}
}
void Make_Set(int i) {
	mass[i] = i;
}
void MST_Kruskal() {
	mass = new int[num];
	vector<Edge> mst;
	for (int i = 0; i < num; i++)
		Make_Set(i);

	Quick_sort(0, edge.size() - 1, edge);
	for (int i = 0; i < edge.size() - 1; i++) {
		if (Find_Set(edge[i].left) != Find_Set(edge[i].right)) {
			mst.push_back(edge[i]);
			Union(Find_Set(edge[i].left),Find_Set(edge[i].right));
		}
	}
	ofstream out("output.txt");
	cout << "\n Минимальное остовное дерево: \n";
	out << "\n Пара вершин : вес ребра \n";
	cout << "\n Пара вершин : вес ребра \n";
	for (int i = 0; i < mst.size(); i++)
	{
		out << i + 1 << ". " << mst[i].left << " - " << mst[i].right << " : " << mst[i].weight << "\n";
		cout << i + 1 << ". " << mst[i].left << " - " << mst[i].right << " : " << mst[i].weight << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	read();
	MST_Kruskal();
	return 0;
}