#include "Libs.h"
using namespace std;
#define loopI(m, n, p) for (int i = m; i < n; i p)
#define loopJ(m, n, p) for (int j = m; j < n; j p)

void reset(int minPath[], bool visited[], int parent[], int cities)
{
    loopI(0, cities, ++)
    {
        minPath[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
}

int findMin(int minPath[], bool visited[], int cities)
{
    int min = INT_MAX;
    int vertex;
    loopI(0, cities, ++)
    {
        if (visited[i] == false && minPath[i] < min)
        {
            vertex = i;
            min = minPath[i];
        }
    }
    return vertex;
}

void dijkstra(int **graph, int cities, int start, int minPath[], bool visited[], int parent[])
{
    reset(minPath, visited, parent, cities);

    parent[start] = -1;
    minPath[start] = 0;

    loopI(0, cities - 1, ++)
    {
        int min = findMin(minPath, visited, cities);
        visited[min] = 1;

        loopJ(0, cities, ++)
        {

            if (graph[min][j] != 0 && !visited[j])
                if (minPath[min] != INT_MAX)
                {
                    {
                        if (minPath[min] + graph[min][j] < minPath[j])
                        {
                            minPath[j] = minPath[min] + graph[min][j];
                            parent[j] = min;
                        }
                    }
                }
        }
    }
}

int main()
{
    fstream testFile;
    testFile.open("dirty.txt", ios::in);

    int cities, edges, start, end;
    testFile >> cities >> edges >> start >> end;
    start--;
    end--;

    int **graph = new int *[cities];
    loopI(0, cities, ++)
    {
        graph[i] = new int[cities];
        loopJ(0, cities, ++)
        {
            graph[i][j] = 0;
        }
    }

    int u, v, d;
    loopI(0, edges, ++)
    {
        testFile >> u >> v >> d;
        u--;
        v--;
        graph[u][v] = d;
    }

    testFile.close();

    testFile.open("dirty.out", ios::out);

    int minPath[cities];
    int parent[cities];
    bool visited[cities];

    dijkstra(graph, cities, start, minPath, visited, parent);
    int minFromStartToEnd = minPath[end];

    if (minFromStartToEnd != INT_MAX)
    {
        testFile << minFromStartToEnd << endl;
        int temp = end;
        vector<int> path;
        while (temp != start)
        {
            path.push_back(temp);
            temp = parent[temp];
        }
        testFile << start + 1;
        for (int i = path.size() - 1; i >= 0; i--)
            testFile << " " << path[i] + 1;

        loopI(0, cities, ++)
        {
            testFile << endl;
            dijkstra(graph, cities, i, minPath, visited, parent);
            loopJ(0, cities, ++) testFile << minPath[j] << " ";
        }
    }
    else
        testFile << "INF";
    testFile.close();
}