#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include"LinkedList-header.h"

int main()
{
    int num;
    node* aadharList = NULL;
    node* aadharListLast = NULL;
    node* passportList = NULL;
    node* passportListLast = NULL;
    node* empcodeList = NULL;
    node* empcodeListLast = NULL;
    indexNode* indexList = NULL;
    indexNode* indexListLast = NULL;
    //index2Node* index2List = NULL;
    //index2Node* index2ListLast = NULL;
    int i,option,idty;
	int quit = 0;
    char idnumber[15];
    block b1;
    InitializeBlocks(&b1);
    Initialize_DB_LL(&aadharList,&aadharListLast,&passportList,&passportListLast,&empcodeList,&empcodeListLast);

    printf("WELCOME TO VNIT ACCOMMODATION CENTRE\n");
    while(quit==0)
	{
		printf("Choose the following by pressing corresponding value\n");
		printf("Insert Record - 0 | Remove Duplicates - 1 | Print Records - 2 | Print Sorted Records - 3 | Search - 4\n" );
		printf("Delete Record - 5 | Update Record - 6 | Special Request Allocation - 7 | Quit - 8\n");
		scanf("%d",&option);
		idnumber[0]='\0';
		switch(option)
		{
			case 0:
				{
					printf("How many records to Insert?");
					scanf("%d",&num);
					for(i=0;i<num;i++)
					{
						InsertRecord(&b1,&aadharList,&aadharListLast,&passportList,&passportListLast,&empcodeList,&empcodeListLast,&indexList,&indexListLast);
					}
				}
				break;
			case 1:
				{
					removeDuplicates(&b1,&aadharList,&aadharListLast,&passportList,&passportListLast,&empcodeList,&empcodeListLast,&indexList,&indexListLast);
					printf("Duplicates Removed");
				}
				break;
			case 2:
				{
					printRecords(aadharList,aadharListLast,passportList,passportListLast,empcodeList,empcodeListLast);
				}
				break;
			case 3:
				{
					printSortedRecords(indexList);
				}
				break;
			case 4:
				{
					search(indexList);
				}
				break;
			case 5:
				{
					deleteRecord(&b1,&aadharList,&aadharListLast,&passportList,&passportListLast,&empcodeList,&empcodeListLast,&indexList,&indexListLast);
				}
				break;
			case 6:
				{
					updateRecord(aadharList,aadharListLast,passportList,passportListLast,empcodeList,empcodeListLast,&indexList,&indexListLast);
				}
				break;
			case 7:
				{
					specialRequestAllocation(&b1,aadharList,aadharListLast,passportList,passportListLast,empcodeList,empcodeListLast);
				}
				break;
			case 8:
				{
					quit = 1;
					printf("Thank you");
				}
				break;
			default:
				{
					printf("Invalid choice");
				}
		}
	}
    return 0;
}
