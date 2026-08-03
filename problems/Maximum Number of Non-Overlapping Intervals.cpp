#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'maximizeNonOverlappingMeetings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY meetings as parameter.
 */

int maximizeNonOverlappingMeetings(vector<vector<int>> a) {
    if(a.size()==0) return 0;
    vector<pair<int,int>> v;
    for(auto u:a) v.push_back({u[0],u[1]});
    sort(v.begin(),v.end(),
                        [](const pair<int,int> &a,const pair<int,int> &b){
                            return a.second < b.second;
                        }
    );
    int ans = 1;
    pair<int,int> last=v[0];
    for(int i=1;i<v.size();i++){
        if(last.second <= v[i].first){
            ans++;
            last = v[i];
        }
    }
    return ans;
}

int main()
{
    string meetings_rows_temp;
    getline(cin, meetings_rows_temp);

    int meetings_rows = stoi(ltrim(rtrim(meetings_rows_temp)));

    string meetings_columns_temp;
    getline(cin, meetings_columns_temp);

    int meetings_columns = stoi(ltrim(rtrim(meetings_columns_temp)));

    vector<vector<int>> meetings(meetings_rows);

    for (int i = 0; i < meetings_rows; i++) {
        meetings[i].resize(meetings_columns);

        string meetings_row_temp_temp;
        getline(cin, meetings_row_temp_temp);

        vector<string> meetings_row_temp = split(rtrim(meetings_row_temp_temp));

        for (int j = 0; j < meetings_columns; j++) {
            int meetings_row_item = stoi(meetings_row_temp[j]);

            meetings[i][j] = meetings_row_item;
        }
    }

    int result = maximizeNonOverlappingMeetings(meetings);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
