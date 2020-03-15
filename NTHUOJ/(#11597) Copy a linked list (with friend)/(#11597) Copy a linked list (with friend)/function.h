#ifndef HEADER_H
#define HEADER_H
#include<stdbool.h>

typedef struct Node
{
	unsigned long id;	//sorry. actually, this is data instead of id
	struct Node *fri;
	struct Node *next;
} Node;

//unlike normal copy, you have privilege to modify src
//I guarantee no other threads will access src
Node* copy(Node *src);
void print(const Node *lst);
bool equal(const Node *lhs,const Node *rhs);	//help you debug without printing

#endif