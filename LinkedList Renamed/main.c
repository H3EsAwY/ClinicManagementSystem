/*
Name: Hany Ali Elesawy
Date: 5/9/2021
*/

#include <stdio.h>
#include "STD_Types.h"
#include "LinkedList.h"

void printf_LL();
void main ()
{
	u8 exitFlag=0;
	u32 input,newValue,pos;
	
	
	while(exitFlag==0)
	{
		printf("***************************************\n");
		printf("To add node enter 0\n");
		printf("To add node at a certain position enter 1\n");
		printf("To delete a value enter 2\n");
		printf("To print linked list enter 3\n");
		printf("To exit enter 4\n\n");
		printf("Your Choice: ");
		fflush(stdout);
		scanf("%d",&input);
		
		switch(input)
		{
			case 0: printf("\nPlease enter node value: ");
					fflush(stdout);
					scanf("%d",&newValue);
					addNodeLast(newValue);
					printf("Node added, Thank You\n\n");
					break;
		
			case 1: printf("\nPlease enter node value: ");
					fflush(stdout);
					scanf("%d",&newValue);
					printf("Please enter node position (1 is 1st): ");
					fflush(stdout);
					scanf("%d",&pos);
					insertNode(newValue,pos);
					printf("Node inserted, Thank You\n\n");
					break;
					
			case 2:	printf("\nPlease enter a value to delete: ");
					fflush(stdout);
					scanf("%d",&newValue);
					deleteValue(newValue);
					break;
			
			case 3: print_LL();
					break;
		
			case 4: printf("\nThank You\nGood Bye");
					exitFlag=1;
					break;
		
			default:printf("\nInvalid Choice, Please Try Again\n");
					break;
		}
	}
	
	
}