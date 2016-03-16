#include "list.h"
#include "stdio.h"
#include "stdlib.h"

#define LEN sizeof(struct node)  


int main ()
{
	char ans[2];
	int num;
	struct node *head = NULL;
	struct node *tail = NULL;

	do 
	{
		do 
		{
			printf("Enter a number: ");
			scanf("%d", &num);
			head = push(head, num);//can change to append
			//tail = append(tail, num);
			printf("Do you want another num (y or n): ");
			scanf("%1s", ans);
			while (1)
			{
				if (ans[0] == 'y' || ans[0] == 'n' )
				{
					break;
				}
				printf("Wrong input, pls input(y or n): ");
				scanf("%1s", ans);
			}
		} while (ans[0] == 'y');

		printf("Sort ascending or descending (a or d)? ");
		scanf("%1s", ans);
		while (1)
		{
			if (ans[0] == 'a' || ans[0] == 'd' )
			{
				break;
			}
			printf("Wrong input, pls input(a or d): ");
			scanf("%1s", ans);
		}

		if (ans[0] == 'a') 
		{
			head = sort_ascending(head);
		}
		else if (ans[0] == 'd')
		{
			head = sort_descending(head);
		}
		else
		{
			printf("Wrong input");
		}

		print(head, length(head));
		printf("\nDo you want to do this again (y ot n)? ");
		scanf("%1s", ans);
		while (1)
		{
			if (ans[0] == 'y' || ans[0] == 'n' )
			{
				break;
			}
			printf("Wrong input, pls input(y or n): ");
			scanf("%1s", ans);
		}

		if (ans[0] == 'y')
		{
			head = clear(head);
		}
	} while (ans[0] == 'y');

	return 0;
}


//return the numbers of nodes, 1,2,3?
int length(struct node * head)
{
	int i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}

void print(struct node * head, int nodeNumbers)
{
	printf("Your linked list is: \n");
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}

//put at front
struct node * push(struct node * first, int num_Now)
{
	if (first == NULL)
	{
		first = (struct node *)malloc(sizeof(LEN));
		first->val = num_Now;
		first->next = NULL;
		first->prev = NULL;

		return first;
	}
	else
	{
		first->prev = (struct node *)malloc(sizeof(LEN));
		first->prev->val = num_Now;
		first->prev->next = first;
		first->prev->prev = NULL;
		first = first->prev;
		return first;
	}
}

//put at back
struct node * append(struct node * last, int num_Now)
{
	if (last == NULL)
	{
		last = (struct node *)malloc(sizeof(LEN));
		last->val = num_Now;
		last->next = NULL;
		last->prev = NULL;

		return last;
	}
	else
	{
		last->next = (struct node *)malloc(sizeof(LEN));
		last->next->val = num_Now;
		last->next->next = NULL;
		last->next->prev = last;

		return last;
	}

}

struct node * clear(struct node * head)
{
	struct node * p = head;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		p->next = NULL;
		p->prev = NULL;
		p = NULL;
		free(p);
		p = head;
	}
	return head;
}

//delete the ith node(from 1, 2, 3, ,,,,)
struct node * Remove(struct node * head, int i)
{
	struct node * p = head;
	int j = 1;
	if (i > length(head) || i <= 0)
	{
		printf("Error! You can give a number bigger than 0 and smaller than number of nodes! /n");
	}

	while (1)
	{
		if (i == j)
		{
			break;
		}
		p = p->next;
		j++;
	}
	//if the first one
	if (p->prev == NULL)
	{
		p->next->prev = NULL;
		p->next = NULL;
		p->prev = NULL;
	}
	//if the last one
	else if (p->next == NULL)
	{		
		p->prev->next = NULL;
		p->next = NULL;
		p->prev = NULL;
	}
	// if in the middle
	else
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		p->next = NULL;
		p->prev = NULL;
	}
	free(p);
	return head;
}

struct node * sort_ascending(struct node * head)
{
	struct node * headcopy = head;
	int tempnum;
	int nodesLen = length(head);
	int * numbers = (int *)malloc(nodesLen * sizeof(int));
	int i = 0;
	int j,k;

	while(headcopy != NULL)
	{
		numbers[i] = headcopy->val;
		headcopy = headcopy->next;
		i++;
	}
	//tempnum = numbers[0];
	for (j = 0; j < nodesLen; j++)
	{
		for (k = j + 1; k < nodesLen; k++)
		{
			if (numbers[j] > numbers[k])
			{
				tempnum = numbers[j];
				numbers[j] = numbers[k];
				numbers[k] = tempnum;
			}
		}
	}

	head = clear(head);

	i = 0;
	while ( i < nodesLen)
	{
		head = push(head, numbers[nodesLen - i -1]);
		i++;
	}

	free(numbers);
	return head;
}

struct node * sort_descending(struct node * head)
{
	struct node * headcopy = head;
	int tempnum;
	int nodesLen = length(head);
	int * numbers = (int *)malloc(nodesLen * sizeof(int));
	int i = 0;
	int j,k;

	while(headcopy != NULL)
	{
		numbers[i] = headcopy->val;
		headcopy = headcopy->next;
		i++;
	}
	//tempnum = numbers[0];
	for (j = 0; j < nodesLen; j++)
	{
		for (k = j + 1; k < nodesLen; k++)
		{
			if (numbers[j] > numbers[k])
			{
				tempnum = numbers[j];
				numbers[j] = numbers[k];
				numbers[k] = tempnum;
			}
		}
	}

	head = clear(head);

	i = 0;
	while ( i < nodesLen)
	{
		head = push(head, numbers[i]);
		i++;
	}

	free(numbers);
	return head;
}

//insert into a specific location in the list
struct node * insert_middle(struct node * head, int i, int num)
{
	struct node * p = head;
	struct node * temp = NULL;
	int j = 1;
	if (i > length(head) || i <= 0)
	{
		printf("Error! You can give a number bigger than 0 and smaller than number of nodes! /n");
	}

	while (1)
	{
		if (i == j)
		{
			break;
		}
		p = p->next;
		j++;
	}
	temp = (struct node *)malloc(sizeof(LEN));
	temp->val = num;
	temp->next = p;
	temp->prev = p->prev;
	p->prev->next = temp;
	p->prev = temp;
	return head;
}
