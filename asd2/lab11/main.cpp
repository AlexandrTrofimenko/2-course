#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>

using namespace std;


int nextState(string tmp, int M, int state, int x)
{
	if (state < M && x == tmp[state])
		return state + 1;

	for (int ns = state; ns > 0; ns--)
	{
		if (tmp[ns - 1] == x)
		{
			for (int i = 0; i < ns - 1; i++)
			{
				if (tmp[i] != tmp[state - ns + 1 + i])
					break;

				if (i == ns - 1)
					return ns;
			}
		}
	}
	return 0;
}

void computeTF(string tmp, int M, int** mas)
{
	for (int state = 0; state <= M; state++)
		for (int x = 0; x < 256; x++)
			mas[state][x] = nextState(tmp, M, state, x);
}

void search(string str, string tmp)
{
	int M = str.size();
	int N = tmp.size();
	int** mas = new int* [M + 1];
	for (int i = 0; i < M + 1; i++)
	{
		mas[i] = new int[256];
	}
	computeTF(tmp, M, mas);
	int state = 0;
	for (int i = 0; i < N; i++)
	{
		state = mas[state][tmp[i]];
		if (state == M)
			cout << "Найдено сходство " << i - M + 1 << endl;
	}

	for (int i = 0; i < M; i++)
		delete[] mas[i];
	delete[] mas;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt");
	string str; int num = 0;
	if (!in)
		return 2;
	else {
		while (in >> str)
			num++;
	}
	in.close();
	in.open("input.txt");
	in >> str;
	in.close();
	cout << str << endl;
	string tmp ="AAA";
	//cout << "Введите строку для поискa:"; cin >> tmp; cout << endl;
	search(str, tmp);
	return 0;
}