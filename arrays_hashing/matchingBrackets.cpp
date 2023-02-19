#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {

        std::vector<char> stack;
        if (!(s.size() > 1)){
            return false;
        }


        for (auto c : s){
            // std::cout<<"C: "<<c<<std::endl;
            if (c == '(' || c == '{' || c == '[' ){
                stack.push_back(c);
            }
            else{
                if (!stack.size()){return false;}

                if ( 
                    (c==')' && stack.back() == '(') ||
                    (c==']' && stack.back() == '[') || 
                    (c=='}' && stack.back() == '{')){ 
                        stack.pop_back();
                } 
                else{return false;}

            }
        }

        return (stack.size() == 0);
    }
};