/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
struct node *find_parent(struct node *, struct node *);
int get_Close_leaf(struct node *);
int dist(struct node *, struct node *);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL)
		return -1;
	if (temp == NULL)
		return -1;
	int h = get_Close_leaf(temp);
	struct node *p = find_parent(root, temp);
	int ph = get_Close_leaf(p);
	int d = dist(p, temp);
	if (ph + d >= h)
		return h;
	else
		return (ph+d);
}
int get_Close_leaf(struct node *root)
{
	if (root == NULL)
		return -1;
	int r = get_Close_leaf(root->right);
	int l = get_Close_leaf(root->left);
	if (l <= r && l != -1)
		return l + 1;
	else if (l <= r)
		return r + 1;
	else if (r < l && r != -1)
		return r + 1;
	else
		return l + 1;
}
int d(struct node *root, struct node *temp)
{
	if (root == temp)
		return 0;
	else
	{
		if (root->data > temp->data)
		{
			int a = d(root->left, temp);
			return a + 1;
		}
		else
		{
			int a = d(root->right, temp);
			return a + 1;
		}
	}
}
struct node * find_parent(struct node *root, struct node *temp)
{
	if (root -> left == temp || root->right == temp || root == temp)
		return root;
	else
	{
		if (root->data > temp->data)
			return find_parent(root->left, temp);
		else
			return find_parent(root->right, temp);
	}
}