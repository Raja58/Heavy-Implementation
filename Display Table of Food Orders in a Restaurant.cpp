// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        21 Nov 2021
//  @Detail  :        Display Table of Food Orders in a Restaurant (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> result;
        map<pair<int, string>, int> cache;
        set<string> table;
        
        for(vector<string> &x : orders)
        {
            cache[{stoi(x[1]), x[2]}]++;
            table.insert(x[2]);
        }
        
        vector<string> title{"Table"};
        for(string x : table)
            title.push_back(x);
        result.push_back(title);
        
        unordered_map<string, int> idx;
        for(int i = 0; i < title.size(); i++)
            idx[title[i]] = i;
        
        int prevTable = -1;
        vector<string> temp(title.size(), "0");
        for(auto it = cache.begin(); it != cache.end(); it++)
        {
            if(it != cache.begin() && it -> first.first != prevTable)
            {
                result.push_back(temp);
                fill(temp.begin(), temp.end(), "0");
            }
            temp[0] = to_string(it -> first.first);
            prevTable = it -> first.first;
            temp[idx[it -> first.second]] = to_string(it -> second);
        }
        result.push_back(temp);
        return result;
    }
};
