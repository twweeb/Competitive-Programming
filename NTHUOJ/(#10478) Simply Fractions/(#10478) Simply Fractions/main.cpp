//
//  main.cpp
//  (#10478) Simply Fractions
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include<iostream>
#include<utility>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    if(a>=b){
        if(a%b==0)return b;
        else
            return gcd(b,a%b);
    }
    else
        return gcd(b,a);
}

void sum(long long int a, long long int b, pair<long long int,long long int>& sum)
{
    long long int p,q,GCD;
    p = sum.first;
    q = sum.second;
    p = p*b + a*q;
    q *= b;
    GCD = gcd(p,q);
    p /= GCD;
    q /= GCD;
    sum = make_pair(p,q);
}

int main(){
    int n;
    while(static_cast<void>(cin >> n), !cin.eof()){
        pair<long long int,long long int> SUM = make_pair(0,1);
        while(n--){
            long long int a,b;
            cin >> a >> b;
            if(a!=0) sum(a,b,SUM);
        }
        cout << SUM.first << "/" << SUM.second << endl;
    }
    return 0;
}

