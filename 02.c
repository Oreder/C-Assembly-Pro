/*
 * Character counting
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	long nc = 0;
	
	while (getchar() != '\n')
		++nc;
	
	printf("Total: %ld.\n", nc);
	return 0;
}