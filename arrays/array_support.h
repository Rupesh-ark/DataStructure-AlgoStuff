#include <bits/stdc++.h>
int getLargest(std::vector<int> &arr);
int getSecondLargest(std::vector<int> &arr);
void reverseArray(int l, int r, std::vector<int> &arr);
int removeDuplicates(std::vector<int> &sortedArr);
void leftRotate(std::vector<int> &arr);
void reverseArray(int &l, int &r, std::vector<int> &arr);
void zerosToBack(std::vector<int> &arr);
int getMissingNumber(std::vector<int> &arr);
std::vector<int> findUnion(std::vector<int> &a, std::vector<int> &b);
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs);
std::vector<int> twoSum(std::vector<int> &nums, int target);
std::vector<int> productExceptSelf(std::vector<int> &nums);
std::vector<int> topKFrequent(std::vector<int> &nums, int k);
int longestConsecutive(std::vector<int> &nums);

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

// Primitive implementation
//  void removeDuplicates(std::vector<int> &sortedArr)
//  {
//      int size = sortedArr.size(), selected, duplicateCount, j, k;
//      for (int i = 0; i < size; i++)
//      {
//          k = 1;
//          selected = sortedArr[i];
//          duplicateCount = 0;
//          for (j = i + 1; j < size; j++)
//          {
//              if (sortedArr[j] == selected)
//                  duplicateCount++;
//              else
//                  break;
//          }

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
int removeDuplicates(std::vector<int> &sortedArr)
{
    int size = sortedArr.size(), i = 0;
    for (int j = 1; j < size; j++)
    {
        if (sortedArr[i] != sortedArr[j])
        {
            i++;
            sortedArr[i] = sortedArr[j];
        }
    }
    return i + 1;
}

void leftRotate(std::vector<int> &arr)
{
    int temp = arr[0], size = arr.size(), j;
    for (j = 1; j < size; j++)
        arr[j - 1] = arr[j];
    arr[j - 1] = temp;
}

void rightRotate(std::vector<int> &arr)
{
    int temp = arr[arr.size() - 1], size = arr.size(), j;
    for (j = size - 2; j >= 0; j--)
        arr[j + 1] = arr[j];
    arr[0] = temp;
}

// Optimised solution
void rightRotateN(std::vector<int> &arr, int k)
{
    int size = arr.size();
    int rotateBy = k % size;
    reverseArray(0, (size - 1), arr);
    reverseArray(0, (rotateBy - 1), arr);
    reverseArray(rotateBy, (size - 1), arr);
}

void reverseArray(int l, int r, std::vector<int> &arr)
{
    while (l < r)
    {
        std::swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void leftRotateN(std::vector<int> &arr, int k)
{
    int size = arr.size(), temp, j;
    for (int i = 0; i < k; i++)
    {
        temp = arr[0];
        for (j = 1; j < size; j++)
            arr[j - 1] = arr[j];
        arr[j - 1] = temp;
    }
}

void zerosToBack(std::vector<int> &arr)
{
    int j = -1, size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    if (j >= 0)
    {
        for (int i = j + 1; i < size; i++)
        {
            if (arr[i] != 0)
            {
                std::swap(arr[i], arr[j]);
                j++;
            }
        }
    }
}

std::vector<int> findUnion(std::vector<int> &a, std::vector<int> &b)
{
    std::vector<int> uni;
    int i = 0, j = 0, lastElement;

    if (a[i] <= b[j])
    {
        uni.push_back(a[i]);
        i++;
    }
    else
    {
        uni.push_back(b[j]);
        j++;
    }
    lastElement = uni[0];

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (a[i] != lastElement)
            {
                uni.push_back(a[i]);
                lastElement = a[i];
            }
            i++;
        }
        else
        {
            if (b[j] != lastElement)
            {
                uni.push_back(b[j]);
                lastElement = b[j];
            }
            j++;
        }
    }
    while (i < a.size())
    {
        if (a[i] != lastElement)
        {
            uni.push_back(a[i]);
            lastElement = a[i];
        }
        i++;
    }
    while (j < b.size())
    {
        if (b[j] != lastElement)
        {
            uni.push_back(b[j]);
            lastElement = b[j];
        }
        j++;
    }
    return uni;
}

int getMissingNumber(std::vector<int> &arr)
{

    int size = arr.size(), xorResA = 0, xorResB = 0;
    for (int i = 0; i < size; i++)
    {
        xorResA = xorResA ^ (i);
        xorResB = xorResB ^ arr[i];
    }
    xorResA = xorResA ^ size;
    return xorResA ^ xorResB;
}

bool containsDuplicate(std::vector<int> &arr)
{
    std::unordered_map<int, bool> arrayHash;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arrayHash[arr[i]])
        {
            return true;
        }
        arrayHash[arr[i]] = true;
    }
    return false;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{

    std::unordered_map<std::string, std::vector<std::string>> stringSum;
    std::vector<std::vector<std::string>> stringGroup;
    int sum;
    std::string key;
    for (std::string str : strs)
    {
        key = str;
        std::sort(key.begin(), key.end());
        stringSum[key].push_back(str);
    }

    for (auto key : stringSum)
    {
        stringGroup.push_back(key.second);
    }
    return stringGroup;
}

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int size = nums.size(), zeroSum;
    std::unordered_map<int, int> numHash;
    for (int i = 0; i < size; i++)
    {
        zeroSum = target - nums[i];
        if (numHash.count(zeroSum))
        {
            return {numHash[zeroSum], i};
        }
        numHash[nums[i]] = i;
    }
    return {};
}

std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> productArray;
    int size = nums.size(), temp = 1;
    for (int i = 0; i < size; i++)
    {
        productArray.push_back(temp);
        temp = temp * nums[i];
    }
    temp = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        productArray[i] = productArray[i] * temp;
        temp = temp * nums[i];
    }
    return productArray;
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    int size = nums.size();
    std::vector<std::vector<int>> bucket(size + 1);
    std::unordered_map<int, int> numHash;
    std::vector<int> solution;

    for (int i = 0; i < size; i++)
    {
        numHash[nums[i]] += 1;
    }
    for (auto i : numHash)
    {
        bucket[i.second].push_back(i.first);
    }

    for (int i = size; i > 0; i--)
    {
        if (solution.size() >= k)
            break;
        if (!bucket[i].empty())
        {
            solution.insert(solution.end(), bucket[i].begin(), bucket[i].end());
        }
    }
    return solution;
}

int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> numSet;
    int longest = 0;

    for (const int &i : nums)
        numSet.insert(i);

    for (const int &i : numSet)
    {
        if (!numSet.contains(i - 1))
        {
            int end = i + 1;
            while (numSet.contains(end))
            {
                end++;
            }
            longest = std::max((end - i), longest);
        }
    }
    return longest;
}

int binarySearch(std::vector<int> &numbers, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (numbers[mid] == x)
            return mid;
        if (numbers[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

std::vector<int> twoSumSortedArray(std::vector<int> &numbers, int target)
{

    int deltaToSearch, index2, i, size = numbers.size();
    for (i = 0; i < size; i++)
    {
        deltaToSearch = target - numbers[i];
        std::cout << "Delta to Search : " << deltaToSearch << std::endl;
        index2 = binarySearch(numbers, i + 1, size - 1, deltaToSearch);
        if (index2 != -1)
        {
            break;
        }
    }
    return {i + 1, index2 + 1};
}

int maxArea(std::vector<int> &height)
{
    int maxArea = 0, i = 0, j = height.size() - 1, temp = 0;
    while (i != j)
    {
        std::cout << "i, height[i]: " << i << "," << height[i] << std::endl;
        std::cout << "j, height[j]: " << j << "," << height[j] << std::endl;
        if (height[i] <= height[j])
        {
            temp = (j - i) * height[i];
            i++;
        }
        else
        {
            temp = (j - i) * height[j];
            j--;
        }
        std::cout << "The current temp :" << temp << std::endl;
        if (temp > maxArea)
            maxArea = temp;
    }
    return maxArea;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int i = 0, size = nums.size(), j, k, sum;
    std::vector<std::vector<int>> solution;
    sort(nums.begin(), nums.end());
    while (i < size)
    {
        if (i > 0 && nums[i] == nums[i + 1])
        {
            i++;
            continue;
        }
        j = i + 1;
        k = size - 1;
        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                solution.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j - 1])
                {
                    j++;
                }
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return solution;
}

int maxProfit(std::vector<int> &prices)
{
    int i = 0, j = 1, maxValue = 0, diff;
    while (j < prices.size())
    {
        diff = prices[j] - prices[i];
        if (diff < 0)
            i = j;
        else
        {
            if (diff > maxValue)
                maxValue = std::max(maxValue, diff);
        }
        j++;
    }
    return maxValue;
}

int lengthOfLongestSubstring(std::string s)
{
    std::cout << "String : " << s << std::endl;
    if (s.empty())
    {
        return 0;
    }
    int longest = 1, temp, l = 0;
    std::unordered_set<char> charSet;

    for (int r = 0; r < s.size(); r++)
    {
        std::cout << "Current char : " << s[r] << std::endl;
        while (charSet.contains(s[r]))
        {
            charSet.erase(s[l]);
            l++;
            std::cout << "    Erasing : " << s[l] << std::endl;
        }
        std::cout << "    Inserting : " << s[r] << std::endl;
        charSet.insert(s[r]);
        longest = std::max(longest, r - l + 1);
    }

    return longest;
}