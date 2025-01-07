#include <bits/stdc++.h>
#include "sortingAlgorithms.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    //selectionSort(n, arr);
    //insertionSort(n, arr);
    //mergeSort(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
}
