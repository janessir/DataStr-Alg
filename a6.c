// //coding
// // q1

// #include <stdio.h>
// #include <stdlib.h>

// #define LOAD_FACTOR 3

// typedef struct _listnode{
//     int key;
//     struct _listnode *next;
//     struct _listnode *pre;
// } ListNode;

// typedef struct _linkedlist{
//    int size;
//    ListNode *head;
// } HashTableNode;

// typedef struct _hashTable{
//    int hSize;
//    int nSize;
//    HashTableNode *Table;
// } HashTable;

// int Hash(int key,int hSize);

// ListNode* HashSearch(HashTable, int);
// int HashInsert(HashTable *, int);
// int HashDelete(HashTable *, int);

// //In Practice, we will not do it
// void HashPrint(HashTable);

// int main()
// {
//     int opt;
//     int size;

//     int i;
//     int key;

//     //Create a HashTable
//     HashTable Q1;

//     printf("============= Hash Table ============\n");
//     printf("|1. Create a hash table             |\n");
//     printf("|2. Insert a key to the hash table  |\n");
//     printf("|3. Search a key in the hash table  |\n");
//     printf("|4. Delete a key from the hash table|\n");
//     printf("|5. Print the hash table            |\n");
//     printf("|6. Quit                            |\n");
//     printf("=====================================\n");

//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     while(opt>=1 && opt <=5){
//         switch(opt){
//         case 1:
//             printf("Enter number of data to be inserted:\n");
//             scanf("%d",&size);

//             Q1.hSize = (int)size/ LOAD_FACTOR;
//             Q1.nSize = 0;

//             Q1.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q1.hSize));

//             for(i=0;i<Q1.hSize;i++){
//                 Q1.Table[i].head = NULL;
//                 Q1.Table[i].size = 0;
//             }
//             printf("HashTable is created.\n");
//             break;
//         case 2: //Insertion
//             printf("Enter a key to be inserted:\n");
//             scanf("%d",&key);
//             if(HashInsert(&Q1,key))
//                 printf("%d is inserted.\n",key);
//             else
//                 printf("%d is a duplicate. No key is inserted.\n",key);
//             break;
//         case 3: //Search
//             printf("Enter a key for searching in the HashTable:\n");
//             scanf("%d",&key);
//             ListNode* node = HashSearch(Q1, key);

//             if(node!=NULL)
//                 printf("%d is found.\n",key);
//             else
//                 printf("%d is not found.\n",key);
//             break;
//         case 4: //Deletion
//             printf("Enter a key to be deleted:\n");
//             scanf("%d",&key);
//             if(HashDelete(&Q1,key))
//                 printf("%d is deleted.\n",key);
//             else
//                 printf("%d is not existing.\n",key);
//             break;
//         case 5:
//             HashPrint(Q1);
//             break;
//         }

//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     }

//     for(i=0;i<Q1.hSize;i++)
//     {
//         while(Q1.Table[i].head)
//         {
//             ListNode *temp;
//             temp = Q1.Table[i].head;
//             Q1.Table[i].head = Q1.Table[i].head->next;
//             free(temp);
//         }
//     }
//     free(Q1.Table);

//     return 0;
// }


int HashInsert(HashTable* Q1Ptr, int key)
{
    //create a node
    ListNode *temp,*cur;
    temp=malloc(sizeof(ListNode));
    temp->key=key;
    temp->next=NULL;

    //get the location
    int loc=Hash(key,Q1Ptr->hSize);
    

    //if empty LL
    if(Q1Ptr->Table[loc].head==NULL){
        Q1Ptr->Table[loc].head=temp;
    }

    //if non-empty LL
    else{
        cur=Q1Ptr->Table[loc].head;
        //find the last node in the LL of that hslot loc
        while(cur->next!=NULL){
            if(cur->key==key)
                return 0;
            cur=cur->next;
        }
        temp->next = Q1Ptr->Table[loc].head;
        Q1Ptr->Table[loc].head=temp;

    }

    Q1Ptr->Table[loc].size++;
    Q1Ptr->nSize++;

    return 1;

}

//rmb to take case of nSize and size of LL
//if deleting from first node, rmb change pointer in slot to NULL
int HashDelete(HashTable* Q1Ptr, int key)
{
    ListNode *pre, *cur;
    
    if (Q1Ptr->nSize==0)
        return 0;
    
    //get the location
    int loc=Hash(key,Q1Ptr->hSize);
    
    pre = Q1Ptr->Table[loc].head;
    
    //if first node has the searched key
    if(Q1Ptr->Table[loc].head->key==key){
        Q1Ptr->Table[loc].head=pre->next;
        pre->next=NULL;
        free(pre);
    }
    
    //if not first node of LL
    else{
        cur=pre->next;
        while(cur!=NULL){
            if(cur->key==key)
                break;
            pre=pre->next;
            cur=cur->next;
        }
        if(cur==NULL)
            return 0;
        pre->next=cur->next;
        cur->next=NULL;
        free(cur);
    }
    
    Q1Ptr->Table[loc].size--;
    Q1Ptr->nSize--;
    
    return 1;
}

// int Hash(int key,int hSize)
// {
//     return key%hSize;
// }

// ListNode* HashSearch(HashTable Q1, int key)
// {
//     int index;

//     ListNode *temp;

//     if(Q1.hSize != 0)
//       index = Hash(key,Q1.hSize);
//     else
//       return NULL;

//     temp = Q1.Table[index].head;
//     while(temp !=NULL){
//         if(temp->key == key)
//             return temp;
//         temp = temp->next;
//     }

//     return NULL;
// }

// void HashPrint(HashTable Q1)
// {
//     int i;
//     ListNode *temp;
//     for(i=0;i<Q1.hSize;i++)
//     {
//         temp =Q1.Table[i].head;
//         printf("%d:  ",i);
//         while(temp !=NULL)
//         {
//             printf("%d -> ", temp->key);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// // ------------------------------------------


// // q2

// #include <stdio.h>
// #include <stdlib.h>

// #define TABLESIZE 37
// #define PRIME     13

// enum Marker {EMPTY,USED,DELETED};

// typedef struct _slot{
//     int key;
//     enum Marker indicator;
// } HashSlot;

// int HashInsert(int key, HashSlot hashTable[]);
// int HashDelete(int key, HashSlot hashTable[]);


// int hash1(int key);
// int hash2(int key);

// int main()
// {
//     int opt;
//     int i;
//     int key;
//     int comparison;
//     HashSlot hashTable[TABLESIZE];

//     for(i=0;i<TABLESIZE;i++){
//         hashTable[i].indicator = EMPTY;
//         hashTable[i].key = 0;
//     }

//     printf("============= Hash Table ============\n");
//     printf("|1. Insert a key to the hash table  |\n");
//     printf("|2. Delete a key from the hash table|\n");
//     printf("|3. Print the hash table            |\n");
//     printf("|4. Quit                            |\n");
//     printf("=====================================\n");
//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     while(opt>=1 && opt <=3){
//         switch(opt){
//         case 1:
//             printf("Enter a key to be inserted:\n");
//             scanf("%d",&key);
//             comparison = HashInsert(key,hashTable);
//             if(comparison <0)
//                 printf("Duplicate key\n");
//             else if(comparison < TABLESIZE)
//                 printf("Insert: %d Key Comparisons: %d\n",key, comparison);
//             else
//                 printf("Key Comparisons: %d. Table is full.\n",comparison);
//             break;
//         case 2:
//             printf("Enter a key to be deleted:\n");
//             scanf("%d",&key);
//             comparison = HashDelete(key,hashTable);
//             if(comparison <0)
//                 printf("%d does not exist.\n", key);
//             else if(comparison <= TABLESIZE)
//                 printf("Delete: %d Key Comparisons: %d\n",key, comparison);
//             else
//                 printf("Error\n");
//             break;
//         case 3:
//             for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
//             break;
//         }
//         printf("Enter selection: ");
//         scanf("%d",&opt);
//     }
//     return 0;
// }

// int hash1(int key)
// {
//     return (key % TABLESIZE);
// }

// //incremental hash function for double hashing
// int hash2(int key)
// {
//     return (key % PRIME) + 1;
// }

// Inserting a duplicate key will return -1.
//if table full return h
int HashInsert(int key, HashSlot hashTable[])
{
    int i,keycmp=0,insAtD=-100;
    
    for(i=0;i<TABLESIZE;i++){
        
        //get the loc
        int loc=hash1(key+(i*hash2(key)));
        
        if(hashTable[loc].indicator==EMPTY){
            // insert back at the first deleted slot prev encountered
            if (insAtD!=-100)
                break;
            hashTable[loc].key=key;
            hashTable[loc].indicator=USED;
            return keycmp;
        }
        
        //USED
        else if(hashTable[loc].indicator==USED){
            if(hashTable[loc].key==key)
                return -1; //duplicate
            keycmp++;
        }
        
        //DELETED
        else{
            //encounter the first deleted slot
            if (insAtD==-100)
                insAtD=loc;
            
        }
    }
    
    //insert at first deleted slot if have
    if(insAtD!=-100){
        hashTable[insAtD].key=key;
        hashTable[insAtD].indicator=USED;
        return keycmp;
    }
    return keycmp; //full
}

//if slot is empty return -1 ie if delete key dont exist return -1
//if deleted key found, delete and return key cmp
//keycmp cannot be more than TABLESIZE
//once deleted, cannot read it

int HashDelete(int key, HashSlot hashTable[])
{
    int i,keycmp=0;
    
    for(i=0;i<TABLESIZE;i++){
        
        //get the loc
        int loc=hash1(key+(i*hash2(key)));
        
        //EMPTY (cant find deleted key)
        if(hashTable[loc].indicator==EMPTY){
            return -1;
        }
        
        //USED (increment key cmp, and check if is deleted key)
        else if(hashTable[loc].indicator==USED){
            keycmp++;
            if(hashTable[loc].key==key){
                hashTable[loc].indicator=DELETED;
                return keycmp;
            }
            if(i==TABLESIZE-1)
                return -1;
        }
        //DELETED (to check if key's still at the back)
        else{
            //final slot is also deleted
            if(i==TABLESIZE-1)
                return -1;
        }
    }
    return  TABLESIZE+1;
}


// ----------------------------------------

// // q3

// #include <stdio.h>
// #include <stdlib.h>

// #define TABLESIZE 37
// #define PRIME     13

// enum Marker {EMPTY,USED};

// typedef struct _slot{
//     int key;
//     enum Marker indicator;
//     int next;
// } HashSlot;

// int HashInsert(int key, HashSlot hashTable[]);
// int HashFind(int key, HashSlot hashTable[]);

// int hash(int key)
// {
//     return (key % TABLESIZE);
// }

// int main()
// {
//     int opt;
//     int i;
//     int key;
//     int index;
//     HashSlot hashTable[TABLESIZE];

//     for(i=0;i<TABLESIZE;i++){
//         hashTable[i].next = -1;
//         hashTable[i].key = 0;
//         hashTable[i].indicator = EMPTY;
//     }

//     printf("============= Hash Table ============\n");
//     printf("|1. Insert a key to the hash table  |\n");
//     printf("|2. Search a key in the hash table  |\n");
//     printf("|3. Print the hash table            |\n");
//     printf("|4. Quit                            |\n");
//     printf("=====================================\n");

//     printf("Enter selection: ");
//     scanf("%d",&opt);
//     while(opt>=1 && opt <=3){
//         switch(opt){
//         case 1:
//             printf("Enter a key to be inserted:\n");
//             scanf("%d",&key);
//             index = HashInsert(key,hashTable);
//             if(index <0)
//                 printf("Duplicate key\n");
//             else if(index < TABLESIZE)
//                 printf("Insert %d at index %d\n",key, index);
//             else
//                 printf("Table is full.\n");
//             break;
//         case 2:
//             printf("Enter a key for searching in the HashTable:\n");
//             scanf("%d",&key);
//             index = HashFind(key, hashTable);

//             if(index!=-1)
//                 printf("%d is found at index %d.\n",key,index);
//             else
//                 printf("%d is not found.\n",key);
//             break;

//         case 3:
//             printf("index:\t key \t next\n");
//             for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
//             break;
//         }
//         printf("Enter selection: ");
//         scanf("%d",&opt);
//     }
//     return 0;
// }

int HashInsert(int key, HashSlot hashTable[])
{
    int ploc=-100, temp, loc=hash(key);
    
    //else
    for(int i=0;i<TABLESIZE;i++){
        
        //check for duplicates
        if(hashTable[loc].indicator==USED && hashTable[loc].key==key)
            return -1;
        
        //found empty slot
        if(hashTable[loc].indicator==EMPTY){
            hashTable[loc].key=key;
            hashTable[loc].indicator=USED;
            if(ploc!=-100)
                hashTable[ploc].next=loc;
            return loc;
        }
        
        //else go next loc
        
        //get the first loc w/ next==-1 to change it ltr when found the index of insertion
        if(ploc==-100 && hashTable[loc].next==-1)
            ploc=loc;
        
        if(hashTable[loc].next==-1){
            loc+=1; //lin probing
            if(loc==TABLESIZE)
                loc=0;
        }
        else
            loc=hashTable[loc].next; //go next
        
        
    }
    return TABLESIZE;
}

int HashFind(int key, HashSlot hashTable[])
{
    int loc=hash(key);
    
    for(int i=0;i<TABLESIZE;i++){
        //if found
        if(hashTable[loc].indicator==USED && hashTable[loc].key==key)
            return loc;
        
        //else
        if(hashTable[loc].next==-1){
            loc+=1; //lin probing
            if(loc==TABLESIZE)
                loc=0;
        }
        else
            loc=hashTable[loc].next; //go next
        
    }
    return -1;
}


//----------------------------
//mcq

// #include <stdio.h>

int ProcessArray(int *listA,int x,int n){
    int i,k,j;
    i=0;
    j=n-1;
    
    do{
        k=(i+j)/2;
        if(x<=listA[k])
            j=k-1;
        if(listA[k]<=x)
            i=k+1;
    }while(i<=j);
    
    if(listA[k]==x)
        return k;
        
    else 
        return -1;
}

// int main(){
//     int x, listA[7]={1,3,4,5,6,10,20};
//     printf("Enter x: ");
//     scanf("%d",&x);
    
//     while(x!=-1000){
//         printf("Ans: %d\n",ProcessArray(listA,x,7));
//         printf("Enter x: ");
//         scanf("%d",&x);
//     }
    
//     return 1;
// }

