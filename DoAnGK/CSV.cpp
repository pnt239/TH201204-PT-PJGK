#include "CSV.h"

void initCSV(RAW_CSV &csv, char *fpath)
{
	FILE *f = fopen(fpath, "rt");
	int count_EOLINE=0;
	if(f != NULL)
	{
		while(fgetc(f) != EOF)
		{
			if(fgetc(f) == '\n')
				count_EOLINE++;
		}
	}											/* Dem so dong trong file */
	csv= new char*[count_EOLINE + 1];			/* Cap phat dong cho mang csv */
	int i=0;
	while(!feof(f))
		{
			fgets(csv[i],10000,f);
			i++;
		}
		csv[i]=NULL;
	fclose(f);
}