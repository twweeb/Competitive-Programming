//
//  main.cpp
//  (#9467) Parentheses Matching
//
//  Created by Magic Bear on 2017/12/21.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//
/*
#include<stack>
#include<iostream>
#include <string>
#include <cstring>
using namespace std;

bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char a, b, c, d;
    
    // Traversing the Expression
    for (int i=0; i<expr.length(); i++){
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{'||expr[i]=='<'){
            // Push the element in the stack
            s.push(expr[i]);
        }
        else{
            switch (expr[i]){
                case ')':

                    // Store the top element in a
                    a = s.top();
                    s.pop();
                    if (a=='{'||a=='['||a=='<')
                        return false;
                    break;
                case '}':
                    
                    // Store the top element in b
                    b = s.top();
                    s.pop();
                    if (b=='('||b=='['||b=='<')
                        return false;
                    break;
                case ']':
                    
                    // Store the top element in c
                    c=s.top();
                    s.pop();
                    if (c=='('||c=='{'||c=='<')
                        return false;
                    break;
                case '>':
                    // Store the top element in d
                    d=s.top();
                    s.pop();
                    if (d=='('||d=='{'||d=='[')
                        return false;
                    break;
            }
        }
    }
    
    // Check Empty Stack
    if (s.empty())
        return true;
    else
        return false;
}

// Driver program to test above function
int main()
{
    int num;
    string x;
    string str;
    
    cin >> num;
    getline(cin, x);
    for(int i = 1; i<=num;i++){
        getline(cin, str);
        if(str.empty())
            cout << "Case " << i << ": Yes"<< endl;
        else{
            cout << "Case " << i << ": ";
            if(areParanthesisBalanced(str))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
*/
#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    string s;
    int N,id=1;
    getline(cin,s);
    stringstream ss(s);
    ss >> N;
    while(N--)
    {
        string str;
        getline(cin,str);
        stack<char> stk;
        bool isYes = true;
        for(int i=0 ; i<str.length() ; i++)
        {
            if(str[i]=='{'||str[i]=='['||str[i]=='('||str[i]=='<') stk.push(str[i]);
            else
            {
                if(str[i]=='}')
                {
                    if(!stk.empty()&&stk.top()=='{') stk.pop();
                    else
                    {
                        isYes = false;
                        break;
                    }
                }
                else if(str[i]==']')
                {
                    if(!stk.empty()&&stk.top()=='[') stk.pop();
                    else
                    {
                        isYes = false;
                        break;
                    }
                }
                else if(str[i]==')')
                {
                    if(!stk.empty()&&stk.top()=='(') stk.pop();
                    else
                    {
                        isYes = false;
                        break;
                    }
                }
                else if(str[i]=='>')
                {
                    if(!stk.empty()&&stk.top()=='<') stk.pop();
                    else
                    {
                        isYes = false;
                        break;
                    }
                }
                else if(str[i]==' ')
                {
                    
                }
                else
                {
                    isYes = false;
                    break;
                }
            }
        }
        cout << "Case " << id++ << ": ";
        if(isYes&&stk.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
