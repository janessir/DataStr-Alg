// //////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>

// //////////////////////////////////////////////////////////////////////////////////

// typedef struct _listnode
// {
// 	int item;
// 	struct _listnode *next;
// } ListNode;	// You should not change the definition of ListNode

// typedef struct _linkedlist
// {
// 	int size;
// 	ListNode *head;
// } LinkedList;	// You should not change the definition of LinkedList


// typedef struct _queue
// {
// 	LinkedList ll;
// } Queue;  // You should not change the definition of Queue

// ///////////////////////// function prototypes ////////////////////////////////////

// // You should not change the prototypes of these functions
// void createQueueFromLinkedList(LinkedList *ll, Queue *q);
// void removeOddValues(Queue *q);

// void enqueue(Queue *q, int item);
// int dequeue(Queue *q);
// int isEmptyQueue(Queue *q);
// void removeAllItemsFromQueue(Queue *q);


// // You may use the following functions or you may write your own
// void printList(LinkedList *ll);
// void removeAllItems(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);

// //////////////////////////// main() //////////////////////////////////////////////

// int main()
// {
// 	int c, i;
// 	LinkedList ll;
// 	Queue q;

// 	c = 1;

// 	// Initialize the linked list as an empty linked list
// 	ll.head = NULL;
// 	ll.size = 0;

// 	// Initialize the Queue as an empty queue
// 	q.ll.head = NULL;
// 	q.ll.size = 0;


// 	printf("1: Insert an integer into the linked list:\n");
// 	printf("2: Create the queue from the linked list:\n");
// 	printf("3: Remove odd numbers from the queue:\n");
// 	printf("0: Quit:\n");


// 	while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/3/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want insert into the List: ");
// 			scanf("%d", &i);
// 			insertNode(&ll, ll.size, i);
// 			printf("The resulting linked list is: ");
// 			printList(&ll);
// 			break;
// 		case 2:
// 			createQueueFromLinkedList(&ll, &q); // You need to code this function
// 			printf("The resulting queue is: ");
// 			printList(&(q.ll));
// 			break;
// 		case 3:
// 			removeOddValues(&q); // You need to code this function
// 			printf("The resulting queue after removing odd integers is: ");
// 			printList(&(q.ll));
// 			removeAllItemsFromQueue(&q);
// 			removeAllItems(&ll);
// 			break;
// 		case 0:
// 			removeAllItemsFromQueue(&q);
// 			removeAllItems(&ll);
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}

// 	}

// 	return 0;
// }


// //////////////////////////////////////////////////////////////////////////////////

// void createQueueFromLinkedList(LinkedList *ll, Queue *q)
// {
// 	int count=0;
// 	ListNode *temp;

// 	removeAllItemsFromQueue(q);
// 	(q->ll).head=NULL;
// 	(q->ll).size=0;

// 	for(int i=0; i<ll->size; i++){
// 		temp=findNode(ll,i);
// 		enqueue(q,temp->item);

// 	}

// }

// void removeOddValues(Queue *q)
// {
// 	int i,data,len;

// 	len=(q->ll).size; //IMPT is not size will keep changing coz u dequeue and enqueue ur queue

// 	for(i=0;i<len;i++){
// 		data=dequeue(q);
// 		if(data%2==0){
// 			enqueue(q,data);
// 		}
// 	}

// }

// //////////////////////////////////////////////////////////////////////////////////

// void enqueue(Queue *q, int item) {
// 	insertNode(&(q->ll), q->ll.size, item);
// }

// int dequeue(Queue *q) {
// 	int item;

// 	if (!isEmptyQueue(q)) {
// 		item = ((q->ll).head)->item;
// 		removeNode(&(q->ll), 0);
// 		return item;
// 	}
// 	return -1;
// }

// int isEmptyQueue(Queue *q) {
// 	if ((q->ll).size == 0)
// 		return 1;
// 	return 0;
// }

// void removeAllItemsFromQueue(Queue *q)
// {
// 	int count, i;
// 	if (q == NULL)
// 		return;
// 	count = q->ll.size;

// 	for (i = 0; i < count; i++)
// 		dequeue(q);
// }


// void printList(LinkedList *ll){

// 	ListNode *cur;
// 	if (ll == NULL)
// 		return;
// 	cur = ll->head;
// 	if (cur == NULL)
// 		printf("Empty");
// 	while (cur != NULL)
// 	{
// 		printf("%d ", cur->item);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }


// void removeAllItems(LinkedList *ll)
// {
// 	ListNode *cur = ll->head;
// 	ListNode *tmp;

// 	while (cur != NULL){
// 		tmp = cur->next;
// 		free(cur);
// 		cur = tmp;
// 	}
// 	ll->head = NULL;
// 	ll->size = 0;
// }


// ListNode * findNode(LinkedList *ll, int index){

// 	ListNode *temp;

// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return NULL;

// 	temp = ll->head;

// 	if (temp == NULL || index < 0)
// 		return NULL;

// 	while (index > 0){
// 		temp = temp->next;
// 		if (temp == NULL)
// 			return NULL;
// 		index--;
// 	}

// 	return temp;
// }

// int insertNode(LinkedList *ll, int index, int value){

// 	ListNode *pre, *cur;

// 	if (ll == NULL || index < 0 || index > ll->size + 1)
// 		return -1;

// 	// If empty list or inserting first node, need to update head pointer
// 	if (ll->head == NULL || index == 0){
// 		cur = ll->head;
// 		ll->head = malloc(sizeof(ListNode));
// 		if (ll->head == NULL)
// 		{
// 			exit(0);
// 		}
// 		ll->head->item = value;
// 		ll->head->next = cur;
// 		ll->size++;
// 		return 0;
// 	}


// 	// Find the nodes before and at the target position
// 	// Create a new node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));
// 		if (pre->next == NULL)
// 		{
// 			exit(0);
// 		}
// 		pre->next->item = value;
// 		pre->next->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	return -1;
// }


// int removeNode(LinkedList *ll, int index){

// 	ListNode *pre, *cur;

// 	// Highest index we can remove is size-1
// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return -1;

// 	// If removing first node, need to update head pointer
// 	if (index == 0){
// 		cur = ll->head->next;
// 		free(ll->head);
// 		ll->head = cur;
// 		ll->size--;
// 		return 0;
// 	}

// 	// Find the nodes before and after the target position
// 	// Free the target node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){

// 		if (pre->next == NULL)
// 			return -1;

// 		cur = pre->next;
// 		pre->next = cur->next;
// 		free(cur);
// 		ll->size--;
// 		return 0;
// 	}

// 	return -1;
// }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #define MIN_INT -1000

// //////////////////////////////////////////////////////////////////////////////////

// typedef struct _listnode
// {
// 	int item;
// 	struct _listnode *next;
// } ListNode;	// You should not change the definition of ListNode

// typedef struct _linkedlist
// {
// 	int size;
// 	ListNode *head;
// } LinkedList;	// You should not change the definition of LinkedList

// typedef struct _stack
// {
// 	LinkedList ll;
// }Stack;  // You should not change the definition of Stack

// ///////////////////////// function prototypes ////////////////////////////////////

// // You should not change the prototypes of these functions
// void createStackFromLinkedList(LinkedList *ll , Stack *stack);
// void removeEvenValues(Stack *s);

// void push(Stack *s , int item);
// int pop(Stack *s);
// int isEmptyStack(Stack *s);
// void removeAllItemsFromStack(Stack *s);

// // You may use the following functions or you may write your own
// void printList(LinkedList *ll);
// void removeAllItems(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);

// //////////////////////////// main() //////////////////////////////////////////////

// int main()
// {
// 	int c, i;
// 	LinkedList ll;
// 	Stack s;

// 	c = 1;
// 	// Initialize the linked list as an empty linked list
// 	ll.head = NULL;
// 	ll.size = 0;

// 	// Initialize the stack as an empty stack
// 	s.ll.head = NULL;
// 	s.ll.size = 0;

// 	printf("1: Insert an integer into the linked list:\n");
// 	printf("2: Create the stack from the linked list:\n");
// 	printf("3: Remove even numbers from the stack:\n");
// 	printf("0: Quit:\n");

// 	while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/3/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want to add to the linked list: ");
// 			scanf("%d", &i);
// 			insertNode(&ll, ll.size, i);
// 			printf("The resulting linked list is: ");
// 			printList(&ll);
// 			break;
// 		case 2:
// 			createStackFromLinkedList(&ll, &s); // You need to code this function
// 			printf("The resulting stack is: ");
// 			printList(&(s.ll));
// 			break;
// 		case 3:
// 			removeEvenValues(&s); // You need to code this function
// 			printf("The resulting stack after removing even integers is: ");
// 			printList(&(s.ll));
// 			removeAllItemsFromStack(&s);
// 			removeAllItems(&ll);
// 			break;
// 		case 0:
// 			removeAllItemsFromStack(&s);
// 			removeAllItems(&ll);
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}

// 	}

// 	return 0;
// }


// //////////////////////////////////////////////////////////////////////////////////

// void createStackFromLinkedList(LinkedList *ll, Stack *s)
// {
// 	int i;
// 	ListNode *temp;

// 	removeAllItemsFromStack(s);
// 	(s->ll).head=NULL;
// 	(s->ll).size=0;

// 	for(i=0;i<ll->size;i++){
// 		temp=findNode(ll,i);
// 		push(s,temp->item);
// 	}

// }

// void removeEvenValues(Stack *s)
// {
// 	int i, data,lenS,lenT;
// 	lenS=(s->ll).size;

// 	Stack temp;
// 	temp.ll.head=NULL;
// 	temp.ll.size=0;

// 	for(i=0;i<lenS;i++){
// 		data=pop(s);
// 		if(data%2==1)
// 			push(&temp,data);
// 	}

// 	lenT=temp.ll.size;
// 	for(i=0;i<lenT;i++){
// 		push(s,pop(&temp));
// 	}

// }

// //////////////////////////////////////////////////////////////////////////////////

// void push(Stack *s, int item)
// {
// 	insertNode(&(s->ll), 0, item);
// }

// int pop(Stack *s)
// {
// 	int item;
// 	if (s->ll.head != NULL)
// 	{
// 		item = ((s->ll).head)->item;
// 		removeNode(&(s->ll), 0);
// 		return item;
// 	}
// 	else
// 		return MIN_INT;
// }

// int isEmptyStack(Stack *s)
// {
// 	if ((s->ll).size == 0)
// 		return 1;
// 	else
// 		return 0;
// }


// void removeAllItemsFromStack(Stack *s)
// {
// 	if (s == NULL)
// 		return;
// 	while (s->ll.head != NULL)
// 	{
// 		pop(s);
// 	}
// }

// //////////////////////////////////////////////////////////////////////////////////////////


// void printList(LinkedList *ll){

// 	ListNode *cur;
// 	if (ll == NULL)
// 		return;
// 	cur = ll->head;
// 	if (cur == NULL)
// 		printf("Empty");
// 	while (cur != NULL)
// 	{
// 		printf("%d ", cur->item);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }


// void removeAllItems(LinkedList *ll)
// {
// 	ListNode *cur = ll->head;
// 	ListNode *tmp;

// 	while (cur != NULL){
// 		tmp = cur->next;
// 		free(cur);
// 		cur = tmp;
// 	}
// 	ll->head = NULL;
// 	ll->size = 0;
// }


// ListNode * findNode(LinkedList *ll, int index){

// 	ListNode *temp;

// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return NULL;

// 	temp = ll->head;

// 	if (temp == NULL || index < 0)
// 		return NULL;

// 	while (index > 0){
// 		temp = temp->next;
// 		if (temp == NULL)
// 			return NULL;
// 		index--;
// 	}

// 	return temp;
// }

// int insertNode(LinkedList *ll, int index, int value){

// 	ListNode *pre, *cur;

// 	if (ll == NULL || index < 0 || index > ll->size + 1)
// 		return -1;

// 	// If empty list or inserting first node, need to update head pointer
// 	if (ll->head == NULL || index == 0){
// 		cur = ll->head;
// 		ll->head = malloc(sizeof(ListNode));
// 		if (ll->head == NULL)
// 		{
// 			exit(0);
// 		}
// 		ll->head->item = value;
// 		ll->head->next = cur;
// 		ll->size++;
// 		return 0;
// 	}


// 	// Find the nodes before and at the target position
// 	// Create a new node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));
// 		if (pre->next == NULL)
// 		{
// 			exit(0);
// 		}
// 		pre->next->item = value;
// 		pre->next->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	return -1;
// }


// int removeNode(LinkedList *ll, int index){

// 	ListNode *pre, *cur;

// 	// Highest index we can remove is size-1
// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return -1;

// 	// If removing first node, need to update head pointer
// 	if (index == 0){
// 		cur = ll->head->next;
// 		free(ll->head);
// 		ll->head = cur;
// 		ll->size--;
// 		return 0;
// 	}

// 	// Find the nodes before and after the target position
// 	// Free the target node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){

// 		if (pre->next == NULL)
// 			return -1;

// 		cur = pre->next;
// 		pre->next = cur->next;
// 		free(cur);
// 		ll->size--;
// 		return 0;
// 	}

// 	return -1;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #define MIN_INT -1000

// //////////////////////////////////   linked list /////////////////////////////////

// typedef struct _listnode{
//   int item;
//   struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
//   ListNode *tail;
// } LinkedList;

// ////////////////////////////////// stack //////////////////////////////////////////

// typedef struct stack{
// 	LinkedList ll;
// } Stack;

// ////////////////////////// function prototypes ////////////////////////////////////

// // You should not change the prototypes of these functions
// int isStackPairwiseConsecutive(Stack *s);

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// // You may use the following functions or you may write your own
// void printList(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);
// void removeAllItems(LinkedList *ll);

// //////////////////////////////////////////////////////////////////////////////////////

// int main()
// {
//     int c, value;

//     Stack s;

//     s.ll.head=NULL;
// 	s.ll.size =0;
// 	s.ll.tail =NULL;

//     c =1;

//     printf("1: Insert an integer into the stack:\n");
//     printf("2: Check the stack is pairwise consecutive:\n");
//     printf("0: Quit:\n");

//     while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want insert into the stack: ");
// 			scanf("%d", &value);
// 			push(&s, value);
// 			printf("The stack is: ");
//             printList(&(s.ll));
// 			break;
// 		case 2:
//             if(isStackPairwiseConsecutive(&s))
//             {
//                 printf("The stack is pairwise consecutive.\n");
//             }
//             else{
//                 printf("The stack is not pairwise consecutive.\n");
//             }
//             removeAllItems(&(s.ll));
//             break;
// 		case 0:
// 			removeAllItems(&(s.ll));
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}
// 	}

//     return 0;
// }

// /////////////////////////////////////////////////////////////////////////////////

// int isStackPairwiseConsecutive(Stack *s)
// {
// 	int i,len,a,b;
// 	len=(s->ll).size;

// 	if(len==0)
// 		return 0;

// 	if(len%2==1)
// 		return 0;

// 	while(!isEmptyStack(s)){
// 		a=pop(s);
// 		b=pop(s);

// 		if(a-b!=1 && a-b!=-1)
// 			return 0;
// 	}
// 		return 1;
// }

// //////////////////////////////////////////////////////////////////////////////////

// void push(Stack *s, int item){
//   insertNode(&(s->ll), 0, item);
// }

// int pop(Stack *s){
//   int item;
//   if(!isEmptyStack(s)){
//     item = ((s->ll).head)->item;
//     removeNode(&(s->ll), 0);
//     return item;
//   }
//     return INT_MIN;
// }

// int peek(Stack *s){
//   return ((s->ll).head)->item;
// }

// int isEmptyStack(Stack *s){
//   if ((s->ll).size == 0)
//       return 1;
//   return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

// void printList(LinkedList *ll){

// 	ListNode *cur;
// 	if (ll == NULL)
// 		return;
// 	cur = ll->head;

// 	if (cur == NULL)
// 		printf("Empty");
// 	while (cur != NULL)
// 	{
// 		printf("%d ", cur->item);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }

// ListNode * findNode(LinkedList *ll, int index){

// 	ListNode *temp;

// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return NULL;

// 	temp = ll->head;

// 	if (temp == NULL || index < 0)
// 		return NULL;

// 	while (index > 0){
// 		temp = temp->next;
// 		if (temp == NULL)
// 			return NULL;
// 		index--;
// 	}

// 	return temp;
// }

// int insertNode(LinkedList *ll, int index, int value){

// 	ListNode *pre, *cur;

// 	if (ll == NULL || index < 0 || index > ll->size + 1)
// 		return -1;

// 	// If empty list or inserting first node, need to update head pointer
// 	if (ll->head == NULL || index == 0){
// 		cur = ll->head;
// 		ll->head = malloc(sizeof(ListNode));
// 		ll->head->item = value;
// 		ll->head->next = cur;
// 		ll->size++;
// 		return 0;
// 	}


// 	// Find the nodes before and at the target position
// 	// Create a new node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));
// 		pre->next->item = value;
// 		pre->next->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	return -1;
// }


// int removeNode(LinkedList *ll, int index){

// 	ListNode *pre, *cur;

// 	// Highest index we can remove is size-1
// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return -1;

// 	// If removing first node, need to update head pointer
// 	if (index == 0){
// 		cur = ll->head->next;
// 		free(ll->head);
// 		ll->head = cur;
// 		ll->size--;

// 		return 0;
// 	}

// 	// Find the nodes before and after the target position
// 	// Free the target node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){

// 		if (pre->next == NULL)
// 			return -1;

// 		cur = pre->next;
// 		pre->next = cur->next;
// 		free(cur);
// 		ll->size--;
// 		return 0;
// 	}

// 	return -1;
// }

// void removeAllItems(LinkedList *ll)
// {
// 	ListNode *cur = ll->head;
// 	ListNode *tmp;

// 	while (cur != NULL){
// 		tmp = cur->next;
// 		free(cur);
// 		cur = tmp;
// 	}
// 	ll->head = NULL;
// 	ll->size = 0;
// }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #define MIN_INT -1000

// //////////////////////////////////   linked list /////////////////////////////////

// typedef struct _listnode{
//   int item;
//   struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
//   ListNode *tail;
// } LinkedList;

// ////////////////////////////////// stack    ///////////////////////////////////////////////////////

// typedef struct stack{
// 	LinkedList ll;
// } Stack;

// //////////////////////////////////// queue ////////////////////////////////////////////////////////

// typedef struct _queue{
// 	LinkedList ll;
// } Queue;

// ///////////////////////////////////////////////////////////////////////////////////////////////////

// void reverse(Queue *q);

// ///////////////////////////////////////////////////////////////////////////////////////////////////

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// void enqueue(Queue *q, int item);
// int dequeue(Queue *q);
// int isEmptyQueue(Queue *s);

// ///////////////////////////////////////////////////////////////////////////////////////////////////
// void printList(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);
// void removeAllItems(LinkedList *ll);

// ///////////////////////////////////////////////////////////////////////////////////////////////////


// int main()
// {
//     int c, value;

//     Queue q;

//     //initialize the queue
// 	q.ll.head =NULL;
// 	q.ll.size =0;
// 	q.ll.tail=NULL;

//     c =1;

//     printf("1: Insert an integer into the queue;\n");
//     printf("2: Reverse the queue;\n");
//     printf("0: Quit;\n");

//     while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want insert into the queue: ");
// 			scanf("%d", &value);
// 			enqueue(&q, value);
// 			printf("The queue is: ");
// 			printList(&(q.ll));
// 			break;
// 		case 2:
// 			reverse(&q); // You need to code this function
// 			printf("The resulting queue after reversing its elements is: ");
// 			printList(&(q.ll));
// 			removeAllItems(&(q.ll));
// 			break;
// 		case 0:
// 			removeAllItems(&(q.ll));
// 			break;
// 		default:
// 			printf("Choice unknown;\n");
// 			break;
// 		}
// 	}

//     return 0;
// }

// ///////////////////////////////////////////////////////////////////////////////////////////////////

// void reverse(Queue *q)
// {
// 	Stack s;
// 	s.ll.head=NULL;
// 	s.ll.tail=NULL;
// 	s.ll.size=0;

// 	while (!isEmptyQueue(q)){
// 		push(&s,dequeue(q));
// 	}

// 	while(!isEmptyStack(&s)){
// 		enqueue(q,pop(&s));
// 	}
// }

// ///////////////////////////////////////////////////////////////////////////////////////////////////

// void push(Stack *s, int item){
//   insertNode(&(s->ll), 0, item);
// }

// int pop(Stack *s){
//   int item;
//   if(!isEmptyStack(s)){
//     item = ((s->ll).head)->item;
//     removeNode(&(s->ll), 0);
//     return item;
//   }
//     return INT_MIN;
// }

// int peek(Stack *s){
//   return ((s->ll).head)->item;
// }

// int isEmptyStack(Stack *s){
//   if ((s->ll).size == 0)
//       return 1;
//   return 0;
// }

// void enqueue(Queue *q, int item){
//   insertNode(&(q->ll), q->ll.size, item);
// }

// int dequeue(Queue *q){
//   int item;
//   item = ((q->ll).head)->item;
//   removeNode(&(q->ll), 0);
//   return item;
// }

// int isEmptyQueue(Queue *q){
//   if ((q->ll).size == 0)
//       return 1;
//   return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////

// void printList(LinkedList *ll){

// 	ListNode *cur;
// 	if (ll == NULL)
// 		return;
// 	cur = ll->head;

// 	if (cur == NULL)
// 		printf("Empty");
// 	while (cur != NULL)
// 	{
// 		printf("%d ", cur->item);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }

// ListNode * findNode(LinkedList *ll, int index){

// 	ListNode *temp;

// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return NULL;

// 	temp = ll->head;

// 	if (temp == NULL || index < 0)
// 		return NULL;

// 	while (index > 0){
// 		temp = temp->next;
// 		if (temp == NULL)
// 			return NULL;
// 		index--;
// 	}

// 	return temp;
// }

// int insertNode(LinkedList *ll, int index, int value){

// 	ListNode *pre, *cur;

// 	if (ll == NULL || index < 0 || index > ll->size + 1)
// 		return -1;

// 	// If empty list or inserting first node, need to update head pointer
// 	if (ll->head == NULL || index == 0){
// 		cur = ll->head;
// 		ll->head = malloc(sizeof(ListNode));
// 		ll->head->item = value;
// 		ll->head->next = cur;
// 		ll->size++;
// 		return 0;
// 	}


// 	// Find the nodes before and at the target position
// 	// Create a new node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));
// 		pre->next->item = value;
// 		pre->next->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	return -1;
// }


// int removeNode(LinkedList *ll, int index){

// 	ListNode *pre, *cur;

// 	// Highest index we can remove is size-1
// 	if (ll == NULL || index < 0 || index >= ll->size)
// 		return -1;

// 	// If removing first node, need to update head pointer
// 	if (index == 0){
// 		cur = ll->head->next;
// 		free(ll->head);
// 		ll->head = cur;
// 		ll->size--;

// 		return 0;
// 	}

// 	// Find the nodes before and after the target position
// 	// Free the target node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){

// 		if (pre->next == NULL)
// 			return -1;

// 		cur = pre->next;
// 		pre->next = cur->next;
// 		free(cur);
// 		ll->size--;
// 		return 0;
// 	}

// 	return -1;
// }

// void removeAllItems(LinkedList *ll)
// {
// 	ListNode *cur = ll->head;
// 	ListNode *tmp;

// 	while (cur != NULL){
// 		tmp = cur->next;
// 		free(cur);
// 		cur = tmp;
// 	}
// 	ll->head = NULL;
// 	ll->size = 0;
// }
