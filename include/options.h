#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LINE_SIZE 256

void init_options(int argc, char **argv, char *program_name);
int usage(FILE *stream, int exit_code);
int load(const char *filename);

#endif
