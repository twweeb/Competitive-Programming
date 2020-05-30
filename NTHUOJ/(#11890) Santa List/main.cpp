//
//  main.cpp
//  (#11890) Santa List
//
//  Created by Magic Bear on 2018/4/16.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string coal = "coal";

class List{
private:
    struct Node{
        string name;
        string gift;
        Node* next;
        Node* prev;
    };
    Node *begin_;
    Node *end_;
    Node *first_naughty_;
public:
    List();
    ~List();
    void add(string name, string gift);
    void naughty(string name);
    void print();
};

List::List(){
    begin_ = nullptr;
    first_naughty_  = nullptr;
    end_ = new Node;
    end_->prev = end_->next = nullptr;
}
List::~List(){
    if(begin_==nullptr){
        delete end_;
        end_ = nullptr;
        return;
    }
    Node *curr = begin_;
    while(curr != end_){
        Node* e = curr;
        curr = curr->next;
        delete e;
        e = nullptr;
    }
    delete end_;
    end_ = nullptr;
    return;
}

void List::add(string name, string gift){
    if(begin_==nullptr){
        begin_ = new Node;
        begin_->next = end_;
        begin_->prev = end_;
        end_->prev = begin_;
        end_->next = begin_;
        begin_->name = name;
        begin_->gift = gift;
        return;
    }
    if(begin_==first_naughty_){
        Node *e = new Node;
        e->name = name;
        e->gift = gift;
        e->prev = end_;
        e->next = begin_;
        end_->next = e;
        begin_->prev = e;
        begin_ = e;
        return;
    }
    if(first_naughty_==nullptr){
        Node *e = new Node;
        e->name = name;
        e->gift = gift;
        e->prev = end_->prev;
        e->next = end_;
        end_->prev->next = e;
        end_->prev = e;
        return;
    }
    Node *e = new Node;
    e->name = name;
    e->gift = gift;
    e->prev = first_naughty_->prev;
    e->next = first_naughty_;
    first_naughty_->prev->next = e;
    first_naughty_->prev = e;
    return;
    
}

void List::naughty(string name){
    if(begin_==nullptr) return;
    Node* curr = begin_;
    while(curr!=end_){
        if(curr->name == name)break;
        curr = curr->next;
        if(curr==end_) return;
    }
    //cout << "Find Naughty: " << "(" << curr->name << "," << curr->gift << ")";
    curr->gift = coal;
    if(first_naughty_==nullptr){
        if(curr->next == end_){
            first_naughty_ = curr;
            curr->gift = coal;
            return;
        }
        if(curr == begin_) begin_ = curr->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = end_;
        curr->prev = end_->prev;
        end_->prev->next = curr;
        end_->prev = curr;
        first_naughty_ = curr;
        return;
    }
    if(curr->next==end_) return;
    if(curr==begin_){
        begin_ = curr->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = end_;
        curr->prev = end_->prev;
        end_->prev->next = curr;
        end_->prev = curr;
        return;
    }
    if(curr==first_naughty_){
        first_naughty_ = curr->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = end_;
        curr->prev = end_->prev;
        end_->prev->next = curr;
        end_->prev = curr;
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->next = end_;
    curr->prev = end_->prev;
    end_->prev->next = curr;
    end_->prev = curr;
    return;
}

void List::print(){
    if(begin_ == nullptr) cout << "Empty" << endl;
    else{
        cout << "SantaFinalList" << endl << "(" << begin_->name << "," << begin_->gift << ")";
        Node *curr = begin_->next;
        while(curr!=end_){
            cout << "->(" << curr->name << "," << curr->gift << ")";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main()
{
    string str = "", command = "", name = "", gift = "";
    int N = 0;
    List lst;
    while(cin >> command){
        if(command == "SantaList" || command == "AppendList"){
            cin >> N;
            while(N--){
                cin >> name >> gift;
                lst.add(name, gift);
            }
        }
        else if(command == "NaughtyKid"){
            cin >> N;
            while(N--){
                cin >> name;
                lst.naughty(name);
            }
        }
        else if(command == "End"){
            lst.print();
            break;
        }
    }
    return 0;
}

