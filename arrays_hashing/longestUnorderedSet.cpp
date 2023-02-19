#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(),nums.end());

        int lb = 0;

        for (const auto& num : hashSet){
            if (!hashSet.count(num-1)) {
                int length = 1;

                while(hashSet.count(num + length)){
                    length ++;
                }
                
                lb = std::max(length,lb);
            }
        }

        return lb;

    }
};

