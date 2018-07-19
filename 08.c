#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files */
int main(int argc, char *argv[])
{
	FILE *fp;
	void fcopy(FILE *, FILE *);
	char *prog = argv[0];
	
	if (argc == 1)
		fcopy(stdin, stdout);
	else
	{
		while (--argc)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else
			{
				fcopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	
	if (ferror(stdout))
	{
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	return 0;
}

void fcopy(FILE *ifp, FILE *ofp)
{
	int c;
	while ((c = fgetc(ifp)) != EOF)
		fputc(c, ofp);
}