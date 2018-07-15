/*
 * Print the longest line.
 */

#include <stdio.h>

#define EARGS -1	/* error on command line */ 
#define EFILE -2	/* error on file */

#define MAXSIZE 1000

int max; 			/* maximum length seen so far */
char line[MAXSIZE];	/* current line */
char longest[MAXSIZE];	/* longest line saved here */ 

int getline(FILE *fs);
void copy(void);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Error: Not enough parameters!\n");
		return EARGS;
	}
	
	FILE *fs = fopen(argv[1], "r");
	if (!fs)
		return EFILE;
	
	int len;
	extern int max;
	extern char longest[];
	
	max = 0;
	while ((len = getline(fs)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy();
		}
	}
	
	fclose(fs);
	
	if (max > 0)	/* there was a line */
		printf("%s", longest);
	
	return 0;
}

int getline(FILE *fs)
{
	int c, j;
	extern char line[];
	
	for (j = 0; j < MAXSIZE-1 && (c = fgetc(fs)) != EOF && c != '\n'; ++j)
		line[j] = c;
	
	if (c == '\n')
		line[j++] = c;
	
	line[j] = '\0';
	
	return j;
}

void copy()
{
	int j;
	extern char line[], longest[];
	
	j = 0;
	while ((longest[j] = line[j]) != '\0')
		++j;
}