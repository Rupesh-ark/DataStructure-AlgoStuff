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

    vector<int> testCase = {0,3,7,2,5,8,4,6,0,1};
    vector<int> res;
    res = topKFrequent(testCase, 2);
    for(auto i : res)
        cout << i << ",";

    vector<int> testCase = {0,3,7,2,5,8,4,6,0,1};
    int res;
    res = longestConsecutive(testCase);
    cout << res;

    vector<int> testCase = {5,25,75};
    vector<int> res;
    res = twoSumSortedArray(testCase, 100);
    for(auto i : res)
        cout << i << " ";

    vector<int> testCase = {0,0,0,0};
    vector<vector<int>> res;
    res = threeSum(testCase);
    for(auto i : res){
          for(auto j : i){
            cout << j << ",";
        }
        cout << endl;
    }

    vector<int> testCase = {7,6,4,3,1};
    int output;
    output = maxProfit(testCase);
    cout << "The max profit is : " << output;
    */
    // string testCase = "dvdf";
    //string testCase = "abcabcbb";
    //string testCase = "aab";
    string testCase = "ABABBA";
    int output;
    output = characterReplacement(testCase, 2);
    cout << "The max length is : " << output;
    return 0;
}
