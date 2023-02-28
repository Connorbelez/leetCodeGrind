//
// Created by Connor Beleznay on 2023-02-27.
//

#include <string>
#include <iostream>
#include<stdio.h>
#include<cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int p1,p2;
        string sc;

        for(char letter : s){

            if (isalpha(letter)) sc += tolower(letter);
            if (isdigit(letter)) sc += letter;
        }


        int strLen = sc.size();


        if (strLen % 2 == 0){
            p1 = strLen/2 - 1;
            p2 = p1 ++;
        }else{
            p1 = strLen/2 - 1;
            p2 = p1 +2 ;
        }

        while (p1 >= 0 && p2 < strLen){

            if (sc[p1] != sc[p2]) return false;
            p1--;
            p2++;
        }
        return true;

    }
};

int main(){

//    string s = "A man, a plan, a canal: Panama";

    string s2 = "A man, a plan, a canal: Panama";

    Solution sol;
//    cout<<sol.isPalindrome(s)<<endl;

    cout<<sol.isPalindrome(s2)<<endl;



}