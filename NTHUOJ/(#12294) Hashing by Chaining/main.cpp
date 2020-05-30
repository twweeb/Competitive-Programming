//
//  main.cpp
//  (#12294) Hashing by Chaining
//
//  Created by LeiHsiung on 2019/6/1.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <iostream>
#include <vector>

#define MOD 4294967296

using namespace std;

class Hash{
private:
    int size, M;
    vector< vector<long long int > > table;
    long long int HashFunc(long long int key);
    
public:
    Hash(){};
    Hash(int m, int n):M(m), size(n){
        table.resize(size);
    }
    void Insert(long long int data);
    void PrintTable();
};

void Hash::Insert(long long int data){
    long long int index = HashFunc(data);
    table[index].push_back(data);
}

long long int Hash::HashFunc(long long int key){
    long long int val = key*M;
    return (val % MOD % size);
}

void Hash::PrintTable(){
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if(j != 0) cout << " ";
            cout << table[i][j];
        }
        cout << '\n';
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, m, n;
    long long int tmp,p;
    cin >> T;
    while(T--){
        cin >> m >> n;
        p = n;
        Hash hash(m, n);
        while(n--){
            cin >> tmp;
            hash.Insert(tmp);
        }
        hash.PrintTable();
    }
    return 0;
}
