/*
 * Name: Hany Ali Elesawy
 * Project: Clinic Management System
 * Date Started: 7/Sept/2021 
 * Date Finished: 8/Sept/2021
*/

#include <stdio.h>
#include "STD_Types.h"
#include "clinic.h"

#define ID_DOESNT_EXIST 0
#define ID_EXISTS 1

#define NOT_RESERVED 0
#define RESERVED 1

void main()
{
	u32 defPass=1234;
	u32 keyPress,inputPass,passTries=3;
	u32 sysExitFlag=0,adminExitFlag=0,userExitFlag=0;
	
	u32 id,age;
	u8 name[30],sex;
	
	
	while(sysExitFlag==0)
	{
		printf("Please Chose a Mode:\n");
		printf("1. Admin Mode\n");
		printf("2. User Mode\n");
		printf("3. Exit System\n\n");
		printf("Your Choice: ");
		fflush(stdout);
		scanf("%d",&keyPress);
		
		switch(keyPress)
		{
			case 1: /* Admin Mode */
					passTries=3;
					printf("\nPlease enter Admin password:");
					fflush(stdout);
					scanf("%d",&inputPass);
					passTries--;
			
					while( (inputPass!=defPass)&&(passTries!=0) )
					{
				
						printf("\nWrong Password, You Have %d Attempts Left\n",passTries);
						printf("Please enter Admin password: ");
						fflush(stdout);
						scanf("%d",&inputPass);
						if(inputPass!=defPass)
						passTries--;
					}
					if(passTries==0)
					{
						printf("\nNo Attempts Left, Please Try Again Later");
						return;
					}
			
					printf("\nLogin Successful\n");
					adminExitFlag=0;
					
					while(adminExitFlag==0)
					{
						printf("\n\nWelcome in Admin Mode\n");
						printf("1. Add new patient record. \n");
						printf("2. Edit Patient Record.\n");
						printf("3. Reserve a slot with the doctor.\n");
						printf("4. Cancel reservation.\n");
						printf("5. Exit Admin Mode.\n\n");
				
						printf("Your Choice: ");
						fflush(stdout);
						scanf("%d",&keyPress);
				
						switch(keyPress)
						{
							case 1: 
					
									printf("\nPlease Enter a New Patient's ID: "); fflush(stdout);
									scanf("%d",&id);
									fflush(stdin);
									
									/* if(checkID(id)==0) i.e if id doesn't exist it return 0 */
									if(checkID(id)==ID_DOESNT_EXIST) 
									{
										printf("\nPlease Enter The Patient's Name: "); fflush(stdout);
										scanf("%[^\n]s",name);
										//gets(name);
										
										printf("\nPlease Enter The Patient's Gender(M/F): "); fflush(stdout);
										scanf(" %c",&sex);
										
										printf("\nPlease Enter Mr/Ms %s's age: ",name); fflush(stdout);
										scanf("%d",&age);
										
										addRecord(id,name,sex,age);
										
										printf("\nPatient Record Added Successfully\n");
									}
									else
									{
										printf("\nEntry Rejected, ID occupied\n");
									}
									break;
						
							case 2: 
									printf("\nPlease Enter a Patient's ID To Edit His/Her Record : "); 
									fflush(stdout);
									scanf("%d",&id);
									
									 /* if(checkID(id)==1) i.e if id exists it return 1 */ 
									if(checkID(id)==ID_EXISTS)
									{
										/*a pointer to the PatientNode to be edited is stored here */
										patNode* ptrEditTemp; 
										
										/*viewRecord() returns a pointer the viewed PatientNode saving time*/
										ptrEditTemp=viewRecord(id); 
										editRecord(ptrEditTemp);
									}
									else
									printf("\nPlease enter a valid ID ");
									break;
					
							case 3: addReserv();
									break;
					
							case 4: viewReserv();
									cancelReserv();
									break;
						
							case 5: printf("Exitting Admin Mode....\n\n");
									adminExitFlag=1;
									break;
					
							default:printf("Invalid Entry, Try again.\n\n");
									break;
									
						}
					}
					break;
					
			
			case 2: 
					userExitFlag=0;
					while(userExitFlag==0)
					{
						printf("\n\nWelcome in User Mode\n");
						printf("1. View patient record.\n");
						printf("2. View today's reservations.\n");
						printf("3. Exit User Mode.\n");
						
						printf("\nYour Choice: ");
						fflush(stdout);
						scanf("%d",&keyPress);
						switch(keyPress)
						{
							case 1: printf("Please Enter Patient ID: "); fflush(stdout);
									scanf("%d",&id);
									if(checkID(id)==ID_EXISTS)
										viewRecord(id);
									else
										printf("\nPlease enter a valid ID ");
									break;
									
							case 2: viewReserv();
									break;
							
							case 3: userExitFlag=1;
									break;
							
							default:printf("Invalid Entry, Try again.\n\n");
									break;
						}
					}
					break;
					
			case 3: printf("Exitting System....\n\n");
					sysExitFlag=1; break;
					
			default:printf("Invalid Entry, Try again.\n\n");
					break;
					
		}
	}
	
}