//
// Created by Connor Beleznay on 2023-02-23.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> cars;
        float time;
        for (int i = 0; i < position.size(); ++i) {
            time = ((float)(target-position[i]) / (float)speed[i]);
            cars.emplace_back(position[i],time);
        }

        std::sort(cars.begin(),
                  cars.end(),
                  [&](pair<int,float> a,pair<int,float>b){return a.first > b.first;});

        vector<float> stack{cars[0].second};

        float curCar;
        for (int i = 1; i < cars.size(); ++i) {
            curCar = cars[i].second;
            if (curCar > stack.back()){
                stack.push_back(curCar);
            }
        }
        return stack.size();
    }
};


int main(){
    Solution s;
    vector<int> p{8,3,7,4,6,5};
    vector<int> sp{4,4,4,4,4,4};
    cout<<s.carFleet(10,p,sp);
}

