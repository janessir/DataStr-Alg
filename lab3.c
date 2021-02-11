/*
Q1: recursive fn mirrorTree tt will modify a bin tree so that the resulting tree is a mirror of the original str
	Should not create any intermediate/temp trees
	Fn accepts root pointer

Q2: printSmallerValues(): accepts root pointer, prints all ints stored in the tree that are SMALLER than a iven vaue m

Q3: smallestValue(): returns the smallest value stored in a given tree.
	Fn accepts root pointer

Q4: recursive fn hasGreatGrandchild(): prints vaue stored in all nodes of nin tree that have at least one great-grandchil
	Fn accepts root ptr

*/

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct _btnode{
// 	int item;
// 	struct _btnode *left;
// 	struct _btnode *right;

// } BTNode;

// void mirrorTree(BTNode *node);
// void printSmallerValues(BTNode *node, int m);
// int smallestValue(BTNode *node);
// int hasGreatGrandchild(BTNode *node);

// void printTree_InOrder(BTNode *node);

// int main(int argc, const char * argv[]){

// 	int i;
// 	BTNode *root, *root2;
// 	BTNode btn[15];

// 	// Create the tree in Q1
// 	// Using manual dynamic allocation of memory for BTNodes

// 	root = malloc(sizeof(BTNode));
// 	root->item = 4;

// 	root->left = malloc(sizeof(BTNode));
// 	root->left->item = 5;

// 	root->right = malloc(sizeof(BTNode));
// 	root->right->item = 2;

// 	root->left->left = NULL;

// 	root->left->right = malloc(sizeof(BTNode));
// 	root->left->right->item = 1;

// 	root->left->right->left = NULL;
// 	root->left->right->right = NULL;

// 	root->right->left = malloc(sizeof(BTNode));
// 	root->right->left->item = 3;

// 	root->right->right = malloc(sizeof(BTNode));
// 	root->right->right->item = 1;

// 	root->right->left->left = NULL;

// 	root->right->left->right = NULL;

// 	root->right->right->left = NULL;

// 	root->right->right->right = NULL;

// 	printf("Question 1");
// 	printf("\nOrinial Tree:\n");
// 	printTree_InOrder(root);
// 	printf("\nmirrorTree():\n");
// 	mirrorTree(root);
// 	printTree_InOrder(root);
// 	printf("\n\n");

// 	//question 2
// 	printf("Question 2");
// 	printf("\nInput m for question 2: ");
// 	scanf("%d", &i);
// 	printf("the values smaller than %d are: ", i);
// 	printSmallerValues(root, i);
// 	printf("\n\n");

// 	//question 3
// 	printf("Question 3");
// 	printf("\nThe smallest value in the tree is: %d\n\n", smallestValue(root));

// 	//question 4
// 	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
// 	// Use array of BTNodes, create tree by linking nodes together
// 	for (i = 0; i <= 6; i++){
// 		btn[i].item = i;
// 		btn[i].left = &(btn[i * 2 + 1]);
// 		btn[i].right = &(btn[i * 2 + 2]);
// 	}

// 	for (i = 7; i <= 14; i++){
// 		btn[i].item = i;
// 		btn[i].left = NULL;
// 		btn[i].right = NULL;
// 	}
// 	root2 = &btn[0];

// 	printf("Question 4\n");
// 	printf("The tree for question 4 visited by in-order is: ");
// 	printTree_InOrder(root2);
// 	printf("\nThe values stored in all nodes of the tree that have at least one great-grandchild are: {");
// 	hasGreatGrandchild(root2);
// 	printf("}\n");

// 	return 0;
// }

void mirrorTree(BTNode *node){
	//can do pre-order
	BTNode *temp=NULL;

	if(node==NULL)
		return;

	mirrorTree(node->left);
	mirrorTree(node->right);

	//work
	temp=node->left;
	node->left=node->right;
	node->right=temp;

}

void printSmallerValues(BTNode *node, int m){

	//I use in-order since printtree is inorder

	if(node==NULL)
		return;

	printSmallerValues(node->left,m);
	//work
	if (node->item < m)
		printf("%d ",node->item);
	//
	printSmallerValues(node->right,m);

}

int smallestValue(BTNode *node) {
	int l, r;

	//post order: info propogates upwards

	if (node==NULL)
		return 10;

	l=smallestValue(node->left);
	r=smallestValue(node->right);

	//work
	if((l<r) && (l<node->item))
		return l;
	else if ((r<l) && (r<node->item))
		return r;
	else
		return node->item;

}


int hasGreatGrandchild(BTNode *node){
	//print nodes w/ >3 levels down
	//need info to propogate upwards, use post-order

	int l,r,h;

	if(node==NULL)
		return -1;

	l=hasGreatGrandchild(node->left);
	r=hasGreatGrandchild(node->right);

	//getting max of right and left child +1
	if(l>r)
		h=l+1;
	else
		h=r+1;

	if(h>=3)
		printf("%d ",node->item);

	return h;

}





void printTree_InOrder(BTNode *node){ //inorder TT

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
