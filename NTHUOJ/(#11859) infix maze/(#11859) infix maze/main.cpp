//
//  main.cpp
//  (#11859) infix maze
//
//  Created by Magic Bear on 2018/3/28.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#define MAXN 110
#define MAX 1000

#include <iostream>
//#include <stack>
#include <cstring>
#include <string>

using namespace std;

bool isSolve = false;
int n = 0,w = 0,h = 0;
char maze[MAXN][MAXN];
bool isVisit[MAXN][MAXN];
string str = "",ans = "";


class Stack
{
    int top;
public:
    char a[MAX];    //Maximum size of Stack
    
    Stack()  { top = -1; }
    bool push(char x);
    char pop();
    char gettop();
    bool isEmpty();
};

bool Stack::push(char x)
{
    if (top >= MAX)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

char Stack::gettop()
{
    if( top < 0)
    {
        //cout << "Stack Underflow";
        return 0;
    }
    else
    {
        return a[top];
    }
}

char Stack::pop()
{
    if (top < 0)
    {
        //cout << "Stack Underflow";
        return 0;
    }
    else
    {
        char x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void init()//讀w h
{
    cin>>w>>h;
    cout<<w<<endl<<h<<endl;
    for(int i=0 ; i<w ; ++i)
    {
        for(int j=0 ; j<h ; ++j)
        {
            cin >> maze[i][j];
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    memset(isVisit, false, sizeof(isVisit[0][0])*MAXN*MAXN);
    isSolve = false;
    str = "";
    //cout << "Finish initial." << endl;
}

bool isNum(char c)
{
    return c>='1' && c<='9';
}

bool isOp(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/';
}

bool isLegal()
{
    int cnt = 0;
    for(int i=0 ; i<str.length() ; ++i)
    {
        if(cnt<0) return false;
        char cur = str[i];
        if(cur=='(') cnt++;
        if(cur==')') cnt--;
        if(isOp(cur))
        {
            if(i==0 || i==str.length()-1) return false;
            if(i>0) if(isOp(str[i-1]) || str[i-1]=='(') return false;
            if(i<str.length()-1) if(isOp(str[i+1]) || str[i+1]==')') return false;
        }
    }
    if(cnt!=0) return false;
    return true;
}

bool isLegalMid()
{
    int cnt = 0;
    for(int i=0 ; i<str.length() ; ++i)
    {
        char cur = str[i];
        if(cur=='(') cnt++;
        if(cur==')') cnt--;
        if(isOp(cur))
        {
            //if(i==0 || i==str.length()-1) return false;
            if(i>0) if(isOp(str[i-1]) || str[i-1]=='(') return false;
            if(i<str.length()-1) if(isOp(str[i+1]) || str[i+1]==')') return false;
        }
        if(cnt<0) return false;
    }
    return true;
}

void dfs(int x, int y) //down > right > left >> up
{
    if(x<0 || x>=w || y<0 || y>=h) return;
    if(!isLegalMid()) return;
    if(x==w-1 && y==h-1) //infix to postfix
    {
        str.push_back(maze[x][y]);
        if(isLegal())
        {
            isSolve = true;
            ans = str;
            return;
        }
        str.pop_back();
        return;
    }
    if(!isVisit[x][y])
    {
        isVisit[x][y] = true;
        str.push_back(maze[x][y]);
        if(!isSolve) dfs(x+1, y);
        if(!isSolve) dfs(x, y+1);
        if(!isSolve) dfs(x, y-1);
        if(!isSolve) dfs(x-1, y);
        str.pop_back();
        isVisit[x][y] = false;
    }
}

int priority(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    }
}

void in2post()
{
    for(int i=0 ; i<ans.length() ; ++i)
    {
        if(i<ans.length()-1 && isNum(ans[i]) && isNum(ans[i+1])) cout << ans[i];
        else cout << ans[i] << ' ';
    }
    cout << endl;
    struct Stack st;
    //string postfix = "";
    for(int i = 0; i<ans.length() ; i++){
        switch(ans[i]) {
            case '(':              // parathensis save in stack
                st.push(ans[i]);
                break;
            case '+': case '-': case '*': case '/':
                while(priority(st.gettop()) >= priority(ans[i])) {
                    cout << st.pop() << " ";
                }
                st.push(ans[i]); // Operator Save in stack
                break;
            case ')':
                while(st.gettop() != '(') {
                    if(st.gettop()!='(')
                        cout << st.pop() << " ";
                    else st.pop();
                }
                break;
            default: //Number output
                cout << ans[i];
                if((i<=ans.length()-1) && !isNum(ans[i+1]))
                    cout << " ";
        }
    }
    while(!st.isEmpty()) {
        if(st.gettop()!='(')
            cout << st.pop() << " ";
        else st.pop();
    }
    cout << endl;
}

void solve()
{
    dfs(0,0);
    if(isSolve)
    {
        cout << "Yes" << endl;
        in2post();
    }
    else cout << "No" << endl;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    cout << n << endl;
    while(n--)
    {
        init();
        solve();
    }
    return 0;
}
