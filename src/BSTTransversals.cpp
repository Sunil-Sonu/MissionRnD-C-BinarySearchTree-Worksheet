/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int in = 0, pr = 0, po = 0;
void inor(struct node *, int *);
void preor(struct node *, int *);
void poor(struct node *, int *);
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	inor(root, arr);
}
void inor(struct node *root, int *arr)
{
	inor(root->left, arr);
	arr[in++] = root->data;
	inor(root->right, arr);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	preor(root, arr);
}
void preor(struct node *root, int *arr)
{
	arr[pr++] = root->data;
	preor(root->left, arr);
	preor(root->right, arr);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	poor(root, arr);
}
void poor(struct node *root, int *arr)
{
	poor(root->left, arr);
	poor(root->right, arr);
	arr[po++] = root->data;
}
