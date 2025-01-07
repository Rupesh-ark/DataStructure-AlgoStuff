#include <bits/stdc++.h>
int getLargest(std::vector<int> &arr);
int getSecondLargest(std::vector<int> &arr);

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