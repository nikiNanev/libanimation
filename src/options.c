#include "../include/options.h"

static char *program_name = NULL;

const struct option long_options[] =
{
        { "help", 0, NULL, 'h' },
        { "load", 1, NULL, 'l' },
        { NULL, 0, NULL, 0 }
};      

const char *short_options = "hl:";

int usage(FILE *stream, int exit_code)
{

	fprintf(stream, "\nUsage: %s options [ input file ... ]\n", (program_name != NULL) ? program_name : "");
	fprintf(stream, "	-h		--help			Display this information\n"
			"	-l inputfile	--load inputfile	Loads the specified input file\n");
	return exit_code;
}

int load(const char *filename)
{


	fprintf(stdout, "\nLoad object to animate\n");

	if(filename)
	{
		FILE *handle_file = fopen(filename, "r");

		if(handle_file)
		{
			char buffer[128];
			while(fgets(buffer, 128, handle_file))
			{
				fprintf(stdout, "%s\n", buffer);
			}

		}
		else
		{
			fprintf(stderr, "Could not open file for reading: (%s)\n", strerror(errno));
			return -2;
		}
	}
	else
	{
		fprintf(stderr, "Failed to load object! ( %s )\n", strerror(errno));
		return -1;
	}
	return 0;
}

void init_options(int argc, char **argv, char *program_name)
{

	int next_option;

	do
	{

		next_option = getopt_long(argc, argv, short_options, long_options, NULL);

		switch(next_option)
		{
			case 'h':
				usage(stdout, 0);
				break;
			case 'l':
				load(optarg);
				break;
			case '?':
				usage(stderr, 1);
				break;
			case ':':
				usage(stderr, 2);
				break;
			case -1:
				break;
			default:
				fprintf(stdout, "Aborting...");
				abort();
		}

	} while(next_option != -1);

	if(argc == 1)
		usage(stdout, 0);

}
