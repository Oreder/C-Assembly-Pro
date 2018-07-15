/*
 * Counting the number of occurrences of each letter, of each digit, 
 * of white space character (blank, tab, newline), and of all other
 * characters.
 */

#include <stdio.h>

#define EARGS -1	/* error on command line */ 
#define EFILE -2	/* error on file */

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
	
	int c;
	int nLetter[26];
	int nDigit[10];
	int nWhite, nOther;
	
	for (int j = 0; j < 26; ++j)
	{
		nLetter[j] = 0;
		if (j < 10)
			nDigit[j] = 0;
	}
	
	nWhite = nOther = 0;
	
	while ((c = fgetc(fs)) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			++nLetter[c - 'a'];
		else if (c >= 'A' && c <= 'Z')
			++nLetter[c - 'A'];
		else if (c >= '0' && c <= '9')
			++nDigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nWhite;
		else
			++nOther;
	}
	
	fclose(fs);
	
	printf("Result:\n\n1. Letters:\n");
	for (int j = 0; j < 26; ++j)
		printf("\t%c: %d\n", 'a' + j, nLetter[j]);
	printf("\n2. Digits:");
	for (int j = 0; j < 10; ++j)
		printf(" %d", nDigit[j]);
	printf("\n3. White space: %d\n4. Other: %d\n", nWhite, nOther);
	
	return 0;
}