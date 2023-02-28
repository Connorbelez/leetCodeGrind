//
// Created by Connor Beleznay on 2023-02-24.
//
#include <vector>
#include <iostream>
using namespace std;;

//
//Given an array of integers heights representing the
//histogram's bar height where the width of each bar
//is 1, return the area of the largest rectangle in the histogram.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<pair<int,int>> rectStack; //height, position
        rectStack.emplace_back(heights[0],0);
        auto calcRect = [](int loopIndex, pair<int,int> rect){
            return ((loopIndex - rect.second) * rect.first);
        };
        int largest = heights[0];
        int posCounter;
        for (int i = 0; i < heights.size(); ++i) {
            //if larger than what's on stack, add it to the top of the stack
            if (heights[i] == rectStack.back().first) continue;
            if(heights[i] > rectStack.back().first){
                rectStack.emplace_back(heights[i],i);
            }
            else{
//                posCounter = i;
                while(rectStack.size() && heights[i] < rectStack.back().first){
                    posCounter = rectStack.back().second;
                    largest = std::max(largest,calcRect(i,rectStack.back()));
                    rectStack.pop_back();
                }
                rectStack.emplace_back(heights[i],posCounter);
            }
        }

        for(pair<int,int> rect: rectStack){
            largest = std::max(largest, calcRect(heights.size(),rect));
        }

        return largest;

    }
};

int main(){
    std::vector<int> input{2,1,2,5,6,2,3}; //expects 10, getting 10.
    std::vector<int> input2{1,3,2,1,2};// expects 5, getting 3

    Solution s;
    std::cout<<s.largestRectangleArea(input)<<endl;
    std::cout<<s.largestRectangleArea(input2)<<endl;
}