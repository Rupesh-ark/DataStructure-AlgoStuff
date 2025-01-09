#include <bits/stdc++.h>
int getLargest(std::vector<int> &arr);
int getSecondLargest(std::vector<int> &arr);
//void removeDuplicates(std::vector<int> &sortedArr);
int removeDuplicates(std::vector<int> &sortedArr);
void leftRotate(std::vector<int> &arr);

int getLargest(std::vector<int> &arr)
{
    int largest = 0;
    for (int i : arr)
    {
        if (largest < i)
        {
            largest = i;
        }
    }
    return largest;
}

int getSecondLargest(std::vector<int> arr)
{
    int largest = 0, secondLargest = 0;
    if (arr.size() < 2)
        return -1;
    for (int i : arr)
    {
        if (largest < i)
        {
            secondLargest = largest;
            largest = i;
        }
        else if (secondLargest < i && secondLargest != largest)
        {
            secondLargest = i;
        }
    }
    return secondLargest;
}

// A[i] == B[(i+x) % A.length]
bool sortCheck(std::vector<int> arr)
{
    int count = 0, size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
            count++;
    }

    if (arr[size - 1] > arr[0])
        count++;

    return count <= 1;
}

//Primitive implementation
// void removeDuplicates(std::vector<int> &sortedArr)
// {
//     int size = sortedArr.size(), selected, duplicateCount, j, k;
//     for (int i = 0; i < size; i++)
//     {
//         k = 1;
//         selected = sortedArr[i];
//         duplicateCount = 0;
//         for (j = i + 1; j < size; j++)
//         {
//             if (sortedArr[j] == selected)
//                 duplicateCount++;
//             else
//                 break;
//         }
        
//         if (duplicateCount > 0)
//         {
//             while (j < size)
//             {
//                 sortedArr[i + k] = sortedArr[j];
//                 k++;
//                 j++;
//             }
//             size -= duplicateCount;
//         }
//     }
// }

// Optimised solution
int removeDuplicates(std::vector<int> &sortedArr){
    int size = sortedArr.size(), i = 0;
    for (int j = 1; j < size; j++)
    {
        if(sortedArr[i] != sortedArr[j]){
            i++;
            sortedArr[i] = sortedArr[j];
        }
    }
    return i + 1;
}

void leftRotate(std::vector<int> &arr){
    int temp = arr[0], size = arr.size(), j;
    for (j = 1; j < size; j++)
        arr[j - 1] = arr[j];
    arr[j - 1] = temp;
}

void rightRotate(std::vector<int> &arr){
    int temp = arr[arr.size() - 1], size = arr.size(), j;
    for (j = size - 2; j >= 0; j--)
        arr[j + 1] = arr[j];
    arr[0] = temp;
}

void leftRotateN(std::vector<int> &arr, int k){

    int size = arr.size(), temp, j; 
    for (int i = 0; i < k; i++)
    {
        temp = arr[0];
        for (j = 1; j < size; j++)
            arr[j - 1] = arr[j];
        arr[j - 1] = temp;
    }
}