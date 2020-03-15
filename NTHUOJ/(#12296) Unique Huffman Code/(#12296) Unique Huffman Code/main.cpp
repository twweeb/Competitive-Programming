//
//  main.cpp
//  (#12296) Unique Huffman Code
//
//  Created by LeiHsiung on 2019/6/1.
//  Copyright © 2019 LeiHsiung. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

char alpha[27] = {'-','a','b','c','d','e','f',
                  'g','h','i','j','k','l','m',
                  'n','o','p','q','r','s','t',
                  'u','v','w','x','y','z'};
string code[27];
int freq[27];

struct HuffNode {
    int c;
    unsigned freq;
    HuffNode *left, *right;
    HuffNode(int c, unsigned freq):
        c(c), freq(freq), left(nullptr), right(nullptr){};
};

struct Comp{
    bool operator()(HuffNode* a, HuffNode* b){
        if(a->freq == b->freq) return a->c > b->c;
        return a->freq > b->freq;
    }
};

bool isLeaf(HuffNode* root)
{
    return (root->left==nullptr && root->right==nullptr);
}


void setCode(int *arr, int top, int c)
{
    for (int i = 0; i < top; ++i){
        code[c] += (arr[i])? '1' : '0';
    }
}

void HuffCode(HuffNode* root, int *arr, int top)
{
    if(root == nullptr) return;
    if (isLeaf(root))
        setCode(arr, top, root->c);
    else{
            arr[top] = 0;
            HuffCode(root->left, arr, top + 1);
        
            arr[top] = 1;
            HuffCode(root->right, arr, top + 1);
    }
}

HuffNode* BuildHuffTree()
{
    HuffNode *left = nullptr, *right = nullptr, *tmp = nullptr;
    priority_queue<HuffNode*, vector<HuffNode*>, Comp> HuffHeap;
    
    for (int i = 0; i < 27; ++i){
        if(freq[i])
            HuffHeap.push(new HuffNode(i,freq[i]));
    }
    
    while (HuffHeap.size() > 1) {
        left = HuffHeap.top(); HuffHeap.pop();
        right = HuffHeap.top(); HuffHeap.pop();
        //cout << left->c << ": " << left->freq << ", " << right->c << ": " << right->freq << endl;
        tmp = new HuffNode((left->c < right->c)? left->c:right->c, left->freq + right->freq);
        tmp->left = left;
        tmp->right = right;
        HuffHeap.push(tmp);
    }
    return HuffHeap.top();
}

void CountFreq(string str)
{
    for (int i = 0; i < str.size(); ++i)
        ++freq[(str[i] == '-')? 0: (str[i] - 'a' + 1)];
}

void Encode(string str)
{
    for (int i = 0; i < str.size(); ++i)
        cout << code[(str[i] == '-') ? 0 : str[i] - 'a' + 1];

    cout << '\n';
}

void Decode(HuffNode* root, string str)
{
    string ans = "";
    HuffNode* curr = root;
    for (int i=0;i<str.size();i++)
    {
        curr = (str[i] == '0') ? curr->left : curr = curr->right;
        
        if (isLeaf(curr))
        {
            ans += alpha[curr->c];
            curr = root;
        }
    }
    cout << ans << endl;
}

void Huff()
{
    fill_n(code, 27, "");
    fill_n(freq, 27, 0);
    int arr[100] = {0};
    string str;
    cin >> str;
    CountFreq(str);
    
    HuffNode *root = BuildHuffTree();
    HuffCode (root, arr, 0);
    
    //for (int i = 0; i < 27; ++i)
    //{
    //    cout << alpha[i] << ": " << freq[i] <<endl;
    //}
    
    Encode(str);
    cin >> str;
    Decode(root, str);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int C = 0;
    cin >> C;
    while (C--) Huff();
    return 0;
}
