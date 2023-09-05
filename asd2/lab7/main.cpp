#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

#define INF INT_MAX

// Структура для представления вершины графа
struct Node {
    int cost; // Стоимость пути до вершины
    int parent; // Родитель вершины

    Node() {
        cost = INF;
        parent = -1;
    }
};

// Реализация алгоритма Прима для минимального остовного дерева
void MST_Prim(vector<vector<int>>& graph, int startVertex) {
    int n = graph.size(); // Количество вершин в графе

    vector<bool> visited(n, false); // Посещены ли вершины
    vector<Node> nodes(n); // Массив для хранения информации о каждой вершине

    nodes[startVertex].cost = 0; // Начинаем с выбранной стартовой вершины

    // Создаем приоритетную очередь, в которой вершины отсортированы по их текущей стоимости
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, startVertex }); // Добавляем стартовую вершину в очередь

    while (!pq.empty()) {
        int u = pq.top().second; // Получаем вершину с наименьшей стоимостью
        pq.pop();

        visited[u] = true; // Посещаем вершину

        // Проходим по всем соседним вершинам и обновляем их стоимости, если это необходимо
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < nodes[v].cost) {
                nodes[v].cost = graph[u][v];
                nodes[v].parent = u;
                pq.push({ nodes[v].cost, v });
            }
        }
    }

    // Выводим минимальное остовное дерево
    for (int i = 0; i < n; i++) {
        if (i != startVertex) {
            cout << "Ребро: " << i << " - " << nodes[i].parent << ", Стоимость: " << nodes[i].cost << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int num=0; // Количество вершин графа
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

    cout << "Матрица смежности графа:\n";
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
    cout << "Введите стартовую вершину: ";
    cin >> startVertex;

    MST_Prim(graph, startVertex);

    return 0;
}