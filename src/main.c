#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/animation.h"


#define VERSION 0x000001

int main(int argc, char **argv)
{

	printf("\e[1;30;42m Animation library v0.0.1 \n\e[0m");

	init(VERSION);

	return 0;
}
