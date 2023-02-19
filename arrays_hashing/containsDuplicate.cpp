#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& val : nums){ //auto& shares object with the list. <- refrence. 
            if(s.count(val)){
                return true;
            }
            s.insert(val);
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}