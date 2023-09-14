#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>

using namespace std;


string nextState(string tmp)
{
	string time = "";
	for (int i = 0; i < tmp.length(); i++)
	{
		if (time.find(tmp[i]) == string::npos)
			time += tmp[i];
	}

	return time;
}

void computeTF(string tmp, int M, int** mas)
{
	int len = 0;
	for (int i = 0; i < M; i++)
	{
		mas[0][i] = 0;
	}
	mas[0][0] = 1;

	for (int i = 1; i < tmp.length() + 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mas[i][j] = mas[len][j];
		}
		mas[i][nextState(tmp).find(tmp[i])] = i + 1;
		len = mas[len][nextState(tmp).find(tmp[i])];
	}


}

void search(string str, string tmp)
{
	if (str.length() < tmp.length())
		exit(1);
	int M = str.size();
	int N = tmp.size();
	int** mas = new int* [M + 1];
	for (int i = 0; i < M + 1; i++)
	{
		mas[i] = new int[256];
	}
	computeTF(str, M, mas);
	int state = 0;
	vector<int> result;
	for (int i = 0; i < M; i++)
	{
		if (nextState(tmp).find(str[i]) == string::npos)
			state = mas[state][nextState(tmp).length()];
		else
			state = mas[state][nextState(tmp).find(str[i])];
		if (state == tmp.length())
			result.push_back(i - tmp.length() + 2);
	}
	if (!result.empty())
	{
		for (auto i : result)
			cout << i << " ";
	}
	else
		cout << "не найдено";


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
	string tmp ="AABA";
	//cout << "¬ведите строку дл€ поискa:"; cin >> tmp; cout << endl;
	search(str, tmp);
	return 0;
}