/*
Project: Clinic Management System
Name: Hany Ali Elesawy
Date Started: 7/9/2021 
Date Finished: 8/9/2021
*/

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "clinic.h"

#define ID_DOESNT_EXIST 0
#define ID_EXISTS 1

#define NOT_RESERVED 0
#define RESERVED 1

#define numSlots 5  /* Number of default available slots */

reserv resInfo[numSlots] = {	{"2pm to 2:30pm",0,NOT_RESERVED},
								{"2:30pm to 3pm",0,NOT_RESERVED},
								{"3pm to 3:30pm",0,NOT_RESERVED},
								{"4pm to 4:30pm",0,NOT_RESERVED},
								{"4:30pm to 5pm",0,NOT_RESERVED},
							};
							
															

patNode* ptrHead=NULL;


u32 checkID(u32 id) /* 0 -> id doesn't exist ||| 1 -> id exists */
{
	patNode* ptrCheckTemp=ptrHead;
	
	if(ptrHead==NULL) /* if List is empty then id doesn't exist */
	{
		return 0;
	}
	else
	{
		while(ptrCheckTemp!=NULL)
		{
			if(ptrCheckTemp->ID==id)
			{
				return ID_EXISTS; /* id esists */
			}
			else
			{
				ptrCheckTemp=ptrCheckTemp->ptrNext;
			}
			
		}
		return ID_DOESNT_EXIST; /* id doesn't exist */
	}
}

void addRecord(u32 id, u8 name[30], u8 sex, u32 age)
{
	patNode* ptrNewPat=(patNode*) malloc(sizeof(patNode));
	
	ptrNewPat->ID=id;
	strncpy(ptrNewPat->NAME,name,30);
	//ptrNewPat->NAME=name;
	ptrNewPat->SEX=sex;
	ptrNewPat->AGE=age;
	
	ptrNewPat->ptrNext=NULL;
	
	if(ptrHead==NULL) /*if List is empty, just add the thing */
	{
		ptrHead=ptrNewPat;
	}
	else /* if list is not empty check id is unique first */
	{
		patNode* ptrSearchLastNode=ptrHead;
		while(ptrSearchLastNode->ptrNext!=NULL)
		{
			ptrSearchLastNode=ptrSearchLastNode->ptrNext;
		}
		ptrSearchLastNode->ptrNext=ptrNewPat;
	}
}

patNode* fetchPatNode(u32 id)
{
	/* fetchPatNode() returns a pointer to the node containing the passed id */
	
	/* we are sure that the id exists as we checked before passing the id to fetchPatNode()*/
	patNode* ptrIdSearch=ptrHead;
	
	while(ptrIdSearch->ID!=id)
	{
		ptrIdSearch=ptrIdSearch->ptrNext;
	}
	
	return ptrIdSearch;
	
}


patNode* viewRecord(u32 id) 
{
	/*viewRecord returns a pointer to the viewed Node and Prints Patient Data thus saving time when editing*/
	
	/* we are sure that the id exists as we checked before passing the id to viewRecord()*/
	patNode* ptrIdSearch=ptrHead;
	
	while(ptrIdSearch->ID!=id) 
	{
		ptrIdSearch=ptrIdSearch->ptrNext;
	}
	
	printf("\n1. Patient's ID: %d\n",ptrIdSearch->ID);
	printf("2. Patient's Name: %s\n",ptrIdSearch->NAME);
	printf("3. Patient's Sex: %c\n",ptrIdSearch->SEX);
	printf("4. Patient's Age: %d\n",ptrIdSearch->AGE);

	return ptrIdSearch;
}

void editRecord(patNode* ptrEditNode)
{
	u32 keyInput,id,age,editFlag=0;
	u8 name[30],sex;
	
	printf("\nWhat do you want to edit?\n");
	printf("1. ID\n");
	printf("2. Name\n");
	printf("3. Sex\n");
	printf("4. Age\n\n");
	printf("Your Choice: ");
	fflush(stdout);
	
	scanf("%d",&keyInput);
	
	switch(keyInput)
	{
		case 1: printf("Please enter the new ID: "); fflush(stdout);
				scanf("%d",&id); fflush(stdin);
				ptrEditNode->ID=id;
				editFlag=1;
				break;
		
		case 2: printf("Please enter the new Name: "); fflush(stdout);
				scanf("%[^\n]s",name); fflush(stdin);
				strncpy(ptrEditNode->NAME,name,30);
				editFlag=1;
				break;
		
		case 3: printf("Please enter the new Gender(M/F): "); fflush(stdout);
				scanf(" %c",&sex);
				ptrEditNode->SEX=sex;
				editFlag=1;
				break;
		case 4: printf("Please enter the new age: "); fflush(stdout);
				scanf("%d",&age);
				ptrEditNode->AGE=age;
				editFlag=1;
				break;
		
		default:printf("\nInvalid input\n");
				break; 
	}
	
	if(editFlag==1)
	{
		printf("\nYou Have Successfully Edited A Patient Record\n");
	}

}

void addReserv()
{
	u32 keyInput,id;
	
	printf("\nAvailable Appointment Slots Are:\n");
	for(u32 i=0; i<numSlots; i++)
	{
		if(resInfo[i].reservFlag==NOT_RESERVED)
		{
			printf("Time: %s |-> Appointment Slot Number: %d  \n",resInfo[i].time,i+1);
		}
	}
	printf("\nTo Go Back To Admin Mode Press 0\n");
	printf("\nPlease Enter The Slot Number: "); fflush(stdout);
	scanf("%d",&keyInput);
	
	if(keyInput==0) /* Exit back to admin mode */
	return;
	
	
	if( (keyInput>0&&keyInput<=5) && (resInfo[keyInput-1].reservFlag==NOT_RESERVED) ) 
	{
		printf("\nPlease Enter A Valid Patient ID To Reserve The Chosen Slot: "); fflush(stdout);
		scanf("%d",&id);
		if(checkID(id)==ID_EXISTS)
		{
			resInfo[keyInput-1].reservID=id;
			resInfo[keyInput-1].reservFlag=RESERVED;
			
			
			printf("\nAppointment Slot Reserved Successfully\n");
			printf("Mr/Ms %s's Appointment is at %s:\n",fetchPatNode(id)->NAME,resInfo[keyInput-1].time);
		}
		else
		{
			printf("\nPlease Enter A Valid Patient ID\n");
		}
	}
	else if(keyInput<0 || keyInput>5)
	{
		printf("\nPlease Enter a valid option. Exiting to Admin Mode....\n");
	}
	else if(resInfo[keyInput-1].reservFlag==RESERVED)
	{
		printf("Please Choose a Valid Appointment Slot. You think you are funny hah?");
	}
}

void viewReserv()
{
	printf("\n");
	for(u32 i=0; i<numSlots; i++)
	{
		if(resInfo[i].reservFlag==NOT_RESERVED)
		{
			printf("Time: %s |-> Appointment Slot Number: %d [ Not Reserved ]  \n",resInfo[i].time,i+1);
		}
		else if(resInfo[i].reservFlag==RESERVED)
		{
			printf("Time: %s |-> Appointment Slot Number: %d ",resInfo[i].time,i+1);
			printf("[ Reserved To ID: %d ]\n",resInfo[i].reservID);
		}
	}
}

void cancelReserv()
{
	u32 id,numReservSlots=0,cancelCounter=0;
	
	for(u32 i=0; i<numSlots; i++)
	{
		if(resInfo[i].reservFlag==RESERVED)
		{
			numReservSlots++; 
		}
	}
	
	if(numReservSlots!=0) 
	{
		/* meaning that if at least one slot is reserved you can go ahead and cancel */
		
		printf("\n\nPlease enter an ID to cancel its reservation: "); fflush(stdout);
		scanf("%d",&id);
		for(u32 i=0; i<numSlots; i++)
		{
			if(resInfo[i].reservID==id)
			{
				resInfo[i].reservFlag=NOT_RESERVED;
				cancelCounter++;
			}
		}
	}
	else
	{
		printf("\n\nAll Appointments are free and not reserved, you can't cancel any.");
		return;
	}
	
	if(cancelCounter>0)
		printf("\n\n%d Reservations Cancelled Successfully For ID: [%d]. ",cancelCounter,id);
	else /*if(cancelCounter=0)*/
		printf("\n\nThis ID Doesn't Have Any Reservations To Cancel.");
	
}

