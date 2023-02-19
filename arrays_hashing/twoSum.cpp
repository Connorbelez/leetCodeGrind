#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        vector<int> ret;

        for (int i = 0; i<nums.size(); i++){
            if(numMap.count(target - nums[i])){
                ret = {numMap[target - nums[i]], i};
                return ret;
            }

            if (!numMap.count(nums[i])){
                numMap[nums[i]] = i;
            }

        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,7,11,15};
    vector<int> ret = s.twoSum(nums,9);
    for (auto& val : ret){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}