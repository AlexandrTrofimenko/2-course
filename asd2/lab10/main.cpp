#include <iostream>
#include <vector>
#include <stack>
#include <fstream>


using namespace std;
bool isConnected(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<bool> visited(n, false);

	stack<int> stack;
	stack.push(0);
	visited[0] = true;

	int count = 1;
	while (!stack.empty()) {
		int vertex = stack.top();
		stack.pop();

		for (int i = 0; i < n; i++) {
			if (graph[vertex][i] != 0 && !visited[i]) {
				stack.push(i);
				visited[i] = true;
				count++;
			}
		}
	}

	return count == n;
}
void EulerCycle(vector<vector<int>>& graph,int startVertex) {

	int n = graph.size();
	stack<int> eulerCycle;
	vector<int> degree(n, 0);

	eulerCycle.push(startVertex);

	while (!eulerCycle.empty()) {
		int vertex = eulerCycle.top();
		int i;

		for (i = 0; i < n; i++) {
			if (graph[vertex][i] != 0) {
				break;
			}
		}

		if (i == n) {
			eulerCycle.pop();
			cout << vertex << " ";
		}
		else {
			degree[vertex]--;
			degree[i]--;

			graph[vertex][i] = 0;
			graph[i][vertex] = 0;

			eulerCycle.push(i);
		}
	}

	cout << endl;

}


int main()
{
	
	ifstream in("input.txt");
	int elem = 0, num = 0;
	if (!in)
		return 2;
	else {
		while (in >> elem)
			num++;
	}
	in.close();
	num = sqrt(num);
	vector<vector<int>> Graph(num);
	in.open("input.txt");
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			in >> elem;
			Graph[i].push_back(elem);
		}
	}
	in.close();
	EulerCycle(Graph, 0);
	return 0;
}