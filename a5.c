// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define SIZE 80 //The size of the array

// enum ExpType {OPT,OPERAND};

// typedef struct _listnode
// {
//     int  item;
//     enum ExpType type;
// 	struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
// } LinkedList;

// void insertNode(LinkedList *llPtr, int item, enum ExpType type);
// int deleteNode(LinkedList *llPtr);
// void removeAllNodes(LinkedList *llPtr);
// int isEmptyLinkedList (LinkedList ll);

// void expressionLL(char* infix, LinkedList *inExpLL);

// void printExpLL(LinkedList inExpQ, int seed);

// int main()
// {
//     char infix[SIZE];
//     char *p;

//     //printf("Enter an infix expression:\n");
//     fgets(infix,SIZE,stdin);
//     p=strchr(infix,'\n');
//     if(p) *p='\0';

//     LinkedList inExpLL;
//     inExpLL.head = NULL;
//     inExpLL.size = 0;

//     expressionLL(infix, &inExpLL);

//     int seed;
//     //printf("Enter a seed: \n");
//     scanf("%d",&seed);
//     printExpLL(inExpLL,seed);

//     removeAllNodes(&inExpLL);
//     return 0;
// }

void expressionLL(char* infix, LinkedList *inExpLL)
{
    int num=-1, i=strlen(infix)-1, tenth;

    inExpLL->head=NULL;
    inExpLL->size=0;

    while(i>=0){
        if(isdigit(infix[i])){
            num=(infix[i])-'0';
            i--;
            tenth=10;

            while(isdigit(infix[i])){
                num+=tenth*(infix[i]-'0');
                tenth*=10;
                i--;
            }
        }
        //if operator/ parenthesis
        else{
            if(num==-1){
                insertNode(inExpLL,infix[i],OPT);
            }
            else{
                insertNode(inExpLL,num,OPERAND);
                insertNode(inExpLL,infix[i],OPT);
                num=-1;
            }
            i--;
        }
    }
    if(num!=-1)
        insertNode(inExpLL,num,OPERAND);
}

// void printExpLL(LinkedList inExpLL, int seed)
// {
//     ListNode* temp = NULL;
//     temp = inExpLL.head;
//     while(temp!= NULL){
//         if(temp->type == OPERAND)
//             printf(" %d ",temp->item+ seed);
//         else
//             printf(" %c ",(char)(temp->item));
//         temp = temp->next;
//     }
//     printf("\n");
// }

// void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
//     ListNode *newNode;
//     newNode = malloc(sizeof(ListNode));
//     if(newNode==NULL) exit(0);

//     newNode->item = item;
//     newNode->type = type;
//     newNode->next = LLPtr->head;
//     LLPtr->head=newNode;
//     LLPtr->size++;

// }

// int deleteNode(LinkedList *LLPtr) {
//     if(LLPtr==NULL || LLPtr->size==0){ //Queue is empty or NULL pointer
//         return 0;
//     }
//     else{
//       ListNode *temp = LLPtr->head;
//       LLPtr->head = LLPtr->head->next;

//       free(temp);
//       LLPtr->size--;
//       return 1;
//     }
// }

// int isEmptyLinkedList (LinkedList ll) {
//     if(ll.size==0) return 1;
//     else return 0;
// }

// void removeAllNodes(LinkedList *LLPtr)
// {
// 	while(deleteNode(LLPtr));
// }


// ----------------------------------------------------------


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define SIZE 80 //The size of the array

// enum ExpType {OPT,OPERAND};

// typedef struct _stackNode{
//     char item;
//     struct _stackNode *next;
// }StackNode;

// typedef struct _stack{
//   int size;
//   StackNode *head;
// }Stack;

// void push(Stack *sPtr, char item);
// int pop(Stack *sPtr);
// char peek(Stack s);
// int isEmptyStack(Stack s);

// typedef struct _listnode
// {
//     int  item;
//     enum ExpType type;
// 	struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
// } LinkedList;

// void insertNode(LinkedList *llPtr, int item,enum ExpType type);
// int deleteNode(LinkedList *llPtr);
// void removeAllNodes(LinkedList *llPtr);
// int isEmptyLinkedList (LinkedList ll);


// void in2PreLL(char* infix, LinkedList *inExpLL);
// int lowerPrec(char curCh, char topStackCh);


// void printExpLL(LinkedList inExp);

// int main(){
//     char infix[SIZE];
//     char* p;

//     //printf("Enter an infix expression:\n");
//     fgets(infix,SIZE,stdin);
//     p=strchr(infix,'\n');
//     if(p) *p='\0';

//     LinkedList inExpLL;
//     inExpLL.head = NULL;
//     inExpLL.size = 0;

//     in2PreLL(infix, &inExpLL);

//     printExpLL(inExpLL);

//     removeAllNodes(&inExpLL);
//     return 0;
// }

void in2PreLL(char* infix, LinkedList *inExpLL)
{
    inExpLL->head=NULL;
    inExpLL->size=0;


    //do postfix on the reversed infix
    Stack s;
    s.head=NULL;
    s.size=0;

    int i=strlen(infix)-1,num,tenth;

    while(i>=0){

        //if operand, add to LL
        if(isdigit(infix[i])){
            num=(infix[i])-'0';
            i--;
            tenth=10;

            while(isdigit(infix[i])){
                num+=tenth*(infix[i]-'0');
                tenth*=10;
                i--;
            }
            i++;
            insertNode(inExpLL,num,OPERAND);
        }

        //if '('
        else if(infix[i] == '('){
            while(peek(s)!=')'){
                insertNode(inExpLL,peek(s),OPT);
                pop(&s);
            }
            pop(&s);
        }

        //if ')'
        else if(infix[i]==')')
            push(&s,infix[i]);

        //if operator
        else{
            while(!isEmptyStack(s) && lowerPrec(infix[i],peek(s))){
                insertNode(inExpLL,peek(s),OPT);
                pop(&s);
            }
            push(&s,infix[i]);
        }
        i--;
    }

    //add any operands left in the stack to the LL
    while(!isEmptyStack(s)){
        insertNode(inExpLL,peek(s),OPT);
        pop(&s);
    }
}



// //my fn --
// int lowerPrec(char curCh, char topStackCh){
//     char operators[]={'+', '*', '-', '/'};
//     int curCh_i, topStackCh_i;

//     if (topStackCh==')')
//         return 0;

//     for (int i=0; i< 4; i++){
//         if (curCh==operators[i])
//             curCh_i=i;
//         if (topStackCh==operators[i])
//             topStackCh_i=i;
//     }

//     if (curCh_i%2 < topStackCh_i%2 ){
//         return 1;}
//     else return 0;
// }

// //----

// void printExpLL(LinkedList inExpLL)
// {
//     ListNode* temp = NULL;
//     temp = inExpLL.head;
//     while(temp!= NULL){
//         if(temp->type == OPERAND)
//             printf(" %d ",temp->item);
//         else
//             printf(" %c ",(char)(temp->item));
//         temp = temp->next;
//     }
//     printf("\n");
// }

// void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
//     ListNode *newNode;
//     newNode = malloc(sizeof(ListNode));
//     if(newNode==NULL) exit(0);

//     newNode->item = item;
//     newNode->type = type;
//     newNode->next = LLPtr->head;
//     LLPtr->head=newNode;
//     LLPtr->size++;
// }

// int deleteNode(LinkedList *LLPtr) {
//     if(LLPtr==NULL || LLPtr->size==0){
//         return 0;
//     }
//     else{
//       ListNode *temp = LLPtr->head;
//       LLPtr->head = LLPtr->head->next;

//       free(temp);
//       LLPtr->size--;
//       return 1;
//     }
// }

// int isEmptyLinkedList (LinkedList ll) {
//     if(ll.size==0) return 1;
//     else return 0;
// }

// void removeAllNodes(LinkedList *LLPtr)
// {
// 	while(deleteNode(LLPtr));
// }

// void push(Stack *sPtr, char item){
//     StackNode *newNode;
//     newNode = malloc(sizeof(StackNode));
//     newNode->item = item;
//     newNode->next = sPtr->head;
//     sPtr->head = newNode;
//     sPtr->size++;
// }

// int pop(Stack *sPtr){
//     if(sPtr == NULL || sPtr->head == NULL){
//         return 0;
//     }
//     else{
//       StackNode *temp = sPtr->head;
//       sPtr->head = sPtr->head->next;
//       free(temp);
//       sPtr->size--;
//       return 1;
//     }
// }

// char peek(Stack s){
//     return s.head->item;
// }

// int isEmptyStack(Stack s){
//      if(s.size == 0) return 1;
//      else return 0;
// }


//------------------------------



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <math.h>

// #define SIZE 200 //The number digit limitation

// typedef struct _btnode{
// 	int item;
// 	struct _btnode *left;
// 	struct _btnode *right;
// } BTNode;   // You should not change the definition of BTNode

// typedef struct _node{
//      BTNode* item;
//      struct _node *next;
// }StackNode;

// typedef struct _stack{
//    int size;
//    StackNode *head;
// }Stack;

// void deleteTree(BTNode **root);

// void createExpTree(BTNode** root,char* prefix);
// void printTree(BTNode *node);
// void printTreePostfix(BTNode *node);
// double computeTree(BTNode *node);

// void push(Stack *sPtr,  BTNode* item);
// int pop(Stack *sPtr);
// BTNode *peek(Stack s);
// int isEmptyStack(Stack s);

// //my fn
// double evOperands(double op1, double op2, char optr);

// int main()
// {
//     char prefix[SIZE];
//     BTNode* root=NULL;
//     char *p;

//     //printf("Enter an prefix expression:\n");
//     fgets(prefix,80,stdin);
//     p=strchr(prefix,'\n');
//     if(p) *p='\0';

//     createExpTree(&root, prefix);

//     // printf("The Infix Expression:\n");
//     printTree(root);
//     printf("\n");
//     //printf("The Postfix (Reverse Polish) Expression:\n");
//     printTreePostfix(root);
//     printf("\n");
//     //printf("Answer ");
//     printf("%.2f\n", computeTree(root));
//     deleteTree(&root);
//     return 0;
// }

void createExpTree(BTNode** root,char* prefix)
{
    *root=NULL;
    int i=0,num,tenth,a=0;

    Stack s;
    s.head=NULL;
    s.size=0;

    BTNode* temp;

    while(i<strlen(prefix)){
        if(prefix[i]!=' '){

            //new node
            temp=malloc(sizeof(BTNode));
            temp->right=NULL;
            temp->left=NULL;

            int hi=prefix[i];

            //if operator
            if(!isdigit(prefix[i])){

                 //if root node
                if(*root==NULL){
                    *root=temp;
                    temp->item=prefix[i];
                }

                if(!isEmptyStack(s)){

                    //add to left child
                    if(peek(s)->left==NULL){
                        temp->item=prefix[i];
                        peek(s)->left=temp;
                    }
                    //add to right child
                    else if(peek(s)->right==NULL){
                        temp->item=prefix[i];
                        peek(s)->right=temp;
                    }

                    //if BTNode on top of stack has 2 child
                    if(peek(s)->left!=NULL && peek(s)->right!=NULL)
                        pop(&s);

                }

                //push new operator BTNode temp to stack
                push(&s,temp);

            }
            //if operand
            else{
                if(isEmptyStack(s))
                    return;


                //get the number
                num=prefix[i]-'0';
                i++;
                a=0;

                while(isdigit(prefix[i])){
                    i++;
                    a++;
                }

                i=i-a;

                if(a>0){
                    num*=pow(10,a);
                    a--;

                    while(a>=0){
                        num+=(prefix[i]-'0')*pow(10,a);
                        a--;
                        i++;
                    }
                }
                i--;


                //if no left child
                if(peek(s)->left==NULL){
                    temp->item=num;
                    peek(s)->left=temp;
                }
                //add to right child
                else if(peek(s)->right==NULL){
                    temp->item=num;
                    peek(s)->right=temp;
                }

                // pop BTNode operator in stack if it has 2 children alr
                if(peek(s)->left!=NULL && peek(s)->right!=NULL)
                    pop(&s);
            }
        }
        i++;
    }
}

// print tree in-order
void printTree(BTNode *node){
    //base, ie leaf node
    if(node==NULL)
        return;

    //left
    printTree(node->left);

    //cur
    if(node->left == NULL && node->right==NULL) //leaf node operand
        printf("%d ",node->item);
    else
        printf("%c ",(char)(node->item));

    //right
    printTree(node->right);
}


//print tree post-order
void printTreePostfix(BTNode *node){
   //base, ie leaf node
    if(node==NULL)
        return;

    //left
    printTreePostfix(node->left);

    //right
    printTreePostfix(node->right);

    //cur
    if(node->left == NULL && node->right==NULL) //leaf node operand
        printf("%d ",node->item);
    else
        printf("%c ",(char)(node->item));
}

//post-order
double computeTree(BTNode *node){

    double l, r;

    if(node==NULL)
        return 0.0;

    l=computeTree(node->left);
    r=computeTree(node->right);

    if(node->left==NULL && node->right==NULL)
        return node->item;
    else
        return evOperands(l,r,node->item);

}

//---

double evOperands(double op1, double op2, char optr){


    switch (optr){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
    return -10000.0;
}
//---

// void push(Stack *sPtr, BTNode *item){
//     StackNode *newNode;
//     newNode = malloc(sizeof(StackNode));
//     newNode->item = item;
//     newNode->next = sPtr->head;
//     sPtr->head = newNode;
//     sPtr->size++;
// }

// int pop(Stack *sPtr){
//     if(sPtr == NULL || sPtr->head == NULL){
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

// BTNode *peek(Stack s){
//     return s.head->item;
// }

// int isEmptyStack(Stack s){
//      if(s.size == 0) return 1;
//      else return 0;
// }

// void deleteTree(BTNode **root){
//     BTNode* temp;
//     if(*root !=NULL)
//     {
//         temp = (*root)->right;
//         deleteTree(&((*root)->left));
//         free(*root);
//         *root = NULL;
//         deleteTree(&temp);
//     }
// }

