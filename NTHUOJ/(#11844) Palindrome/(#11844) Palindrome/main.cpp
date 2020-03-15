//
//  main.cpp
//  (#11844) Palindrome
//
//  Created by Magic Bear on 2018/3/17.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(size_t start, size_t end, string str);
bool Palindrome(string str,int num);

bool Palindrome(string str,int num){
    if(isPalindrome(0, str.length()-1, str) && num>=0){
        return true;
    }
    if(num==0)
        return false;
    else{
        for(size_t pos = 0; pos< str.length(); pos++){
            string StrCut = str;
            StrCut.erase(StrCut.begin()+pos);
            if(Palindrome(StrCut, num-1)){
                return true;
            }
        }
    }
    return false;
}

/*bool isPalindrome(string str){
    unsigned short length = str.length();
    for(size_t i = 0;i<=length/2;i++){
        if(str[i] != str[length-i-1])
            return false;
    }
    return true;
}
*/

bool isPalindrome(size_t start, size_t end, string str){
    if(start >= end)
        return true;
    else if(str[start] != str[end])
        return false;
    else
        return isPalindrome(++start, --end, str);
}

int main(){
    int num = 0;
    string str = "";
    cin >> num;
    cin.ignore();
    while(getline(cin,str)){
        if(Palindrome(str,num))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
