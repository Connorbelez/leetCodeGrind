// Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.

// The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

// You must write an algorithm that runs in `O(n)` time and without using the division operation.

// **Example 1:**

// **Input:** nums = [1,2,3,4]
// **Output:** [24,12,8,6]

// **Example 2:**

// **Input:** nums = [-1,1,0,-3,3]
// **Output:** [0,0,9,0,0]

// **Constraints:**

// -   `2 <= nums.length <= 105`
// -   `-30 <= nums[i] <= 30`
// -   The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

// **Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The `output array` **does not** count as extra space for space complexity analysis.)

// >We create a new array (the `output array `) and we do two passes through the input array, in the first pass we set the corresponding index to the product of all elements to the left of that point. We can do this by keeping a running tally of the prefix and setting the value at the current index to the value of the prefix* index-1. then updating the prefix to the value at that index

// >On the second pass we also keep a running tally of the postfix, the product of all the values to the `right of the current index in the input array` and we multiply it by the prefix at the current index (f`rom the output array`) and store the product in` output array` at the current index. We update the post fix like so:` post = post*nums[j+1] `where `nums` is the `input array`. 


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solution(vector<int>& nums){
        vector<int> outVec(nums.size(),1);
        
        //iterate through array, we want each element in the outVec, to be the prefix of the values up to that point
        int preFix = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            preFix *= nums[i-1];
            outVec[i] = preFix;
        }

        int postFix = 1;
        for (int i = nums.size()-2; i >= 0; i--)
        {   
            std::cout<<"Num: "<<nums[i+1]<<endl;
            postFix *= nums[i+1];
            outVec[i] = outVec[i]*postFix;
        }
        
        for (auto val : outVec){
            std::cout<<val<<" ";
        }
        std::cout<<endl;
        return outVec;
    };

};

int main(){
    Solution s;
    std::vector<int> in({1,2,3,4});
    std:;vector<int> in2({-1,1,0,-3,3});
    s.solution(in);
    s.solution(in2);
};