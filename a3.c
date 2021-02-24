// //q1: identical()

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _btnode{
// 	int item;
// 	struct _btnode *left;
// 	struct _btnode *right;
// } BTNode;   // You should not change the definition of BTNode


// typedef struct _stackNode{
//     BTNode *btnode;
//     struct _stackNode *next;
// }StackNode;

// typedef struct _stack{
//     StackNode *top;
// }Stack;


// // You should not change the prototypes of these functions
// int identical(BTNode *tree1, BTNode *tree2);

// BTNode* createBTNode(int item);

// BTNode* createTree();
// void push( Stack *stk, BTNode *node);
// BTNode* pop(Stack *stk);

// void printTree(BTNode *node);
// void removeAll(BTNode **node);

// int main()
// {
//     int c, s;
//     char e;
//     BTNode *root1, *root2;

//     root1 = NULL;
//     root2 = NULL;
//     c = 1;

//     printf("1: Create a binary tree1.\n");
//     printf("2: Create a binary tree2.\n");
//     printf("3: Check whether two trees are structurally identical.\n");
//     printf("0: Quit;\n");

//     while(c != 0){
//         printf("Please input your choice(1/2/3/0): ");
//         if(scanf("%d", &c) > 0)

//         {

//             switch(c)
//             {
//             case 1:
//                 removeAll(&root1);
//                 printf("Creating tree1:\n");
//                 root1 = createTree();
//                 printf("The resulting tree1 is: ");
//                 printTree(root1);
//                 printf("\n");
//                 break;
//             case 2:
//                 removeAll(&root2);
//                 printf("Creating tree2:\n");
//                 root2 = createTree();
//                 printf("The resulting tree2 is: ");
//                 printTree(root2);
//                 printf("\n");
//                 break;
//             case 3:
//                 s = identical(root1, root2);
//                 if(s){
//                 printf("Both trees are structurally identical.\n");
//                 }
//                 else{
//                 printf("Both trees are different.\n");
//                 }
//                 removeAll(&root1);
//                 removeAll(&root2);
//                 break;
//             case 0:
//                 removeAll(&root1);
//                 removeAll(&root2);
//                 break;
//             default:
//                 printf("Choice unknown;\n");
//                 break;
//             }
// 		}
//         else
//         {
//             scanf("%c",&e);
//         }

//     }
//     return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

//using recursive fn + pre-order
int identical(BTNode *tree1, BTNode *tree2)
{
    if(tree1==NULL && tree2==NULL)
        return 1;
    else if((tree1==NULL &&tree2!=NULL)||(tree1!=NULL &&tree2==NULL))
        return 0;

    if(tree1->item!=tree2->item)
        return 0;

    if(!identical(tree1->left,tree2->left))
        return 0;
    if (!identical(tree1->right,tree2->right))
        return 0;

    return 1;

}

// /////////////////////////////////////////////////////////////////////////////////

// BTNode *createBTNode(int item){
//     BTNode *newNode = malloc(sizeof(BTNode));
//     newNode->item = item;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }


// BTNode *createTree()
// {
//     Stack stk;
//     BTNode *root, *temp;
//     char s;
//     int item;

//     stk.top = NULL;
//     root = NULL;

//     printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
//     printf("Enter an integer value for the root: ");
//     if(scanf("%d",&item) > 0)
//     {
//         root = createBTNode(item);
//         push(&stk,root);
//     }
//     else
//     {
//         scanf("%c",&s);
//     }

//     while((temp =pop(&stk)) != NULL)
//     {

//         printf("Enter an integer value for the Left child of %d: ", temp->item);

//         if(scanf("%d",&item)> 0)
//         {
//             temp->left = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         printf("Enter an integer value for the Right child of %d: ", temp->item);
//         if(scanf("%d",&item)>0)
//         {
//             temp->right = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         if(temp->right != NULL)
//             push(&stk,temp->right);
//         if(temp->left != NULL)
//             push(&stk,temp->left);
//     }
//     return root;
// }

// void push( Stack *stk, BTNode *node){
//     StackNode *temp;

//     temp = malloc(sizeof(StackNode));
//     if(temp == NULL)
//         return;
//     temp->btnode = node;
//     if(stk->top == NULL){
//         stk->top = temp;
//         temp->next = NULL;
//     }
//     else{
//         temp->next = stk->top;
//         stk->top = temp;
//     }
// }

// BTNode* pop(Stack *stk){
//   StackNode *temp, *top;
//   BTNode *ptr;
//   ptr = NULL;

//   top = stk->top;
//   if(top != NULL){
//         temp = top->next;
//         ptr = top->btnode;

//         stk->top = temp;
//         free(top);
//         top = NULL;
//   }
//   return ptr;
// }

// void printTree(BTNode *node){
//     if(node == NULL) return;

//     printTree(node->left);
//     printf("%d ",node->item);
//     printTree(node->right);
// }

// void removeAll(BTNode **node){
//     if(*node != NULL){
//         removeAll(&((*node)->left));
//         removeAll(&((*node)->right));
//         free(*node);
//         *node = NULL;
//     }
// }

//////////////////////////////////////////////////////////////////////////////////


// //q2: maHeight()
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _btnode{
// 	int item;
// 	struct _btnode *left;
// 	struct _btnode *right;
// } BTNode;   // You should not change the definition of BTNode


// typedef struct _stackNode{
//     BTNode *btnode;
//     struct _stackNode *next;
// }StackNode;

// typedef struct _stack{
//     StackNode *top;
// }Stack;


// // You should not change the prototypes of these functions
// int maxHeight(BTNode *node);

// BTNode *createBTNode(int item);

// BTNode *createTree();
// void push( Stack *stk, BTNode *node);
// BTNode* pop(Stack *stk);

// void printTree(BTNode *node);
// void removeAll(BTNode **node);


// int main()
// {
//     int c;
//     char e;
// 	c = 1;

//     BTNode *root;
//     root = NULL;

//     printf("1: Create a binary tree.\n");
//     printf("2: Find the maximum height of the binary tree.\n");
//     printf("0: Quit;\n");

//     while(c != 0){
//         printf("\nPlease input your choice(1/2/0): ");
//         if(scanf("%d", &c) > 0)
//         {
//             switch(c)
//             {
//             case 1:
//                 removeAll(&root);
//                 root = createTree();
//                 printf("The resulting binary tree is: ");
//                 printTree(root);
//                 printf("\n");
//                 break;
//             case 2:
//                 c = maxHeight(root);
//                 printf("The maximum height of the binary tree is: %d\n",c);
//                 removeAll(&root);
//                 break;
//             case 0:
//                 removeAll(&root);
//                 break;
//             default:
//                 printf("Choice unknown;\n");
//                 break;
//             }
// 		}
//         else
//         {
//             scanf("%c",&e);
//         }

//     }

//     return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

//using post-order as info propogates upwards
int maxHeight(BTNode *node)
{
    //empty tree
    if (node==NULL)
        return -1;
    //leaf node; base case
    if(node->left==NULL && node->right==NULL)
        return 0;

    if(maxHeight(node->left)>=maxHeight(node->right))
        return(maxHeight(node->left)+1);
    else
        return(maxHeight(node->right)+1);

}

// ///////////////////////////////////////////////////////////////////////////////////

// BTNode *createBTNode(int item){
//     BTNode *newNode = malloc(sizeof(BTNode));
//     newNode->item = item;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }


// BTNode *createTree()
// {
//     Stack stk;
//     BTNode *root, *temp;
//     char s;
//     int item;

//     stk.top = NULL;
//     root = NULL;

//     printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
//     printf("Enter an integer value for the root: ");
//     if(scanf("%d",&item) > 0)
//     {
//         root = createBTNode(item);
//         push(&stk,root);
//     }
//     else
//     {
//         scanf("%c",&s);
//     }

//     while((temp =pop(&stk)) != NULL)
//     {

//         printf("Enter an integer value for the Left child of %d: ", temp->item);

//         if(scanf("%d",&item)> 0)
//         {
//             temp->left = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         printf("Enter an integer value for the Right child of %d: ", temp->item);
//         if(scanf("%d",&item)>0)
//         {
//             temp->right = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         if(temp->right != NULL)
//             push(&stk,temp->right);
//         if(temp->left != NULL)
//             push(&stk,temp->left);
//     }
//     return root;
// }

// void push( Stack *stk, BTNode *node){
//     StackNode *temp;

//     temp = malloc(sizeof(StackNode));
//     if(temp == NULL)
//         return;
//     temp->btnode = node;
//     if(stk->top == NULL){
//         stk->top = temp;
//         temp->next = NULL;
//     }
//     else{
//         temp->next = stk->top;
//         stk->top = temp;
//     }
// }

// BTNode* pop(Stack *stk){
//   StackNode *temp, *top;
//   BTNode *ptr;
//   ptr = NULL;

//   top = stk->top;
//   if(top != NULL){
//         temp = top->next;
//         ptr = top->btnode;

//         stk->top = temp;
//         free(top);
//         top = NULL;
//   }
//   return ptr;
// }

// void printTree(BTNode *node){
//     if(node == NULL) return;

//     printTree(node->left);
//     printf("%d ",node->item);
//     printTree(node->right);
// }

// void removeAll(BTNode **node){
//     if(*node != NULL){
//         removeAll(&((*node)->left));
//         removeAll(&((*node)->right));
//         free(*node);
//         *node = NULL;
//     }
// }

//////////////////////////////////////////////////////////////////////////////////


// //q3. countOneChildNodes()
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _btnode
// {
//     int item;
//     struct _btnode *left;
//     struct _btnode *right;
// } BTNode;   // You should not change the definition of BTNode

// typedef struct _stackNode
// {
//     BTNode *btnode;
//     struct _stackNode *next;
// } StackNode;

// typedef struct _stack
// {
//     StackNode *top;
// } Stack;


// // You should not change the prototypes of these functions
// int countOneChildNodes(BTNode *node);

// BTNode *createBTNode(int item);

// BTNode *createTree();
// void push( Stack *stack, BTNode *node);
// BTNode* pop(Stack *stack);

// void printTree(BTNode *node);
// void removeAll(BTNode **node);


// int main()
// {
//     char e;
//     int c,s;
//     BTNode *root;

//     c = 1;
//     root = NULL;


//     printf("1: Create a binary tree.\n");
//     printf("2: Count the number of nodes that have exactly one child node.\n");
//     printf("0: Quit;\n");

//     while(c != 0)
//     {
//         printf("Please input your choice(1/2/0): ");
//         if( scanf("%d",&c) > 0)
//         {
//             switch(c)
//             {
//             case 1:
//                 removeAll(&root);
//                 root = createTree();
//                 printf("The resulting binary tree is: ");
//                 printTree(root);
//                 printf("\n");
//                 break;
//             case 2:
//                 s = countOneChildNodes(root);
//                 printf("The number of nodes that have exactly one child node is: %d.\n", s);
//                 removeAll(&root);
//                 break;
//             case 0:
//                 removeAll(&root);
//                 break;
//             default:
//                 printf("Choice unknown;\n");
//                 break;
//             }
//         }
//         else
//         {
//             scanf("%c",&e);
//         }

//     }
//     return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

//return # of nodes tt have exactly 1 child node
//using pre-order

int countOneChildNodes(BTNode *node)

{
    int lcount, rcount, count=0;
    
    //empty tree
    if(node==NULL)
        return 0;

    //leaf node
    if(node->left==NULL && node->right==NULL)
        return 0;
    
    //one child
    if((node->left!=NULL && node->right==NULL) || (node->left==NULL && node->right!=NULL))
        count++;
        
    count+=countOneChildNodes(node->left);
    count+=countOneChildNodes(node->right);

    return count;
}

// ///////////////////////////////////////////////////////////////////////////////////

// BTNode *createBTNode(int item)
// {
//     BTNode *newNode = malloc(sizeof(BTNode));
//     newNode->item = item;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// BTNode *createTree()
// {
//     Stack stack;
//     BTNode *root, *temp;
//     char s;
//     int item;

//     stack.top = NULL;
//     root = NULL;
//     printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
//     printf("Enter an integer value for the root: ");
//     if(scanf("%d",&item) > 0)
//     {
//         root = createBTNode(item);
//         push(&stack,root);
//     }
//     else
//     {
//         scanf("%c",&s);
//     }

//     while((temp =pop(&stack)) != NULL)
//     {

//         printf("Enter an integer value for the Left child of %d: ", temp->item);

//         if(scanf("%d",&item)> 0)
//         {
//             temp->left = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         printf("Enter an integer value for the Right child of %d: ", temp->item);
//         if(scanf("%d",&item)>0)
//         {
//             temp->right = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         if(temp->right != NULL)
//             push(&stack,temp->right);
//         if(temp->left != NULL)
//             push(&stack,temp->left);
//     }
//     return root;
// }

// void push( Stack *stack, BTNode *node)
// {
//     StackNode *temp;

//     temp = malloc(sizeof(StackNode));
//     if(temp == NULL)
//         return;
//     temp->btnode = node;
//     if(stack->top == NULL)
//     {
//         stack->top = temp;
//         temp->next = NULL;
//     }
//     else
//     {
//         temp->next = stack->top;
//         stack->top = temp;
//     }
// }

// BTNode* pop(Stack *stack)
// {
//     StackNode *temp, *top;
//     BTNode *ptr;
//     ptr = NULL;

//     top = stack->top;
//     if(top != NULL)
//     {
//         temp = top->next;
//         ptr = top->btnode;

//         stack->top = temp;
//         free(top);
//         top = NULL;
//     }
//     return ptr;
// }

// void printTree(BTNode *node)
// {
//     if(node == NULL) return;

//     printTree(node->left);
//     printf("%d ",node->item);
//     printTree(node->right);
// }

// void removeAll(BTNode **node)
// {
//     if(*node != NULL)
//     {
//         removeAll(&((*node)->left));
//         removeAll(&((*node)->right));
//         free(*node);
//         *node = NULL;
//     }
// }

//////////////////////////////////////////////////////////////////////////////////


// //q4. sumOfOddNodes():
// #include <stdio.h>
// #include <stdlib.h>


// typedef struct _btnode
// {
//     int item;
//     struct _btnode *left;
//     struct _btnode *right;
// } BTNode;   // You should not change the definition of BTNode

// typedef struct _stackNode
// {
//     BTNode *btnode;
//     struct _stackNode *next;
// } StackNode;

// typedef struct _stack
// {
//     StackNode *top;
// } Stack;


// // You should not change the prototypes of these functions
// int sumOfOddNodes(BTNode *root);

// BTNode *createBTNode(int item);

// BTNode *createTree();
// void push( Stack *stack, BTNode *node);
// BTNode* pop(Stack *stack);

// void printTree(BTNode *node);
// void removeAll(BTNode **node);


// int main()
// {
//     char e;
//     int c,oddValueCount;
//     BTNode *root;

//     c = 1;
//     oddValueCount = 0;
//     root = NULL;

//     printf("1: Create a binary tree.\n");
//     printf("2: Find the sum of all odd numbers in the binary tree.\n");
//     printf("0: Quit;\n");

//     while(c != 0)
//     {
//         printf("Please input your choice(1/2/0): ");
//         if( scanf("%d",&c) > 0)
//         {
//             switch(c)
//             {
//             case 1:
//                 removeAll(&root);
//                 root = createTree();
//                 printf("The resulting binary tree is: ");
//                 printTree(root);
//                 printf("\n");
//                 break;
//             case 2:
//                 oddValueCount = sumOfOddNodes(root);
//                 printf("The sum of all odd numbers in the binary tree is: %d.\n",oddValueCount);
//                 removeAll(&root);
//                 break;
//             case 0:
//                 removeAll(&root);
//                 break;
//             default:
//                 printf("Choice unknown;\n");
//                 break;
//             }
//         }
//         else
//         {
//             scanf("%c",&e);
//         }

//     }
//     return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

//using post-order
int sumOfOddNodes(BTNode *node)
{
    int lOsum,rOsum;
    //empty tree
    if(node==NULL)
        return 0;

    //leaf node
    if(node->left==NULL && node->right==NULL){
        if((node->item)%2==1) //is odd
            return node->item;
        else
            return 0;
    }

    lOsum=sumOfOddNodes(node->left);
    rOsum=sumOfOddNodes(node->right);

    if(node->item%2==1)
        return lOsum+rOsum+node->item;
    else
        return lOsum+rOsum;
}

// //////////////////////////////////////////////////////////////////////////////////

// BTNode *createBTNode(int item)
// {
//     BTNode *newNode = malloc(sizeof(BTNode));
//     newNode->item = item;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// BTNode *createTree()
// {
//     Stack stack;
//     BTNode *root, *temp;
//     char s;
//     int item;

//     stack.top = NULL;
//     root = NULL;
//     printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
//     printf("Enter an integer value for the root: ");
//     if(scanf("%d",&item) > 0)
//     {
//         root = createBTNode(item);
//         push(&stack,root);
//     }
//     else
//     {
//         scanf("%c",&s);
//     }

//     while((temp =pop(&stack)) != NULL)
//     {

//         printf("Enter an integer value for the Left child of %d: ", temp->item);

//         if(scanf("%d",&item)> 0)
//         {
//             temp->left = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         printf("Enter an integer value for the Right child of %d: ", temp->item);
//         if(scanf("%d",&item)>0)
//         {
//             temp->right = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         if(temp->right != NULL)
//             push(&stack,temp->right);
//         if(temp->left != NULL)
//             push(&stack,temp->left);
//     }
//     return root;
// }

// void push( Stack *stack, BTNode *node)
// {
//     StackNode *temp;

//     temp = malloc(sizeof(StackNode));
//     if(temp == NULL)
//         return;
//     temp->btnode = node;
//     if(stack->top == NULL)
//     {
//         stack->top = temp;
//         temp->next = NULL;
//     }
//     else
//     {
//         temp->next = stack->top;
//         stack->top = temp;
//     }
// }

// BTNode* pop(Stack *stack)
// {
//     StackNode *temp, *top;
//     BTNode *ptr;
//     ptr = NULL;

//     top = stack->top;
//     if(top != NULL)
//     {
//         temp = top->next;
//         ptr = top->btnode;

//         stack->top = temp;
//         free(top);
//         top = NULL;
//     }
//     return ptr;
// }

// void printTree(BTNode *node)
// {
//     if(node == NULL) return;

//     printTree(node->left);
//     printf("%d ",node->item);
//     printTree(node->right);
// }

// void removeAll(BTNode **node)
// {
//     if(*node != NULL)
//     {
//         removeAll(&((*node)->left));
//         removeAll(&((*node)->right));
//         free(*node);
//         *node = NULL;
//     }
// }
