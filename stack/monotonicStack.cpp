#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> indexStack{0};
        int size = temperatures.size();
        int curTemp;
        int index;
        vector<int> result(size,0);
        for (int i = 1; i < size; ++i) {
            curTemp = temperatures[i];

            while (indexStack.size() && curTemp > temperatures[indexStack.back()]){
                index = indexStack.back();
                indexStack.pop_back();
                result[index] = i - index;
            }
            indexStack.push_back(i);

        }

        return result;
    }
};


int main(){
    Solution s;
    std::vector<int> vect{73,74,75,71,69,72,76,73};
    cout<<"READY?"<<endl;
    vector<int> v = s.dailyTemperatures(vect);

    for (auto val : v){
        std::cout<<val<<" ";
    }
};