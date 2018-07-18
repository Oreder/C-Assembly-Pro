/*
 * itob() implementation
 * Author: Binh D. Nguyen
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 3-5, page 64
 *
 * Write the function itob(n, s, b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n, s, 16) formats n as a hexadecimal integer in s.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EARGS -1	/* error on command line */ 

void itob(int, char *, int);
void reverse(char *);

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("Error: Not enough parameters!\n");
		return EARGS;
	}
	
    int value = atoi(argv[1]);
	int base = atoi(argv[2]);
    char s[64];
	
	itob(value, s, base);
    printf("Result: %s\n", s);

    return EXIT_SUCCESS;
}

/* itob:  comvert n into string s in base b */
void itob(int n, char s[], int b)
{
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    if (b < 2 || b > strlen(symbols))
        return;     /* not a valid base */
    
    int sign = n, i = 0;
    
	do		/* generate symbols in reverse order */
	{            
		s[i++] = symbols[abs(n % b)];	/* get next symbols */
    } while (n /= b);					/* remove it */
    
	if (sign < 0)
		s[i++] = '-';
    s[i] = '\0';
    
	reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{	
	for (int i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}