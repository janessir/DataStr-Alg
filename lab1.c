//Q1: fn should return 0 if the delete op is successful, and -1 otherwise


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode{
//     int item;
//     struct _listnode *next;
// } ListNode;


// void printList(ListNode *cur);
// ListNode * findNode(ListNode *cur, int index);
// int insertNode(ListNode **ptrHead, int index, int item);

// int removeNode(ListNode **ptrHead,int index);

// int main()
// {
//     ListNode *head=NULL;
//     int size =0;
//     int item;
//     int index;

//     printf("Enter a list of numbers, terminated by any non-digit character: \n");
//     while(scanf("%d",&item))
//         if(insertNode(&head,size, item)) size++;
//     scanf("%*s");

//     printList(head);

//     while(1){
//         printf("Enter the index of the node to be removed: ");
//         scanf("%d",&index);

//         if(removeNode(&head,index))
//             size--;
//         else{
//             printf("The node cannot be removed.\n");
//             break;
//         }

//         printf("After the removal operation,\n");
//         printList(head);
//     }

//     printList(head);
//     return 0;
// }

// void printList(ListNode *cur){
//     printf("Current List: ");
//     while (cur != NULL){
//         printf("%d ", cur->item);
//         cur = cur->next;
//     }
//     printf("\n");
// }

// ListNode *findNode(ListNode* cur, int index)
// {
//   if (cur==NULL || index<0)
//       return NULL;
//   while(index>0){
//       cur=cur->next;
//       if (cur==NULL)
//          return NULL;
//       index--;
//   }
//   return cur;
// }

// int insertNode(ListNode **ptrHead, int index, int item){
//     ListNode  *pre, *newNode;
//     // If empty list or inserting first node, update head pointer
//     if (index == 0){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = *ptrHead;
//         *ptrHead = newNode;
//         return 1;
//     }
//     // Find the nodes before and at the target position
//     // Create a new node and reconnect the links
//     else if ((pre = findNode(*ptrHead, index-1)) != NULL){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = pre->next;
//         pre->next = newNode;
//         return 1;
//     }
//     return 0;
// }

//write code
int removeNode(ListNode **ptrHead,int index)
{
    ListNode *pre, *cur;

    if(*ptrHead==NULL || index<0)
        return 0;

    //delete first node
    if(index==0){
        cur=*ptrHead;
        *ptrHead=(*ptrHead)->next;
        free(cur);
        return 1;
    }

    //delete others

    if((pre=findNode(*ptrHead,index-1))!=NULL){
        cur=pre->next;
        if(cur==NULL)
            return 0;
        pre->next=cur->next;
        free(cur);
        return 1;
    }
    return 0;
}

----------------------------------------

Q2. removeNode2 using LinkedList struct


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode{
//     int item;
//     struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//     ListNode *head;
//     int size;
// } LinkedList;

// void printList2(LinkedList ll);
// ListNode* findNode2(LinkedList ll, int index);
// int insertNode2(LinkedList *ll, int index, int item);

// int removeNode2(LinkedList *ll,int index);

// int main()
// {
//     LinkedList ll;
//     ll.head =NULL;
//     ll.size = 0;
//     int item;
//     int index;

//     printf("Enter a list of numbers, terminated by any non-digit character: \n");
//     while(scanf("%d",&item))
//     {
//         if(!insertNode2(&ll,ll.size, item)) break;
//     }

//     scanf("%*s");

//     printList2(ll);

//     while(1){
//         printf("Enter the index of the node to be removed: ");
//         scanf("%d",&index);

//         if(!removeNode2(&ll,index)){
//             printf("The node cannot be removed.\n");
//             break;
//         }

//         printf("After the removal operation,\n");
//         printList2(ll);
//     }

//     printList2(ll);
//     return 0;
// }

// void printList2(LinkedList ll){
//     if(ll.head != NULL){
//         ListNode *cur = ll.head;
//         printf("Current List has %d elements: ",ll.size);

//         while (cur != NULL){
//             printf("%d ", cur->item);
//             cur = cur->next;
//         }
//         printf("\n");
//     }
// }

// ListNode* findNode2(LinkedList ll, int index)
// {
//   if(ll.head != NULL){
//         ListNode *cur = ll.head;
//         if (cur==NULL || index<0 || index >ll.size)
//           return NULL;

//         while(index>0){
//             cur=cur->next;
//             if (cur==NULL)
//                 return NULL;
//             index--;
//         }
//         return cur;
//   }
//   else
//      return NULL;
// }

// int insertNode2(LinkedList *ll, int index, int item){
//     ListNode  *pre, *newNode;
//     // If empty list or inserting first node, update head pointer
//     if (index == 0){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = ll->head;

//         ll->head = newNode;
//         ll->size++;
//         return 1;
//     }
//     // Find the nodes before and at the target position
//     // Create a new node and reconnect the links
//     else if ((pre = findNode2(*ll, index-1)) != NULL){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = pre->next;
//         pre->next = newNode;
//         ll->size++;
//         return 1;
//     }
//     return 0;
// }

//write code
int removeNode2(LinkedList *ll,int index)
{
    ListNode *cur, *pre;

    if(ll->head==NULL || index<0)
        return 0;

    if(index==0){
        cur=ll->head;
        ll->head=(ll->head)->next;
        free(cur);
        return 1;
    }

    if((pre=findNode2(*ll,index-1))!=NULL){
        cur=pre->next;
        if(cur==NULL)
            return 0;
        pre->next=cur->next;
        free(cur);
        return 1;
    }
    return 0;
}

----------------------------------------

Q3. split()


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode{
//     int item;
//     struct _listnode *next;
// } ListNode;


// void printList(ListNode *cur);
// ListNode * findNode(ListNode *cur, int index);
// int insertNode(ListNode **ptrHead, int index, int item);
// void deleteList(ListNode **ptrHead);

// int split(ListNode *cur,ListNode **ptrEvenList,ListNode **ptrOddList);

// int main()
// {
//     ListNode *head=NULL;
//     ListNode *oddHead = NULL;
//     ListNode *evenHead = NULL;

//     int size =0;
//     int item;

//     printf("Enter a list of numbers, terminated by any non-digit character: \n");
//     while(scanf("%d",&item))
//         if(insertNode(&head,size, item)) size++;
//     scanf("%*s");

//     printf("\nBefore split() is called:\n");
//     printf("The original list:\n");
//     printList(head);

//     split(head, &evenHead, &oddHead);

//     printf("\nAfter split() was called:\n");
//     printf("The original list:\n");
//     printList(head);
// 	printf("\nThe even list:\n");
// 	printList(evenHead);
// 	printf("\nThe odd list:\n");
// 	printList(oddHead);

// 	if(head!=NULL)
//       deleteList(&head);
//     if(oddHead!=NULL)
//       deleteList(&oddHead);
//     if(evenHead!=NULL)
//       deleteList(&evenHead);
//     return 0;
// }

// void printList(ListNode *cur){
//     printf("Current List: ");
//     while (cur != NULL){
//         printf("%d ", cur->item);
//         cur = cur->next;
//     }
//     printf("\n");
// }

// ListNode *findNode(ListNode* cur, int index)
// {
//   if (cur==NULL || index<0)
//       return NULL;
//   while(index>0){
//       cur=cur->next;
//       if (cur==NULL)
//          return NULL;
//       index--;
//   }
//   return cur;
// }

// int insertNode(ListNode **ptrHead, int index, int item){
//     ListNode  *pre, *newNode;
//     // If empty list or inserting first node, update head pointer
//     if (index == 0){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = *ptrHead;
//         *ptrHead = newNode;
//         return 1;
//     }
//     // Find the nodes before and at the target position
//     // Create a new node and reconnect the links
//     else if ((pre = findNode(*ptrHead, index-1)) != NULL){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = pre->next;
//         pre->next = newNode;
//         return 1;
//     }
//     return 0;
// }

// void deleteList(ListNode **ptrHead){
//     ListNode *cur = *ptrHead;
//     ListNode *temp;
//     while (cur!= NULL) {
// 		temp=cur->next;
// 		free(cur);
// 		cur=temp;
// 	}
// 	*ptrHead=NULL;
// }

//write code
int split(ListNode *cur, ListNode **ptrEvenList, ListNode **ptrOddList)
{
    int Ecount=0, Ocount=0, index=0;
    *ptrEvenList=*ptrOddList=NULL;

    if(cur==NULL)
        return 0;

    while(cur!=NULL){
        if(index%2==0){
            insertNode(ptrEvenList,Ecount,cur->item);
            Ecount++;
        }
        else{
            insertNode(ptrOddList,Ocount,cur->item);
            Ocount++;
        }

        cur=cur->next;
        index++;
    }

    return 1;
}

----------------------------------------

//#4. duplicateReverse(): creates a linked list w/ nodes stored in reverse


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode{
//     int item;
//     struct _listnode *next;
// } ListNode;


// void printList(ListNode *cur);
// ListNode * findNode(ListNode *cur, int index);
// int insertNode(ListNode **ptrHead, int index, int item);
// void deleteList(ListNode **ptrHead);
// int duplicateReverse(ListNode *cur,ListNode **ptrNewHead);

// int main()
// {
//     ListNode *head=NULL;
//     ListNode *dupRevHead=NULL;
//     int size =0;
//     int item;

//     printf("Enter a list of numbers, terminated by any non-digit character: \n");
//     while(scanf("%d",&item))
//         if(insertNode(&head,size, item)) size++;
//     scanf("%*s");

//     printf("\nBefore duplicateReverse() is called:\n");
//     printList(head);

//     duplicateReverse(head,&dupRevHead);

//     printf("\nAfter duplicateReverse() was called:\n");
//     printf("The original list:\n");
//     printList(head);
//     printf("The duplicated reverse list:\n");
//     printList(dupRevHead);

//     if(head!=NULL)
//       deleteList(&head);
//     if(dupRevHead)
//       deleteList(&dupRevHead);

//     return 0;
// }

// void printList(ListNode *cur){
//     printf("Current List: ");
//     while (cur != NULL){
//         printf("%d ", cur->item);
//         cur = cur->next;
//     }
//     printf("\n");
// }

// ListNode *findNode(ListNode* cur, int index)
// {
//   if (cur==NULL || index<0)
//       return NULL;
//   while(index>0){
//       cur=cur->next;
//       if (cur==NULL)
//          return NULL;
//       index--;
//   }
//   return cur;
// }

// int insertNode(ListNode **ptrHead, int index, int item){
//     ListNode  *pre, *newNode;
//     // If empty list or inserting first node, update head pointer
//     if (index == 0){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = *ptrHead;
//         *ptrHead = newNode;
//         return 1;
//     }
//     // Find the nodes before and at the target position
//     // Create a new node and reconnect the links
//     else if ((pre = findNode(*ptrHead, index-1)) != NULL){
//         newNode = malloc(sizeof(ListNode));
//         newNode->item = item;
//         newNode->next = pre->next;
//         pre->next = newNode;
//         return 1;
//     }
//     return 0;
// }

// void deleteList(ListNode **ptrHead){
//     ListNode *cur = *ptrHead;
//     ListNode *temp;
//     while (cur!= NULL) {
//         temp=cur->next;
//         free(cur);
//         cur=temp;
//     }
//     *ptrHead=NULL;
// }

//write code
int duplicateReverse(ListNode *cur,ListNode **ptrNewHead)
{
    int data;

    if (cur==NULL)
        return 0;

    while(cur!=NULL){
        data=cur->item;
        insertNode(ptrNewHead,0,data);
        cur=cur->next;
    }
    return 1;
}


