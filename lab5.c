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
//   int size;
//   StackNode *head;
// }Stack;

// void push(Stack *sPtr, char item);
// int pop(Stack *sPtr);
// char peek(Stack s);
// int isEmptyStack(Stack s);

// void in2Post(char*, char*);

// //my fn
// int lowerEqPrec(char curCh, char topStackCh);

// int main()
// {
//     char infix[SIZE];
//     char postfix[SIZE];
//     char dummy;

//     printf("Enter an infix expression:\n");
//     fgets(infix,SIZE,stdin);

//     // printf("infix=%s\n",infix);

//     in2Post(infix,postfix);
//     printf("The postfix expression is \n");
//     printf("%s\n",postfix);
//     return 0;
// }

void in2Post(char* infix, char* postfix)
{
    Stack s;
    s.head=NULL;
    s.size=0;

    int i, len=strlen(infix)-1;

    for (i=0; i<len; i++){

        //if operand eg a,b,c etc
        if (isalnum(*infix)){
            *postfix=*infix;
            postfix++;
        }

        //if ')'
        else if (*infix == ')'){
            while (peek(s)!='('){
                *postfix=peek(s);
                pop(&s);
                postfix++;
            }
            pop(&s);
        }
        //987-654-/3+*+

        //if '('
        else if (*infix == '(')
            push(&s,*infix);

        //if is operator ie '+', '-', '*', '/'
        else{
            //while instead of if bcoz wanna pop out all those that are more than or eq precedence to *infix (ie wanna ev all of them first, eg inside stack have *,+, and *infix=='+')
            while(!isEmptyStack(s) && lowerEqPrec(*infix,peek(s))){
                *postfix=peek(s);
                pop(&s);
                postfix++;
            }
            push(&s, *infix);
        }

        infix++;
    }

    //no other operands left but stack not empty
    while (!isEmptyStack(s)){
        *postfix=peek(s);
        pop(&s);
        postfix++;
    }

}

//my fn
int lowerEqPrec(char curCh, char topStackCh){
    char operators[]={'+', '*', '-', '/'};
    int curCh_i, topStackCh_i;

    if (topStackCh=='(')
        return 0;

    for (int i=0; i< 4; i++){
        if (curCh==operators[i])
            curCh_i=i;
        if (topStackCh==operators[i])
            topStackCh_i=i;
    }

    if (curCh_i%2 <= topStackCh_i%2){
        return 1;}
    else return 0;
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


// ---------------------------------------------------------------


// //Q2.

// #include <stdio.h>
// #include <stdlib.h>
//  #include <string.h>
// #include <ctype.h>

// #define SIZE 80 //The limit of expression length

// typedef struct _stackNode{
//     double item;
//     struct _stackNode *next;
// }StackNode;

// typedef struct _stack{
//   int size;
//   StackNode *head;
// }Stack;

// void push(Stack *sPtr, double item);
// int pop(Stack *sPtr);
// double peek(Stack s);
// int isEmptyStack(Stack s);

// double exePostfix(char*);
// double evOperands(double op1, double op2, char optr);


// int main()
// {
//     char postfix[SIZE];

//     printf("Enter a postfix expression:\n");
//     fgets(postfix,SIZE,stdin);

//     printf("The answer is %.2lf.\n",exePostfix(postfix));

//     return 0;
// }

//may assume operands are single-digit #
double exePostfix(char* postfix)
{
    Stack s;
    s.head=NULL;
    s.size=0;

    double op1, op2;

    int len=strlen(postfix)-1;

    while(len){

        //if operand
        if(isdigit(*postfix)){
            push(&s,(double) (*postfix-'0'));
        }
        //if operator
        else{
            op2=peek(s);
            pop(&s);
            op1=peek(s);
            pop(&s);
            push(&s,evOperands(op1,op2,*postfix));
            // printf("\npeek=%lf\n",peek(s));
        }
        postfix++;
        len--;

    }
    return peek(s);
}



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




// void push(Stack *sPtr, double item){
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

// double peek(Stack s){
//     return s.head->item;
// }

// int isEmptyStack(Stack s){
//      if(s.size == 0) return 1;
//      else return 0;
// }


// ---------------------------------------------------------------


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

// void in2Pre(char*, char*);

// //my fns
// void revString(char* str, char* revStr);
// int lowerPrec(char curCh, char topStackCh);


// int main()
// {
//     char infix[SIZE];
//     char prefix[SIZE];

//     printf("Enter an infix expression:\n");
//     fgets(infix,SIZE, stdin);

//     in2Pre(infix,prefix);
//     printf("The prefix expression is \n");
//     printf("%s\n",prefix);

//     return 0;
// }

void in2Pre(char* infix, char* prefix)
{
    int len=strlen(infix)-1;

    //to reverse the string
    char revInfix[SIZE];
    revString(infix,revInfix);
    // printf("revInfix: %s\n",revInfix);

    //do postfix on the revInfix
    char postRevIn[SIZE];
    Stack s;
    s.head=NULL;
    s.size=0;

    int i=0,k=0;

    while(revInfix[i]!='\0'){

        //if operand eg a,b,c etc
        if (isalnum(revInfix[i])){
            postRevIn[k]=revInfix[i];
            k++;
        }

        //if '('
        else if (revInfix[i] == '('){
            while (peek(s)!=')'){
                postRevIn[k]=peek(s);
                pop(&s);
                k++;
            }
            pop(&s);
        }

        //if ')'
        else if (revInfix[i] == ')')
            push(&s,revInfix[i]);

        //if is operator ie '+', '-', '*', '/'
        else{
            //while instead of if bcoz wanna pop out all those that are more than or eq precedence to *infix (ie wanna ev all of them first, eg inside stack have *,+, and *infix=='+')
            while(!isEmptyStack(s) && lowerPrec(revInfix[i],peek(s))){
                postRevIn[k]=peek(s);
                pop(&s);
                k++;
            }
            push(&s, revInfix[i]);
        }
        i++;
    }

    //-+a*bc*d/ef
    //+9*-87+/6-543

    //no other operands left but stack not empty
    while (!isEmptyStack(s)){
        postRevIn[k]=peek(s);
        pop(&s);
        k++;
    }
    // printf("postRevIn= %s\n",postRevIn);

    //reverse back the postRevIn to get prefix
    revString(postRevIn,prefix);
    // printf("prefix: %s\n",prefix);


}

//my fn ---
void revString(char* str, char* revStr){

    Stack s;
    s.head=NULL;
    s.size=0;

    printf("postRevIn inside= %s\n",str);


    while(*str!='\0'){
        push(&s,*str);
        str++;
    }

    while(!isEmptyStack(s)){
        *revStr=peek(s);
        pop(&s);
        revStr++;
    }
    *revStr='\0';

    printf("postRevIn inside= %s\n",revStr);

}

int lowerPrec(char curCh, char topStackCh){
    char operators[]={'+', '*', '-', '/'};
    int curCh_i, topStackCh_i;

    if (topStackCh==')')
        return 0;

    for (int i=0; i< 4; i++){
        if (curCh==operators[i])
            curCh_i=i;
        if (topStackCh==operators[i])
            topStackCh_i=i;
    }

    if (curCh_i%2 < topStackCh_i%2){
        return 1;}
    else return 0;
}

// //------

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
