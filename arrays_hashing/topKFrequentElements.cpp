#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> kMap;
        for(int i = 0; i<nums.size(); i++){
            kMap[nums[i]] ++;
        }

        vector<pair<int,int>> kVec(kMap.begin(),kMap.end());

		auto srt = [](pair<int,int> a,pair<int,int> b){return a.second > b.second;};
		
        std::sort(kVec.begin(),kVec.end(),srt);
        
        vector<int> finalVec;
        for (int i = 0; i<k; i++){
            finalVec.push_back(kVec[i].first);
        }

        
        return finalVec;
        
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ret = s.topKFrequent(nums,2);
    for (auto& val : ret){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}