#include "free.h"

char *freeExplode(char **exp)
{
	char *ret = NULL;
	ret = exp[1];
	delete exp;
	return ret;
}

void freeRAWCSV(RAW_CSV &csv)
{
	delete[] csv;
}