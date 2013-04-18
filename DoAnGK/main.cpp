#include "CSV.h"

void main(int argc,char **argv)
{
	RAW_CSV raw_data;
	printf("%d\n", initCSV(raw_data, "data.csv"));
}