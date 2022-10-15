#include "Libs.h"
using namespace std;

void heapify(int arr[], int n, int i)
{

    int max = i;

    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < n && arr[l] > arr[max])
        max = l;

    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int j = n - 1; j > 0; j--)
    {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}