// lab1 q1

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define SIZE 80 //The limit of expression length

// typedef struct _stackNode{
//     char item;
//     struct _stackNode *next;
// }StackNode;

// typedef struct _stack{
//    int size;
//    StackNode *head;
// }Stack;

// void push(Stack *sPtr, char item);
// int pop(Stack *sPtr);
// char peek(Stack s);
// int isEmptyStack(Stack s);

// void in2Post(char*, char*);
// int highEqPrec(char sOp, char cOp);

// int main()
// {
//     char infix[SIZE];
//     char postfix[SIZE];

//     printf("Enter an infix expression:\n");
//     fgets(infix,SIZE,stdin);
//     char* p=strchr(infix,'\n');
//     *p='\0';

//     in2Post(infix,postfix);
//     printf("The postfix expression is \n");
//     printf("%s\n",postfix);
//     return 0;
// }

//infix to postfix
void in2Post(char* infix, char* postfix)
{
    char temp;
    int len=strlen(infix),i=0;
    Stack s;
    s.size=0;
    s.head=NULL;

    while(i<len){
        //if operand
        if(isalnum(*infix)){
            *postfix=*infix;
            postfix++;
        }
        //if operator
        else if(*infix=='('){
            push(&s,*infix);
        }
        else if(*infix==')'){
            while(peek(s)!='('){
                temp=peek(s);
                *postfix=temp;
                pop(&s);
                postfix++;
            }
            pop(&s);
        }
        else{
            while(!isEmptyStack(s) && highEqPrec(peek(s),*infix)){
                temp=peek(s);
                *postfix=temp;
                pop(&s);
                postfix++;
            }
            push(&s,*infix);
            }
        infix++;
        i++;
    }

    while(!isEmptyStack(s)){
        temp=peek(s);
        *postfix=temp;
        pop(&s);
        postfix++;
    }
}

//precedence of operators
int highEqPrec(char sOp, char cOp){
    if(sOp=='(')
        return 0;
    if(sOp=='*' || sOp=='/')
        return 1;
    //else if sOp=='+'/'-'
    if(cOp=='+' || cOp=='-')
        return 1;
    return 0;
}

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
//        StackNode *temp = sPtr->head;
//        sPtr->head = sPtr->head->next;
//        free(temp);
//        sPtr->size--;
//        return 1;
//     }
// }

// char peek(Stack s){
//     return s.head->item;
// }

// int isEmptyStack(Stack s){
//      if(s.size == 0) return 1;
//      else return 0;
// }

// ---------------------------------------------------------------------------


