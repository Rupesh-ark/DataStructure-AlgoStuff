#include "stack_support.h"
using namespace std;


int main(){
    
    string s;
    cin >> s;
    cout << "Input string : " << s << "\n";
    bool isValid = isValidPrenthesesStack(s);
    cout << "Is this valid?? : " << isValid;


}