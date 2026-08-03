#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'isAlphabeticPalindrome' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code as parameter.
 */

bool isAlphabeticPalindrome(string code) {
    string x,y;
    for(char c:code){
        if(c >= 'a' && c <= 'z') x.push_back(c);
        else if(c >= 'A' && c <= 'Z') x.push_back(c+32);
    }
    y=x;
    reverse(y.begin(),y.end());
    return x==y;
}

int main()
{
    string code;
    getline(cin, code);

    bool result = isAlphabeticPalindrome(code);

    cout << result << "\n";

    return 0;
}
