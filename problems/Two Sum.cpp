#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findTaskPairForSlot' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY taskDurations
 *  2. INTEGER slotLength
 */

vector<int> findTaskPairForSlot(vector<int> taskDurations, int slotLength) {
    vector<int> ans = {-1,-1};
    int n = taskDurations.size();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({taskDurations[i],i});
    }
    int i = 0, j = v.size()-1;
    sort(v.begin(),v.end());
    while(i < j){
        if(v[i].first + v[j].first == slotLength){
            ans.clear();
            ans.push_back(min(v[i].second,v[j].second));
            ans.push_back(max(v[i].second,v[j].second));
            // ans = {min(v[i].second,v[j].second),max(v[i].second,v[j].second)};
            return ans;
        }
        if(i+1<j && v[i+1].first + v[j].first >= slotLength){
            j--;
        }else if(j-1>i && v[i].first + v[j-1].first <= slotLength){
            i++;
        }
    }
    return ans;
}

int main()
{
    string taskDurations_count_temp;
    getline(cin, taskDurations_count_temp);

    int taskDurations_count = stoi(ltrim(rtrim(taskDurations_count_temp)));

    vector<int> taskDurations(taskDurations_count);

    for (int i = 0; i < taskDurations_count; i++) {
        string taskDurations_item_temp;
        getline(cin, taskDurations_item_temp);

        int taskDurations_item = stoi(ltrim(rtrim(taskDurations_item_temp)));

        taskDurations[i] = taskDurations_item;
    }

    string slotLength_temp;
    getline(cin, slotLength_temp);

    int slotLength = stoi(ltrim(rtrim(slotLength_temp)));

    vector<int> result = findTaskPairForSlot(taskDurations, slotLength);

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
