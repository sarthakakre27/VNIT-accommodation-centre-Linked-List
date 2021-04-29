//structure for the Record Fields
typedef struct accommodation_tag
{ 
	char firstname[50]; 
	char lastname[50]; 
	char accommodation_type [20];
	int idtype; 
	char address[100]; 
	int blockind;
    int LLindex;
	struct idnum
	{ 
		char aadhaar[15]; 
		char passport[15]; 
		char empcode [15];
	}id; 	
}accommodation;

//record for node of a block
typedef struct block_node_tag
{
	int ac;
	struct block_node_tag* next;
}block_node;

//structure for the blocks of 4 types of accommodation
typedef struct block_tag
{
	block_node* t1;
	block_node* t2;
	block_node* t3;
	block_node* t4;
	
}block;

//structure for the main LinkedList of Records
typedef struct node_tag
{
    struct node_tag* next;
    struct node_tag* prev;
    accommodation A1;
    
}node;

//structure for indexList with pointer index
typedef struct index_node_tag
{
    struct index_node_tag* next;
    struct index_node_tag* prev;
    node* llptr;
}indexNode;

//structure for indexList with integer index
typedef struct index2_node_tag
{
    struct index2_node_tag* next;
    struct index2_node_tag* prev;
    int index;
}index2Node;

//Functions for the Records and the utility functions for them
void InitializeNode(node* ptr);
void Initialize_DB_LL(node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr);
void InitializeBlocks(block* b1);
void InsertRecord(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void InsertToIndexLL(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void printSortedRecords(indexNode* indexList);
void setRecord(node* ptr);
void printRecords(node* aadharList,node* aadharListLast,node* passportList,node* passportListLast,node* empcodeList,node* empcodeListLast);
void removeDuplicates(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void deleteRecord(block* b1,node** aadharListAdr,node** aadharListLastAdr,node** passportListAdr,node** passportListLastAdr,node** empcodeListAdr,node**empcodeListLastAdr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void updateIndexLL(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void updateRecord(node* aadharList,node* aadharListLast,node* passportList,node* passportListLast,node* empcodeList,node* empcodeListLast,indexNode** indexListAdr,indexNode** indexListLastAdr);
void changeIndexOnUpdate(node* ptr,indexNode** indexListAdr,indexNode** indexListLastAdr);
void search(indexNode* indexList);
void specialRequestAllocation(block* b1,node* aadharList,node* aadharListLast,node*passportList,node*passportListLast,node*empcodeList,node*empcodeListLast);

//functions for integer index indexList
char* getFname(node* aadharList,int ind);
char* getLname(node* aadharList,int ind);
void InsertToIndex2(node* ptr,node* aadharList,index2Node** index2ListAdr,index2Node** index2ListLastAdr);
void printSortedRecords2(node* aadharList,index2Node* index2List);
void updateIndex2OnDelete(node* ptr,index2Node** index2ListAdr,index2Node** index2ListLastAdr);
void changeIndex2OnUpdate(node* ptr,node* aadharList,index2Node** index2ListAdr,index2Node** index2ListLastAdr);