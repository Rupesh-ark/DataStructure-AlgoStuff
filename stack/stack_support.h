#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    void push(int val)
    {
        if (val < stack.top().second)
        {
            stack.push({val, val});
        }
        else
        {
            stack.push({val, stack.top().second});
        }
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }

private:
    stack<pair<int, int>> stack;
};

bool isValidPrenthesesStack(string s)
{
    stack<char> charStack;
    char temp;
    for (const char &c : s)
    {
        switch (c)
        {
        case '(':
            charStack.push(')');
            break;
        case '[':
            charStack.push(']');
            break;
        case '{':
            charStack.push('}');
            break;
        default:
            if (charStack.empty())
                return false;
            else
            {
                temp = charStack.top();
                if (c == temp)
                    charStack.pop();
                else
                    return false;
            }
            break;
        }
    }
    if (charStack.empty())
        return true;
    else
        return false;
}

vector<int> dailyTemperatures(vector<int> &temperatures)
{

    int size = temperatures.size();
    stack<pair<int, int>> tempStack;
    vector<int> output(size);
    tempStack.push({temperatures[0], 0});
    for (size_t i = 1; i < size; i++)
    {   pair<int, int> current = tempStack.top();
        while (current.first < temperatures[i])
        {
            output[current.second] = i - current.second;
            tempStack.pop();
            if(tempStack.empty())
                break;
            current = tempStack.top();
        }
        tempStack.push({temperatures[i], i});
    }
    return output;
}