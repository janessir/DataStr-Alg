// //question 1

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode
// {
//     int vertex;
//     struct _listnode *next;
// } ListNode;

// typedef struct _graph{
//     int V;
//     int E;
//     ListNode **list;
// }Graph;

// typedef ListNode QueueNode;

// typedef struct _queue{
//    int size;
//    QueueNode *head;
//    QueueNode *tail;
// } Queue;

// int BFS (Graph G, int v, int w);

// void printGraphList(Graph );

// // You should not change the prototypes of these functions
// void enqueue(Queue *qPtr, int item);
// int dequeue(Queue *qPtr);
// int getFront(Queue q);
// int isEmptyQueue(Queue q);
// void removeAllItemsFromQueue(Queue *qPtr);

// int main()
// {
//     Graph g;
//     int i,j;
//     ListNode *temp;

//     printf("Enter the number of vertices:\n");
//     scanf("%d",&g.V);

//     g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));

//     for(i=0;i<g.V;i++)
//         g.list[i] = NULL;

//     printf("Enter two vertices which are adjacent to each other:\n");
//     while(scanf("%d %d",&i,&j)==2)
//     {
//         i=i-1;

//         if(g.list[i]==NULL){
//             g.list[i] = (ListNode *)malloc(sizeof(ListNode));
//             g.list[i]->vertex = j;
//             g.list[i]->next = NULL;
//         }
//         else{
//             temp = (ListNode *)malloc(sizeof(ListNode));
//             temp->next = g.list[i];
//             temp->vertex = j;
//             g.list[i] = temp;
//         }
//         g.E++;
//         printf("Enter two vertices which are adjacent to each other:\n");
//     }
//     scanf("%*c");
//     printf("Enter two vertices for finding their shortest distance:\n");
//     scanf("%d %d", &i, &j);

//     int d = BFS(g,i,j);
    
//     if(d==-1)
//         printf("%d and %d are unconnected.\n",i,j);
//     else
//         printf("The shortest distance is %d\n",d);
//     printGraphList(g);
//     return 0;
// }

int BFS (Graph g, int v, int w){
    
    int parentNode[g.V];
    int visited[g.V];
    int i,n,dist=0,found=0;
    ListNode *cur;
    
    Queue q;
    q.head=NULL;
    q.tail=NULL;
    q.size=0;
    
    //if no path
    if(g.V<2)
        return -1;
    
    
    for(i=0;i<g.V;i++)
        visited[i]=0;
    
    //build the BFS tree
    enqueue(&q,v);
    visited[v-1]=1;
    parentNode[v-1]=-1; // staer root v of BFS tree has no node
    
    while(!isEmptyQueue(q)){
        n=getFront(q);
        if(n==w){
            found=1;
            break;
        }
        cur=g.list[n-1];
        while(cur!=NULL){
            if(visited[cur->vertex-1]!=1){
                enqueue(&q,cur->vertex);
                visited[cur->vertex-1]=1;
                parentNode[cur->vertex-1]=n;
            }
            cur=cur->next;
        }
        dequeue(&q);
    }
    
    //trace back
    if(found==1){
        while(parentNode[n-1]!=-1){
            dist++;
            n=parentNode[n-1];
        }
        return dist;
    }
    
    return -1;
}

// void printGraphList(Graph g){
//     int i;
//     ListNode* temp;

//     for(i=0;i<g.V;i++)
//     {
//         printf("%d:\t",i+1);
//         temp = g.list[i];
//         while(temp!=NULL){
//             printf("%d -> ",temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// void enqueue(Queue *qPtr, int item) {
//     QueueNode *newNode;
//     newNode = malloc(sizeof(QueueNode));
//     if(newNode==NULL) exit(0);

//     newNode->vertex = item;
//     newNode->next = NULL;

//     if(isEmptyQueue(*qPtr))
//         qPtr->head=newNode;
//     else
//         qPtr->tail->next = newNode;

//     qPtr->tail = newNode;
//     qPtr->size++;
// }

// int dequeue(Queue *qPtr) {
//     if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
//         return 0;
//     }
//     else{
//        QueueNode *temp = qPtr->head;
//        qPtr->head = qPtr->head->next;
//        if(qPtr->head == NULL) //Queue is emptied
//            qPtr->tail = NULL;

//        free(temp);
//        qPtr->size--;
//        return 1;
//     }
// }

// int getFront(Queue q){
//     return q.head->vertex;
// }

// int isEmptyQueue(Queue q) {
//     if(q.size==0) return 1;
//     else return 0;
// }

// void removeAllItemsFromQueue(Queue *qPtr)
// {
//     while(dequeue(qPtr));
// }


// ------------------------------------------------------------------------------------

// // question 2
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _listnode
// {
//     int vertex;
//     struct _listnode *next;
// } ListNode;
// typedef ListNode StackNode;

// typedef struct _graph{
//     int V;
//     int E;
//     ListNode **list;
// }Graph;

// typedef ListNode QueueNode;

// typedef struct _queue{
//    int size;
//    QueueNode *head;
//    QueueNode *tail;
// } Queue;

// typedef struct _stack
// {
//     int size;
//     StackNode *head;
// } Stack;

// int CC (Graph g);

// void printGraphList(Graph );

// // You should not change the prototypes of these functions
// void enqueue(Queue *qPtr, int item);
// int dequeue(Queue *qPtr);
// int getFront(Queue q);
// int isEmptyQueue(Queue q);
// void removeAllItemsFromQueue(Queue *qPtr);
// //////STACK///////////////////////////////////////////
// void push(Stack *sPtr, int vertex);
// int pop(Stack *sPtr);
// int peek(Stack s);
// int isEmptyStack(Stack s);
// void removeAllItemsFromStack(Stack *sPtr);
// //////////////////////////////////

// int main()
// {
//     Graph g;
//     int i,j;
//     ListNode *temp;

//     printf("Enter the number of vertices:\n");
//     scanf("%d",&g.V);

//     g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));

//     for(i=0;i<g.V;i++)
//         g.list[i] = NULL;

//     printf("Enter two vertices which are adjacent to each other:\n");
//     while(scanf("%d %d",&i,&j)==2)
//     {
//         i=i-1;

//         if(g.list[i]==NULL){
//             g.list[i] = (ListNode *)malloc(sizeof(ListNode));
//             g.list[i]->vertex = j;
//             g.list[i]->next = NULL;
//         }
//         else{
//             temp = (ListNode *)malloc(sizeof(ListNode));
//             temp->next = g.list[i];
//             temp->vertex = j;
//             g.list[i] = temp;
//         }
//         g.E++;
//         printf("Enter two vertices which are adjacent to each other:\n");
//     }
//     scanf("%*c");

//     int res = CC(g);
//     if(res ==1)
//         printf("The graph is strongly connected.\n");
//     else
//         printf("The graph is not strongly connected.\n");

//     printGraphList(g);
//     return 0;
// }

int CC (Graph g)
{
    int i,j,n,count=0;
    int visited[g.V];
    ListNode *cur;
    
    Stack s;
    s.head=NULL;
    s.size=0;
    
    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            visited[j]=0;
        count=0;
        push(&s,i+1);
        visited[i]=1;
        while(!isEmptyStack(s)){
            n=peek(s);
            pop(&s);
            count++;
            //push its neighbours
            cur=g.list[n-1];
            while(cur!=NULL){
                if(visited[cur->vertex-1]!=1){
                    push(&s,cur->vertex);
                    visited[cur->vertex-1]=1;
                }
                cur=cur->next;
            }
        }
        if(count!=g.V)
            return 0;
    }
    return 1;
}


// void printGraphList(Graph g){
//     int i;
//     ListNode* temp;

//     for(i=0;i<g.V;i++)
//     {
//         printf("%d:\t",i+1);
//         temp = g.list[i];
//         while(temp!=NULL){
//             printf("%d -> ",temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// void enqueue(Queue *qPtr, int vertex) {
//     QueueNode *newNode;
//     newNode = malloc(sizeof(QueueNode));
//     if(newNode==NULL) exit(0);

//     newNode->vertex = vertex;
//     newNode->next = NULL;

//     if(isEmptyQueue(*qPtr))
//         qPtr->head=newNode;
//     else
//         qPtr->tail->next = newNode;

//     qPtr->tail = newNode;
//     qPtr->size++;
// }

// int dequeue(Queue *qPtr) {
//     if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
//         return 0;
//     }
//     else{
//        QueueNode *temp = qPtr->head;
//        qPtr->head = qPtr->head->next;
//        if(qPtr->head == NULL) //Queue is emptied
//            qPtr->tail = NULL;

//        free(temp);
//        qPtr->size--;
//        return 1;
//     }
// }

// int getFront(Queue q){
//     return q.head->vertex;
// }

// int isEmptyQueue(Queue q) {
//     if(q.size==0) return 1;
//     else return 0;
// }

// void removeAllItemsFromQueue(Queue *qPtr)
// {
//     while(dequeue(qPtr));
// }

// void push(Stack *sPtr, int vertex)
// {
//     StackNode *newNode;
//     newNode= malloc(sizeof(StackNode));
//     newNode->vertex = vertex;
//     newNode->next = sPtr->head;
//     sPtr->head = newNode;
//     sPtr->size++;
// }

// int pop(Stack *sPtr)
// {
//     if(sPtr==NULL || sPtr->head==NULL){
//         return 0;
//     }
//     else{
//        StackNode *temp = sPtr->head;
//        sPtr->head = sPtr->head->next;
//        free(temp);
//        sPtr->size--;
//        return 1;
//     }
// }

// int isEmptyStack(Stack s)
// {
//      if(s.size==0) return 1;
//      else return 0;
// }

// int peek(Stack s){
//     return s.head->vertex;
// }

// void removeAllItemsFromStack(Stack *sPtr)
// {
//     while(pop(sPtr));
// }

// ------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray; //the size of a possible sequence
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the number of possible sequences
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum;
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
void insertToArrList(LinkedList* ll, ArrayList* al);

int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);
    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){
        for(j=0;j<temp->sizeArray;j++)
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
    int i,j,k,count;
    ListNode *cur,*pre;
    
    
    for(i=1;i<=C;i++){
        //creating first listnode
        ll->head=malloc(sizeof(ListNode));
        ll->head->item=i;
        ll->head->next=NULL;
        ll->size=1;
        
        ll->sum=i;
        
        //ie the last element == C
        if(ll->sum==C){
            insertToArrList(ll,al);
            return;
        }
        
        //check
        for(j=i+1;j<=C;j++){
            if(ll->sum==C){
                insertToArrList(ll,al);
                //backtrack by 2 steps
                
                if(ll->size==2)
                    break;
                
                //else
                //backtrack by 2 steps
                count=0;
                pre=ll->head;
                for(k=0;k<ll->size-3;k++)
                    pre=pre->next;
                count+=pre->next->next->item;
                free(pre->next->next);
                count+=pre->next->item;
                free(pre->next);
                pre->next=NULL;
                ll->sum-=count;
                ll->size-=2;
                
                //create and add listnode to ll
                cur=ll->head;
                while(cur->next!=NULL)
                    cur=cur->next;
                cur->next=malloc(sizeof(ListNode));
                cur->next->next=NULL;
                cur->next->item=j;
                
                
            }
            else if(ll->sum<C){
                //create and add listnode to ll
                cur=ll->head;
                while(cur->next!=NULL)
                    cur=cur->next;
                cur->next=malloc(sizeof(ListNode));
                cur->next->next=NULL;
                cur->next->item=j;
            }
            else{
                if(ll->size==2)
                    break;
                
                //else
                //backtrack by 2 steps
                count=0;
                pre=ll->head;
                for(k=0;k<ll->size-3;k++)
                    pre=pre->next;
                count+=pre->next->next->item;
                free(pre->next->next);
                count+=pre->next->item;
                free(pre->next);
                pre->next=NULL;
                ll->sum-=count;
                ll->size-=2;
                
                //create and add listnode to ll
                cur=ll->head;
                while(cur->next!=NULL)
                    cur=cur->next;
                cur->next=malloc(sizeof(ListNode));
                cur->next->next=NULL;
                cur->next->item=j;
            }
            
            ll->sum+=j;
        }
        
    }
    
}

void insertToArrList(LinkedList* ll, ArrayList* al){
    int k;
    ListNode *cur;
    ArrayNode *tail;
    
    ArrayNode an;
    an.itemArray=NULL;
    an.next=NULL;
    an.sizeArray=0;
    
    //trf items in LL to arraynode
    an.sizeArray=ll->size;
    cur=ll->head;
    k=0;
    while(cur!=NULL){
        an.itemArray[k++]=cur->item;
        cur=cur->next;
    }
    an.next=NULL;
    
    al->size+=1;
    if(al->head==NULL)
        al->head=&an;
    else{
        tail=al->head;
        while(tail->next!=NULL)
            tail=tail->next;
        tail->next=&an;
    }
}
//ArrayNode* temp;
//int i,j;
//temp = al.head;
//for(i=0;i<al.size;i++){
//    for(j=0;j<temp->sizeArray;j++)
//        printf(" %d ",temp->itemArray[j]);
//    printf("\n");
//    temp = temp->next;
//}



///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

    ListNode *pre, *cur;

    if (ll == NULL || index < 0 || index > ll->size)
        return 0;

        if (index == 0){
        cur = ll->head;
        ll->head = (ListNode*) malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        ll->sum += value;
        ll->size++;
        return 1;
    }


    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(*ll, index - 1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        ll->sum += value;
        ll->size++;
        return 1;
    }

    return 0;
}


int removeNode(LinkedList *ll, int index){

    ListNode *pre, *cur;

    // Highest index we can remove is size-1
    if (ll == NULL || index < 0 || index > ll->size)
        return 0;

    // If removing first node, need to update head pointer
    if (index == 0){
        cur = ll->head->next;
        ll->sum -= ll->head->item;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        return 1;
    }

    // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if ((pre = findNode(*ll, index - 1)) != NULL){

        if (pre->next == NULL)
            return 0;

        cur = pre->next;
        ll->sum -= cur->item;
        pre->next = cur->next;
        free(cur);
        ll->size--;
        return 1;
    }

    return 0;
}

ListNode *findNode(LinkedList ll, int index){

    ListNode *temp;

    if (index < 0 || index >= ll.size)
        return NULL;

    temp = ll.head;

    if (temp == NULL || index < 0)
        return NULL;

    while (index > 0){
        temp = temp->next;
        if (temp == NULL)
            return NULL;
        index--;
    }

    return temp;
}

void removeAllItems(LinkedList *ll)
{
    ListNode *cur = ll->head;
    ListNode *tmp;

    while (cur != NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    ll->head = NULL;
    ll->size = 0;
    ll->sum =0;
}
