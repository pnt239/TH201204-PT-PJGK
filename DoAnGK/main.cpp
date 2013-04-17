#include <stdio.h>
#include <string.h>

void main(int argc,char **argv)
{
	//test
	if(argc<3)
		printf("Usage:generate-html.exe FilePath<CSV> Path-<result>");
	/* thong so ham main su dung: 
	1.ten chuong trinh
	2.duong dan toi file CSV
	3.duong dan toi thu muc ket qua
	*/
	else
	{
	char s[1024];
	FILE *f = fopen(argv[1], "rt"); //Lay file CSV
	while (!feof(f)) {
	fgets(s, 1024, f);

	char *word = strtok(s, ",");
	while (word != NULL) {
		printf("%s\n", word);
		word = strtok(NULL, ",");
	}
	}
	fclose(f);
	}
}