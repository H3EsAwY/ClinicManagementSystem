/*
Project: Clinic Management System
Name: Hany Ali Elesawy
Date Started: 7/9/2021 
Date Finished: 9/9/2021
*/

#ifndef _CLINIC_H
#define _CLINIC_H

/* 			    |** Overall Description And Overview **|

Patients' data are stored in a linked list so that we can dynamically allocate
data as we need it. Saving space at the expense of slightly longer access time.
But on the otherhand adding or deleteing patients will be significantly easier,
faster and more space efficient.

We have 2 structures in the project. "PatNode" struct datatype to store patients
data in a Linked List and "reserv" struct datatype, objects of "reserv" can store
reservation data like:
1. Reservation time description
2. IDs of patients who reserved a slots
3. A flag indicating if the slot is reserved or not

*/

/*A PatientNode contains the patient's data and a pointer to next PatientNode*/
struct PatNode
{
	/*Patient Data*/
	u32 ID;
	u32 AGE;
	u8 NAME[30];
	u8 SEX;
	
	u32 reservNum;
	
	/*Pointer to next patient node */
	struct PatNode* ptrNext;
	
};
typedef struct PatNode patNode;

/* A struct data type for reservation slots information */
typedef struct
{
	char time[20];
	u32 reservID;
	u32 reservFlag;
}reserv;


/*------------------------------------Functions--------------------------------------*/

/* checkID(u32 id) ---->>>> return "0" -> id doesn't exist ||and|| return "1" -> id exists */
/* fetchPatNode() ---->>>> returns a pointer to the node containing the passed id, used to refrence names easily */
/* viewRecord returns a pointer to the viewed Node and Prints Patient Data thus saving time when editing */
/* editRecord() takes a PatientNode as an argument so it doesn't have to search for the id again saving time */

/*-----------------------------------------------------------------------------------*/
u32 checkID(u32 id); 
void addRecord(u32 id, u8 name[30], u8 sex, u32 age);
patNode* viewRecord(u32 id); 	 
void editRecord(patNode* ptrEditNode);

patNode* fetchPatNode(u32 id);
void addReserv();
void cancelReserv();
void viewReserv(); 			


#endif