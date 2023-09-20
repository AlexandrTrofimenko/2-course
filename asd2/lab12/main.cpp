#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

void kmp_init(int*& prefix,string q)
{
	int len = 0;
	prefix[0] = 0;
	int i = 1;
	while (i < q.length())
	{
		if (q[i] == q[len]) {
			len++;
			prefix[i] = len;
			i++;
		}
		else
			if (len != 0)
			{
				len = prefix[len - 1];
			}
			else {
				prefix[i] = 0;
				i++;
			}
	}
}
void kmp_search(string str,string q)
{
	if (str.length() < q.length())
		exit(1);
	vector<int> k_mas;
	int* prefix = new int[q.length()];
	kmp_init(prefix, q);
	int j = 0, i = 0;
	while (i <= str.length())
	{
		if (q[j] == str[i])
		{
			i++;
			j++;
		}
		if (j == q.length())
		{
			k_mas.push_back(i - j + 1);
			j = prefix[j - 1];
		}
		else if (i <= str.length() && q[j] != str[i])
		{
			if (j == 0)
				i++;
			else
				j = prefix[j - 1];
		}
	}
	if (!k_mas.empty())
	{
		for (auto i : k_mas)
			cout << i << " " << endl;
	}
	else
		cout << "не найдено";

	delete[] prefix;
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
	kmp_search(str, tmp);
	return 0;
}