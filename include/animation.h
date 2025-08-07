#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <stdio.h>

typedef struct _node
{
	unsigned int id;

	double width, height;
	char *description;
} Node;

typedef struct _frame
{
	unsigned int id;
	Node *node;

	char *description;

} Frame;

int init(long version);

#endif
