#include "CSV.h"
#include "student.h"
#include "stringex.h"

int main(int argc,char **argv)
{
	RAW_CSV raw_data;
	STS st;
	// Load du lieu tho
	if (initCSV(raw_data, "data.csv") == -1) {
		printf("Khong the lay du lieu duoc\n");
		return -1;
	}
	// Xy ly du lieu tho
	convertRAWtoST(raw_data, st);

	// Giai phong du lieu tho
	freeST(st);
	freeCSV(raw_data);
	return 0;
}