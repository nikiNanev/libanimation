#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "../include/animation.h"
#include "../include/options.h"

#define VERSION 0x000001

#include <dlfcn.h>

int main(int argc, char **argv)
{

	printf("\n\n\tAnimation library\n\n");

	init(VERSION);

	void *handle = dlopen("./libanimation.so", RTLD_LAZY);

	if(handle != NULL)
	{
		
		dlerror();

		double (*sum)(double, double);		


		*(void **)(&sum) = dlsym(handle, "sum2");


		char *error;
		error = dlerror();
		if(error != NULL)
		{
			fprintf(stderr, "%s\n", error);

			dlclose(handle);
			return -1;
		}
		double output = (*sum)(5.0, 8.8);
		printf("%.3f\n", output);

		dlclose(handle);

	}
	else
	{
		fprintf(stderr, "Could not open libanimation.so.0, (%s)\n", strerror(errno));

	}

	init_options(argc, argv, argv[0]);

	return 0;
}
