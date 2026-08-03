#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'processCouponStackOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> processCouponStackOperations(vector<string> operations) {
    vector<int> ans;
    set<int> st;
    stack<int> q;
    for(auto x:operations){
        if(x == "top" && !q.empty()){
            ans.push_back(q.top());
            // cout<<"This val: "<<q.top()<<endl;
        }
        else if(x == "pop" && !q.empty()){
            int val = q.top();
            q.pop();
            auto it = st.find(val);
            st.erase(it);
        }
        else if(x == "getMin" && !st.empty()) ans.push_back(*(st.begin()));
        else{
            int val = 0;
            if(x.size() == 8) {
                val +=  (int(x[5]-'0'))*100;
                val +=  (int(x[6]-'0'))*10;
                val +=  int(x[7]-'0');
            }else if(x.size() == 7){
                val +=  (int(x[5]-'0'))*10;
                val +=  int(x[6]-'0');
            }else val +=  int(x[5]-'0');
            st.insert(val);
            q.push(val);
        }
    }
    return ans;
}

int main()
{
    string operations_count_temp;
    getline(cin, operations_count_temp);

    int operations_count = stoi(ltrim(rtrim(operations_count_temp)));

    vector<string> operations(operations_count);

    for (int i = 0; i < operations_count; i++) {
        string operations_item;
        getline(cin, operations_item);

        operations[i] = operations_item;
    }

    vector<int> result = processCouponStackOperations(operations);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
