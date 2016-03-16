struct node
{
	int val;
	struct node *next;
	struct node *prev;
};

//Implemented in Lab #9, but now return new head address
int length(struct node *);
void print(struct node *, int);
struct node * push(struct node *, int);//put at front
struct node * append(struct node *, int);//put at back

struct node * clear(struct node * );// clear all nodes
struct node * Remove(struct node *, int);//remove a node at a specific location
struct node * sort_ascending(struct node *);
struct node * sort_descending(struct node *);
//insert into a specific location in the list
struct node * insert_middle(struct node *, int, int);

