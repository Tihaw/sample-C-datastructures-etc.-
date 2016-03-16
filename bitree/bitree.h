#include <stdio.h>
#include <stdlib.h>

/*define the datastructure as problem*/
typedef int ElementType;
struct BTreeNode {
 ElementType Element;
 struct BTreeNode * Left;
 struct BTreeNode * Right;
};
typedef struct BTreeNode BTNode;

/* insert, swap, search value, search minimum and search maximum values */
struct BTreeNode *tnode_insert(struct BTreeNode *p, int value);
struct BTreeNode *tnode_swap(struct BTreeNode *p);
struct BTreeNode *tnode_search(struct BTreeNode *p, int key);
struct BTreeNode *tnode_searchmin(struct BTreeNode *p);
struct BTreeNode *tnode_searchmax(struct BTreeNode *p);

/* destroy, count tree nodes */
void tnode_destroy(struct BTreeNode *p);
int tnode_count(struct BTreeNode *p);
int leaf( BTNode *t) ;


/* print binary tree inorder, preorder, postorder [recursive] */
void print_inorder(struct BTreeNode *p);
void print_preorder(struct BTreeNode *p);
void print_postorder(struct BTreeNode *p);