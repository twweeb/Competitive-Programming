//
//  main.cpp
//  (#12295) Prefix Matching
//
//  Created by LeiHsiung on 2019/6/1.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

struct TrieNode {
    bool isEmpty, isWord, isVisit[26];
    TrieNode* Trie[26];
    set<int> validIdx;
   // map<char, TrieNode*> Trie;
};

TrieNode* newNode()
{
    TrieNode* node = new TrieNode;
    node->isEmpty = true;
    node->isWord = false;
    fill(node->isVisit, node->isVisit+26, 0);
    return node;
}

void insert(TrieNode*& root, const string& str)
{
    if (root == nullptr)
        root = newNode();
    
    TrieNode* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        
        if (!temp->isVisit[x-'a'])
        {
            temp->Trie[x-'a'] = newNode();
            temp->isVisit[x-'a'] = true;
            temp->isEmpty = false;
            temp->validIdx.insert(x-'a');
        }
        
        temp = temp->Trie[x-'a'];
    }
    temp->isWord = true;
}

TrieNode* search(TrieNode* root, const string& str)
{
    if (root == nullptr) return nullptr;
    
    TrieNode* tmp = root;
    for (int i = 0; i < str.length(); ++i) {
        if(tmp->isVisit[str[i]-'a'])
            tmp = tmp->Trie[str[i]-'a'];
        else return nullptr;
    }
    return tmp;
}

bool isLastNode(TrieNode* root)
{
    return root->isEmpty;
}

void matchPre(TrieNode* root, string pre)
{
    if (root->isWord) cout << pre << '\n';
    if (isLastNode(root)) return;
    for (set<int>::iterator it=root->validIdx.begin() ;  it!=root->validIdx.end() ; ++it )
    {
        pre.push_back(*it+'a');
        matchPre(root->Trie[*it], pre);
        pre.pop_back();
    }
}

bool prematch(TrieNode* root, string query)
{
    TrieNode* tmp = search(root, query);
    
    if(tmp == nullptr) return false;
    
    bool isWord = tmp->isWord;
    bool isLast = isLastNode(tmp);
    
    if (isWord && isLast)
    {
        cout << query << endl;
        return true;
    }
    
    if (!isLast)
    {
        matchPre(tmp, query);
        query = "";
        tmp = nullptr;
        delete tmp;
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    string str;
    cin >> n;
    TrieNode* root = nullptr;
    while (n--)
    {
        cin >> str;
        insert(root,str);
    }
    
    cin >> n;
    
    while (n--)
    {
        cin >> str;
        if(!prematch(root, str))
            cout << "No match\n";
        str = "";
    }
    return 0;
}
