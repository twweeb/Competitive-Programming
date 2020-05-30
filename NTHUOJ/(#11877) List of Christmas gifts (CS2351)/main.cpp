//
//  main.cpp
//  (#11877) List of Christmas gifts (CS2351)
//
//  Created by Magic Bear on 2018/4/10.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class List{
private:
    struct Node{
        Node *next;
        Node *prev;
        int price;
        string gift;
    };
    Node *begin_;
    Node *end_;
    
public:
    List();
    ~List();
    void InsertBack(string gift, int price);
    void InsertAfter(string gift, int price, int priceToInsertAfter);
    void Delete(int price);
    void Reverse();
    void End();
};

List::List(){
    begin_ = nullptr;
    end_ = new Node;
    end_->price = -1;
    end_->gift = "end";
    end_->next = end_->prev = nullptr;
}

List::~List(){
    int count = 1;
    Node *curr = begin_;
    if(begin_ == nullptr)
    {
        delete end_;
        end_ = nullptr;
        return;
    }
    while(curr!=end_){
        count++;
        curr = curr->next;
    }
    curr = begin_;
    for(int i = 0; i < count ; i++){
        Node *tmp = curr;
        curr = curr->next;
        tmp->next = nullptr;
        delete tmp;
        tmp = nullptr;
    }
}

void List::InsertBack(string gift, int price){
    if(begin_ == nullptr){
        begin_ = new Node;
        begin_->gift = gift;
        begin_->price = price;
        end_->next = begin_;
        begin_->prev = end_;
        end_->prev = begin_;
        begin_->next = end_;
        return;
    }
    Node *curr = begin_;
    while(curr!=end_){
        if(curr->price == price)
            return;
        curr = curr->next;
    }
    Node *e = new Node;
    e->gift = gift;
    e->price = price;
    e->prev = end_->prev;
    e->next = end_;
    end_->prev->next = e;
    end_->prev = e;
}

void List::InsertAfter(string gift, int price, int priceToIn)
{
    if(begin_==nullptr) return;
    Node *curr = begin_;
    while(curr!=end_){
        if(curr->price == price)
            return;
        curr = curr->next;
    }
    curr = begin_;
    while(curr!=end_){
        if(curr->price == priceToIn){
            Node *e = new Node;
            e->gift = gift;
            e->price = price;
            e->prev = curr;
            e->next = curr->next;
            curr->next->prev = e;
            curr->next = e;
            return;
        }
        curr = curr->next;
    }
}

void List::Delete(int price)
{
    if(begin_==nullptr) return;
    if(begin_->price == price)
    {
        if(begin_->next!=end_)
        {
            end_->next = begin_->next;
            begin_->next->prev = end_;
            Node *e = begin_;
            begin_ = begin_->next;
            delete e;
            e = nullptr;
            return;
        }
        begin_->prev = nullptr;
        begin_->next = nullptr;
        delete begin_;
        begin_ = nullptr;
        return;
    }
    
    Node *curr = begin_->next;
    while(curr!=end_){
        if(curr->price == price){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            return;
        }
        curr = curr->next;
    }
}

void List::Reverse()
{
    if(begin_==nullptr) return;
    Node *curr = begin_,
    *prev = begin_;
    while(curr!=end_)
    {
        curr = curr->next;
        prev->next = prev->prev;
        prev->prev = curr;
        if(curr==end_)
        {
            end_->prev = begin_;
            begin_ = prev;
            end_->next = prev;
            return;
        }
        prev = curr;
    }
}

void List::End()
{
    if(begin_==nullptr)
    {
        cout << "Empty" << endl;
        return;
    }
    cout << "List" << endl;
    Node *curr = begin_;
    cout << "(" << curr->gift << "," << curr->price << ")";
    curr = curr->next;
    while(curr!=end_)
    {
        cout << "->(" << curr->gift << "," << curr->price << ")";
        curr = curr->next;
    }
    cout << endl;
}

int main(void) {
    string command = "";
    List lst;
    while(cin>>command){
        if(command == "InsertBack")
        {
            string gift = "";
            int price = 0;
            cin >> gift >> price;
            lst.InsertBack(gift, price);
        }
        else if(command == "InsertAfter")
        {
            string gift = "";
            int price = 0, pos = 0;
            cin >> gift >> price >> pos;
            lst.InsertAfter(gift, price, pos);
        }
        else if(command == "Delete")
        {
            int price = 0;
            cin >> price;
            lst.Delete(price);
        }
        else if(command == "Reverse")
            lst.Reverse();
        
        else if(command == "End")
        {
            lst.End();
            break;
        }
    }
    return 0;
}
