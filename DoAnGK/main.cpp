#include "CSV.h"
#include "stringex.h"

int main(int argc,char **argv)
{
	RAW_CSV raw_data;
	// Load du lieu tho
	if (initCSV(raw_data, "data.csv") == -1) {
		printf("Khong the lay du lieu duoc\n");
		return -1;
	}
	
	// Giai phong du lieu tho
	freeCSV(raw_data);
	return 0;
}