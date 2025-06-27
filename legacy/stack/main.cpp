#include "stack_support.h"
using namespace std;


int main(){
    
    // string s;
    // cin >> s;
    // cout << "Input string : " << s << "\n";
    // bool isValid = isValidPrenthesesStack(s);
    // cout << "Is this valid?? : " << isValid;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
       cin >> x;

    vector<int> output = dailyTemperatures(arr);
    for(int &x: output)
        cout << x << " ";


}