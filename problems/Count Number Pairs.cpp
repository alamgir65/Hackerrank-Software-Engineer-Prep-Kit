#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countAffordablePairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER budget
 */

int countAffordablePairs(vector<int> prices, int budget) {
    int ans = 0;
    int n = prices.size();
    for(int i=1;i<n;i++){
        if((prices[i]+prices[i-1]) <= budget) ans += i;
        else if(prices[i]<budget){
            int rem = budget - prices[i];
            int it = upper_bound(prices.begin(), prices.begin() + i, rem) - prices.begin();
            ans += it;
        }
        else break;
    }
    return ans;
}

int main()
{
    string prices_count_temp;
    getline(cin, prices_count_temp);

    int prices_count = stoi(ltrim(rtrim(prices_count_temp)));

    vector<int> prices(prices_count);

    for (int i = 0; i < prices_count; i++) {
        string prices_item_temp;
        getline(cin, prices_item_temp);

        int prices_item = stoi(ltrim(rtrim(prices_item_temp)));

        prices[i] = prices_item;
    }

    string budget_temp;
    getline(cin, budget_temp);

    int budget = stoi(ltrim(rtrim(budget_temp)));

    int result = countAffordablePairs(prices, budget);

    cout << result << "\n";

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
