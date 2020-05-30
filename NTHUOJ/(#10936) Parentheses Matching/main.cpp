//
//  main.cpp
//  (#10936) Parentheses Matching
//
//  Created by LeiHsiung on 2019/3/8.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int cnt = 0;

bool isLeft(char c){
    return c == '(' || c == '<' || c == '[' || c == '{';
}
char matchParen(char c){
    switch (c) {
        case '(':
            return ')';
            break;
        case '[':
            return ']';
            break;
        case '{':
            return '}';
            break;
        case '<':
            return '>';
            break;
        case ')':
            return '(';
            break;
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
        case '>':
            return '<';
            break;
            
        default:
            return '!';
    }
}

void cleanStack(stack<int> &st)
{
    while(!st.empty())
    {
        st.pop();
    }
}


int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    stack<int> st;
    cin.ignore();
    bool isValid = true;
    while(N--)
    {
        string str="";
        getline(cin, str);
        for(int i = 0; i<str.length();i++)
        {
            if(isLeft(str[i]))
            {
                st.push(matchParen(str[i]));
            }
            else
            {
                if(!st.empty() && str[i] == st.top())
                    st.pop();
                else
                {
                    isValid = false;
                    break;
                }
            }
        }
        if(!st.empty()) isValid = false;
        if(isValid == true)
        {
            ++cnt;
        }
        isValid = true;
        cleanStack(st);
        
    }
    cout << cnt << endl;
    
    return 0;
}
