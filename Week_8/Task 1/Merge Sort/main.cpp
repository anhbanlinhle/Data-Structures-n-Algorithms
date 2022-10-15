#include "Libs.h"
using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int a1 = mid - left + 1;
    int a2 = right - mid;

    int leftArr[a1];
    int rightArr[a2];

    for (int i = 0; i < a1; i++)
        leftArr[i] = array[left + i];
    for (int i = 0; i < a2; i++)
        rightArr[i] = array[mid + 1 + i];

    int IOa1 = 0;
    int IOa2 = 0;
    int IOa = left;
    while (IOa1 < a1 && IOa2 < a2)
    {
        if (leftArr[IOa1] <= rightArr[IOa2])
        {
            array[IOa] = leftArr[IOa1];
            IOa1++;
        }
        else
        {
            array[IOa] = rightArr[IOa2];
            IOa2++;
        }
        IOa++;
    }

    while (IOa1 < a1)
    {
        array[IOa] = leftArr[IOa1];
        IOa1++;
        IOa++;
    }

    while (IOa2 < a2)
    {
        array[IOa] = rightArr[IOa2];
        IOa2++;
        IOa++;
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    int n;
    cin >> n;

    int task1[n];
    for (int i = 0; i < n; i++)
        cin >> task1[i];

    mergeSort(task1, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << task1[i] << " ";
}