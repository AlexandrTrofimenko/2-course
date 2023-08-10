#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct Edge {
	int left, right, weight;
	Edge(int m_left, int m_right, int m_weight)
	{
		left = m_left;
		right = m_right;
		weight = m_weight;
	}
};

int Num = 0;//����� ������
bool* visit;
vector<int>* v;//������ ���������
vector<Edge> g;//������ <�����, ������, ���>
int* parent;//������ ��������

void Quick_Sort(int low, int high, vector<Edge>& x)
{
	if (low >= high)
	{
		return;
	}
	int m = (low + high) / 2 + 1;
	int k = x[m].weight;
	int l = low - 1;
	int r = high + 1;
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
	Quick_Sort(low, l, x);
	Quick_Sort(r, high, x);
}
void Read()
{
	//������� ���� � ������� ������� ������
	int element;
	ifstream in("input.txt");
	if (!in)
		exit(1);
	else
		while (in >> element)
			Num++;
	in.close();
	Num = sqrt(Num);

	//��������� ���� � ���������� ������� �������
	v = new vector<int>[Num];
	in.open("input.txt");
	if (!in)
		exit(1);
	for (int i = 0; i < Num; i++)
		for (int j = 0; j < Num; j++)
		{
			in >> element;
			if (element != 0)
			{
				v[i].push_back(j);
				g.push_back(Edge(i, j, element));
			}
		}
	in.close();

	cout << "\n�������: ������� � ��� \n";
	for (int i = 0; i < Num; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}

	cout << "\n <����� �������, ������ ������� : ����� �����> \n";
	for (int i = 0; i < g.size(); i++)
		cout << "<" << g[i].left << ", " << g[i].right << " : " << g[i].weight << ">" << endl;
}

//����� ��������� ������ �������
int Find_Set(int i)
{
	if (parent[i] == i)
		return i;
	else
		return Find_Set(parent[i]);
}

//����������� ��������� (��-�� ������� u ������ ����� ����� ��-�� ������� v)
void Union(int u, int v)
{
	parent[u] = parent[v];
}

void MST_Kruskal()
{
	parent = new int[Num];
	vector<Edge> MST; //����� �������� ������ ���������� ��������� ������
	for (int i = 0; i < Num; i++)
		parent[i] = i;
	//������������� �� ���� ����� (�� �����������)
	Quick_Sort(0, g.size() - 1, g);

	//���������, ���� ��� ������� ������� �� � ����� ��-��, �� ��������� + ���������� ��-��
	for (int i = 0; i < g.size(); i++)
		if (Find_Set(g[i].left) != Find_Set(g[i].right))
		{
			MST.push_back(g[i]);
			Union(Find_Set(g[i].left), Find_Set(g[i].right));
		}

	ofstream out; out.open("output.txt");
	cout << "\n ����������� �������� ������: \n";
	out << "\n ���� ������ : ��� ����� \n";
	cout << "\n ���� ������ : ��� ����� \n";
	for (int i = 0; i < MST.size(); i++)
	{
		out << i + 1 << ". " << MST[i].left << " - " << MST[i].right << " : " << MST[i].weight << "\n";
		cout << i + 1 << ". " << MST[i].left << " - " << MST[i].right << " : " << MST[i].weight << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Read();
	MST_Kruskal();
	return 0;
}