/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void swap(int *, int *);
void fix(struct node **, struct node **, struct node **, struct node **, struct node *);
void fix_bst(struct node *root){
	struct node *s = NULL, *m = NULL, *p = NULL, *e = NULL;
	fix(&s, &m, &e, &p, root);
	if (s != NULL && e != NULL)
		swap(&(s->data), &(e->data));
	else if (s!=NULL && e!=NULL)
		swap(&(s->data), &(m->data));
}
void fix(struct node **s, struct node **m, struct node **e, struct node **p, struct node *root)
{
	if (root != NULL)
	{
		fix(s, m, e, p, root->left);
		if (root->data < p->data && *p)
		{
			*s = *p;
			*m = root;
		}
		else
			*e = root;
	}
	*p = root;
	fix(s, m, e, p, root->right);
}
void swap(int *x, int *y)
{
	int *t = *x;
	*x = *y;
	*y = t;
}