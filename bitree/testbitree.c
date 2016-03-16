#include "bitree.h"

int main(void) {
	int demo_nr[] = {1, 3, 4, 7, 2, 9, 9, 0, 5, 6, 8, 7, 1, 2, 4};
	struct BTreeNode *root = NULL; 
	struct BTreeNode *searchval = NULL;
	int querry = 0;
	int i = 0;
	int number_nodes = 0;

	/* demo: insert some nr's into the binary tree */
	for(i = 0; i < 15; i++)
		root = tnode_insert(root, demo_nr[i]);

	printf("=-=-=\n");
	printf("Total number of tree nodes: %d\n", tnode_count(root));
	printf("inorder  : ");
	print_inorder(root);
	printf("\n");

	printf("preorder : ");
	print_preorder(root);
	printf("\n");

	printf("postorder: ");
	print_postorder(root);
	printf("\n");

	printf("=-=-=\n");
	number_nodes = leaf(root);
	printf("Number of the nodes are %d\n", number_nodes);
	printf("Destroying btree... bye!\n");
	tnode_destroy(root);

	return 0;
}