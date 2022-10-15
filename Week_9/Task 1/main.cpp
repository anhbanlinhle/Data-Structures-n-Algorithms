#include "Libs.h"
using namespace std;

void visit(vector<int> graph[], int index, bool check[])
{
    for (int i = 0; i < graph[index].size(); i++)
    {
        int temp = graph[index][i];
        if (check[temp] == 0)
        {
            visit(graph, temp, check);
            check[temp] = 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];

    int node, neighbour;

    for (int i = 0; i < m; i++)
    {
        cin >> node >> neighbour;
        graph[node].push_back(neighbour);
    }

    bool visited[n + 1];

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visit(graph, i, visited);
            visited[i] = 1;
            count++;
        }
    }
    cout << count;
}