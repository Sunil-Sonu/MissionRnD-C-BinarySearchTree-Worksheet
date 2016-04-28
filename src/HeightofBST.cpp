/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int get_res_l(struct node *, int );
int get_res_r(struct node *, int );
int get_height(struct node *root){
	int l, r;
	if (root==NULL)
	return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
	{
		l = get_height(root->left);
		r = get_height(root->right);
	}
	if (l > r)
		return l + 1;
	else
		return r + 1;
}

int get_left_subtree_sum(struct node *root){
	int res;
	if (root==NULL)
	return 0;
	res = root->right->data;
	get_res_r(root->right, res);
	return res;
}

int get_right_subtree_sum(struct node *root){
	int res;
	if (root == NULL)
		return 0;
	res = root->left->data;
	get_res_l(root->left, res);
	return res;
}
int get_res_l(struct node *root, int res)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			res = res + root->left->data;
		if (root->right != NULL)
			res = res + root->right->data;
		get_res_l(root->left, res);
	}
	return res;
}

int get_res_r(struct node *root, int res)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			res = res + root->left->data;
		if (root->right != NULL)
			res = res + root->right->data;
		get_res_l(root->right, res);
	}
	return res;
}