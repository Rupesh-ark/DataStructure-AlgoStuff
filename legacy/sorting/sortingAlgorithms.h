#include <bits/stdc++.h>
void selectionSort(int n, std::vector<int> &arr);
void insertionSort(int n, std::vector<int> &arr);
void merge(std::vector<int> &arr, int low, int middle, int high);
void mergeSort(std::vector<int> &arr, int low, int high);
int partition(std::vector<int> &arr, int low, int high);
void quickSort(std::vector<int> &arr, int low, int high);

void selectionSort(int n, std::vector<int> &arr)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}

void insertionSort(int n, std::vector<int> &arr)
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeSort(std::vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int middle = (low + high) / 2;
    mergeSort(arr, low, middle);
    mergeSort(arr, middle + 1, high);
    merge(arr, low, middle, high);
}

void merge(std::vector<int> &arr, int low, int middle, int high)
{

    std::vector<int> temp;
    int left = low;
    int right = middle + 1;

    while (left <= middle && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= middle)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void quickSort(std::vector<int> &arr, int low, int high){
    if(high <= low) return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int partition(std::vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for( int j = low; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    i++;
    std::swap(arr[i], arr[high]);

    return i;
}