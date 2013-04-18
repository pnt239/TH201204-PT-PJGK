#include "CSV.h"
#include "stringex.h"
#include "free.h"

int main(int argc,char **argv)
{
	RAW_CSV raw_data;
	if (initCSV(raw_data, "data.csv") == -1) {
		printf("Khong the lay du lieu duoc\n");
		return -1;
	}
	
	for(int i=0; raw_data[i] != NULL; i++)
        delete[] raw_data[i];
    delete[] raw_data; 
	return 0;
}