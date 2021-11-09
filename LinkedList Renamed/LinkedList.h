/*
Name: Hany Ali Elesawy
Date: 5/9/2021
*/
#ifndef _Lec10_A2_LINKEDLIST_H
#define _Lec10_A2_LINKEDLIST_H

struct node{
	u32 data;
	struct node* ptrNextStructNode;
};

typedef struct node node;


void addNodeLast(u32 newValue);
void insertNode(u32 newValue,u32 pos);
void deleteValue(u32 newValue);
void print_LL();


#endif