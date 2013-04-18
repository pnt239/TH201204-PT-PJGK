#include "CSV.h"

int initCSV(RAW_CSV &csv, char *fpath)
{
	int LINE_COUNT =0;

	FILE *f = fopen(fpath, "rt");
	if(f != NULL) return -1;

	while(fgetc(f) != EOF)
	{
		if(fgetc(f) == '\n')
			LINE_COUNT++;
	}											/* Dem so dong trong file */
	csv= new char*[LINE_COUNT + 1];			/* Cap phat dong cho mang csv */
	int i=0;
	while(!feof(f))
		{
			fgets(csv[i],10000,f);
			i++;
		}
		csv[i]=NULL;
	fclose(f);
}