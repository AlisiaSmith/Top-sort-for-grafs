#include "Header.h"

void errors(int k)
{
	switch (k)
	{
	case 0:
		fprintf(stdout, "%s", "bad number of vertices");
		break;
	case 1:
		fprintf(stdout, "%s", "bad number of edges");
		break;
	case 2:
		fprintf(stdout, "%s", "bad vertex");
		break;
	case 3:
		fprintf(stdout, "%s", "bad number of lines");
		break;
	case 4:
		fprintf(stdout, "%s", "impossible to sort");
		break;
	}
	exit(0);
}

void verify_values(int n, int m)
{
	if ((n < 0) || (n > 1000))				errors(BNV);
	if ((m < 0) || (m > n*(n + 1) / 2))		errors(BNE);
}

void verify_include(int n, int v)
{
	if ((v < 1) || (v > n))					errors(BV);
}

void verify_sort(elem *graf, int num)
{
	for (int i = 0; i < num; i++)
		if (graf[i].color != BLACK)
			errors(ITS);
}