#include <stdio.h>
#include <string.h>

void main()
{
	char s[1024];
	FILE *f = fopen("data.csv", "rt");
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