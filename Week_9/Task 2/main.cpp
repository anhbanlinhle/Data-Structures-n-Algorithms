#include "Libs.h"
using namespace std;
#define goI(n) for (int i = 0; i < n; i++)
#define goJ(n) for (int j = 0; j < n; j++)
#define goK(m, n) for (int k = m; k < n; k++)

string findMin(int **graph, int n, int start, int end, string path, string &min, bool visited[])
{
    // count for debug.
    int static count = 1;

    goI(n)
    {
        // check if edge exist.
        if (graph[start][i] != 0)
        {
            // check if city visited.
            if (!visited[i])
            {
                // branch new path.
                string temp = path;

                // add visited city.
                temp += to_string(i + 1);
                visited[i] = 1;

                // // debug block-------------------------------------------------------------
                // cout << "\n";
                // goJ(n) cout << " City " << j + 1 << ": " << (visited[j] ? "Y " : "N ");
                // cout << " Last city visited: " << i + 1 << "\n";
                // // debug block-------------------------------------------------------------

                // if meet end cordinate.
                if (i == end)
                {

                    // // debug block-------------------------------------------------------------
                    // cout << "\n\tPath number " << count << ": " << temp
                    //      << "\tPrevious min: " << min << endl;
                    // count++;
                    // // debug block-------------------------------------------------------------

                    // if new path shorter than previous.
                    if (temp.size() < min.size())
                        min = temp;

                    // reset path.
                    goK(i, n) visited[k] = 0;
                }

                // else continue visiting.
                else
                {
                    temp = findMin(graph, n, i, end, temp, min, visited);

                    // reset branched path.
                    visited[i] = 0;
                }
            }
        }
    }
    return min;
}

int main()
{
    // init cities, edges, start, end.
    int n, m, start, end;
    cin >> n >> m >> start >> end;

    // convert to cordinates start from 0.
    start--;
    end--;

    // init new graph.
    int **graph = new int *[n];
    int x, y;

    goI(n)
    {
        graph[i] = new int[n];
        goJ(n)
            graph[i][j] = 0;
    }

    // get data for graph.
    goI(m)
    {
        cin >> x >> y;
        x--;
        y--;
        graph[x][y] = 1;
    }

    // init path with start cordinate.
    string path = "";
    path = to_string(start + 1);

    // init min = longest path possible.
    string min = "";
    goI(n) min += to_string(i + 1);

    // init visited data
    bool visited[n];
    goI(n) visited[i] = 0;
    visited[start] = 1;

    // print result
    string minPath = findMin(graph, n, start, end, path, min, visited);

    // // debug block-------------------------------------------------------------
    // cout << "Shortest path: " << minPath << "\nShortest length: ";
    // // debug block-------------------------------------------------------------

    cout << minPath.size() - 1;

    // uncomment all debug blocks to see how code works.
}