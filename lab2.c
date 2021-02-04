//Q1: removeUntil(): pops off a stack on ints down to but not including the 1st occurance of the chosen value
//Q2: recursiveReverse(): reverses the order of items stored in a QUEUE of ints
//Q3: palindrome(): dtms whether the given string is a palindrome; return 0 of a palindrome, return -1 otherwise
	//ignore the NULL terminator. Ignore the case of each letter
//Q4. balanced(): dtms if an expression compromised of the characters () [] {} is balanced
	//is balanced if the ORDEN & QUANTITY of the parenthesis match

//////////////////////////////////////////////////////////////////////////////////////////////

// #include "stdio.h"
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// typedef struct _listnode{
// 	int item;
// 	struct _listnode *next;
// } ListNode;

// typedef struct _linkedlist{
// 	int size;
// 	ListNode *head;
// 	ListNode *tail;
// } LinkedList;

// typedef struct stack{
// 	LinkedList ll;
// } Stack;


// typedef struct _queue{
// 	LinkedList ll;
// } Queue;

// void printList(ListNode *head);
// ListNode * findNode(LinkedList *ll, int index);
// int insertNode(LinkedList *ll, int index, int value);
// int removeNode(LinkedList *ll, int index);

// void push(Stack *s, int item);
// int pop(Stack *s);
// int peek(Stack *s);
// int isEmptyStack(Stack *s);

// void enqueue(Queue *q, int item);
// int dequeue(Queue *q);
// int isEmptyQueue(Queue *s);

// // four questions
// void removeUntil(Stack *s, int value);
// void recursiveReverse(Queue *q);
// int palindrome(char *word);
// int balanced(char *expression);


// int main()
// {
// 	Stack s;
// 	Queue q;
// 	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
// 	int i;
// 	char *word1 = "A man a plan a canal Panama";
// 	char *word2 = "Superman in the sky";

// 	//for question 1
// 	//initialize the stack
// 	s.ll.head = NULL;
// 	s.ll.size = 0;
// 	s.ll.tail = NULL;

// 	for (i = 0; i<11; i++)
// 		push(&s, item[i]);

// 	printf("removeUntil():\n");
// 	printf("Original linked list: ");
// 	printList(s.ll.head);
// 	printf("The resulting linked list: ");
// 	removeUntil(&s, 5);
// 	printList(s.ll.head);
// 	printf("\n");

// 	//for question 2
// 	//initialize the queue
// 	q.ll.head = NULL;
// 	q.ll.size = 0;
// 	q.ll.tail = NULL;

// 	for (i = 0; i<10; i++)
// 		enqueue(&q, i);
// 	printf("recursiveReverse():\n");
// 	printf("Original linked list: ");
// 	printList(q.ll.head);
// 	printf("The resulting linked list: ");
// 	recursiveReverse(&q);
// 	printList(q.ll.head);
// 	printf("\n");


// 	//for question 3
// 		//*word1="A man a plan a canal Panama";
// 		// *word2="Superman in the sky";
// 		printf("palindrome():\n");
// 	if(palindrome(word1))
// 		printf("\'%s\': Is a palindrome :)\n",word1);
// 	else
// 		printf("\'%s\': Is not a palindrome :(\n",word1);

// 	if (palindrome(word2))
// 		printf("%s: Is a palindrome :)\n",word2);
// 	else
// 		printf("\'%s\': Is not a palindrome :(\n",word2);
// 	printf("\n");



// 	//for question 4
// 	printf("balanced():\n");
// 	if (balanced("()"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("[()]"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("{[]()[]}"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("[({{)])"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("[({{)])))"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("[{}]}"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	if (balanced("{[{}]{}()}"))
// 		printf("not balanced!\n");
// 	else
// 		printf("balanced!\n");

// 	printf("\n");

// 	return 0;
// }

////////////////////////////////////////////////////////////////
//Question 1

void removeUntil(Stack *s, int value){
	int len=s->ll.size;
	for(int i=0;i<len;i++){
		if(peek(s)==value)
			break;
		else
			pop(s);
	}

}

////////////////////////////////////////////////////////////
//Question 2 {HARD AF}

void recursiveReverse(Queue *q){

	if(isEmptyQueue(q))
		return;

	else{
		int data=dequeue(q);
		recursiveReverse(q);
		enqueue(q,data);
	}
}

////////////////////////////////////////////////////////////
//Question 3
//strip spaces, make same casing, and make a reverse string, if it is identical, return 1

int palindrome(char *word){

	// Stack s1,s2;
	// s1.ll.head=NULL;
	// s1.ll.tail=NULL;
	// s1.ll.size=0;

	// s2.ll.head=NULL;
	// s2.ll.tail=NULL;
	// s2.ll.size=0;

	// int i, count=0;


	// for(i=0; i<(strlen(word));i++){
	// 	if(word[i]!=' '){
	// 		push(&s1,toupper(word[i]));
	// 		count++;
	// 	}
	// }
	// for(i=0;i<count/2;i++){
	// 	push(&s2,pop(&s1));
	// }

	// if(count%2==1)
	// 	pop(&s1);


	// printList(s1.ll.head);
	// printList(s2.ll.head);


	// for(i=0; i<count/2;i++){
	// 	if(pop(&s1)!=pop(&s2))
	// 		return 0;
	// }

	// return 1;

	Stack s; Queue q;
	s.ll.head=NULL;
	s.ll.tail=NULL;
	s.ll.size=0;

	q.ll.head=NULL;
	q.ll.tail=NULL;
	q.ll.size=0;

	int count=0;

	while(*word!='\0'){
		if(*word!=' '){
			push(&s,toupper(*word));
			enqueue(&q,toupper(*word));
			count++;
		}
		word++;
	}
	// printList(s.ll.head);
	// printList(q.ll.head);
	int what;
	for(int i=0;i<count;i++){
		if( dequeue(&q) != pop(&s)) {
			return 0;
		}
	}
	return 1;

}
// A man a plan a canal Panama

//First mthd was using 2 stacks
//second was using 1 stack 1 queue

////////////////////////////////////////////////////////////
//Question 4 {HARD AF}

int balanced(char *expression){

	Stack s;
	s.ll.head=NULL;
	s.ll.tail=NULL;
	s.ll.size=0;

	while(*expression != '\0'){

		if (*expression=='[' || *expression=='{' || *expression=='(' )
			push(&s,*expression);

		else{
			if(isEmptyStack(&s))
				return 1;
			else if( (*expression==']' && peek(&s)=='[') || (*expression=='}' && peek(&s)=='{') || (*expression==')' && peek(&s)=='(') )
				pop(&s);
			else
				return 1;
		}
		expression++;
	}
	if(isEmptyStack(&s))
		return 0;
	return 1;
}

//////////////////////////////////////

// void push(Stack *s, int item){
// 	insertNode(&(s->ll), 0, item);
// }

// int pop(Stack *s){
// 	int item;

// 	item = ((s->ll).head)->item;
// 	removeNode(&(s->ll), 0);
// 	return item;
// }

// int peek(Stack *s){
// 	return ((s->ll).head)->item;
// }

// int isEmptyStack(Stack *s){
// 	if ((s->ll).size == 0)
// 		return 1;
// 	return 0;
// }


// void enqueue(Queue *q, int item){
// 	insertNode(&(q->ll), q->ll.size, item);
// }

// int dequeue(Queue *q){
// 	int item;
// 	item = ((q->ll).head)->item;
// 	removeNode(&(q->ll), 0);
// 	return item;
// }

// int isEmptyQueue(Queue *q){
// 	if ((q->ll).size == 0)
// 		return 1;
// 	return 0;
// }


// void printList(ListNode *head){

// 	ListNode *temp = head;

// 	if (temp == NULL)
// 		return;

// 	while (temp != NULL){
// 		printf("%d ", temp->item);
// 		temp = temp->next;
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
// 		ll->tail = ll->head;
// 		ll->head->item = value;
// 		ll->head->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	// Inserting as new last node
// 	if (index == ll->size){
// 		pre = ll->tail;
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));
// 		ll->tail = pre->next;
// 		pre->next->item = value;
// 		pre->next->next = cur;
// 		ll->size++;
// 		return 0;
// 	}

// 	// Find the nodes before and at the target position
// 	// Create a new node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){
// 		cur = pre->next;
// 		pre->next = malloc(sizeof(ListNode));

// 		if (index == ll->size)
// 			ll->tail = pre->next;

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

// 		if (ll->size == 0)
// 			ll->tail = 0;

// 		return 0;
// 	}

// 	// Find the nodes before and after the target position
// 	// Free the target node and reconnect the links
// 	if ((pre = findNode(ll, index - 1)) != NULL){

// 		// Removing the last node, update the tail pointer
// 		if (index == ll->size - 1){
// 			ll->tail = pre;
// 			free(pre->next);
// 			pre->next = NULL;
// 		}
// 		else{
// 			cur = pre->next->next;
// 			free(pre->next);
// 			pre->next = cur;
// 		}
// 		ll->size--;
// 		return 0;
// 	}

// 	return -1;
// }
