/*
Name: Hany Ali Elesawy
Date: 5/9/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "LinkedList.h"

u32 listLength=0;
node* ptrHeadNode=NULL;

void addNodeLast(u32 newValue)
{
		/*1*/
		node* ptrNewNode=(node*) malloc(sizeof(node));
		/*2*/
		ptrNewNode->data=newValue;
		/*3*/
		ptrNewNode->ptrNextStructNode=NULL;
		
		if(listLength==0)
		{
			ptrHeadNode=ptrNewNode;
			listLength++;
		}
		else
		{
			/*4*/
			node* ptrSearchLastNode=ptrHeadNode;
			while((ptrSearchLastNode->ptrNextStructNode)!=NULL)
			{
				ptrSearchLastNode=ptrSearchLastNode->ptrNextStructNode;
			}
			/*5*/
			ptrSearchLastNode->ptrNextStructNode=ptrNewNode;
		
			listLength++;
		}
}

void insertNode(u32 newValue,u32 pos)
{
	
	if( (ptrHeadNode==NULL)||(pos>listLength+1) ) /*Special Case: if List is Empty or invalid position*/
	{
		addNodeLast(newValue);
		return;
	}
	

	node* ptrPrev=ptrHeadNode;
	
	/* 1- Create New Node (nth node) */
	node* ptrNewNode=(node*)malloc(sizeof(node));
	/* 2-  Assign Data to nth node */
	ptrNewNode->data=newValue;

	if(pos==1) /*Special Case: if you want to make the new node the head node */
	{
		ptrNewNode->ptrNextStructNode=ptrHeadNode;
		ptrHeadNode=ptrNewNode;
		listLength++;
		return;
	}
	
	/* 3- Search for n-1th node (prev node ) */
	for(u32 i=0; i<pos-2;i++)
	{
		ptrPrev=ptrPrev->ptrNextStructNode;
	}
	/* 4- make the next of the new node point to the next of prev node */
	ptrNewNode->ptrNextStructNode=ptrPrev->ptrNextStructNode;
	/* 5- make the prev node point to new node */
	ptrPrev->ptrNextStructNode=ptrNewNode;
	
	listLength++;
}
void deleteValue(u32 newValue)
{
	node* ptrCurrentTemp=ptrHeadNode;
	node* ptrPrevNode=NULL;
	u32 deleteFlag=0;
	
	/* if the head node to be deleted */
	/* 
		The while condition here is VERY IMPORTANT "ptrCurrentTemp!=NULL" is it
		ensure that when the list has one element left (The first and only node)
		we ensure that it doesn't try to derefrence NULL pointer when checking
		this condition "ptrCurrentTemp->data==newValue"
	*/
	while( (ptrCurrentTemp!=NULL) && (ptrCurrentTemp->data==newValue) )
	{
		ptrHeadNode=ptrHeadNode->ptrNextStructNode;
		free(ptrCurrentTemp);
		ptrCurrentTemp=ptrHeadNode;
		
		listLength--;
		deleteFlag=1;
	}
	
	/* if any other node to be deleted */
	
	
	while (ptrCurrentTemp!=NULL) /* To traverse the Linked LIst */
	{
		
		if((ptrCurrentTemp->data)==newValue)
		{
			/* to skip nodes that are have match */
			ptrPrevNode->ptrNextStructNode=ptrCurrentTemp->ptrNextStructNode;
			/*
				Note that prtPrevNode will not be null here as it will be changed
				in the first iteration
			*/
			
			/* to free the location of the deleted node */
			free(ptrCurrentTemp);
			listLength--;
			deleteFlag=1;
			
			/*Point temp again to next location to continue traversing */
			ptrCurrentTemp=ptrPrevNode->ptrNextStructNode;
			
		}
		/* To traverse the Linked LIst if no match was found*/
		/* 	
			note that at the first iteration ptrCurrentTemp will
			be equal to the head node, so the prev will be changed
			to point at head node and current will point at 2nd node 
		*/
		else
		{
			ptrPrevNode=ptrCurrentTemp;
			ptrCurrentTemp=ptrPrevNode->ptrNextStructNode;
		}
	
	}
	
	if(deleteFlag==0)
	{
		printf("Value not found\n");
	}
	else
	{
		printf("Value deleted successfully\n");
	}
	
}


void print_LL()
{
	node* ptrPrintTempNode=ptrHeadNode;
	
	printf("\n");
	for(u32 i=0; i<30; i++)
	printf("-");
	printf("\n");
	
	if(listLength==0) /* if ptrHeadNode == null is also okay */
	{
		printf("Linked List is Empty\n");
	}
	else
	{
		for(u32 i=1;ptrPrintTempNode!=NULL;i++)
		{
			printf("Node Number %d = %d\n",i,ptrPrintTempNode->data);
			ptrPrintTempNode=ptrPrintTempNode->ptrNextStructNode;
		}
	}
	
	for(u32 i=0; i<30;i++)
	printf("-");
	printf("\n\n");
	
}