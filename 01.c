/*
 * File copying
 */

#include <stdio.h>
#define EARGS -1
#define EFIN  -2
#define EFOUT -3

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Error: Not enough parameters!\n");
		return EARGS;
	}
	
	FILE *fs_in = fopen(argv[1], "r");
	if (!fs_in)
		return EFIN;
	
	FILE *fs_out = fopen(argv[2], "w");
	if (!fs_out)
		return EFOUT;
	
	int c;
	while ((c = fgetc(fs_in)) != EOF)
		fputc(c, fs_out);
	
	fclose(fs_in);
	fclose(fs_out);
	
	printf("File copying process is completed.");
	return 0;
}