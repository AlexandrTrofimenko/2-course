#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class HashTable
{
public:
    HashTable()
    {
        list<string>* p = new list<string>;

        for (int i = 0; i < size_table; i++)
            table.push_back(*p);
        delete p;
    }

    ~HashTable()
    {

    }

    int HashFunction(string str)
    {
        int Sum = 0;
        for (int i = 0; i < str.length(); i++)
            Sum += int(str[i]);

        return Sum % size_table;
    }

    void AddToTable(string str)
    {
        table[HashFunction(str)].push_back(str);
    }

    void AddInTable()
    {
        ifstream in; in.open("input.txt");

        char vhod = ' '; string str = "";
        while (!in.eof())
        {
            in.get(vhod);
            if ((vhod == ' ' || vhod == '\n') && !str.empty())
            {
                AddToTable(str);
                str.clear();
            }
            else
                str += vhod;
        }
        in.close();
        if (!str.empty())
            AddToTable(str);

    }

    void Out_Table()
    {
        for (int i = 0; i < size_table; i++)
        {
            if (!table[i].empty())
            {
                cout << i + 1 << " -> ";
                copy(table[i].begin(), table[i].end(), ostream_iterator<string>(cout, " "));
                cout << endl;
            }
        }
    }

private:
    static const int size_table = 37;
    vector< list< string > > table;
};
int main()
{
    HashTable table;
    table.AddInTable();
    table.Out_Table();

    return 0;
}