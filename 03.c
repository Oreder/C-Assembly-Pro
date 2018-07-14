/*
 * Counting lines, words, and character
 */

#include <stdio.h>

#define EARGS -1	/* error on command line */ 
#define EFILE -2	/* error on file */

#define IN  1	/*  inside a word */
#define OUT 0	/* outside a word */

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
	
	int c, nLine, nWord, nChar, state;
	
	state = OUT;
	nLine = nWord = nChar = 0;
	
	while ((c = fgetc(fs)) != EOF)
	{
		++nChar;
		
		if (c == '\n')
			++nLine;
		
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nWord;
		}
	}
	
	++nLine;	/* the last line does not contain an endline syntax (bug was found and fixed)*/
	fclose(fs);
	
	printf("Line count: %d\nWord count: %d\nChar count: %d\n", nLine, nWord, nChar);
	return 0;
}