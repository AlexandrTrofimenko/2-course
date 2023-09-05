#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

#define INF INT_MAX

// ��������� ��� ������������� ������� �����
struct Node {
    int cost; // ��������� ���� �� �������
    int parent; // �������� �������

    Node() {
        cost = INF;
        parent = -1;
    }
};

// ���������� ��������� ����� ��� ������������ ��������� ������
void MST_Prim(vector<vector<int>>& graph, int startVertex) {
    int n = graph.size(); // ���������� ������ � �����

    vector<bool> visited(n, false); // �������� �� �������
    vector<Node> nodes(n); // ������ ��� �������� ���������� � ������ �������

    nodes[startVertex].cost = 0; // �������� � ��������� ��������� �������

    // ������� ������������ �������, � ������� ������� ������������� �� �� ������� ���������
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, startVertex }); // ��������� ��������� ������� � �������

    while (!pq.empty()) {
        int u = pq.top().second; // �������� ������� � ���������� ����������
        pq.pop();

        visited[u] = true; // �������� �������

        // �������� �� ���� �������� �������� � ��������� �� ���������, ���� ��� ����������
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < nodes[v].cost) {
                nodes[v].cost = graph[u][v];
                nodes[v].parent = u;
                pq.push({ nodes[v].cost, v });
            }
        }
    }

    // ������� ����������� �������� ������
    for (int i = 0; i < n; i++) {
        if (i != startVertex) {
            cout << "�����: " << i << " - " << nodes[i].parent << ", ���������: " << nodes[i].cost << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int num=0; // ���������� ������ �����
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

    vector<vector<int>> graph(num, vector<int>(num));

    cout << "������� ��������� �����:\n";
    in.open("input.txt");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            in >> elem;
            graph[i][j] = elem;
        }
    }
    in.close();
     for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int startVertex=0;
    cout << "������� ��������� �������: ";
    cin >> startVertex;

    MST_Prim(graph, startVertex);

    return 0;
}