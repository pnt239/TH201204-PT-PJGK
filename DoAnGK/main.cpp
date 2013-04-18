#include "CSV.h"
#include "stringex.h"

int main(int argc,char **argv)
{
	//RAW_CSV raw_data;
	//printf("%d\n", initCSV(raw_data, "data.csv"));
	char str[] ="Pham, Ngoc Thanh";
	char **s = explode(str, ", ");
	printf("%s'\n%s'\n", s[0], s[1]);

	delete s[0];
	delete s[1];
	delete s;

	return 0;
}