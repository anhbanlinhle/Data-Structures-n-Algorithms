#include "Libs.h"
using namespace std;
#define loopI(m, n) for (int i = m; i < n; i++)
#define loopJ(m, n) for (int j = m; j < n; j++)

// find cycle.
bool findCycle(int job, vector<vector<int>> graph, int color[]) {
    color[job] = 1;
    loopI(0, graph[job].size()) {
        if(color[graph[job][i]] == 0)
            findCycle(graph[job][i],graph,color);
        else if (color[graph[job][i]] == 1)
            return 1;
    }
    color[job] = 2;
    return 0;
}

// topological sort.
void topo(vector<vector<int>> graph, int jobs, int indegree[], queue<int> &ans)
{
    loopI(0, jobs) 
        if (indegree[i] == 0)
            ans.push(i);

    loopI(0, jobs)
    {
        loopJ(0, graph[i].size())
        {
            indegree[graph[i][j]]--;

            if (indegree[graph[i][j]] == 0)
                ans.push(graph[i][j]);
        }
    }
}


int main()
{
    int jobs, order;
    int u, v;

    // read input file.
    fstream testFile;
    testFile.open("jobs.txt", ios::in);
    testFile >> jobs >> order;

    // init indegree count.
    int *indegree = new int[jobs];
    loopI(0, jobs)
        indegree[i] = 0;

    // init adj matrix.
    vector<vector<int> > graph(jobs);

    loopI(0, order)
    {
        testFile >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        indegree[v]++;
    }

    testFile.close();

    // start solving.
    queue<int> ans;

    // check if exist cycle.
    bool cycleFound = 0;
    int *color = new int[jobs];
    loopI(0, jobs)
        color[i] = 0;
    
    loopI(0, jobs)
        if(findCycle(i, graph, color))
            cycleFound = 1;

    // start sorting.
    if(!cycleFound)
        topo(graph, jobs, indegree, ans);

    // write output file.
    testFile.open("jobs.out", ios::out);

    while(!ans.empty()) {
        testFile << ans.front() + 1 << " ";
        ans.pop();
    }
    testFile.close();
}