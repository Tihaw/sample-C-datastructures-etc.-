#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ListDeque.h"

/*	Create a link for a value.
	Use this function in your add operations to make it easier to allocate links

	param: 	val		the value to store in the newy created link
	pre:	none
	post:	a link is allocated on the heap, storing the argument value
	ret:	the newly allocated link
*/
DLink* _createLink(TYPE val)
{
	DLink* lnk = (DLink*) malloc(sizeof(DLink));
   	assert(lnk != 0);
	
	lnk->value = val;
	lnk->next = NULL;
	lnk->prev = NULL;
	return lnk;
}

/* ************************************************************************
	Basic Operations
************************************************************************ */

/* Initializes a deque.

	param: 	d		pointer to the deque
	pre:	d is not null
	post:	size, head, and tail are initialized
*/
void initListDeque(ListDeque* d)
{
	/*FIXME you will write this function */
	assert(d != 0);

	d->size = 0;
	d->head = NULL;
	d->tail = NULL;
}

/*	De-allocate all links of the deque.
	Write this function in terms of a remove function, such as removeBack.

	param: 	d		pointer to the deque
	pre:	d is not null
	post:	All links are de-allocated
*/
void freeListDeque(ListDeque* d)
{	
	/*FIXME you will write this function */
	DLink* lnk;
	DLink* tmp;
	assert(d != 0);

	lnk = d->head;
	while(lnk != NULL)
	{
		tmp = lnk;
		lnk = lnk->next;
		free(tmp);
	}

	d->head = NULL;
	d->tail = NULL;
	d->size = 0;
}

/* Check whether the deque is empty.

	param: 	d		pointer to the deque
	pre:	d is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyListDeque(ListDeque *d) 
{
	/*FIXME you will write this function */
	assert(d != 0);

	if (d->size == 0 && d->head == NULL
			&& d->tail == NULL)
	{
		return 1;
	}
	return 0;
}

/* Get the value stored in the link at the front of the deque

	param: 	d		pointer to the deque
	pre:	d is not null 
	pre:	d is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontListDeque (ListDeque *d) 
{
   assert(!isEmptyListDeque(d));
   return d->head->value;
}

/* Get the value stored in the link at the back of the deque

	param: 	d		pointer to the deque
	pre:	d is not null
	pre:	d is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backListDeque(ListDeque *d)
{
	/*FIXME you will write this function */
	TYPE var;
	assert(!isEmptyListDeque(d));

	var = d->tail->value;
	return var;
}

/*	Adds a link AFTER another link.
	Write your other add functions in terms of addAfter and addBefore when possible.
 
	param: 	d			pointer to the deque
	param: 	addAfter	pointer to the existing link in the deque
	param: 	newLnk		pointer to the new link to add after the existing link
	pre:	d is not null
	pre: 	newLnk has been properly initialized
	pre:	addAfter is in the deque if it is not a NULL pointer
	post:	newLnk is added into the deque AFTER the existing link
 */
void addLinkAfterListDeque(ListDeque* d, DLink* addAfter, DLink* newLnk)
{
	/*FIXME you will write this function */
	assert(d != 0);
	assert(containsListDeque(d, addAfter->value));
	assert(newLnk != NULL);

	newLnk->next = addAfter->next;
	newLnk->prev = addAfter;
	addAfter->next->prev = newLnk;
	addAfter->next = newLnk;

	d->size += 1;
}

/*
/ *count the size of the deque* /
number_size = 0;
lnk = d->head;
d->tail = lnk;
while(lnk != NULL)
{
	number_size ++;
	lnk = lnk->next;
	if (lnk == NULL)
	{
		break;
	}
	d->tail = lnk;
}
d->size = number_size;
*/


/* Adds a link BEFORE another link.
	Write your other add functions in terms of addAfter and addBefore when possible.
 
	param: 	d			pointer to the deque
	param: 	addBefore	pointer to the existing link in the deque
	param: 	newLnk		pointer to the new link to add before the existing link
	pre:	d is not null
	pre: 	newLnk has been properly initialized
	pre:	addBefore is in the deque if it is not a NULL pointer
	post:	newLnk is added into the deque BEFORE the existing link
 */
void addLinkBeforeListDeque(ListDeque* d, DLink* addBefore, DLink* newLnk)
{
	/*FIXME you will write this function */
	assert(d != 0);
	assert(containsListDeque(d, addBefore->value));
	assert(newLnk != NULL);

	newLnk->next = addBefore;
	newLnk->prev = addBefore->prev;
	addBefore->prev->next = newLnk;
	addBefore->prev = newLnk;

	d->size += 1;
}

/*	Remove a link from the deque.
	Write our other remove functions in terms of this function when possible.
	Be careful not to use a pointer that you have already freed when returning.

	param: 	d		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	d is not null 
	pre:	d is not empty
	pre:	lnk is in the deque 
	post:	lnk is removed from the deque
	ret:	The pointer which follows lnk
*/
DLink* removeLinkListDeque(ListDeque *d, DLink *lnk)
{
	/*FIXME you will write this function */
	DLink *tmp;
	assert(d != 0);
	assert(!isEmptyListDeque(d));
	assert(containsListDeque(d, lnk->value));

	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	tmp = lnk->next;
	free(lnk);
	return tmp;
}

/* ************************************************************************
	Deque Interface
************************************************************************ */

/*	Adds a link to the back of the deque.
	Write this function in terms of addLinkAfter() when possible.

	param: 	d		pointer to the deque
	param: 	val		value for the link to be added
	pre:	d is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackListDeque (ListDeque *d, TYPE val) 
{
	/*FIXME you will write this function */
	DLink *tmp;
	assert(d != 0);

	tmp = _createLink(val);
	if (d->head == NULL)
	{
		d->head = tmp;
		d->tail = tmp;
	}
	else
	{
		d->tail->next = tmp;
		tmp->prev = d->tail;
		d->tail = tmp;
	}

	d->size += 1;
}

/*	Adds a link to the front of the deque.
	Write this function in terms of addLinkBefore when possible.

	param: 	d		pointer to the deque
	param: 	val		value for the link to be added
	pre:	d is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontListDeque(ListDeque *d, TYPE val)
{
	/*FIXME you will write this function */
	DLink *tmp;
	assert(d != 0);

	tmp = _createLink(val);
	if (d->head != NULL)
	{
		d->head->prev = tmp;
		tmp->next= d->head;
		d->head = tmp;
	}
	else
	{
		d->head = tmp;
		d->tail = tmp;
	}

	d->size += 1;
}

/*	Remove the front of the deque.
	Write this function in terms of removeLinkListDeque().

	param: 	d		pointer to the deque
	pre:	d is not null
	pre:	d is not empty
	post:	the front is removed from the deque
*/
void removeFrontListDeque (ListDeque *d) 
{
	/*FIXME you will write this function */
	DLink *tmp;
	assert(!isEmptyListDeque(d));

	if (d->size == 1)
	{
		freeListDeque(d);
	}

	else
	{

		tmp =	d->head;
		d->head = d->head->next;
		free(tmp);

		d->size -= 1;
	}
}

/* Remove the back of the deque.
	Write this function in terms of removeLinkListDeque().

	param: 	d		pointer to the deque
	pre:	d is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackListDeque(ListDeque *d)
{
	/*FIXME you will write this function */
	DLink *tmp;
	assert(!isEmptyListDeque(d));

	tmp =	d->tail;
	if (d->tail->prev != NULL)
	{
		d->tail = d->tail->prev;
		d->tail->next = NULL;
		free(tmp);
	}
	else
	{
		d->head = NULL;
		d->tail = NULL;
		free(tmp);
	}

	d->size -= 1;
}

/* ************************************************************************
	Bag Interface
************************************************************************ */
/*	Returns whether or not the given value is stored in the deque

	param:	d		pointer to the deque
	param:	val		value that we are looking for in the deque
	ret:	1 if val is contained in d, 0 otherwise
*/
int containsListDeque(ListDeque* d, TYPE val)
{
	/*FIXME you will write this function */
	DLink* lnk;
	assert(d != 0);

	lnk = d->head;
	while(lnk != NULL)
	{
		if (lnk->value == val)
		{
			return 1;
		}
		lnk = lnk->next;
	}

	return 0;
}

/* Removes the first occurrence of the given value from the list.

	param:	d		pointer to the deque
	param:	val		value that we are looking for in the deque
	post:	first occurrence of val is removed from the list
*/
void removeListDeque(ListDeque* d, TYPE val)
{
	/*FIXME you will write this function */
	DLink *lnk;
	assert(!isEmptyListDeque(d));

	lnk = d->head;
	while(lnk != NULL)
	{
		if (lnk->value == val)
		{
			if (lnk == d->head)
			{
				d->head = d->head->next;
			}
			else
			{
				lnk->next->prev = lnk->prev;
				lnk->prev->next = lnk->next;
			}
			free(lnk);
			d->size -= 1;
			break;
		}
		lnk = lnk->next;
	}
}

/* Reverse the deque.  Note that careful swapping of the pointers inside each link
	(next and prev) will cause a reverse, provided head and tail are updated properly.

    param:  d       pointer to the deque
    pre:    d is not null
    post:   the deque is reversed
*/
void reverseListDeque(ListDeque *d)
{
	/*FIXME you will write this function */
	DLink *lnk;
	ListDeque newd;
	assert(d != 0);

	initListDeque(&newd);
	lnk = d->head;
	while(lnk != NULL)
	{
		addFrontListDeque(&newd, lnk->value);
		lnk = lnk->next;
	}

	freeListDeque(d);
	lnk = newd.head;
	while(lnk != NULL)
	{
		addBackListDeque(d, lnk->value);
		lnk = lnk->next;
	}
}

/*	Print the links in the deque from front to back

	param: 	d		pointer to the deque
	pre:	d is not null
	post: 	the links in the deque are printed from front to back
*/
void printListDeque(ListDeque *q)
{
	DLink* lnk;
	lnk = q->head;
	printf("Size = %d [ ", q->size);
	while(lnk != NULL)
	{
		printf("%c ", lnk->value);
		lnk = lnk->next;
	}
	printf("]\n");
}