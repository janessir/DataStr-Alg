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
//     int **matrix;
// }Graph;

// typedef struct _linkedlist
// {
//     int size;
//     ListNode *head;
// } Stack;

// // You should not change the prototypes of these functions
// //////STACK///////////////////////////////////////////
// void push(Stack *sPtr, int vertex);
// int pop(Stack *sPtr);
// int peek(Stack s);
// int isEmptyStack(Stack s);
// void removeAllItemsFromStack(Stack *sPtr);
// ////GRAPH////////////////////////////////////////////
// void printGraphMatrix(Graph );
// ////////////////////////////////////////////

// void DFS_I (Graph , int );


// int main()
// {
//     Graph g;
//     int i,j;

//     printf("Enter the number of vertices:\n");
//     scanf("%d",&g.V);

//     g.E = 0;
//     g.matrix = (int **)malloc(g.V*sizeof(int *));
//     for(i=0;i<g.V;i++)
//         g.matrix[i] = (int *)malloc(g.V*sizeof(int));

//     for(i=0;i<g.V;i++)
//        for(j=0;j<g.V;j++)
//            g.matrix[i][j] = 0;

//     int V1, V2;
//     printf("Enter two vertices which are adjacent to each other:\n");
//     while(scanf("%d %d",&V1,&V2)==2)
//     {
//         if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
//         {
//             g.matrix[V1-1][V2-1] = 1;
//             g.matrix[V2-1][V1-1] = 1;
//             g.E++;
//         }
//         else
//             break;
//         printf("Enter two vertices which are adjacent to each other:\n");
//     }
//     scanf("%*c");
//     printf("Enter a start vertex for DFS:\n");
//     scanf("%d", &i);
//     printGraphMatrix(g);
//     DFS_I(g,i);

//     return 0;
// }

void DFS_I (Graph g, int v)
{
    int i, w, a=-1, visited[g.V];
    for (i=0;i<g.V;i++)
        visited[i]=0;
    
    //create stack
    Stack s;
    s.size=0;
    s.head=NULL;
    
    //push v into the stack
    push(&s,v);
    visited[v-1]=1;
    
    printf("number of edges: %d\n",g.E);
    printf("Ans: ");
    while(!isEmptyStack(s)){
        a=-1;
        w=peek(s);
        //iterate across the matrix to find an unvisited adjaceny vertex
        for (i=1; i<=g.V; i++){ //descending
            if(visited[i-1]==0 && g.matrix[w-1][i-1]==1){
                a=i;
                break;
            }
        }
        
        if(a!=-1){
            push(&s,a);
            visited[a-1]=1;
            continue;
        }
        else{
            printf("%d ",w);
            pop(&s);
        }
    }
}

// void printGraphMatrix(Graph g)
// {
//     int i,j;

//     for(i=0;i<g.V;i++){
//         for(j=0;j<g.V;j++)
//             printf("%d\t",g.matrix[i][j]);
//         printf("\n");
//     }

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

// // --------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;

typedef struct _graph{
    int V;
    int E;
    int *visited;
    int **matrix;
}Graph_DFS;

////GRAPH////////////////////////////////////////////
void printGraphMatrix(Graph_DFS );
////////////////////////////////////////////

void DFS_R (Graph_DFS , int );

int main()
{
    Graph_DFS g;
    int i,j;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
       for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;

    g.visited = (int *) malloc(sizeof(int)*g.V);
    for(i=0;i<g.V;i++) g.visited[i] = 0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.matrix[V1-1][V2-1] = 1;
            g.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");
    printf("Enter a start vertex for DFS:\n");
    scanf("%d", &i);
    printGraphMatrix(g);
    DFS_R(g,i);

    return 0;
}

//recursive approach, finding the adjacent unvisited neighbours for each v
void DFS_R (Graph_DFS g, int v)
{
    int i=0;
    
    //base
    if(g.matrix[v][i]==0 && )
}





void printGraphMatrix(Graph_DFS g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }

}


// // --------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

int nQueens(int** board, int N, int col);
int isSafe(int** board,int N, int row, int col);
void printSolution(int** board, int N);

int main()
{
    int **board;
    int BSize;

    int i,j;

    printf("Enter the size of chessBoard:\n");
    scanf("%d",&BSize);

    board = (int **)malloc(BSize*sizeof(int *));
    for(i=0;i<BSize;i++)
        board[i] = (int *)malloc(BSize*sizeof(int));

    for(i=0;i<BSize;i++)
       for(j=0;j<BSize;j++)
           board[i][j] = 0;

    printf("Number of Solutions: %d\n",nQueens(board, BSize, 0));

    return 0;
}
 
int nQueens(int** board, int BSize, int col)
{
 //Write your code here
 //Safe Place checking is provide below, you are free to use it.
    
    int row,count=1;
    
    //base case
    if (col>=BSize)
        return 1;
    
    //else
    for(row=0;row<BSize;row++){
        if(isSafe(board,BSize,row,col)){
            board[row][col]=1; //add the queen
            if(nQueens(board,BSize,col+1)){
                if(col==BSize-1)
                    return count+1;
                return 1; //ie all the queens are non-attacking
            }
            else{
                count--;
                board[row][col]=0; //delete queen //ie the whole 'col space' are not safe
            }
        }
    }
    return 0;
}

//Safe checking
int isSafe(int** board,int BSize, int row, int col)
{
    int i, j;

    // Horicatal check
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Upper left diagonal check
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Lower left diagonal check
    for (i = row, j = col; j >= 0 && i < BSize; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printSolution(int** board, int BSize)
{
    int i,j;
    for (i = 0; i < BSize; i++) {
        for (j = 0; j < BSize; j++){
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" + ");
        }
        printf("\n");
    }
    printf("\n");
}



