//
//  main.cpp
//  (#9101) Postfix Evaluation
//
//  Created by Magic Bear on 2018/4/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isNum(string str)
{
    if((str[0] - '0')>=0 && (str[0] - '0')<=9) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    int N = 0, M = 0;
    cin >> N;
    for(int i = 1; i <=N ; i++)
    {
        cin >> M;
        string str = "";
        int num = 0, num1 = 0, num2 = 0;
        stack<int> st;
        for(int j = 0;j < M ; j++)
        {
            cin >> str;
            if(isNum(str))
            {
                num = 0;
                for(size_t k = 0;k < str.length(); k++)
                {
                    num += (str[k]-'0')*pow(10,str.length()-1-k);
                }
                //cout << num << endl;
                st.push(num);
            }
            else
            {
                switch(str[0])
                {
                    case '+':
                        num1 = st.top();
                        st.pop();
                        num2 = st.top()+num1;
                        st.pop();
                        st.push(num2);
                        break;
                    case '-':
                        num1 = st.top();
                        st.pop();
                        num2 = st.top() - num1;
                        st.pop();
                        st.push(num2);
                        break;
                    case '*':
                        num1 = st.top();
                        //cout << "num1 = " << num1 <<endl;
                        st.pop();
                        num2 = st.top()*num1;
                        //cout << "num2 = " << num2 <<endl;
                        st.pop();
                        st.push(num2);
                        break;
                    case '/':
                        num1 = st.top();
                        st.pop();
                        num2 = st.top()/num1;
                        st.pop();
                        st.push(num2);
                        break;
                }
            }
            if(j == M-1)
            {
                cout << "Case " << i << ": " << st.top() << endl;
                st.pop();
                if(!st.empty())
                    cout << "Stack Not Empty." << endl;
            }
        }
    }
    return 0;
}
