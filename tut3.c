/*Q1: levelOrderTraversal():
    write an iterative C fn that prints a level-by-level traversal of bin tree using Queues
    Starting at the root node level
    Should only use queue and enqueue ops when adding/removing int from the queue
    Rmb to empty the queue at the beginning if Queue is not empty
*/

// #include <stdio.h>
// #include <stdlib.h>

// #define BUFFER_SIZE 1024

// typedef struct _bstnode{
// 	int item;
// 	struct _bstnode *left;
// 	struct _bstnode *right;
// } BSTNode;   // You should not change the definition of BSTNode

// typedef struct _QueueNode {
// 	BSTNode *data;
// 	struct _QueueNode *nextPtr;
// }QueueNode; // You should not change the definition of QueueNode


// typedef struct _queue
// {
// 	QueueNode *head;
// 	QueueNode *tail;
// }Queue; // You should not change the definition of queue


// // You should not change the prototypes of these functions
// void levelOrderTraversal(BSTNode *node);
// void insertBSTNode(BSTNode **node, int value);

// BSTNode* dequeue(QueueNode **head, QueueNode **tail);
// void enqueue(QueueNode **head, QueueNode **tail, BSTNode *node);
// int isEmpty(QueueNode *head);
// void removeAll(BSTNode **node);


// int main()
// {
// 	int c, i;
// 	c = 1;

// 	//Initialize the Binary Search Tree as an empty Binary Search Tree
// 	BSTNode *root;
// 	root = NULL;

// 	printf("1: Insert an integer into the binary search tree;\n");
// 	printf("2: Print the level-order traversal of the binary search tree;\n");
// 	printf("0: Quit;\n");


// 	while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want to insert into the Binary Search Tree: ");
// 			scanf("%d", &i);
// 			insertBSTNode(&root, i);
// 			break;
// 		case 2:
// 			printf("The resulting level-order traversal of the binary search tree is: ");
// 			levelOrderTraversal(root); // You need to code this function
// 			printf("\n");
// 			break;
// 		case 0:
// 			removeAll(&root);
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}

// 	}

// 	return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

// iterative not recursive fn!!
void levelOrderTraversal(BSTNode* root)
{
    Queue q;
    q.head=NULL;
    q.tail=NULL;

    int data;

	//if not nodes in tree
	if (root==NULL){
		printf("Tree is empty!\n");
		return;
	}

	//if only 1 root in the tree
	if(root->left==NULL && root->right==NULL){
		printf("%d\n",root->item);
		return;
	}

	//enqueue first node
	enqueue(&q.head,&q.tail,root);

	while(!isEmpty(q.head)){

		//enqueue children if right/left child of the first node in the queue
		if(((q.head)->data)->left != NULL){
			enqueue(&q.head,&q.tail,((q.head)->data)->left);
		}
		if(((q.head)->data)->right !=NULL){
			enqueue(&q.head,&q.tail,((q.head)->data)->right);
		}

		printf("%d ",dequeue(&q.head,&q.tail)->item);

	}

	printf("\n");
}



// ///////////////////////////////////////////////////////////////////////////////

// void insertBSTNode(BSTNode **node, int value){
// 	if (*node == NULL)
// 	{
// 		*node = malloc(sizeof(BSTNode));

// 		if (*node != NULL) {
// 			(*node)->item = value;
// 			(*node)->left = NULL;
// 			(*node)->right = NULL;
// 		}
// 	}
// 	else
// 	{
// 		if (value < (*node)->item)
// 		{
// 			insertBSTNode(&((*node)->left), value);
// 		}
// 		else if (value >(*node)->item)
// 		{
// 			insertBSTNode(&((*node)->right), value);
// 		}
// 		else
// 			return;
// 	}
// }


// // enqueue node
// void enqueue(QueueNode **headPtr, QueueNode **tailPtr, BSTNode *node)
// {
// 	// dynamically allocate memory
// 	QueueNode *newPtr = malloc(sizeof(QueueNode));

// 	// if newPtr does not equal NULL
// 	if (newPtr != NULL) {
// 		newPtr->data = node;
// 		newPtr->nextPtr = NULL;

// 		// if queue is empty, insert at head
// 		if (isEmpty(*headPtr)) {
// 			*headPtr = newPtr;
// 		}
// 		else { // insert at tail
// 			(*tailPtr)->nextPtr = newPtr;
// 		}

// 		*tailPtr = newPtr;
// 	}
// 	else {
// 		printf("Node not inserted");
// 	}
// }

// BSTNode* dequeue(QueueNode **headPtr, QueueNode **tailPtr)
// {
// 	BSTNode *node = (*headPtr)->data;
// 	QueueNode *tempPtr = *headPtr;
// 	*headPtr = (*headPtr)->nextPtr;

// 	if (*headPtr == NULL) {
// 		*tailPtr = NULL;
// 	}

// 	free(tempPtr);

// 	return node;
// }

// int isEmpty(QueueNode *head)
// {
// 	return head == NULL;
// }

// void removeAll(BSTNode **node)
// {
// 	if (*node != NULL)
// 	{
// 		removeAll(&((*node)->left));
// 		removeAll(&((*node)->right));
// 		free(*node);
// 		*node = NULL;
// 	}
// }

/////////////////////////////////////////////////////////////////////////////////


//Q2.

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _bstnode{
// 	int item;
// 	struct _bstnode *left;
// 	struct _bstnode *right;
// } BSTNode;   // You should not change the definition of BSTNode

// typedef struct _stackNode{
// 	BSTNode *data;
// 	struct _stackNode *next;
// }StackNode; // You should not change the definition of StackNode

// typedef struct _stack
// {
// 	StackNode *top;
// }Stack; // You should not change the definition of Stack


// // You should not change the prototypes of these functions
// void preOrderIterative(BSTNode *root);

// void insertBSTNode(BSTNode **node, int value);

// // You may use the following functions or you may write your own
// void push(Stack *stack, BSTNode *node);
// BSTNode *pop(Stack *s);
// BSTNode *peek(Stack *s);
// int isEmpty(Stack *s);
// void removeAll(BSTNode **node);


// int main()
// {
// 	int c, i;
// 	c = 1;

// 	//Initialize the Binary Search Tree as an empty Binary Search Tree
// 	BSTNode * root;
// 	root = NULL;

// 	printf("1: Insert an integer into the binary search tree;\n");
// 	printf("2: Print the pre-order traversal of the binary search tree;\n");
// 	printf("0: Quit;\n");


// 	while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want to insert into the Binary Search Tree: ");
// 			scanf("%d", &i);
// 			insertBSTNode(&root, i);
// 			break;
// 		case 2:
// 			printf("The resulting pre-order traversal of the binary search tree is: ");
// 			preOrderIterative(root); // You need to code this function
// 			printf("\n");
// 			break;
// 		case 0:
// 			removeAll(&root);
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}

// 	}

// 	return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

void preOrderIterative(BSTNode *root)
{
	Stack s;
	s.top=NULL;

	BSTNode *temp;

	//check null condition
	if(root==NULL){
		printf("Tree is empty!\n");
		return;
	}

	//if only 1 node
	else if(root->left==NULL && root->right==NULL){
		printf("%d\n",root->item);
		return;
	}

	//else, push the root node into stack
	push(&s,root);

	//more than one node:
	while(!isEmpty(&s)){

		temp=peek(&s); //temp will always point to the top of the stack
		printf("%d ",pop(&s)->item);

		//push children onto stack
		if(temp->right!=NULL){
			push(&s,temp->right);
		}
		if(temp->left!=NULL){
			push(&s,temp->left);
		}
	}
	printf("\n");
}

// ///////////////////////////////////////////////////////////////////////////////

// void insertBSTNode(BSTNode **node, int value){
// 	if (*node == NULL)
// 	{
// 		*node = malloc(sizeof(BSTNode));

// 		if (*node != NULL) {
// 			(*node)->item = value;
// 			(*node)->left = NULL;
// 			(*node)->right = NULL;
// 		}
// 	}
// 	else
// 	{
// 		if (value < (*node)->item)
// 		{
// 			insertBSTNode(&((*node)->left), value);
// 		}
// 		else if (value >(*node)->item)
// 		{
// 			insertBSTNode(&((*node)->right), value);
// 		}
// 		else
// 			return;
// 	}
// }


// void push(Stack *stack, BSTNode * node)
// {
// 	StackNode *temp;

// 	temp = malloc(sizeof(StackNode));

// 	if (temp == NULL)
// 		return;
// 	temp->data = node;

// 	if (stack->top == NULL)
// 	{
// 		stack->top = temp;
// 		temp->next = NULL;
// 	}
// 	else
// 	{
// 		temp->next = stack->top;
// 		stack->top = temp;
// 	}
// }


// BSTNode * pop(Stack * s)
// {
// 	StackNode *temp, *t;
// 	BSTNode * ptr;
// 	ptr = NULL;

// 	t = s->top;
// 	if (t != NULL)
// 	{
// 		temp = t->next;
// 		ptr = t->data;

// 		s->top = temp;
// 		free(t);
// 		t = NULL;
// 	}

// 	return ptr;
// }

// BSTNode * peek(Stack * s)
// {
// 	StackNode *temp;
// 	temp = s->top;
// 	if (temp != NULL)
// 		return temp->data;
// 	else
// 		return NULL;
// }

// int isEmpty(Stack *s)
// {
// 	if (s->top == NULL)
// 		return 1;
// 	else
// 		return 0;
// }


// void removeAll(BSTNode **node)
// {
// 	if (*node != NULL)
// 	{
// 		removeAll(&((*node)->left));
// 		removeAll(&((*node)->right));
// 		free(*node);
// 		*node = NULL;
// 	}
// }

////////////////////////////////////////////////////////////////////////////////


//Q3.
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
// int maxDepth(BTNode *node);

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
//     printf("2: Find the maximum depth of the binary tree.\n");
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
//                 c = maxDepth(root);
//                 printf("The maximum depth of the binary tree is: %d\n",c);
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

// using preorder
int maxDepth(BTNode *node)
{
	//no nodes
	if (node==NULL)
		return -1;
		
	//leaf node AKA base case
	else if(node->left==NULL && node->right==NULL)
		return 0;
	
	if(maxDepth(node->left)>maxDepth(node->right))
		return maxDepth(node->left)+1;
	else return maxDepth(node->right)+1;
}

// ///////////////////////////////////////////////////////////////////////////////////

// BTNode *createBTNode(int item){
//     BTNode *newNode = malloc(sizeof(BTNode));
//     newNode->item = item;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }


// //////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////


// //q4.
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


// BTNode *searchNode(BTNode *root, int key);
// BTNode *createBTNode(int item);

// // You may use the following functions or you may write your own
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
//     BTNode *snode;


//     printf("1: Create binary tree.\n");
//     printf("2: Search binary tree by given int value.\n");
//     printf("0: Quit;\n");

//     c = 1;
//     root = NULL;
//     snode = NULL;

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
//                 printf("Result Tree is: ");
//                 printTree(root);
//                 printf("\n\n");
//                 break;
//             case 2:
//                 printf("Please enter a value to search: ");
//                 if(scanf("%d",&s)){
//                     snode = searchNode(root,s);
//                 }
//                 else{
//                     scanf("%c",&e);
//                 }
//                 if(snode != NULL){
//                     printf("Node found.\n\n");
//                 }
//                 else{
//                     printf("Node of given value not found.\n\n");
//                 }
//                 break;
//             case 0:
//                 removeAll(&root);
//                 break;
//             default:
//                 printf("Choice unknown;\n\n");
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

//using pre-order
BTNode *searchNode(BTNode *node, int key)
{
	if(node==NULL)
		return NULL;
		
	if(node->item==key)
		return node;
	
	if(searchNode(node->left,key)!=NULL)
		return searchNode(node->left,key);
	else if(searchNode(node->right,key)!=NULL)
		return searchNode(node->right,key);

	return NULL;
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
//     printf("Please enter int values to insert. Any Alpha value will be treated as NULL.\n");
//     printf("Enter int value as root: ");
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

//         printf("Enter Left child for %d: ", temp->item);

//         if(scanf("%d",&item)> 0)
//         {
//             temp->left = createBTNode(item);
//         }
//         else
//         {
//             scanf("%c",&s);
//         }

//         printf("Enter Right child for %d: ", temp->item);
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
