#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/animation.h"
#include "../include/options.h"

#define VERSION 0x000001

int main(int argc, char **argv)
{

	printf("\n\n\tAnimation library\n\n");

	init(VERSION);

	init_options(argc, argv, argv[0]);

	return 0;
}
