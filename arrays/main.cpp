#include <bits/stdc++.h>
#include "array_support.h"
using namespace std;

int main()
{
    /*
    int n;
    int missingNumber;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
       cin >> x;

    cout << "The Largest number is : " << getLargest(arr);
    cout << "The Second largest number is : " << getSecondLargest(arr);
    cout << "Is the array sorted : " << (sortCheck(arr));
    int newSize = removeDuplicates(arr);
    cout << "Array without duplicates is : ";
    for (int j = 0; j < newSize; j++)
        cout << arr[j] << " ";
    leftRotate(arr);
    leftRotateN(arr, 3);
    rightRotate(arr);
    zerosToBack(arr);

    missingNumber = getMissingNumber(arr);
    cout << "The missing number is : " << missingNumber;
    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";
    vector<vector<string>> res;
    //vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};

    res = groupAnagrams(strs);
    cout<<endl<<endl;
    for (auto i : res){
        for( auto m : i){
            cout << m << ",";
        }
        cout << endl;
    }

    vector<int> testCase = {2,7,11,15};
    vector<int> res;
    int target = 9;
    res = twoSum(testCase, target);
    cout << res[0] << "," << res[1];
    */
    
    vector<int> testCase = {-1,1,0,-3,3};
    vector<int> res;
    res = productExceptSelf(testCase);
    for (auto i : res){
        
        cout << i << ",";
    }
}
