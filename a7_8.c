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

// // question 3


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _arraynode
// {
//     int *itemArray;
//     int sizeArray; //the size of a possible sequence
//     struct _arraynode *next;
// }ArrayNode;

// typedef struct _arraylist{
//    int size; //the number of possible sequences
//    ArrayNode *head;
// } ArrayList;

// typedef struct _listnode
// {
//     int item;
//     struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//    int sum;
//    int size;
//    ListNode *head;
// } LinkedList;

// // You should not change the prototypes of these functions
// //////LinkedList///////////////////////////////////////////
// int insertNode(LinkedList *ll, int index, int coin);
// int removeNode(LinkedList *ll, int index);
// ListNode *findNode(LinkedList ll, int index);
// void removeAllItems(LinkedList *ll);
// ///////////////////////////////////////////////////

// void sumToC(LinkedList* ll, int C, ArrayList* al);
// //void printresult(LinkedList *ll);
// void insertToArrList(LinkedList* ll, ArrayList* al);

// int main()
// {
//     int C;
//     printf("Enter a number:\n");
//     scanf("%d",&C);

//     LinkedList ll;
//     ll.head = NULL;
//     ll.sum = 0;
//     ll.size = 0;
//     ArrayList al;
//     al.head = NULL;
//     al.size = 0;

//     sumToC(&ll,C,&al);
//     ArrayNode* temp;
//     int i,j;
//     temp = al.head;
//     for(i=0;i<al.size;i++){
//         for(j=0;j<temp->sizeArray;j++)
//             printf(" %d ",temp->itemArray[j]);
//         printf("\n");
//         temp = temp->next;
//     }

//     return 0;
// }

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
    int s,l;
    insertNode(ll,0,1);
    
    //while ll is not empty
    while(ll->size!=0){
        if(ll->head->item==C){
            //insert to array
            insertToArrList(ll,al);
//            printresult(ll);
            break;
        }
        if(ll->sum==C){
            //insert to array
            insertToArrList(ll,al);
//            printresult(ll);
            removeNode(ll,ll->size-1);
            s=findNode(*ll,ll->size-1)->item;
            removeNode(ll,ll->size-1);
            insertNode(ll,ll->size,s+1);
        }
        else if(ll->sum<C){
            l=findNode(*ll,ll->size-1)->item;
            insertNode(ll,ll->size,l+1);
        }
        else{
            removeNode(ll,ll->size-1);
            s=findNode(*ll,ll->size-1)->item;
            removeNode(ll,ll->size-1);
            insertNode(ll,ll->size,s+1);
        }
    }
}

//void printresult(LinkedList *ll){
//    //check
//    ListNode *cur=ll->head;
//    if(ll->size!=0){
//        for (int j=0;j<ll->size;j++){
//            printf("%d ",cur->item);
//            cur=cur->next;
//        }
//        printf("\n");
//    }
//}


void insertToArrList(LinkedList* ll, ArrayList* al){
    int i;
    ArrayNode *temp;
    ListNode *cur=ll->head;
    if (al->head == NULL){
        al->head = (ArrayNode *)malloc(sizeof(ArrayNode));
        al->head->itemArray=malloc(ll->size*sizeof(int));
        for(i=0;i<ll->size;i++){
            al->head->itemArray[i]=cur->item;
            cur=cur->next;
        }
        al->head->sizeArray = ll->size;
        al->head->next = NULL;
    }
    else{
        temp = al->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (ArrayNode *)malloc(sizeof(ArrayNode));
        temp->next->itemArray=malloc(ll->size*sizeof(int));
        for(i=0;i<ll->size;i++){
                temp->next->itemArray[i]=cur->item;
                cur=cur->next;
        }
        temp->next->sizeArray = ll->size;
        temp->next->next = NULL;
    }
    al->size++;
}



// ///////////////////////////////////////////////////////
// int insertNode(LinkedList *ll, int index, int value){

//     ListNode *pre, *cur;

//     if (ll == NULL || index < 0 || index > ll->size)
//         return 0;

//         if (index == 0){
//         cur = ll->head;
//         ll->head = (ListNode*) malloc(sizeof(ListNode));
//         ll->head->item = value;
//         ll->head->next = cur;
//         ll->sum += value;
//         ll->size++;
//         return 1;
//     }


//     // Find the nodes before and at the target position
//     // Create a new node and reconnect the links
//     if ((pre = findNode(*ll, index - 1)) != NULL){
//         cur = pre->next;
//         pre->next = malloc(sizeof(ListNode));
//         pre->next->item = value;
//         pre->next->next = cur;
//         ll->sum += value;
//         ll->size++;
//         return 1;
//     }

//     return 0;
// }



// int removeNode(LinkedList *ll, int index){

//     ListNode *pre, *cur;

//     // Highest index we can remove is size-1
//     if (ll == NULL || index < 0 || index > ll->size)
//         return 0;

//     // If removing first node, need to update head pointer
//     if (index == 0){
//         cur = ll->head->next;
//         ll->sum -= ll->head->item;
//         free(ll->head);
//         ll->head = cur;
//         ll->size--;
//         return 1;
//     }

//     // Find the nodes before and after the target position
//     // Free the target node and reconnect the links
//     if ((pre = findNode(*ll, index - 1)) != NULL){

//         if (pre->next == NULL)
//             return 0;

//         cur = pre->next;
//         ll->sum -= cur->item;
//         pre->next = cur->next;
//         free(cur);
//         ll->size--;
//         return 1;
//     }

//     return 0;
// }

// ListNode *findNode(LinkedList ll, int index){

//     ListNode *temp;

//     if (index < 0 || index >= ll.size)
//         return NULL;

//     temp = ll.head;

//     if (temp == NULL || index < 0)
//         return NULL;

//     while (index > 0){
//         temp = temp->next;
//         if (temp == NULL)
//             return NULL;
//         index--;
//     }

//     return temp;
// }

// void removeAllItems(LinkedList *ll)
// {
//     ListNode *cur = ll->head;
//     ListNode *tmp;

//     while (cur != NULL){
//         tmp = cur->next;
//         free(cur);
//         cur = tmp;
//     }
//     ll->head = NULL;
//     ll->size = 0;
//     ll->sum =0;
// }


// question 4

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    int **matrix;;
    int *arr;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph *g);
void printGraphMatrix(Graph );
int dfs(Graph* g, int s, int t);
void printGraphArray(Graph g,int size);
int insertToAr(Graph *g,int parent[],int t);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
    int Prj, Std, Mtr; //Project, Student and Mentor;
    int maxMatch;
    scanf("%d %d %d", &Std, &Prj, &Mtr);

    int np,nm; //number of projects and number of mentors
    int pi=0,si=Prj,si2=Prj+Std, mi=Prj+Std+Std; //starting index of project, student, mentor respectively
    
    //build graph
    Graph g;
    //Write your code
        int i,j,k;

    g.V=Prj+Std+Std+Mtr+2;
    g.E = 0;
    g.arr=NULL;
    
    //creating |V|x|V| matrix
    g.matrix = (int **)malloc(g.V*sizeof(int *)); //creating the rows of the 2d matrix
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int)); //creating the corresponding columns of the 2d matrix
    
    //initializing all the vertex as no links
    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.matrix[i][j] = 0;

    //establishing the links btw the nodes
    int V1, V2;
    for(i=0;i<Std;i++){
        scanf("%d %d ",&np,&nm);
        for(j=0;j<np;j++){
            //input projects by students
            scanf("%d ",&V1);
            g.matrix[pi+V1-1][si+i]=1;
            g.E++;
        }
        //input mentors by students
        for(j=0;j<nm;j++){
            scanf("%d",&V2);
            g.matrix[si2+i][mi+V2-1]=1;
            g.E+=2;
        }
    }
    //links btw the 2 student bipartite
    for(k=0;k<Std;k++){
        g.matrix[si+k][si2+k]=1;
        g.E++;
    }
    //links from source
    for(k=0;k<Prj;k++){
        g.matrix[g.V-2][k]=1;
        g.E++;
    }
    //links to sink
    for(k=0;k<Mtr;k++){
        g.matrix[mi+k][g.V-1]=1;
        g.E++;
    }
    
    
    printGraphMatrix(g);
    
//    apply Ford Fulkerson algorithm
//     use DFS or BFS to find a path
    maxMatch = matching(&g);
    printf("%d\n", maxMatch);
    return 0;
}

int matching(Graph *g)
{
    int i,maxMatch=0;
    //while finding a path from s->t
    printf("\n---------------------------------------------------\n");
    
    int count=dfs(g,g->V-2,g->V-1);
    while(count){
        printGraphArray(*g,count);
        for(i=0;i<count-1;i++){
            g->matrix[g->arr[i]][g->arr[i+1]]=0;
            g->matrix[g->arr[i+1]][g->arr[i]]=1;
        }
        printGraphMatrix(*g);
        free(g->arr);
        maxMatch++;
        count=dfs(g,g->V-2,g->V-1);
    }
    if(maxMatch)
        return maxMatch;
    return 0;
}

// s: source indec, t: sink index
int dfs(Graph *g, int s, int t){

    int a,n,m;

    Stack y;
    y.head=NULL;
    y.size=0;
    
    int visited[g->V];
    int parent[g->V];
    
    for(int l=0;l<g->V;l++){
        visited[l]=0;
        parent[l]=0;
    }
    //push s to stack
    push(&y,s);
    visited[s]=1;
    parent[s]=-1;
    while(!isEmptyStack(y)){
        a=-1;
        n=peek(y);
//        pop(&y);
        if(n==t){
//            removeAllItemsFromStack(&y);
            return insertToAr(g,parent,t);
        }
        for(m=g->V-1;m>=0;m--){
            if(g->matrix[n][m]==1 && visited[m]!=1){
                a=m;
                break;
            }
        }
        if(a!=-1){
            push(&y,a);
            visited[a]=1;
            parent[a]=n;
            continue;
        }
        else{
            pop(&y);
        }
    }
    return 0;
}

int insertToAr(Graph *g,int parent[g->V],int t){
    
    Stack z;
    z.head=NULL;
    z.size=0;
    
    int count=0;
    
    int c=t;
    push(&z,t);
    count++;
    while(parent[c]!=-1){
        push(&z,parent[c]);
        c=parent[c];
        count++;
    }
    g->arr=malloc(count*sizeof(int));
    for(int i=0;i<count;i++){
        g->arr[i]=peek(z);
        pop(&z);
    }
    
    printGraphArray(*g,count);
    
    return count;
}

void printGraphArray(Graph g,int size){
    printf("hi\n");
    for(int i=0;i<size;i++)
        printf("%d ",g.arr[i]);
    
    printf("\n");
}

void printGraphMatrix(Graph g)
{
    int i,j;
    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }
}


void removeAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp, *preTemp;
    if(*AdjList != NULL)
    {
        if((*AdjList)->vertex ==vertex){//first node
            temp = *AdjList;
            *AdjList = (*AdjList)->next;
            free(temp);
            return;
        }
        preTemp = *AdjList;
        temp = (*AdjList)->next;
        while(temp!=NULL && temp->vertex != vertex)
        {
            preTemp= temp;
            temp = temp->next;
        }
        preTemp->next = temp->next;
        free(temp);
    }

}
void insertAdjVertex(ListNode** AdjList,int vertex)
{
    ListNode *temp;
    if(*AdjList==NULL)
    {
        *AdjList = (ListNode *)malloc(sizeof(ListNode));
        (*AdjList)->vertex = vertex;
        (*AdjList)->next = NULL;
    }
    else{
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertex = vertex;
        temp->next = *AdjList;
        *AdjList = temp;
    }
}
void enqueue(Queue *qPtr, int vertex) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
    while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
    if(cur==NULL) printf("Empty");

    while (cur != NULL){
        printf("%d ", cur->vertex);
        cur = cur->next;
    }
    printf("\n");
}

void push(Stack *sPtr, int vertex)
{
    StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
    while(pop(sPtr));
}
