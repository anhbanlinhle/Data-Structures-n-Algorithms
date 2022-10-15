#include "Libs.h"
using namespace std;

bool findSum(int arr[], int n, int X)
{
    if (X == 0)
        return !X;
    if (n == 0)
        return n;

    if (arr[n - 1] > X)
        return findSum(arr, n - 1, X);

    return findSum(arr, n - 1, X) || findSum(arr, n - 1, X - arr[n - 1]);
}

int main()
{
    int n, X;
    cin >> n >> X;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (findSum(arr, n, X))
        cout << "YES";
    else
        cout << "NO";
}