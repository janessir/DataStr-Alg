#include <stdio.h>
#include <stdlib.h>

enum GraphType {ADJ_MATRIX, ADJ_LIST}; // Types of Graph Representation

typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;

union GraphForm{
    int **matrix;
    ListNode **list;
};

typedef struct _graph{
    int V;
    int E;
    enum GraphType type;
    union GraphForm adj;
}Graph;

void printGraphMatrix(Graph );
void adjM2adjL(Graph *);
void adjL2adjM(Graph *);
void printGraphList(Graph );
void calDegreeV(Graph,int *);
void printDegreeV(int *,int );

int main()
{
    Graph g;
    int i,j;

    int* degreeV;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    //creating |V|x|V| matrix
    g.adj.matrix = (int **)malloc(g.V*sizeof(int *)); //creating the rows of the 2d matrix
    for(i=0;i<g.V;i++)
        g.adj.matrix[i] = (int *)malloc(g.V*sizeof(int)); //creating the corresponding columns of the 2d matrix
    
    //initializing all the vertex as no links
    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.adj.matrix[i][j] = 0;
    g.type = ADJ_MATRIX;
    
    //creating a 1d array to store degree for respective vertex
    degreeV = (int *) malloc(g.V*sizeof(int));
    for(i=0;i<g.V;i++)
        degreeV[i]=0;

    //establishing the links btw the nodes
    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            //undirected graph
            g.adj.matrix[V1-1][V2-1] = 1;
            g.adj.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    
    //q3
    calDegreeV(g,degreeV);
    printGraphMatrix(g);
    printDegreeV(degreeV,g.V);

    //q1
    printf("\nQuestion 1:\n");
    adjM2adjL(&g);
    calDegreeV(g,degreeV);
    
    printGraphList(g);
    printDegreeV(degreeV,g.V);

    //q2
    printf("\nQuestion 2:\n");
    adjL2adjM(&g);
    printGraphMatrix(g);

    return 0;
}

void printGraphMatrix(Graph g)
{
    int i,j;
    if(g.type == ADJ_LIST) {printf("Error"); return;}

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.adj.matrix[i][j]);
        printf("\n");
    }

}

void printDegreeV(int *degreeV,int V)
{
    int i;
    for(i=0;i<V;i++)
        printf("%d: %d degree\n",i+1,degreeV[i]);
}

void printGraphList(Graph g){
    int i;
    ListNode* temp;

    if(g.type == ADJ_MATRIX) {printf("Error"); return;}

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.adj.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Question 1
void adjM2adjL(Graph *g)
{
    int i, row,col;
    ListNode *cur,*temp;
    ListNode **list; //make a dynamic 2d array
    
    if(g->type==ADJ_LIST){
        printf("Error\n");
        return;
    }
    if(g->V<=0){
        printf("Empty Graph!\n");
        return;
    }


    list=malloc(g->V*sizeof(ListNode *)); //stores a 1d array of ListNode ptr
    for(i=0;i<g->V;i++){
        list[i]=NULL;
    }

    //printf("%d\t",g.adj.matrix[i][j]);
    //iterating thru the array
    for(row=0; row<g->V; row++){
        for(col=0; col<g->V; col++){
            //if there's en edge
            if((g->adj.matrix[row][col])==1){
                //create ListNode
                temp=malloc(sizeof(ListNode));
                temp->vertex=col+1;
                temp->next=NULL;

                //if first listnode
                if(list[row]==NULL)
                    list[row]=temp;

                else{
                    cur=list[row];
                    while(cur->next!=NULL)
                        cur=cur->next;
                    cur->next=temp;
                }

            }
        }
    }
    
    //free matrix
    for(i=0;i<g->V;i++)
        free(g->adj.matrix[i]);
    free(g->adj.matrix);
    
    g->adj.list=list;
    g->type=ADJ_LIST;

}

//questio 2
void adjL2adjM(Graph *g){
    int i,j;
    int **matrix;
    ListNode *cur;
    
    //creating the 1d array first
    matrix=malloc(g->V*sizeof(int*)); //malloc returns pointer to array of pointers
    //creating the 2d array
    for(i=0;i<g->V;i++)
        matrix[i]=malloc(g->V*sizeof(int)); //malloc returns pointer to array of ints
    
    for(i=0;i<g->V;i++)
        for(j=0;j<g->V;j++)
            matrix[i][j]=0;
    

    for(i=0;i<g->V;i++){
        cur=g->adj.list[i];
        while(cur!=NULL){
            matrix[i][cur->vertex-1]=1;
            cur=cur->next;
        }
    }
    
    //free list
    for(i=0;i<g->V;i++)
        free(g->adj.list[i]);
    free(g->adj.list);
    
    g->adj.matrix=matrix;
    g->type=ADJ_MATRIX;
    
}

// Question 3
// count the number of of '1' in each row
//using array degreeV, store the degree of each vertex in i-1
void calDegreeV(Graph g, int *degreeV)
{
    int i,j,count;
    ListNode* cur;
    
    if(g.type==ADJ_MATRIX){
        for(i=0;i<g.V;i++){
            count=0;
            //adj vertex(?)
            for(j=0;j<g.V;j++){
                if(g.adj.matrix[i][j]==1)
                    count++;
            }
            degreeV[i]=count;
        }
    }
    
    //list
    else{
        for(i=0;i<g.V;i++){
            cur=g.adj.list[i];
            count=0;
            while(cur!=NULL){
                count++;
                cur=cur->next;
            }
            degreeV[i]=count;
        }
    }
}

