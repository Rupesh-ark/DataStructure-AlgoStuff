#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    void push(int val) {
       if(val < stack.top().second){
            stack.push({val, val});
       } else{
            stack.push({val, stack.top().second});
       }
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
private:
    stack<pair<int, int>> stack; 
};

bool isValidPrenthesesStack(string s){
    stack<char> charStack;
    char temp;
    for(const char &c : s){
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
                if(charStack.empty())
                    return false;
                else{
                    temp = charStack.top();
                    if(c == temp)
                        charStack.pop();
                    else
                        return false;
                }
                break;
        }
    }
    if(charStack.empty())
        return true;
    else
        return false;
}