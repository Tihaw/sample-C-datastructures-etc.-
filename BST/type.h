/*	type.h
	
	Defines the type to be stored in the data structure.  These macros
	are for convenience to avoid having to search and replace/dup code
	when you want to build a structure of doubles as opposed to ints
	for example.
*/

#ifndef __TYPE_H
#define __TYPE_H

struct Task {
	char* name;
	int priority;
};
typedef struct Task Task;

# ifndef TYPE
# define TYPE      Task
# define TYPE_SIZE sizeof(Task)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

#endif
