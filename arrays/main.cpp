#include <bits/stdc++.h>
#include "array_support.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    //cout << "The Largest number is : " << getLargest(arr);
    //cout << "The Second largest number is : " << getSecondLargest(arr);
    cout << "Is the array sorted : " << (sortCheck(arr));
    
}
