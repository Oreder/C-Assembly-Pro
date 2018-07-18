/*
 * Quick sort, applying for array of int/real numbers.
 * Author: Binh D. Nguyen
 */
 
/* icmp: compare 2 integer */
int icmp(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;
	return *a < *b;
}

/* rcmp: compare 2 real numbers */
int rcmp(const void *p, const void *q)
{
	const double *a = p;
	const double *b = q;
	return *a < *b;
}
 
/* iswap: exchanges 2 integer elements by given position */
void iswap(int *array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/* rswap: exchanges 2 double elements by given position */
void rswap(double *array, int i, int j)
{
	double tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/* qsort: sort v[left] .. v[right] into increasing order */
void qsort(void *s, int left, int right, int (*cmp)(const void *, const void *))
{
	if (left >= right)
		return;
	
	int *v = (int *)s;	// casting pointer type, set (double *) in case of real numbers
	int pivot = left;
	int i = left;
	int j = right;
	
	while (i < j)
	{
		// increment i until we get a number greater than the pivot element
		while (cmp(&v[i], &v[pivot]) > 0 && i <= right)
			++i;
		
		// decrement j until we get a number less than the pivot element
		while (cmp(&v[pivot], &v[j]) > 0 && j >= left)
			--j;
		
		// if i < j then swap those elements
		if (i < j)
			iswap(v, i, j);
	}
	
	// when i >= j that means the j-th position is the correct position
	// of the pivot element, hence swap the pivot element with the j-th element
	iswap(v, j, pivot);
	
	// Recursion
	qsort(s, left, j-1, cmp);
	qsort(s, j+1, right, cmp);
}