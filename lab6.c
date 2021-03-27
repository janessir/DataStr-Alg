// #include <stdio.h>
// #include <stdlib.h>

// void dualSearch (int[],int, int, int[]);

// int main()
// {
//     int i,size,K;
//     int* A;
//     int index[2] = {-1,-1};

//     //Search key
//     printf("Enter the search key: ");
//     scanf("%d",&K);

//     //create an array
//     printf("Enter the size of your array: ");
//     scanf("%d",&size);

//     printf("Enter your array: \n");
//     A=(int *)malloc(sizeof(int)*size);
//     for(i=0; i<size; i++)
//     {
//         scanf("%d",&A[i]);
//     }

//     dualSearch(A,size,K,index);

//     if(index[0]!=-1)
//         printf("%d %d\n",index[0], index[1]);
//     else
//         printf("Not found");

//     free(A);
//     return 0;
// }


void dualSearch(int A[], int size, int K, int dualIndex[])
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(A[i]+A[j]==K){
                (*dualIndex++)=A[i];
                (*dualIndex)=A[j];
                return;

            }
        }
    }

}

// // --------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>

// #define LOAD_FACTOR 3

// typedef struct _listnode{
//     int key;
//     struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//    int size;
//    ListNode *head;
// } HashTableNode;

// typedef struct _hashTable{
//    int hSize;
//    int nSize;
//    HashTableNode *Table; //is my pointer to the LL/HastTableNode (if there is any)
// } HashTable;

// int Hash(int,int);

// ListNode* HashSearch(HashTable, int);
// int HashInsert(HashTable *, int);

// //In Practice, we will not do it
// void HashPrint(HashTable);

// int main()
// {
//     int opt;
//     int size;

//     int i;
//     int key;

//     //Create a HashTable
//     HashTable Q3Hash;
//     Q3Hash.hSize = 0;
//     Q3Hash.nSize = 0;
//     Q3Hash.Table = NULL;

//     printf("============= Hash Table ============\n");
//     printf("|1. Create a hash table             |\n");
//     printf("|2. Insert a key to the hash table  |\n");
//     printf("|3. Search a key in the hash table  |\n");
//     printf("|4. Print the hash table            |\n");
//     printf("|5. Quit                            |\n");
//     printf("=====================================\n");

//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     while(opt>=1 && opt <=4){
//         switch(opt){
//         case 1:
//             printf("Enter number of data to be inserted:\n");
//             scanf("%d",&size);

//             Q3Hash.hSize = (int)size/ LOAD_FACTOR; //h slots
//             Q3Hash.nSize = 0;

//             Q3Hash.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q3Hash.hSize)); // making a pointer to LL for h slots

//             //initialize each LL of h slots as NULL
//             for(i=0;i<Q3Hash.hSize;i++){
//                Q3Hash.Table[i].head = NULL;
//                Q3Hash.Table[i].size = 0;
//             }
//             printf("HashTable is created.\n");
//             break;
//         case 2: //Insertion
//             printf("Enter a key to be inserted:\n");
//             scanf("%d",&key);

//             if(HashInsert(&Q3Hash,key))
//                 printf("%d is inserted.\n",key);
//             else
//                 printf("%d is a duplicate. No key is inserted.\n",key);
//             break;
//         case 3: //Search
//             printf("Enter a key for searching in the HashTable:\n");
//             scanf("%d",&key);
//             ListNode* node = HashSearch(Q3Hash, key);

//             if(node!=NULL)
//                 printf("%d is found.\n",key);
//             else
//                 printf("%d is not found.\n",key);
//             break;
//         case 4:
//             HashPrint(Q3Hash);
//             break;
//         }

//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     }

//     for(i=0;i<Q3Hash.hSize;i++)
//     {
//         while(Q3Hash.Table[i].head)
//         {
//             ListNode *temp;
//             temp = Q3Hash.Table[i].head;
//             Q3Hash.Table[i].head = Q3Hash.Table[i].head->next;
//             free(temp);
//         }
//     }
//     free(Q3Hash.Table);

//     return 0;

// }

// //create a hash table
// int Hash(int key,int hSize)
// {
//     return key%hSize;
// }

//--------

//search for key in hash table
ListNode* HashSearch(HashTable Q3Hash, int key)
{
    if(Q3Hash.hSize==0)
        return NULL;
    int loc=Hash(key,Q3Hash.hSize);

    ListNode *cur;
    cur=Q3Hash.Table[loc].head;
    while(cur!=NULL){
        if(cur->key==key)
            return cur;
        cur=cur->next;
    }

    return NULL;
}

//insert a key into a hash table
int HashInsert(HashTable* Q3HashPtr, int key)
{
    //create a node
    ListNode *temp,*cur;
    temp=malloc(sizeof(ListNode));
    temp->key=key;
    temp->next=NULL;

    //get the location
    int loc=Hash(key,Q3HashPtr->hSize);

    //at loc, insert the node to the LL

    //if empty LL
    if(Q3HashPtr->Table[loc].head==NULL){
        Q3HashPtr->Table[loc].head=temp;
    }

    //if non-empty LL
    else{
        cur=Q3HashPtr->Table[loc].head;
        //find the last node in the LL of that hslot loc
        while(cur->next!=NULL){
            if(cur->key==key)
                return 0;
            cur=cur->next;
        }
    cur->next=temp;
    }

    Q3HashPtr->Table[loc].size++;
    Q3HashPtr->nSize++;

    return 1;

}

// //--------

// void HashPrint(HashTable Q3Hash)
// {
//     int i;
//     ListNode *temp;
//     for(i=0;i<Q3Hash.hSize;i++)
//     {
//         temp =Q3Hash.Table[i].head;
//         printf("%d:  ",i);
//         while(temp !=NULL)
//         {
//             printf("%d -> ", temp->key);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }


// //--------------------------------------------------------


// #include <stdio.h>
// #include <stdlib.h>

// void quickSort(int A[], int low, int high);
// int partition (int A[], int low, int high);

// void dualSortedSearch (int[],int, int, int[]);

// int main()
// {
//     int i,size,K;
//     int* A;
//     int index[2] = {-1,-1};

//     //Search key
//     printf("Enter search key: ");
//     scanf("%d",&K);

//     //create an array
//     printf("Enter array size: ");
//     scanf("%d",&size);
//     printf("Enter array: ");
//     A=(int *)malloc(sizeof(int)*size);
//     for(i=0; i<size; i++)
//     {
//         scanf("%d",&A[i]);
//     }

//     quickSort(A,0,size-1);
//     dualSortedSearch(A,size,K,index);

//     if(index[0]!=-1)
//         printf("Found: %d %d\n",index[0], index[1]);
//     else
//         printf("Not found\n");

//     free(A);
//     return 0;
// }

void dualSortedSearch(int A[], int size, int K, int dualIndex[])
{
    int i,first,last,mid,diff,goOut=0;
    
    if(size<2)
        return;
    
    for(i=0;i<size;i++){
        if(A[i]*2==K){
            dualIndex[0]=A[i];
            dualIndex[1]=A[i];
            return;
        }
        
        first=i+1;
        last=size-1;
        mid=(first+last)/2;
        diff=K-A[i];
        
        while(1){
            
            if(goOut)
                return;
            
            if(first==last)
                goOut=1; //ie next iteration, return
            
            if(diff==A[mid]){
                dualIndex[0]=A[i];
                dualIndex[1]=A[mid];
                return; //found
            }
            else if(diff<A[mid]){
                last=mid-1;
                mid=(first+last)/2;
                continue;
            }
            else{
                first=mid+1;
                mid=(first+last)/2;
                continue;
            }
        }
    }
    
}

// int partition (int A[], int low, int high)
// {
//     int pivot = A[high];
//     int i = (low - 1);

//     int temp;
//     for (int j = low; j <= high- 1; j++)
//     {
//         if (A[j] < pivot)
//         {
//             i++;

//             temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         }
//     }

//     temp = A[i+1];
//     A[i+1]= A[high];
//     A[high] = temp;
//     return (i + 1);
// }

// void quickSort(int A[], int low, int high)
// {
//     if (low < high)
//     {
//         int pivot = partition(A, low, high);

//         quickSort(A, low, pivot - 1);
//         quickSort(A, pivot + 1, high);
//     }
// }

