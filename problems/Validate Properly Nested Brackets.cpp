#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'areBracketsProperlyMatched' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code_snippet as parameter.
 */

bool areBracketsProperlyMatched(string code_snippet) {
    // cout<<code_snippet<<endl;
    stack<char> st;
    for(char c:code_snippet){
        // cout<<c<<endl;
        if(c==')' || c=='}' || c==']'){
            if(st.empty()) return false;
            if(!st.empty() && st.top() == '(' && c != ')') return false;
            if(!st.empty() && st.top() == '{' && c != '}') return false;
            if(!st.empty() && st.top() == '[' && c != ']') return false;
            st.pop();
        }
        else if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        
    }
    if(st.empty()) return true;
    return false;
}

int main()
{
    string code_snippet;
    getline(cin, code_snippet);

    bool result = areBracketsProperlyMatched(code_snippet);

    cout << result << "\n";

    return 0;
}
