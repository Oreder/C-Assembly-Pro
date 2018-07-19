/*
 *	Swap using bit operators
 */
#include <stdio.h>

int main()
{
	int a = 5, b = -1;
	void swap(int *, int *);

	swap(&a, &b);
	printf("%d : %d\n", a, b);
	return 0;
}

void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}