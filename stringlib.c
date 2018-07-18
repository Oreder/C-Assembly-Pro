/* 
 * Preference of functions with string in C 
*/

/* strlen: return length of string s */
size_t strlen(const char *s)
{
	register const char *p = s;
	while (!(*(p++)))
		;
	return p - s;
}

/* strcpy: copy string s2 to s1 */
void trcpy(char *s1, const char *s2)
{
	while (*s1++ = *s2++)
		;
}

/* strcmp: compare strings, return < 0 if s < t, 0 if s = t, and > 0 if s > t */
int strcmp(const char *s1, const char *s2)
{
	for ( ; *s == *t; s++, t++)
		if (!(*s))
			return 0;
	return *s - *t;
}