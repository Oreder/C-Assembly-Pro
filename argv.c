/*
 * Amazing statement with printf
 */
 
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	while (--argc)
		printf((argc > 1)? "%s " : "%s\n", *++argv);
	return 0;
}