#include "bitree.h"
/* insert a tnode into the binary tree */
struct BTreeNode *tnode_insert(struct BTreeNode *p, int value) {
 struct BTreeNode *tmp_one = NULL;
 struct BTreeNode *tmp_two = NULL;

 if(p == NULL) {
  /* insert [new] tnode as root node */
  p = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  p->Element = value;
  p->Left = p->Right = NULL;
 } else {
  tmp_one = p;
  /* Traverse the tree to get a pointer to the specific tnode */
  /* The child of this tnode will be the [new] tnode */
  while(tmp_one != NULL) {
   tmp_two = tmp_one;
   if(tmp_one ->Element > value)
    tmp_one = tmp_one->Left;
   else
    tmp_one = tmp_one->Right;
  }

  if(tmp_two->Element > value) {
   /* insert [new] tnode as left child */
   tmp_two->Left = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
   tmp_two = tmp_two->Left;
   tmp_two->Element = value;
   tmp_two->Left = tmp_two->Right = NULL;
  } else {
   /* insert [new] tnode as left child */
   tmp_two->Right = (struct BTreeNode *)malloc(sizeof(struct BTreeNode)); 
   tmp_two = tmp_two->Right;
   tmp_two->Element = value;
   tmp_two->Left = tmp_two->Right = NULL;
  }
 }

 return(p);
}

/* print binary tree inorder */
void print_inorder(struct BTreeNode *p) {
 if(p != NULL) {
  print_inorder(p->Left);
  printf("%d ", p->Element);
  print_inorder(p->Right);
 }
}

/* print binary tree preorder */
void print_preorder(struct BTreeNode *p) {
 if(p != NULL) {
  printf("%d ", p->Element);
  print_preorder(p->Left);
  print_preorder(p->Right);
 }
}

/* print binary tree postorder */
void print_postorder(struct BTreeNode *p) {
 if(p != NULL) {
  print_postorder(p->Left);
  print_postorder(p->Right);
  printf("%d ", p->Element);
 }
}

/* returns the total number of tree nodes */
int tnode_count(struct BTreeNode *p) {
 if(p == NULL)
  return 0;
 else {
  if(p->Left == NULL && p->Right == NULL)
   return 1;
  else
   return(1 + (tnode_count(p->Left) + tnode_count(p->Right)));
 }
}

/* exchange all left and right tnodes */
struct BTreeNode *tnode_swap(struct BTreeNode *p) {
 struct BTreeNode *tmp_one = NULL; 
 struct BTreeNode *tmp_two = NULL;

 if(p != NULL) { 
  tmp_one = tnode_swap(p->Left);
  tmp_two = tnode_swap(p->Right);
  p->Right = tmp_one;
  p->Left  = tmp_two;
 }

 return(p);
}

/* locate a value in the btree */
struct BTreeNode *tnode_search(struct BTreeNode *p, int key) {
 struct BTreeNode *temp;
 temp = p;

 while(temp != NULL) {
  if(temp->Element == key)
   return temp;
  else if(temp->Element > key)
   temp = temp->Left;
  else
   temp = temp->Right;
 }

 return NULL;
}

/* locate a minimum value in the btree */
struct BTreeNode *tnode_searchmin(struct BTreeNode *p) {
 if(p == NULL)
  return NULL;
 else
  if(p->Left == NULL)
   return p;
  else
   return tnode_searchmin(p->Left);
}

/* locate a maximum value in the btree */
struct BTreeNode *tnode_searchmax(struct BTreeNode *p) {
 if(p != NULL)
  while(p->Right != NULL)
   p = p->Right;

 return p;
}

/* destroy the binary tree */
void tnode_destroy(struct BTreeNode *p) {
 if(p != NULL) {
  tnode_destroy(p->Left);
  tnode_destroy(p->Right);

  free(p);
 }
}

/* returns the total number of tree nodes */
int leaf( BTNode *t )
{
	if(t == NULL)
		return 0;
	else {
		if(t->Left == NULL && t->Right == NULL)
			return 1;
		else
			return(1 + (tnode_count(t->Left) + tnode_count(t->Right)));
	}
}
