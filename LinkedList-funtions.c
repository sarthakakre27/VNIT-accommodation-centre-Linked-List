#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include"BT19CSE099-Assign1-header.h"

//function for initializing the 3 dummy nodes by setting values to default
void InitializeNode(node* ptr)
{
    ptr->A1.accommodation_type[0] = '\0';
    ptr->A1.address[0] = '\0';
    ptr->A1.blockind = -1;
    ptr->A1.firstname[0] = '\0';
    ptr->A1.lastname[0] = '\0';
    ptr->A1.id.aadhaar[0] = '\0';
    ptr->A1.id.passport[0] = '\0';
    ptr->A1.id.empcode[0] = '\0';
}

//This function initializes the linked list of the Records by setting up the three dummy nodes for the 
//idtype = 0 , 1 , 2. 
void Initialize_DB_LL(node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr)
{
    node* aadharList = *aadharListAdr;
    node* aadharListLast = *aadharListLastAdr;
    node* passportList = *passportListAdr;
    node* passportListLast = *passportListLastAdr;
    node* empcodeList = *empcodeListAdr;
    node* empcodeListLast = *empcodeListLastAdr;
    //creating dummy nodes for the DB linked List
    aadharList = (node*)malloc(sizeof(node));
    *aadharListAdr = aadharList;
    InitializeNode(aadharList);
    aadharList->A1.idtype = -3;
    aadharListLast = aadharList;
    *aadharListLastAdr = aadharListLast;

    passportList = (node*)malloc(sizeof(node));
    *passportListAdr = passportList;
    InitializeNode(passportList);
    passportList->A1.idtype = -2;
    passportListLast = passportList;
    *passportListLastAdr = passportListLast;

    empcodeList = (node*)malloc(sizeof(node));
    *empcodeListAdr = empcodeList;
    InitializeNode(empcodeList);
    empcodeList->A1.idtype = -1;
    empcodeListLast = empcodeList;
    *empcodeListLastAdr = empcodeListLast;

    aadharList->prev = NULL;
    aadharListLast->next = passportList;
    passportList->prev = aadharListLast;
    passportListLast->next = empcodeList;
    empcodeList->prev = passportListLast;
    empcodeListLast->next = NULL;
}

//function to initialize blocks of 4 types of acommodation
void InitializeBlocks(block* b1)
{
    block_node* temp = NULL;
    b1->t1 = (block_node*)malloc(sizeof(block_node));
    block_node* t1end = b1->t1;
    t1end->ac = 0;
    b1->t2 = (block_node*)malloc(sizeof(block_node));
    block_node* t2end = b1->t2;
    t2end->ac = 0;
    b1->t3 = (block_node*)malloc(sizeof(block_node));
    block_node* t3end = b1->t3;
    t3end->ac = 0;
    b1->t4 = (block_node*)malloc(sizeof(block_node));
    block_node* t4end = b1->t4;
    t4end->ac = 0;
    int i = 0;
    for(i = 0; i < 9; i++)
    {
        temp = (block_node*)malloc(sizeof(block_node));
        t1end->next = temp;
        t1end = temp;
        t1end->ac = 0;
        t1end->next = NULL;

        temp = (block_node*)malloc(sizeof(block_node));
        t2end->next = temp;
        t2end = temp;
        t2end->ac = 0;
        t2end->next = NULL;

        temp = (block_node*)malloc(sizeof(block_node));
        t3end->next = temp;
        t3end = temp;
        t3end->ac = 0;
        t3end->next = NULL;

        temp = (block_node*)malloc(sizeof(block_node));
        t4end->next = temp;
        t4end = temp;
        t4end->ac = 0;
        t4end->next = NULL;

    }
}

//function for inserting a node for the Record -- this functions also sets the index field and marks accommodation block
void InsertRecord(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    node* aadharList = *aadharListAdr;
    node* aadharListLast = *aadharListLastAdr;
    node* passportList = *passportListAdr;
    node* passportListLast = *passportListLastAdr;
    node* empcodeList = *empcodeListAdr;
    node* empcodeListLast = *empcodeListLastAdr;
    node* newptr = NULL;//new node for new Record Entry
    node* search_ptr = NULL;
    node* trav_ptr = NULL;//ptr for traversing
    block_node* bptr = NULL;
    int LLindex;
    int i = 0;
	int found = 0;
	int choice;
	int avail = 0;
	int k;
    int id;//user scanf id type
	char t1[7]={'t','y','p','e','-','1','\0'};
	char t2[7]={'t','y','p','e','-','2','\0'};
	char t3[7]={'t','y','p','e','-','3','\0'};
	char t4[7]={'t','y','p','e','-','4','\0'};
	printf("INSERT RECORD\n");
	printf("Enter the type of accommodation\nEnter number accordingly\n");
	printf("Type-1 - 1 |  Type-2 - 2 | Type-3 - 3 | Type-4 - 4\n");
	scanf("%d",&choice);
	
	if(choice == 1)
	{
        bptr = b1->t1;
		for(k = 0;k < 10 && avail == 0;k++)
		{
			if(bptr->ac == 0)
			{
				avail = 1;
				bptr->ac = 1;
                newptr = (node*)malloc(sizeof(node));//allocating new node
                newptr->A1.blockind = k;//setting the block index in the particular type of accommodation that was found before
                strcpy(newptr->A1.accommodation_type,t1);
                k--;
			}
            bptr = bptr->next;
		}
	}
	else if(choice == 2)
	{
        bptr = b1->t2;
		for(k = 0;k < 10 && avail == 0;k++)
		{
			if(bptr->ac == 0)
			{
				avail = 1;
				bptr->ac = 1;
                newptr = (node*)malloc(sizeof(node));//allocating new node
                newptr->A1.blockind = k;//setting the block index in the particular type of accommodation that was found before
                strcpy(newptr->A1.accommodation_type,t2);
                k--;
			}
            bptr = bptr->next;
		}
	}
	else if(choice == 3)
	{
        bptr = b1->t3;
		for(k = 0;k < 10 && avail == 0;k++)
		{
			if(bptr->ac == 0)
			{
				avail = 1;
				bptr->ac = 1;
                newptr = (node*)malloc(sizeof(node));//allocating new node
                newptr->A1.blockind = k;//setting the block index in the particular type of accommodation that was found before
                strcpy(newptr->A1.accommodation_type,t3);
                k--;
			}
            bptr = bptr->next;
		}
	}
	else if(choice == 4)
	{
        bptr = b1->t4;
		for(k = 0;k < 10 && avail == 0;k++)
		{
			if(bptr->ac == 0)
			{
				avail = 1;
				bptr->ac = 1;
                newptr = (node*)malloc(sizeof(node));//allocating new node
                newptr->A1.blockind = k;//setting the block index in the particular type of accommodation that was found before
                strcpy(newptr->A1.accommodation_type,t4);
                k--;
			}
            bptr = bptr->next;
		}
	}

    if(k<10)
    {
        printf("Enter the id Type. Choose from following -  \n");
        printf(" 0 - AADHAR | 1 - PASSPORT | 2 - EMPCODE\n");
        scanf("%d",&id);

        if(id == 0)
        {
            if((aadharList == aadharListLast) && (passportList == passportListLast) && (empcodeList == empcodeListLast))
            {
                //first node to be recorded
                LLindex = 0;
                newptr->A1.LLindex = LLindex;
            }
            else//there is atleast 1 node
            {
                found = 0;
                search_ptr = aadharListLast;
                while(search_ptr != NULL && found == 0)//searching for node backwards
                {
                    if(search_ptr->A1.idtype >= 0)//ignoring dummy nodes
                    {
                        found = 1;
                        LLindex = search_ptr->A1.LLindex;
                    }
                    search_ptr = search_ptr->prev;
                }
                if(found == 1)
                {
                    newptr->A1.LLindex = LLindex + 1;
                    //Adjusting node indices greater than newptr->A1.LLindex
                    trav_ptr = passportList;
                    while(trav_ptr != NULL)
                    {
                        if(trav_ptr->A1.idtype >= 0 && trav_ptr->A1.LLindex >= newptr->A1.LLindex)//second condition implicit
                        {
                            trav_ptr->A1.LLindex++;
                        }
                        trav_ptr = trav_ptr->next;
                    }
                }
                else if(found == 0)
                {
                    search_ptr = passportList;
                    while(search_ptr != NULL && found == 0)//searching for node frontwards
                    {
                        if(search_ptr->A1.idtype >= 0)//ignoring dummy nodes
                        {
                            found = 1;
                            LLindex = search_ptr->A1.LLindex;
                        }
                        search_ptr = search_ptr->next;
                    }
                    newptr->A1.LLindex = LLindex;
                    //Adjusting node indices greater than newptr->A1.LLindex
                    trav_ptr = passportList;
                    while(trav_ptr != NULL)
                    {
                        if(trav_ptr->A1.idtype >= 0 && trav_ptr->A1.LLindex >= newptr->A1.LLindex)//second condition implicit
                        {
                            trav_ptr->A1.LLindex++;
                        }
                        trav_ptr = trav_ptr->next;
                    }
                }
            
            }

            //setting the record
            newptr->A1.idtype = 0;
            setRecord(newptr);
            //Add to IndexList - newptr->A1.LLindex
            InsertToIndexLL(newptr,indexListAdr,indexListLastAdr);
            newptr->next = aadharListLast->next;
            newptr->prev = passportList->prev;
            aadharListLast->next = newptr;
            passportList->prev = newptr;
            aadharListLast = newptr;
            *aadharListLastAdr = newptr;
            newptr = NULL;
        }

        else if(id == 1)
        {
            if(aadharList == aadharListLast && passportList == passportListLast && empcodeList == empcodeListLast)
            {
                //first node to be recorded
                LLindex = 0;
                newptr->A1.LLindex = LLindex;
            }
            else//there is atleast 1 node
            {
                found = 0;
                search_ptr = passportListLast;
                while(search_ptr != NULL && found == 0)//searching for node backwards
                {
                    if(search_ptr->A1.idtype >= 0)//ignoring dummy nodes
                    {
                        found = 1;
                        LLindex = search_ptr->A1.LLindex;
                    }
                    search_ptr = search_ptr->prev;
                }
                if(found == 1)
                {
                    newptr->A1.LLindex = LLindex + 1;
                    //Adjusting node indices greater than newptr->A1.LLindex
                    trav_ptr = empcodeList;//incrementing indices of empcodeList
                    while(trav_ptr != NULL)
                    {
                        if(trav_ptr->A1.idtype >= 0 && trav_ptr->A1.LLindex >= newptr->A1.LLindex)//second condition implicit
                        {
                            trav_ptr->A1.LLindex++;
                        }
                        trav_ptr = trav_ptr->next;
                    }
                }
                else if(found == 0)
                {
                    search_ptr = empcodeList;
                    while(search_ptr != NULL && found == 0)//searching for node frontwards
                    {
                        if(search_ptr->A1.idtype >= 0)//ignoring dummy nodes
                        {
                            found = 1;
                            LLindex = search_ptr->A1.LLindex;
                        }
                        search_ptr = search_ptr->next;
                    }
                    newptr->A1.LLindex = LLindex;
                    //Adjusting node indices greater than newptr->A1.LLindex
                    trav_ptr = empcodeList;
                    while(trav_ptr != NULL)
                    {
                        if(trav_ptr->A1.idtype >= 0 && trav_ptr->A1.LLindex >= newptr->A1.LLindex)//second condition implicit
                        {
                            trav_ptr->A1.LLindex++;
                        }
                        trav_ptr = trav_ptr->next;
                    }
                }
            
            }

            //setting the record
            newptr->A1.idtype = 1;
            setRecord(newptr);
            //Add to IndexList - newptr->A1.LLindex
            InsertToIndexLL(newptr,indexListAdr,indexListLastAdr);
            newptr->next = passportListLast->next;
            newptr->prev = empcodeList->prev;
            passportListLast->next = newptr;
            empcodeList->prev = newptr;
            passportListLast = newptr;
            *passportListLastAdr = newptr;
            newptr = NULL;
        }

        else if(id == 2)
        {
            if(aadharList == aadharListLast && passportList == passportListLast && empcodeList == empcodeListLast)
            {
                //first node to be recorded
                LLindex = 0;
                newptr->A1.LLindex = LLindex;
            }
            else//there is atleast 1 node
            {
                found = 0;
                search_ptr = empcodeListLast;
                while(search_ptr != NULL && found == 0)//searching for node backwards
                {
                    if(search_ptr->A1.idtype >= 0)//ignoring dummy nodes
                    {
                        found = 1;
                        LLindex = search_ptr->A1.LLindex;
                    }
                    search_ptr = search_ptr->prev;
                }
                if(found == 1)//a node has to be present at the back
                {
                    newptr->A1.LLindex = LLindex + 1;
                }
            
            }

            //setting the record
            newptr->A1.idtype = 2;
            setRecord(newptr);
            //Add to IndexList - newptr->A1.LLindex
            InsertToIndexLL(newptr,indexListAdr,indexListLastAdr);
            newptr->next = empcodeListLast->next;//NULL
            newptr->prev = empcodeListLast;
            empcodeListLast->next = newptr;
            empcodeListLast = newptr;
            *empcodeListLastAdr = newptr;
            empcodeListLast->next = NULL;
            newptr = NULL;
        }
    }
    else
    {
        printf("Block Not Available\n");
    }
}

//function to add a node to the indexList at proper position soted according to the firstname and dispute resolved by the lastname
//takes O(n) to insert at coorect position -- worst case
void InsertToIndexLL(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    indexNode* indexList = *indexListAdr;
    indexNode* indexListLast = *indexListLastAdr;
    indexNode* nextnode = NULL;
    indexNode* prevnode = NULL;
    indexNode* travptr = NULL;//traversing
    indexNode* newIndexNode = (indexNode*)malloc(sizeof(indexNode));
    if(indexList == indexListLast && indexList == NULL)//both NULL
    {
        indexList = newIndexNode;
        *indexListAdr = newIndexNode;
        indexListLast = indexList;
        *indexListLastAdr = indexList;
        indexListLast->next = NULL;
        indexList->prev = NULL;
        indexList->llptr = ptr;
    }
    else if(strcmp(ptr->A1.firstname,indexList->llptr->A1.firstname) <= 0)
    {
        if(strcmp(ptr->A1.firstname,indexList->llptr->A1.firstname) < 0)
        {
            newIndexNode->next = indexList;
            indexList->prev = newIndexNode;
            newIndexNode->prev = NULL;
            indexList = newIndexNode;
            *indexListAdr = newIndexNode;
            indexList->llptr = ptr;
        }
        else// == 0
        {
            if(strcmp(ptr->A1.lastname,indexList->llptr->A1.lastname) <= 0)
            {
                newIndexNode->next = indexList;
                indexList->prev = newIndexNode;
                newIndexNode->prev = NULL;
                indexList = newIndexNode;
                *indexListAdr = newIndexNode;
                indexList->llptr = ptr;
            }
            else// > 0
            {
                if(indexList->next == NULL)//indexList == indexListLast single node
                {
                    indexList->next = newIndexNode;
                    newIndexNode->prev = indexList;
                    indexListLast = newIndexNode;
                    *indexListLastAdr = newIndexNode;
                    indexListLast->next = NULL;
                    indexListLast->llptr = ptr;
                }
                else//has at atleast two nodes
                {
                    nextnode = indexList->next;
                    newIndexNode->next = nextnode;
                    newIndexNode->prev = indexList;
                    indexList->next = newIndexNode;
                    nextnode->prev = newIndexNode;
                    newIndexNode->llptr = ptr;
                }
            }
        }
    }
    else if(strcmp(ptr->A1.firstname,indexListLast->llptr->A1.firstname) >= 0)
    {
        if(strcmp(ptr->A1.firstname,indexListLast->llptr->A1.firstname) > 0)
        {
            indexListLast->next = newIndexNode;
            newIndexNode->prev = indexListLast;
            indexListLast = newIndexNode;
            *indexListLastAdr = newIndexNode;
            newIndexNode->next = NULL;
            newIndexNode->llptr = ptr;
        }
        else// == 0
        {
            if(strcmp(ptr->A1.lastname,indexListLast->llptr->A1.lastname) >= 0)
            {
                indexListLast->next = newIndexNode;
                newIndexNode->prev = indexListLast;
                indexListLast = newIndexNode;
                *indexListLastAdr = newIndexNode;
                newIndexNode->next = NULL;
                newIndexNode->llptr = ptr;
            }
            else// < 0
            {
                if(indexListLast->prev == NULL)//one node
                {
                    newIndexNode->next = indexListLast;
                    indexListLast->prev = newIndexNode;
                    indexList = newIndexNode;
                    *indexListAdr = newIndexNode;
                    indexList->prev = NULL;
                    newIndexNode->llptr = ptr;
                }
                else
                {
                    prevnode = indexListLast->prev;
                    newIndexNode->next = indexListLast;
                    newIndexNode->prev = prevnode;
                    prevnode->next = newIndexNode;
                    indexListLast->prev = newIndexNode;
                    newIndexNode->llptr = ptr;
                }
            }
        }
    }
    else//to be added somewhere in between -- not at the end nodes
    {
        travptr = indexList;
        while(travptr != NULL && (strcmp(travptr->llptr->A1.firstname,ptr->A1.firstname) < 0))
        {
            travptr = travptr->next;
        }
        if(strcmp(ptr->A1.firstname,travptr->llptr->A1.firstname) == 0)
        {
            if(strcmp(ptr->A1.lastname,travptr->llptr->A1.lastname) <= 0)
            {
                prevnode = travptr->prev;
                newIndexNode->next = travptr;
                newIndexNode->prev = prevnode;
                prevnode->next = newIndexNode;
                travptr->prev = newIndexNode;
                newIndexNode->llptr = ptr;
            }
            else// >
            {
                nextnode = travptr->next;
                newIndexNode->next = nextnode;
                newIndexNode->prev = travptr;
                travptr->next = newIndexNode;
                nextnode->prev = newIndexNode;
                newIndexNode->llptr = ptr;
            }
        }
        else//(strcmp(travptr->llptr->A1.firstname,ptr->A1.firstname) > 0)
        {
            prevnode = travptr->prev;
            newIndexNode->next = travptr;
            newIndexNode->prev = prevnode;
            prevnode->next = newIndexNode;
            travptr->prev = newIndexNode;
            newIndexNode->llptr = ptr;
        }

    }
}


//funtion to print sorted records -- infers the indexList to the work
void printSortedRecords(indexNode* indexList)
{
    //in the index list, instead of storing index as an integer we have stored the pointer to that record node
    //which inherently brings the index of that node and also helps in faster access of record fields to print 
    //in sorted order
    indexNode* travptr = indexList;
    while(travptr != NULL)
    {
        printf("Firstname- %s\n",travptr->llptr->A1.firstname);
	    printf("Lastname- %s\n",travptr->llptr->A1.lastname);
		printf("Accommodation type- %s\n",travptr->llptr->A1.accommodation_type);
		printf("ID type- %d\n",travptr->llptr->A1.idtype);
        if(travptr->llptr->A1.idtype == 0)
        {
            printf("AADHAR- %s\n",travptr->llptr->A1.id.aadhaar);
        }
        else if(travptr->llptr->A1.idtype == 1)
        {
            printf("PASSPORT- %s\n",travptr->llptr->A1.id.passport);
        }
        else
        {
            printf("EMPCODE- %s\n",travptr->llptr->A1.id.empcode);
        }
		printf("Block number- %d\n",travptr->llptr->A1.blockind);
		printf("Address- %s\n\n",travptr->llptr->A1.address);

        travptr = travptr->next;
    }
}

//funtion to set the record fields
void setRecord(node* ptr)
{
	printf("Enter first name\n");
	scanf("%s",ptr->A1.firstname);
	printf("Enter last name\n");
	scanf("%s",ptr->A1.lastname);
	if(ptr->A1.idtype == 0)
	{
		printf("Enter AADHAAR NO.\n");
		scanf("%s",ptr->A1.id.aadhaar);
        ptr->A1.id.empcode[0] = '\0';
        ptr->A1.id.passport[0] = '\0';
	}
	else if(ptr->A1.idtype == 1)
	{
		printf("Enter PASSPORT NO.\n");
		scanf("%s",ptr->A1.id.passport);
        ptr->A1.id.aadhaar[0] = '\0';
        ptr->A1.id.empcode[0] = '\0';
	}
	else
	{
		printf("Enter EMPLOYEE CODE.\n");
		scanf("%s",ptr->A1.id.empcode);
        ptr->A1.id.aadhaar[0] = '\0';
        ptr->A1.id.passport[0] = '\0';
	}
	fflush(stdin);
	printf("Enter address\n");
	gets(ptr->A1.address);
    
}

//funtion to print the records in order -- aadhar > passport > empcode
void printRecords(node* aadharList,node* aadharListLast,node* passportList,node* passportListLast,node* empcodeList,node* empcodeListLast)
{
    node* ptr = aadharList;
    if(aadharList == aadharListLast && passportList == passportListLast && empcodeList == empcodeListLast)//all point to dummy nodes
    {
        printf("NO RECORDS\n");
    }
    else
    {
        //printing data linearly as the LL is sorted on basis of idtype i.e. aadhar > passport > empcode
        while(ptr != NULL)
        {
            if(ptr->A1.idtype >= 0)//ignoring dummy nodes
            {
                printf("Firstname- %s\n",ptr->A1.firstname);
			    printf("Lastname- %s\n",ptr->A1.lastname);
			    printf("Accommodation type- %s\n",ptr->A1.accommodation_type);
			    printf("ID type- %d\n",ptr->A1.idtype);
                if(ptr->A1.idtype == 0)
                {
                    printf("AADHAR- %s\n",ptr->A1.id.aadhaar);
                }
                else if(ptr->A1.idtype == 1)
                {
                    printf("PASSPORT- %s\n",ptr->A1.id.passport);
                }
                else
                {
                    printf("EMPCODE- %s\n",ptr->A1.id.empcode);
                }
			    printf("Block number- %d\n",ptr->A1.blockind);
			    printf("Address- %s\n\n",ptr->A1.address);
            }
            ptr = ptr->next;
        }
    }
}

//function to remove duplicates in the record LinkList
//also adjusts the index of each node and demarks the allocated block of type-accommodation
void removeDuplicates(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    int i = 0;
    node* aadharList = *aadharListAdr;
    node* aadharListLast = *aadharListLastAdr;
    node* passportList = *passportListAdr;
    node* passportListLast = *passportListLastAdr;
    node* empcodeList = *empcodeListAdr;
    node* empcodeListLast = *empcodeListLastAdr;
    node* ptr1 = NULL;//outer traversal
    node* ptr2 = NULL;//inner traversal
    node* prevnode = NULL;//prev to temp
    node* nextnode = NULL;//next to temp
    node* tempnode = NULL;//temp to be freed
    node* ptr3 = NULL;//for changing indices
    block_node* bptr = NULL;

    //condition for idtype = 0
    if(aadharList == aadharListLast)
    {
        //no nodes -- no duplicates
    }
    else if(aadharList->next == aadharListLast)
    {
        //single node case -- no duplicates
    }
    else
    {
        ptr1 = aadharList->next;
        while(ptr1 != passportList)
        {
            ptr2 = ptr1->next;
            while(ptr2 != passportList)
            {
                if(strcmp(ptr2->A1.id.aadhaar,ptr1->A1.id.aadhaar) == 0)
                {
                    tempnode = ptr2;//node to be freed
                    //setting block index to 0 --free block
                    if(ptr2->A1.accommodation_type[5] == '1')
                    {
                        //b1[0].t1[ptr2->A1.blockind] = 0;
                        bptr = b1->t1;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '2')
                    {
                        //b1[0].t2[ptr2->A1.blockind] = 0;
                        bptr = b1->t2;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '3')
                    {
                        //b1[0].t3[ptr2->A1.blockind] = 0;
                        bptr = b1->t3;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '4')
                    {
                        //b1[0].t4[ptr2->A1.blockind] = 0;
                        bptr = b1->t4;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    prevnode = ptr2->prev;
                    nextnode = ptr2->next;
                    prevnode->next = nextnode;
                    nextnode->prev = prevnode;
                    if(tempnode == aadharListLast)
                    {
                        aadharListLast = aadharListLast->prev;
                        *aadharListLastAdr = aadharListLast;
                    }
                    updateIndexLL(tempnode,indexListAdr,indexListLastAdr);
                    //free(tempnode);
                    ptr2 = nextnode;

                    ptr3 = nextnode;
                    while(ptr3 != NULL)
                    {
                        if(ptr3->A1.idtype >= 0)//ignoring dummy nodes
                        {
                            ptr3->A1.LLindex--;//decrementing indices
                        }
                        ptr3 = ptr3->next;
                    }
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
               
            ptr1 = ptr1->next;
        }
    }

    //condition for idtype = 1
    if(passportList == passportListLast)
    {
        //no nodes -- no duplicates
    }
    else if(passportList->next == passportListLast)
    {
        //single node case -- no duplicates
    }
    else
    {
        ptr1 = passportList->next;
        while(ptr1 != empcodeList)
        {
            ptr2 = ptr1->next;
            while(ptr2 != empcodeList)
            {
                if(strcmp(ptr2->A1.id.passport,ptr1->A1.id.passport) == 0)
                {
                    tempnode = ptr2;
                    //setting block index to 0 --free block
                    if(ptr2->A1.accommodation_type[5] == '1')
                    {
                        //b1[0].t1[ptr2->A1.blockind] = 0;
                        bptr = b1->t1;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '2')
                    {
                        //b1[0].t2[ptr2->A1.blockind] = 0;
                        bptr = b1->t2;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '3')
                    {
                        //b1[0].t3[ptr2->A1.blockind] = 0;
                        bptr = b1->t3;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '4')
                    {
                        //b1[0].t4[ptr2->A1.blockind] = 0;
                        bptr = b1->t4;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    prevnode = ptr2->prev;
                    nextnode = ptr2->next;
                    prevnode->next = nextnode;
                    nextnode->prev = prevnode;
                    if(tempnode == passportListLast)
                    {
                        passportListLast = passportListLast->prev;
                        *passportListLastAdr = passportListLast;
                    }
                    updateIndexLL(tempnode,indexListAdr,indexListLastAdr);
                    //free(tempnode);
                    ptr2 = nextnode;

                    ptr3 = nextnode;
                    while(ptr3 != NULL)
                    {
                        if(ptr3->A1.idtype >= 0)//ignoring dummy nodes
                        {
                            ptr3->A1.LLindex--;//decrementing indices
                        }
                        ptr3 = ptr3->next;
                    }
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
               
            ptr1 = ptr1->next;
        }
    }

    //condition for idtype = 2
    if(empcodeList == empcodeListLast)
    {
        //no nodes -- no duplicates
    }
    else if(empcodeList->next == empcodeListLast)
    {
        //single node case -- no duplicates
    }
    else
    {
        ptr1 = empcodeList->next;
        while(ptr1 != NULL)
        {
            ptr2 = ptr1->next;
            while(ptr2 != NULL)
            {
                if(strcmp(ptr2->A1.id.empcode,ptr1->A1.id.empcode) == 0)
                {
                    tempnode = ptr2;
                    //setting block index to 0 --free block
                    if(ptr2->A1.accommodation_type[5] == '1')
                    {
                        //b1[0].t1[ptr2->A1.blockind] = 0;
                        bptr = b1->t1;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '2')
                    {
                        //b1[0].t2[ptr2->A1.blockind] = 0;
                        bptr = b1->t2;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '3')
                    {
                        //b1[0].t3[ptr2->A1.blockind] = 0;
                        bptr = b1->t3;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    else if(ptr2->A1.accommodation_type[5] == '4')
                    {
                        //b1[0].t4[ptr2->A1.blockind] = 0;
                        bptr = b1->t4;
                        for(i=0;i<ptr2->A1.blockind;i++)
                        {
                            bptr = bptr->next;
                        }
                        bptr->ac = 0;
                    }
                    prevnode = ptr2->prev;
                    nextnode = ptr2->next;
                    prevnode->next = nextnode;
                    if(nextnode != NULL)
                    {
                        nextnode->prev = prevnode;
                    }
                    else
                    {
                        empcodeListLast = prevnode;
                        *empcodeListLastAdr = empcodeListLast;
                        empcodeListLast->next = NULL;
                    }
                    updateIndexLL(tempnode,indexListAdr,indexListLastAdr);
                    //free(tempnode);
                    ptr2 = nextnode;

                    ptr3 = nextnode;
                    while(ptr3 != NULL)
                    {
                        if(ptr3->A1.idtype >= 0)//ignoring dummy nodes
                        {
                            ptr3->A1.LLindex--;//decrementing indices
                        }
                        ptr3 = ptr3->next;
                    }
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
               
            ptr1 = ptr1->next;
        }
    }
}

//function to delete record from the main LinkedList
//also adjusts the index of each node and demarks the block -- type-accommodation
void deleteRecord(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    int i = 0;
    node* aadharList = *aadharListAdr;
    node* aadharListLast = *aadharListLastAdr;
    node* passportList = *passportListAdr;
    node* passportListLast = *passportListLastAdr;
    node* empcodeList = *empcodeListAdr;
    node* empcodeListLast = *empcodeListLastAdr;
    int found = 0;
    int typeid;
    char numid[15];
    numid[0] = '\0';
    node* travptr = NULL;
    node* foundptr = NULL;
    node* prevnode = NULL;
    node* nextnode = NULL;
    node* updateptr = NULL;
    block_node* bptr = NULL;
    printf("Enter the idType - \n");
    scanf("%d",&typeid);
    printf("Enter idNum - \n");
    scanf("%s",numid);

    if(typeid == 0)
    {
        if(aadharList == aadharListLast)//no node -- point to dummy node
        {
            printf("Record Not Found\n");
        }
        else
        {
            found = 0;
            travptr = aadharList;
            while(travptr != passportList && found == 0)
            {
                if(strcmp(travptr->A1.id.aadhaar,numid) == 0)
                {
                    found = 1;
                    foundptr = travptr;
                }
                travptr = travptr->next;
            }

            if(found == 1)
            {
                //resetting the allocated block index to 0
                if(foundptr->A1.accommodation_type[5] == '1')
                {
                    //b1[0].t1[foundptr->A1.blockind] = 0;
                    bptr = b1->t1;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '2')
                {
                    //b1[0].t2[foundptr->A1.blockind] = 0;
                    bptr = b1->t2;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '3')
                {
                    //b1[0].t3[foundptr->A1.blockind] = 0;
                    bptr = b1->t3;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '4')
                {
                    //b1[0].t4[foundptr->A1.blockind] = 0;
                    bptr = b1->t4;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }

                if(foundptr == aadharListLast)
                {
                    aadharListLast = aadharListLast->prev;
                    *aadharListLastAdr = aadharListLast;
                }
                prevnode = foundptr->prev;
                nextnode = foundptr->next;
                //delete in indexLL and also free it there
                updateIndexLL(foundptr,indexListAdr,indexListLastAdr);
                prevnode->next = nextnode;
                nextnode->prev = prevnode;

                updateptr = nextnode;
                while(updateptr != NULL)
                {
                    if(updateptr->A1.idtype >= 0)//ignoring dummy nodes
                    {
                        updateptr->A1.LLindex--;//adjusting the index in the linked list
                    }
                    updateptr = updateptr->next;
                }
                
            }
            else//found == 0
            {
                printf("Record Not Found\n");
            }
        }

    }
    else if(typeid == 1)
    {
        if(passportList == passportListLast)//no node -- point to dummy node
        {
            printf("Record Not Found\n");
        }
        else
        {
            found = 0;
            travptr = passportList;
            while(travptr != empcodeList && found == 0)
            {
                if(strcmp(travptr->A1.id.passport,numid) == 0)
                {
                    found = 1;
                    foundptr = travptr;
                }
                travptr = travptr->next;
            }

            if(found == 1)
            {
                //resetting the allocated block index to 0
                if(foundptr->A1.accommodation_type[5] == '1')
                {
                    //b1[0].t1[foundptr->A1.blockind] = 0;
                    bptr = b1->t1;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '2')
                {
                    //b1[0].t2[foundptr->A1.blockind] = 0;
                    bptr = b1->t2;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '3')
                {
                    //b1[0].t3[foundptr->A1.blockind] = 0;
                    bptr = b1->t3;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '4')
                {
                    //b1[0].t4[foundptr->A1.blockind] = 0;
                    bptr = b1->t4;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }

                if(foundptr == passportListLast)
                {
                    passportListLast = passportListLast->prev;
                    *passportListLastAdr = passportListLast;
                }
                prevnode = foundptr->prev;
                nextnode = foundptr->next;
                //delete in indexLL and also free it there
                updateIndexLL(foundptr,indexListAdr,indexListLastAdr);
                prevnode->next = nextnode;
                nextnode->prev = prevnode;
                
                updateptr = nextnode;
                while(updateptr != NULL)
                {
                    if(updateptr->A1.idtype >= 0)
                    {
                        updateptr->A1.LLindex--;//adjusting the index in the linked list
                    }
                    updateptr = updateptr->next;
                }
            }
            else//found == 0
            {
                printf("Record Not Found\n");
            }
        }

    }
    else if(typeid == 2)
    {
        if(empcodeList == empcodeListLast)//no node -- point to dummy node
        {
            printf("Record Not Found\n");
        }
        else
        {
            found = 0;
            travptr = empcodeList;
            while(travptr != NULL && found == 0)
            {
                if(strcmp(travptr->A1.id.empcode,numid) == 0)
                {
                    found = 1;
                    foundptr = travptr;
                }
                travptr = travptr->next;
            }

            if(found == 1)
            {
                //resetting the allocated block index to 0
                if(foundptr->A1.accommodation_type[5] == '1')
                {
                    //b1[0].t1[foundptr->A1.blockind] = 0;
                    bptr = b1->t1;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '2')
                {
                    //b1[0].t2[foundptr->A1.blockind] = 0;
                    bptr = b1->t2;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '3')
                {
                    //b1[0].t3[foundptr->A1.blockind] = 0;
                    bptr = b1->t3;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }
                else if(foundptr->A1.accommodation_type[5] == '4')
                {
                    //b1[0].t4[foundptr->A1.blockind] = 0;
                    bptr = b1->t4;
                    for(i=0;i<foundptr->A1.blockind;i++)
                    {
                        bptr = bptr->next;
                    }
                    bptr->ac = 0;
                }

                if(foundptr == empcodeListLast)//last node case
                {
                    empcodeListLast = empcodeListLast->prev;
                    *empcodeListLastAdr = empcodeListLast;
                    empcodeListLast->next = NULL;
                    //delete in indexLL and also free it there
                    updateIndexLL(foundptr,indexListAdr,indexListLastAdr);
                }
                else//not a last node
                {
                    prevnode = foundptr->prev;
                    nextnode = foundptr->next;
                    //delete in indexLL and also free it there
                    updateIndexLL(foundptr,indexListAdr,indexListLastAdr);
                    prevnode->next = nextnode;
                    nextnode->prev = prevnode;

                    updateptr = nextnode;
                    while(updateptr != NULL)
                    {
                        if(updateptr->A1.idtype >= 0)
                        {
                            updateptr->A1.LLindex--;//adjusting the index in the linked list
                        }
                        updateptr = updateptr->next;
                    }
                }
                
            }
            else//found == 0
            {
                printf("Record Not Found\n");
            }
        }

    }
}

//function to update the index LinkedList after deletion and updatation in the main LinkedList of Records
void updateIndexLL(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    indexNode* indexList = *indexListAdr;
    indexNode* indexListLast = *indexListLastAdr;
    int found = 0;
    indexNode* travptr = indexList;
    indexNode* foundptr = NULL;
    indexNode* tempnode = NULL;
    indexNode* prevnode = NULL;
    indexNode* nextnode = NULL;
    while(travptr != NULL && found == 0)
    {
        if(travptr->llptr == ptr)
        {
            found = 1;
            foundptr = travptr;
        }
        travptr = travptr->next;
    }

    if(found == 1)
    {
        if(foundptr == indexList)//first node
        {
            tempnode = indexList;
            indexList = indexList->next;
            *indexListAdr = indexList;
            if(indexList == NULL)//there was only 1 indexNode
            {
                indexListLast = NULL;
                *indexListLastAdr = NULL;
            }
            else
            {
                indexList->prev = NULL;
            }
            free(tempnode);
            tempnode = NULL;
            free(ptr);

        }
        else if(foundptr == indexListLast)//last node
        {
            tempnode = indexListLast;
            indexListLast = indexListLast->prev;
            *indexListLastAdr = indexListLast;
            if(indexListLast == NULL)//there was only 1 indexNode
            {
                indexList = NULL;
                *indexListAdr = NULL;
            }
            else
            {
                indexListLast->next = NULL;
            }
            free(tempnode);
            tempnode = NULL;
            free(ptr);
        }
        else//somewhere in between
        {
            tempnode = foundptr;
            prevnode = foundptr->prev;
            nextnode = foundptr->next;
            prevnode->next = nextnode;
            nextnode->prev = prevnode;
            free(tempnode);
            tempnode = NULL;
            free(ptr);
        }
    }
}

//function to update record fields -- calls updateindexList on updatation of the first and last names
void updateRecord(node* aadharList,node* aadharListLast,node* passportList,node* passportListLast,node* empcodeList,node* empcodeListLast,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    char fname[50];
	char lname[50];
	char acctype[20];
	int typeid;
	char numid[15];
	char aadhaar[15];
	char passport[15];
	char empcode[15];
	char address[50];
	int found = 0,choice;
    node* travptr = NULL;
    node* foundptr = NULL;
	
	
	printf("Enter idtype\n");
    printf("AADHAR - 0 | PASSPORT - 1 | EMPCODE - 2\n");
	scanf("%d",&typeid);
	printf("Enter idnum\n");
	scanf("%s",&numid);

    if(typeid == 0)
    {
        travptr = aadharList;
        found = 0;
        while(travptr != passportList && found == 0)
        {
            if(strcmp(travptr->A1.id.aadhaar,numid) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }
    else if(typeid == 1)
    {
        travptr = passportList;
        found = 0;
        while(travptr != empcodeList && found == 0)
        {
            if(strcmp(travptr->A1.id.passport,numid) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }
    else if(typeid == 2)
    {
        travptr = empcodeList;
        found = 0;
        while(travptr != NULL && found == 0)
        {
            if(strcmp(travptr->A1.id.empcode,numid) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }

    if(found == 1)
    {
        printf("press the follwing number to update accordingly\n");
	    printf("firstname - 0 | lastname - 1 | accommodation type - 2 | idtype - 3 | idnum - 4 | address - 5 \n");
	    scanf("%d",&choice);
	
	    switch(choice)
	    {
		    case 0:
			    {
				    printf("Enter firstname to update\n");
				    scanf("%s",&fname);
				    strcpy(foundptr->A1.firstname,fname);
                    changeIndexOnUpdate(foundptr,indexListAdr,indexListLastAdr);
			    }
			    break;
		    case 1:
			    {
				    printf("Enter lastname to update\n");
				    scanf("%s",&lname);
				    strcpy(foundptr->A1.lastname,lname);
                    changeIndexOnUpdate(foundptr,indexListAdr,indexListLastAdr);
			    }
			    break;
		    case 2:
			    {
				    printf("Accommodation type can be requested to change in main menu with SpecialRequestAllocation\n");
			    }
			    break;
		    case 3:
			    {
				    printf("Idtype once entered cannot be updated, to record entry with \n");
                    printf("new idtype and idnum delete record in main menu and insert with update \n");
			    }
			    break;
		    case 4:
			    {
                    //update wrongly entered idnumber
				    if(typeid == 0)
				    {
					    printf("Enter AADHAAR to update\n");
					    scanf("%s",&aadhaar);
					    strcpy(foundptr->A1.id.aadhaar,aadhaar);
				    }
				    else if(typeid == 1)
				    {
					    printf("Enter PASSPORT to update\n");
					    scanf("%s",&passport);
					    strcpy(foundptr->A1.id.passport,passport);
				    }
				    else if(typeid == 2)
				    {
					    printf("Enter EMPCODE to update\n");
					    scanf("%s",&empcode);
					    strcpy(foundptr->A1.id.empcode,empcode);
				    }
			    }
			    break;
		    case 5:
			    {
				    printf("Enter address to update\n");
				    scanf("%d",&address);
				    strcpy(foundptr->A1.address,address);
			    }
			    break;
		    default:
			    {
				    printf("INVALID CHOICE\n");
			    }
			    break;
			
	    }
    }
    else//found == 0
    {
        printf("Record Not Found\n");
    }

}

//function to update the indexLinkedList after update in the main LinkedList
void changeIndexOnUpdate(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr)
{
    int found = 0;
    indexNode* indexList = *indexListAdr;
    indexNode* indexListLast = *indexListLastAdr;
    indexNode* travptr = indexList;
    indexNode* foundptr = NULL;
    indexNode* tempnode = NULL;
    indexNode* prevnode = NULL;
    indexNode* nextnode = NULL;
    while(travptr != NULL && found == 0)
    {
        if(travptr->llptr == ptr)
        {
            found = 1;
            foundptr = travptr;
        }
        travptr = travptr->next;
    }

    if(found == 1)//extra guard condition -- has to be present
    {
        if(foundptr == indexList)//first node
        {
            tempnode = indexList;
            indexList = indexList->next;
            *indexListAdr = indexList;
            if(indexList == NULL)//there was only 1 indexNode
            {
                indexListLast = NULL;
                *indexListLastAdr = NULL;
            }
            else
            {
                indexList->prev = NULL;
            }
            free(tempnode);
            tempnode = NULL;
            InsertToIndexLL(ptr,indexListAdr,indexListLastAdr);
        }
        else if(foundptr == indexListLast)//last node
        {
            tempnode = indexListLast;
            indexListLast = indexListLast->prev;
            *indexListLastAdr = indexListLast;
            if(indexListLast == NULL)//there was only 1 indexNode
            {
                indexList = NULL;
                *indexListAdr = NULL;
            }
            else
            {
                indexListLast->next = NULL;
            }
            free(tempnode);
            tempnode = NULL;
            InsertToIndexLL(ptr,indexListAdr,indexListLastAdr);
        }
        else//somewhere in between
        {
            tempnode = foundptr;
            prevnode = foundptr->prev;
            nextnode = foundptr->next;
            prevnode->next = nextnode;
            nextnode->prev = prevnode;
            free(tempnode);
            tempnode = NULL;
            InsertToIndexLL(ptr,indexListAdr,indexListLastAdr);
        }
    }
}

//function to search a firstname in the recordsLL and then print them alphabetically according to the lastname
void search(indexNode* indexList)
{
    int found = 0;
    indexNode* travptr = indexList;
    indexNode* foundptr = NULL;
    char fname[50];
    printf("Enter name to Search\n");
    scanf("%s",&fname);

    //seraching using the index list
    while(travptr != NULL && found == 0)
    {
        if(strcmp(travptr->llptr->A1.firstname,fname) == 0)
        {
            found = 1;
            foundptr = travptr;
        }
        travptr = travptr->next;
    }

    if(found == 1)//as the first name is found -- print in alphabetical order -- already sorted in indexLL
    {
        while(foundptr != NULL && (strcmp(foundptr->llptr->A1.firstname,fname) == 0))
        {
            printf("Firstname- %s\n",foundptr->llptr->A1.firstname);
	        printf("Lastname- %s\n",foundptr->llptr->A1.lastname);
		    printf("Accommodation type- %s\n",foundptr->llptr->A1.accommodation_type);
		    printf("ID type- %d\n",foundptr->llptr->A1.idtype);
            if(foundptr->llptr->A1.idtype == 0)
            {
                printf("AADHAR- %s\n",foundptr->llptr->A1.id.aadhaar);
            }
            else if(foundptr->llptr->A1.idtype == 1)
            {
                printf("PASSPORT- %s\n",foundptr->llptr->A1.id.passport);
            }
            else
            {
                printf("EMPCODE- %s\n",foundptr->llptr->A1.id.empcode);
            }
		    printf("Block number- %d\n",foundptr->llptr->A1.blockind);
		    printf("Address- %s\n\n",foundptr->llptr->A1.address);

            foundptr = foundptr->next;
        }
    }
    else
    {
        printf("No Record Found\n");
    }
}


//function to request for a new block in same type blocks or in the different type blocks
void specialRequestAllocation(block* b1,node* aadharList,node* aadharListLast,node*passportList,node*passportListLast,node*empcodeList,node*empcodeListLast)
{
    int id,k,choice,flag = 0;
	int found = 0;
    int i = 0;
    node* travptr = NULL;
    node* foundptr = NULL;
	char idnumber[15];
	idnumber[0] = '\0';
    block_node* bptr = NULL;
	//char t1[7]={'t','y','p','e','-','1','\0'};
	//char t2[7]={'t','y','p','e','-','2','\0'};
	//char t3[7]={'t','y','p','e','-','3','\0'};
	//char t4[7]={'t','y','p','e','-','4','\0'};
	printf("SPECIAL REQUEST ALLOCATION\n");
	printf("please enter your ID type\n");
	scanf("%d",&id);
	printf("please enter ID number\n");
	scanf("%s",&idnumber);

    if(id == 0)
    {
        found = 0;
        travptr = aadharList;
        while(travptr != passportList && found == 0)
        {
            if(strcmp(travptr->A1.id.aadhaar,idnumber) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }
    else if(id == 1)
    {
        found = 0;
        travptr = passportList;
        while(travptr != empcodeList && found == 0)
        {
            if(strcmp(travptr->A1.id.passport,idnumber) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }
    else if(id == 2)
    {
        found = 0;
        travptr = empcodeList;
        while(travptr != NULL && found == 0)
        {
            if(strcmp(travptr->A1.id.empcode,idnumber) == 0)
            {
                found = 1;
                foundptr = travptr;
            }
            travptr = travptr->next;
        }
    }

    if(found == 1)
    {
        printf("Enter the type of accommodation to check for\nOr chose same type to change the block\nEnter number accordingly\n");
		printf("Type-1 - 1 |  Type-2 - 2 | Type-3 - 3 | Type-4 - 4\n");
		scanf("%d",&choice);
		
		flag = 0;
		if(choice == 1)
		{
            bptr = b1->t1;
			for(k=0;k<10 && flag==0;k++)
			{
				if(bptr->ac == 0)
				{
                    bptr->ac = 1;
					flag = 1;
					k--;
				}
                bptr = bptr->next;
			}
		}
		else if(choice == 2)
		{
            bptr = b1->t2;
			for(k=0;k<10 && flag==0;k++)
			{
				if(bptr->ac == 0)
				{
                    bptr->ac = 1;
					flag = 1;
					k--;
				}
                bptr = bptr->next;
			}
		}
		else if(choice == 3)
		{
            bptr = b1->t3;
			for(k=0;k<10 && flag==0;k++)
			{
				if(bptr->ac == 0)
				{
                    bptr->ac = 1;
					flag = 1;
					k--;
				}
                bptr = bptr->next;
			}
		}
		else if(choice == 4)
		{
            bptr = b1->t4;
			for(k=0;k<10 && flag==0;k++)
			{
				if(bptr->ac == 0)
				{
                    bptr->ac = 1;
					flag = 1;
					k--;
				}
                bptr = bptr->next;
			}
		}
		else
		{
			printf("Invalid choice");	
		}

        if(flag == 1)
		{
			printf("Block found\nNew allocation in type- %d block- %d\n",choice,k);
			if(foundptr->A1.accommodation_type[5] == '1')
			{
				//b1[0].t1[foundptr->A1.blockind] = 0;
                bptr = b1->t1;
                for(i=0;i<foundptr->A1.blockind;i++)
                {
                    bptr = bptr->next;
                }
                bptr->ac = 0;
				foundptr->A1.blockind = k;
			}
			else if(foundptr->A1.accommodation_type[5] == '2')
			{
				//b1[0].t2[foundptr->A1.blockind] = 0;
                bptr = b1->t2;
                for(i=0;i<foundptr->A1.blockind;i++)
                {
                    bptr = bptr->next;
                }
                bptr->ac = 0;
				foundptr->A1.blockind = k;
			}
			else if(foundptr->A1.accommodation_type[5] == '3')
			{
				//b1[0].t3[foundptr->A1.blockind] = 0;
                bptr = b1->t3;
                for(i=0;i<foundptr->A1.blockind;i++)
                {
                    bptr = bptr->next;
                }
                bptr->ac = 0;
				foundptr->A1.blockind = k;
			}
			else if(foundptr->A1.accommodation_type[5] == '4')
			{
				//b1[0].t4[foundptr->A1.blockind] = 0;
                bptr = b1->t4;
                for(i=0;i<foundptr->A1.blockind;i++)
                {
                    bptr = bptr->next;
                }
                bptr->ac = 0;
				foundptr->A1.blockind = k;
			}
			
			
			if(choice == 1)
			{
				foundptr->A1.accommodation_type[5] = '1';
			}
			else if(choice == 2)
			{
				foundptr->A1.accommodation_type[5] = '2';
			}
			if(choice == 3)
			{
				foundptr->A1.accommodation_type[5] = '3';
			}
			if(choice == 4)
			{
				foundptr->A1.accommodation_type[5] = '4';
			}
		}
        else//flag == 0
        {
            printf("All blocks full\n");
        }
    }
    else//found == 0
    {
        printf("No Record Found\n");
    }

}

/*--------------------------------------------------------------------------------------------------------------------------*/
/*In arrays we used the index array as a hash table to get quick access to the index of the main Records array to print the records
in the sorted order, here we can store a pointer to the Record Node in the indexList nodes so that the access can become faster
which also inherently stores the index of the main Records List and uses same amount of space as integer, we can also do it by storing
integer in the indexList, but the complexity of accessing will be more,the following functions can be used in this case.
*/

//function to traverse and get the firstname string of the RecordList
char* getFname(node* aadharList,int ind)
{
    int found = 0;
    char* ret_val = NULL;
    node* ptr = aadharList;
    while(ptr != NULL && found == 0)
    {
        if(ptr->A1.LLindex == ind)
        {
            found = 1;
            ret_val = ptr->A1.firstname;
        }
        ptr = ptr->next;
    }
    return ret_val;
}

//function to traverse and get the lastname string of the RecordList
char* getLname(node* aadharList,int ind)
{
    int found = 0;
    char* ret_val = NULL;
    node* ptr = aadharList;
    while(ptr != NULL && found == 0)
    {
        if(ptr->A1.LLindex == ind)
        {
            found = 1;
            ret_val = ptr->A1.lastname;
        }
        ptr = ptr->next;
    }
    return ret_val;
}


//This function call can be used as InsertToIndexLL but this function uses the integer index
//node and thus the getFname and getLname cause a N^2 complexity in accessing the data from the main Linked List
void InsertToIndex2(node* ptr,node* aadharList,index2Node** index2ListAdr,index2Node** index2ListLastAdr)
{
    node* travptr = ptr;
    index2Node* index2List = *index2ListAdr;
    index2Node* index2ListLast = *index2ListLastAdr;
    index2Node* nextnode = NULL;
    index2Node* prevnode = NULL;
    index2Node* travptrindex = NULL;//traversing
    index2Node* newIndex2Node = (index2Node*)malloc(sizeof(index2Node));
    if(travptr != NULL)
    {
        if(index2List == index2ListLast && index2List == NULL)//both NULL
        {
            index2List = newIndex2Node;
            *index2ListAdr = newIndex2Node;
            index2ListLast = index2List;
            *index2ListLastAdr = index2List;
            index2ListLast->next = NULL;
            index2List->prev = NULL;
            index2List->index = travptr->A1.LLindex;
        }
        else if(strcmp(travptr->A1.firstname,getFname(aadharList,index2List->index)) <= 0)//less than or equal to first node of index2List
        {
            if(strcmp(travptr->A1.firstname,getFname(aadharList,index2List->index)) < 0)
            {
                newIndex2Node->next = index2List;
                index2List->prev = newIndex2Node;
                newIndex2Node->prev = NULL;
                index2List = newIndex2Node;
                *index2ListAdr = newIndex2Node;
                index2List->index = travptr->A1.LLindex;
            }
            else// == 0 -- on store on basis of lastname
            {
                if(strcmp(travptr->A1.lastname,getLname(aadharList,index2List->index)) <= 0)
                {
                    newIndex2Node->next = index2List;
                    index2List->prev = newIndex2Node;
                    newIndex2Node->prev = NULL;
                    index2List = newIndex2Node;
                    *index2ListAdr = newIndex2Node;
                    index2List->index = travptr->A1.LLindex;
                }
                else// > 0
                {
                    if(index2List->next == NULL)//indexList == indexListLast single node
                    {
                        index2List->next = newIndex2Node;
                        newIndex2Node->prev = index2List;
                        index2ListLast = newIndex2Node;
                        *index2ListLastAdr = newIndex2Node;
                        index2ListLast->next = NULL;
                        index2ListLast->index = travptr->A1.LLindex;
                    }
                    else//has at atleast two nodes
                    {
                        nextnode = index2List->next;
                        newIndex2Node->next = nextnode;
                        newIndex2Node->prev = index2List;
                        index2List->next = newIndex2Node;
                        nextnode->prev = newIndex2Node;
                        newIndex2Node->index = travptr->A1.LLindex;
                    }
                }
            }
        }
        else if(strcmp(travptr->A1.firstname,getFname(aadharList,index2ListLast->index)) >= 0)
        {
            if(strcmp(travptr->A1.firstname,getFname(aadharList,index2ListLast->index)) > 0)
            {
                index2ListLast->next = newIndex2Node;
                newIndex2Node->prev = index2ListLast;
                index2ListLast = newIndex2Node;
                *index2ListLastAdr = newIndex2Node;
                newIndex2Node->next = NULL;
                newIndex2Node->index = travptr->A1.LLindex;
            }
            else// == 0
            {
                if(strcmp(travptr->A1.lastname,getLname(aadharList,index2ListLast->index)) >= 0)
                {
                    index2ListLast->next = newIndex2Node;
                    newIndex2Node->prev = index2ListLast;
                    index2ListLast = newIndex2Node;
                    *index2ListLastAdr = newIndex2Node;
                    newIndex2Node->next = NULL;
                    newIndex2Node->index = travptr->A1.LLindex;
                }
                else// < 0
                {
                    if(index2ListLast->prev == NULL)//one node
                    {
                        newIndex2Node->next = index2ListLast;
                        index2ListLast->prev = newIndex2Node;
                        index2List = newIndex2Node;
                        *index2ListAdr = newIndex2Node;
                        index2List->prev = NULL;
                        newIndex2Node->index = travptr->A1.LLindex;
                    }
                    else
                    {
                        prevnode = index2ListLast->prev;
                        newIndex2Node->next = index2ListLast;
                        newIndex2Node->prev = prevnode;
                        prevnode->next = newIndex2Node;
                        index2ListLast->prev = newIndex2Node;
                        newIndex2Node->index = travptr->A1.LLindex;
                    }
                }
            }
        }
        else//to be added somewhere in between -- not at the end nodes
        {
            travptrindex = index2List;
            while(travptrindex != NULL && (strcmp(getFname(aadharList,travptrindex->index),travptr->A1.firstname) < 0))
            {
                travptrindex = travptrindex->next;
            }
            if(strcmp(travptr->A1.firstname,getFname(aadharList,travptrindex->index)) == 0)
            {
                if(strcmp(travptr->A1.lastname,getLname(aadharList,travptrindex->index)) <= 0)
                {
                    prevnode = travptrindex->prev;
                    newIndex2Node->next = travptrindex;
                    newIndex2Node->prev = prevnode;
                    prevnode->next = newIndex2Node;
                    travptrindex->prev = newIndex2Node;
                    newIndex2Node->index = travptr->A1.LLindex;
                }
                else// >
                {
                    nextnode = travptrindex->next;
                    newIndex2Node->next = nextnode;
                    newIndex2Node->prev = travptrindex;
                    travptrindex->next = newIndex2Node;
                    nextnode->prev = newIndex2Node;
                    newIndex2Node->index = travptr->A1.LLindex;
                }
            }
            else//(strcmp(travptr->llptr->A1.firstname,ptr->A1.firstname) > 0)
            {
                prevnode = travptrindex->prev;
                newIndex2Node->next = travptrindex;
                newIndex2Node->prev = prevnode;
                prevnode->next = newIndex2Node;
                travptrindex->prev = newIndex2Node;
                newIndex2Node->index = travptr->A1.LLindex;
            }

        }
    }
}


//similarly this function can be used as printSortedRecords
//but this funtion uses the integer indexNode so the complexitiy of this funtion becomes N^2
void printSortedRecords2(node* aadharList,index2Node* index2List)
{
    index2Node* travptrIndex = index2List;
    node* travptr = aadharList;
    while(travptrIndex != NULL)
    {
        travptr = aadharList;
        while(travptr != NULL && travptr->A1.LLindex != travptrIndex->index)
        {
            travptr = travptr->next;
        }
        if(travptr->A1.idtype >= 0)//ignoring dummy nodes
        {
            printf("Firstname- %s\n",travptr->A1.firstname);
			printf("Lastname- %s\n",travptr->A1.lastname);
			printf("Accommodation type- %s\n",travptr->A1.accommodation_type);
			printf("ID type- %d\n",travptr->A1.idtype);
            if(travptr->A1.idtype == 0)
            {
                printf("AADHAR- %s\n",travptr->A1.id.aadhaar);
            }
            else if(travptr->A1.idtype == 1)
            {
                printf("PASSPORT- %s\n",travptr->A1.id.passport);
            }
            else
            {
                printf("EMPCODE- %s\n",travptr->A1.id.empcode);
            }
			printf("Block number- %d\n",travptr->A1.blockind);
			printf("Address- %s\n\n",travptr->A1.address);
        }
        travptrIndex = travptrIndex->next;
    }
}

//function to update integer indexList
void updateIndex2OnDelete(node* ptr,index2Node** index2ListAdr,index2Node** index2ListLastAdr)
{
    index2Node* index2List = *index2ListAdr;
    index2Node* index2ListLast = *index2ListLastAdr;
    index2Node* temp = NULL;
    index2Node* travptr = NULL;
    index2Node* prevnode = NULL;
    index2Node* nextnode = NULL;
    int ind;
    if(index2List == index2ListLast && index2ListLast->index == ptr->A1.LLindex)
    {
        free(index2ListLast);
        index2List = NULL;
        *index2ListAdr = NULL;
        index2ListLast = NULL;
        *index2ListLastAdr = NULL;
        free(ptr);
    }
    else//at least 2 index2Nodes
    {
        if(index2List->index == ptr->A1.LLindex)
        {
            temp = index2List;
            ind = temp->index;
            index2List = index2List->next;
            *index2ListAdr = index2List;
            index2List->prev = NULL;
            free(temp);
            free(ptr);
        }
        else if(index2ListLast->index == ptr->A1.LLindex)
        {
            temp = index2ListLast;
            ind = temp->index;
            index2ListLast = index2ListLast->prev;
            *index2ListLastAdr = index2ListLast;
            index2ListLast->next = NULL;
            free(temp);
            free(ptr);
        }
        else//somewhere in between -- not at end nodes
        {
            travptr = index2List;
            while(travptr->index != ptr->A1.LLindex)
            {
                travptr = travptr->next;
            }
            temp = travptr;
            ind = temp->index;
            prevnode = travptr->prev;
            nextnode = travptr->next;
            nextnode->prev = prevnode;
            prevnode->next = nextnode;
            free(temp);
            free(ptr);
        }
        travptr = index2List;
        while(travptr != NULL)
        {
            if(travptr->index > ind)
            {
                travptr->index--;
            }
            travptr = travptr->next;
        }
    }
}

//this function used as change index on update for the index node containing integer index
void changeIndex2OnUpdate(node* ptr,node* aadharList,index2Node** index2ListAdr,index2Node** index2ListLastAdr)
{
    index2Node* index2List = *index2ListAdr;
    index2Node* index2ListLast = *index2ListLastAdr;
    index2Node* temp = NULL;
    index2Node* travptr = NULL;
    index2Node* prevnode = NULL;
    index2Node* nextnode = NULL;
    int ind;
    if(index2List == index2ListLast && index2ListLast->index == ptr->A1.LLindex)
    {
        free(index2ListLast);
        index2List = NULL;
        *index2ListAdr = NULL;
        index2ListLast = NULL;
        *index2ListLastAdr = NULL;
        InsertToIndex2(ptr,aadharList,index2ListAdr,index2ListLastAdr);
    }
    else//at least 2 index2Nodes
    {
        if(index2List->index == ptr->A1.LLindex)
        {
            temp = index2List;
            ind = temp->index;
            index2List = index2List->next;
            *index2ListAdr = index2List;
            index2List->prev = NULL;
            free(temp);
        }
        else if(index2ListLast->index == ptr->A1.LLindex)
        {
            temp = index2ListLast;
            ind = temp->index;
            index2ListLast = index2ListLast->prev;
            *index2ListLastAdr = index2ListLast;
            index2ListLast->next = NULL;
            free(temp);
        }
        else//somewhere in between -- not at end nodes
        {
            travptr = index2List;
            while(travptr->index != ptr->A1.LLindex)
            {
                travptr = travptr->next;
            }
            temp = travptr;
            ind = temp->index;
            prevnode = travptr->prev;
            nextnode = travptr->next;
            nextnode->prev = prevnode;
            prevnode->next = nextnode;
            free(temp);
        }
        travptr = index2List;
        while(travptr != NULL)
        {
            if(travptr->index > ind)
            {
                travptr->index--;
            }
            travptr = travptr->next;
        }
        InsertToIndex2(ptr,aadharList,index2ListAdr,index2ListLastAdr);
    }
}