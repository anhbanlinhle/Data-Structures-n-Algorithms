#include "Libs.h"
using namespace std;

int maxWeight(int maxWeight, int weight[], int value[], int item)
{
    int maxValue[item + 1][maxWeight + 1];
    for (int i = 0; i <= item; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
                maxValue[i][j] = 0;
            else if (weight[i - 1] <= j)
                maxValue[i][j] = max(value[i - 1] + maxValue[i - 1][j - weight[i - 1]], maxValue[i - 1][j]);
            else
                maxValue[i][j] = maxValue[i - 1][j];
        }
    }
    return maxValue[item][maxWeight];
}

int main()
{
    int n;
    int X;
    cin >> n >> X;

    int weight[n];
    int value[n];

    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    cout << maxWeight(X, weight, value, n);
}