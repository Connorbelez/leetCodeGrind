#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sMap,tMap;
        
        if(s.size()!= t.size()){
            return false;
        }
        for(int i = 0; i<s.size(); i++){
            if(sMap.count(s[i])) sMap[s[i]]++;
            else sMap[s[i]] = 1;

            if(tMap.count(t[i])) tMap[t[i]]++;
            else tMap[t[i]] = 1;
        }

        for(const auto& [key,val] : sMap){
            if( !tMap.count(key) || tMap[key] != val) return false;
        }
        return true;
    }
};


int main(){
    Solution s;
    cout << s.isAnagram("anagram","nagaram") << endl;
    cout << s.isAnagram("rat","car") << endl;
    return 0;
}