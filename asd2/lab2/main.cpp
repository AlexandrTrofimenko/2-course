#include <iostream> 
#include <vector>
#include <fstream>
using namespace std;

void bfs()
{

}


int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt");
	vector <int> arr; int elem;
	if (in.is_open()) {
		while(!in.eof()) {
			in >> elem; arr.push_back(elem);
		}
	}
	
	else {
		cout << "Файл не найден" << endl;
	}
	in.close();
	for (auto i : arr) {
		cout << i + 5 << " ";
	}

	return 0;
}