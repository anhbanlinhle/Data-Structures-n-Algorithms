#include "Libs.h"
using namespace std;
#define loopI(m, n) for (int i = m; i < n; i++)
#define loopJ(m, n) for (int j = m; j < n; j++)

void merge(int **array, int left, int mid, int right) {
    int a1 = mid - left + 1;
    int a2 = right - mid;

    int **leftArr = new int*[a1];
    loopI(0, a1) 
        leftArr[i] = new int[3];

    int **rightArr = new int*[a2];
    loopI(0, a2) 
        rightArr[i] = new int[3];

    loopI(0, a1) {
        leftArr[i][0] = array[left + i][0];
        leftArr[i][1] = array[left + i][1];
        leftArr[i][2] = array[left + i][2];
    }
    loopI(0, a2) {
        rightArr[i][0] = array[mid + 1 + i][0];
        rightArr[i][1] = array[mid + 1 + i][1];
        rightArr[i][2] = array[mid + 1 + i][2];
    }
    int IOa1 = 0;
    int IOa2 = 0;
    int IOa = left;

    while (IOa1 < a1 && IOa2 < a2) {
        if (leftArr[IOa1][2] <= rightArr[IOa2][2]) {
            array[IOa][0] = leftArr[IOa1][0];
            array[IOa][1] = leftArr[IOa1][1];
            array[IOa][2] = leftArr[IOa1][2];
            IOa1++;
        }
        else {
            array[IOa][0] = rightArr[IOa2][0];
            array[IOa][1] = rightArr[IOa2][1];
            array[IOa][2] = rightArr[IOa2][2];
            IOa2++;
        }
        IOa++;
    }

    while (IOa1 < a1) {
        array[IOa][0] = leftArr[IOa1][0];
        array[IOa][1] = leftArr[IOa1][1];
        array[IOa][2] = leftArr[IOa1][2];
        IOa1++;
        IOa++;
    }

    while (IOa2 < a2) {
        array[IOa][0] = rightArr[IOa2][0];
        array[IOa][1] = rightArr[IOa2][1];
        array[IOa][2] = rightArr[IOa2][2];
        IOa2++;
        IOa++;
    }
}

void mergeSort(int **array, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int findParent(int *parent, int u) {
    if (u == parent[u])
        return parent[u];
    parent[u] = findParent(parent, parent[u]);
    return parent[u];
}

void printMst(fstream &file, int total, int **mst, int count) {
    file << total;
    loopI(0, count) {
        file << endl;
        loopJ(0, 3)
            file << mst[i][j] << " ";
    }
}

int main() {
    // read input file.
    int n, m;
    fstream testFile;
    testFile.open("connection.txt", ios::in);
    testFile >> n >> m;

    // init adj matrix from file.
    int **graph = new int *[m];
    loopI(0, m) {
        graph[i] = new int[3];
        loopJ(0, 3)
            testFile >> graph[i][j];
    }
    testFile.close();

    // sort adj matrix by ascending order.
    mergeSort(graph, 0, m - 1);

    // node's parent array. 
    int *parent = new int[n];
    loopI(0,n)
        parent[i] = i;

    // min span tree array.
    int **mst = new int*[n-1];
    loopI(0, n-1)
        mst[i] = new int[3];

    int start, end, weight, total = 0, count = 0;

    loopI(0, m) {
    // if enough edges then quit.
        if (count == n - 1)
            break;

        start = graph[i][0];
        end = graph[i][1];
        weight = graph[i][2];

    // check if adding edge create circle.
        if (findParent(parent, start) != findParent(parent, end)) {
            parent[parent[start]] = parent[parent[end]];
            total += weight;
            mst[count] = graph[i];
            count ++;
        }
    }

    // write output file.
    testFile.open("connection.out", ios::out);
    printMst(testFile, total, mst, count);
    testFile.close();
}