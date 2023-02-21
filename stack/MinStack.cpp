#include <vector>

using namespace std;
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        iStack.push_back(val);
        
        if (iStack.size()){
           if (val<= mStack.back()){
               mStack.push_back(val);
           }
        }else{
            mStack.push_back(val);
        }
    }
    
    void pop() {
        if(iStack.back() == mStack.back()){mStack.pop_back();}
        iStack.pop_back();
    }
    
    int top() {
        return iStack.back();
    }
    
    int getMin() {
        return mStack.back();
    }
private:
    std::vector<int> iStack;
    std::vector<int> mStack;
};