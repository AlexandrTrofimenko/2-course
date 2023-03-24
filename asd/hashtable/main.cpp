#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define N 97 // Простое число, размер таблицы
class Hashtable
{
	int hashfunc(string str)
	{
		int sum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			sum += int(str[i]);
		}
		return sum % N;
	}
public:
	
	Hashtable()
	{
		for (int i = 0; i < N; i++)
		{
			m_table[i] = "";
		}
	
	}
	void AddTable(string str)
	{
		if (elements() >= N)
		{
			return;
		}
		int i = hashfunc(str);
		while (i < N)
		{
			if (m_table[i].empty())
			{
				m_table[i] = str;
				return;
			}
			else
			{
				i++;
			}
		}
	}
	void AddinTable()
	{
		ifstream file("input.txt");
		char in = ' '; string str = "";
		if (!file)
		{
			cout << "Файла не существует";
			return;
		}
		while (!file.eof())
		{
			file.get(in);
			if ((in == ' ' || in == '\n') && !str.empty())
			{
				AddTable(str);
				str = "";
			}
			else
			{
				str += in;
			}
				 
		}
		if (!str.empty())
		{
			cout << str << endl;
			AddTable(str);
		}
		file.close();
	}
	void PrintTable()
	{
		ofstream out("output.txt");
		for (int i = 0; i < N; i++)
		{
			if (!m_table[i].empty())
			{
				cout << i + 1 << " - " << m_table[i] << endl;
				out << i + 1 << " - " << m_table[i] << endl;
			}
		}
	}
	int Find(string str)
	{
		for (int i = 0; i < N; i++)
		{
			if (m_table[i] == str)
			{
				cout << "Find" << endl;
				return i;
			}
		}
		return 0;
	}
	void DeleteStr(string str)
	{
		for (int i = 0; i < N; i++)
		{
			if (m_table[i] == str)
			{
				m_table[i] = "Deleted user";
			}
		}
	}
	~Hashtable()
	{
		//cout << "Delete";
	}
	int elements()
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (!m_table[i].empty())
			{
				sum++;
			}
		}
		return sum;
	}
private:
	string m_table[N];
};
int main()
{
	setlocale(LC_ALL, "Rus");
	Hashtable table;
	table.AddinTable();
	table.PrintTable();
	table.Find("Polina");
	table.DeleteStr("Sasha");
	table.PrintTable();
	table.Find("Sasha");
	return 0;
}