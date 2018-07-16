/*
 * htoi() implementation
 * Author: Binh D. Nguyen
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Exercise 2-3, page 46
 *
 * Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 * 
 */

#include <stdio.h>
#include <assert.h>
#define MAXSIZE 256

int htoi(const char *);

int main(int argc, char *argv[])
{
	char hex[MAXSIZE];
	
	int c, i = 0;
	while ((c = getchar()) != '\n')
		hex[i++] = c;
	hex[i] = '\0';
	
	printf("%s: %d\n", hex, htoi(hex));
	return 0;
}

int htoi(const char *hex)
{
	/* check validity of given string */
	assert(hex[0] == '0');
	assert(hex[1] == 'x' || hex[1] == 'X');
	
	int value = 0;
	for (int j = 2; hex[j] != '\0'; ++j)
	{
		/* check validity of each hex-digit */
		assert(
			(hex[j] >= '0' && hex[j] <= '9') || 
			(hex[j] >= 'a' && hex[j] <= 'f') ||
			(hex[j] >= 'A' && hex[j] <= 'F')
		);
		
		value *= 16;
		
		if (hex[j] >= '0' && hex[j] <= '9')
			value += hex[j] - '0';
		else if (hex[j] >= 'a' && hex[j] <= 'f')
			value += hex[j] - 'a' + 10;
		else
			value += hex[j] - 'A' + 10;
	}
	
	return value;
}