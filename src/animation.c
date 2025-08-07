#include "../include/animation.h"

int init(long version)
{

	fprintf(stdout, "Initiated library!\n");
	
	//Versioning
	unsigned char major = (version & 0xff0000) >> 16;
	unsigned char minor = (version & 0x00ff00) >> 8;
	unsigned char patch = version & 0x0000ff;

	fprintf(stdout, "Current version: %d.%d.%d\n", major, minor, patch);

	//Initiating ( TODO )

	return 0;

}
