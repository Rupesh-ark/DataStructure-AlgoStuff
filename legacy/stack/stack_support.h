#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        if (st.empty() || val < st.top().second) {
            st.push({val, val});
        } else {
            st.push({val, st.top().second});
        }
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() const {
        return st.top().first;
    }

    int getMin() const {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;    
};


bool isValidParenthesesStack(const string &s) {
    stack<char> charStack;
    for (char c : s) {
        switch (c) {
            case '(':  charStack.push(')'); break;
            case '[':  charStack.push(']'); break;
            case '{':  charStack.push('}'); break;
            default:
                if (charStack.empty() || charStack.top() != c)
                    return false;
                charStack.pop();
        }
    }
    return charStack.empty();
}


vector<int> dailyTemperatures(const vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<pair<int,int>> mono;  

    for (int i = 0; i < n; ++i) {
        while (!mono.empty() && temperatures[i] > mono.top().first) {
            auto [t, idx] = mono.top();
            mono.pop();
            answer[idx] = i - idx;
        }
        mono.push({temperatures[i], i});
    }

    return answer;
}
