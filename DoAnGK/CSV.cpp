#include "CSV.h"

int initCSV(RAW_CSV &csv, char *fpath)
{
	/* max_numchar : so ky tu ma dong dai nhat co */
	int line_count = 1, i = 0, cur_numchar = 0, max_numchar = 0;
	char ctemp;

	FILE *f = fopen(fpath, "rt");
	if(f == NULL) return -1;

	/* Dem so dong trong file */
	while(!feof(f)) {
		ctemp = fgetc(f);
		if(ctemp == '\n') {
			line_count++;
			if (cur_numchar > max_numchar) max_numchar = cur_numchar;
			cur_numchar = 0;
		} else {
			cur_numchar++;
		}
	}
	if (cur_numchar > max_numchar) max_numchar = cur_numchar;
	/* Tra ve vi tri dau file */
	fseek(f, 0, SEEK_SET);
	/* Cap phat dong cho mang csv */								
	csv = new char*[line_count + 1];

	while(!feof(f))
	{
		csv[i] = new char[max_numchar];
		fgets(csv[i], max_numchar, f);
		i++;
	}

	csv[i-1]=NULL;

	fclose(f);
	return 0;
}

int freeCSV(RAW_CSV &csv)
{
	for (int i = 0; csv[i] != NULL; i++)
		delete csv[i];
	delete csv;
	return 0;
}