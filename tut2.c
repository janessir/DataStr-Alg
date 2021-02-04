//qn1 reverseStack(): revere the stack itself then return the stack

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>


// typedef struct _listnode{
//   int item;
//   struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
//   ListNode *tail;
// } LinkedList;


// typedef struct stack{
// 	LinkedList ll;
// } Stack;


// typedef struct _queue{
// 	LinkedList ll;
// } Queue;


// // You should not change the prototypes of these functions
// void reverseStack(Stack *s);

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// void enqueue(Queue *q, int item);
// int dequeue(Queue *q);
// int isEmptyQueue(Queue *s);

// void printList(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);
// void removeAllItems(LinkedList *ll);



// int main()
// {
//     int c, value;

//     Stack s;

//     //initialize the stack
// 	s.ll.head =NULL;
// 	s.ll.size =0;


//     c =1;

//     printf("1: Insert an integer into the stack;\n");
//     printf("2: Reverse the stack;\n");
//     printf("0: Quit;\n");

//     while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want to insert into the stack: ");
// 			scanf("%d", &value);
// 			push(&s, value);
// 			printf("The resulting stack is: ");
// 			printList(&(s.ll));
// 			break;
// 		case 2:
// 			reverseStack(&s); // You need to code this function
// 			printf("The resulting stack after reversing its elements is: ");
// 			printList(&(s.ll));
// 			removeAllItems(&(s.ll));
// 			break;
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

// ///////////////////////////////////////////////////////////////////////////////////////////////////


// void reverseStack(Stack *s)
// {
// 	int i,data,len=s->ll.size;
// 	Queue q;
// 	q.ll.head=NULL;
// 	q.ll.tail=NULL;
// 	q.ll.size=0;

// 	for(i=0;i<len;i++){
// 		data=pop(s);
// 		enqueue(&q,data);
// 	}
// 	for(i=0;i<len;i++){
// 		data=dequeue(&q);
// 		push(s,data);
// 	}
// }

//of instead of for loop, can do while(!isEmptyStack(s))

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





//////////////////////////////////////////////////////////////////////////////////


// //question2: reverseFirstKItems()


// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>


// typedef struct _listnode{
//   int item;
//   struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
//   int size;
//   ListNode *head;
//   ListNode *tail;
// } LinkedList;


// typedef struct stack{
// 	LinkedList ll;
// } Stack;


// typedef struct _queue{
// 	LinkedList ll;
// } Queue;


// // You should not change the prototypes of these functions
// void reverseFirstKItems(Queue *q, int k);

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// void enqueue(Queue *q, int item);
// int dequeue(Queue *q);
// int isEmptyQueue(Queue *s);

// void printList(LinkedList *ll);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);
// void removeAllItems(LinkedList *ll);


// int main()
// {
//     int c, value;

//     Queue q;

//     //initialize the stack
// 	q.ll.head =NULL;
// 	q.ll.size =0;


//     c =1;

//     printf("1: Insert an integer into the queue;\n");
//     printf("2: Reverse the elements of the queue until the given number;\n");
//     printf("0: Quit;\n");

//     while (c != 0)
// 	{
// 		printf("Please input your choice(1/2/0): ");
// 		scanf("%d", &c);

// 		switch (c)
// 		{
// 		case 1:
// 			printf("Input an integer that you want to insert into the queue: ");
// 			scanf("%d", &value);
// 			enqueue(&q, value);
// 			printf("The resulting queue is: ");
// 			printList(&(q.ll));
// 			break;
// 		case 2:
// 			printf("Enter an integer to reverse the queue until that number: ");
//             scanf("%d",&value);
// 			reverseFirstKItems(&q, value);// You need to code this function
// 			printf("The resulting queue after reversing first %d elements is: ", value);
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

///////////////////////////////////////////////////////////////////////////////////////////////////


// void reverseFirstKItems(Queue *q, int k)
// {
// 	int i,data;
// 	int len=q->ll.size;
// 	// int diff=len-k;

// 	// int same[20];

// 	Stack s;
// 	s.ll.head=NULL;
// 	s.ll.tail=NULL;
// 	s.ll.size=0;



// 	//if invalid k
// 	if(k>len || k<0){
// 		printf("You inputed an invalid k. The size of your list is %d. Please try again.\n",q->ll.size);
// 		return;
// 	}

// 	//if empty list or one element list, of when k==0
// 	if(isEmptyQueue(q) || len==1 || k<=1)
// 		return;

// 	//note: when k=1, it refers to the first element, ie index=0

// 	//to put into a stack so first element out was the last element
// 	for (i=0;i<k;i++){
// 		data=dequeue(q);
// 		push(&s,data);
// 	}

// 	// if(k<len){
// 	// 	for(i=0;i<(len-k);i++){
// 	// 		same[i]=dequeue(q);
// 	// 	}
// 	// }

// 	//to put back in a queue so that first element in was the last
// 	for(i=0;i<k;i++){
// 		data=pop(&s);
// 		enqueue(q,data);
// 	}

// 	// if(k<len){
// 	// 	for(i=0;i<(len-k);i++){
// 	// 		enqueue(q,same[i]);
// 	// 	}
// 	// }

// 	//instead of making arrays and all de bs, just dequeue and enqueue
// 	if(k<len){
// 		for(i=0;i<(len-k);i++){
// 			enqueue(q,dequeue(q));
// 		}
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



//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct _listnode{
  int item;
  struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
  int size;
  ListNode *head;
  ListNode *tail;
} LinkedList;


typedef struct stack{
	LinkedList ll;
} Stack;


typedef struct _queue{
	LinkedList ll;
} Queue;


// You should not change the prototypes of these functions
void sortStack(Stack *s);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);



int main()
{
    int c, value;

    Stack s;

    //initialize the stack
	s.ll.head =NULL;
	s.ll.size =0;


    c =1;

    printf("1: Insert an integer into the stack;\n");
    printf("2: Sort the stack in ascending order ;\n");
    printf("0: Quit;\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the stack: ");
			scanf("%d", &value);
			push(&s, value);
			printf("The resulting stack is: ");
			printList(&(s.ll));
			break;
		case 2:
			sortStack(&s); // You need to code this function
			printf("The resulting stack after sorting it in ascending order is: ");
			printList(&(s.ll));
			removeAllItems(&(s.ll));
			break;
		case 0:
			removeAllItems(&(s.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//Hint: want to make stack s always sorted, so first try all but the last element to temp stack ts

void sortStack(Stack *s)
{
	int i,temp,count;

	Stack ts;
	ts.ll.head=NULL;
	ts.ll.tail=NULL;
	ts.ll.size=0;

	while(s->ll.size>1){
		push(&ts,pop(s));
	}

	while(!isEmptyStack(&ts)){
		temp=pop(&ts);

		if(peek(s)>=temp)
			push(s,temp);
		else{
			count=0;
			while (!isEmptyStack(s) && peek(s)<temp){ // !!!!! must check is empty or not !!
				push(&ts,pop(s));
				count++;
			}
			push(s,temp);
			for(i=0;i<count;i++)
				push(s,pop(&ts));
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
  insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
  int item;
  if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
  }
    return INT_MIN;
}

int peek(Stack *s){
  return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
  if ((s->ll).size == 0)
      return 1;
  return 0;
}


void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

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

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
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
}





