//
// Created by Connor Beleznay on 2023-02-27.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> out1;
        int p1 = 0;

        while (p1<p2<p3){

        }


        return out1;

    }
};

int main(){

    vector<int> nums{-1,0,1,2,-1,-4};

    Solution s;

    vector<vector<int>> out = s.threeSum(nums);

    for(auto v: out){
        for(auto val: v){
            cout<<val;
        }
        cout<<"\n";
    }

}