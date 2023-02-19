#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<int>> anaMap;
        vector<vector<string>> anaList;
        
        string curString;
        for (int i=0; i<strs.size(); i++){
            curString = strs[i];
            std::sort(curString.begin(),curString.end());
            anaMap[curString].push_back(i);
        }

        for (const auto& [key,val] : anaMap){
            vector<string> row;
            for (const auto& index : val){
                row.push_back(strs[index]);
            }
            anaList.push_back(row);
        }
        return anaList;
    }
};