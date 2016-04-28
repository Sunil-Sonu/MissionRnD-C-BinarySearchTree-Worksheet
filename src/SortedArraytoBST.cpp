/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node * convert_array_to_bst(int *arr, int len){
	int f = 0, l = len - 1;
	if (arr==NULL)
	return NULL;
	else
	{
		struct node tree;
		tree = to_arr(arr, f, l);
		return tree;
	}
}
struct node *to_arr(int *arrr, int f, int l)
{
	if (f > l)
		return NULL;
	int m = (f + l) / 2
		;
	struct node *root = c_node(arr[mid]);
	root->left = to_arr(arr, f, m - 1);
	root->right = to_arr(arr, m + 1, l);
}
struct node *c_node(int data)
{
	struct node *n;
	n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
