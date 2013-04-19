#include "stringex.h"

char** strsplit(char *str, char *delim, bool csv)
{
	char **ret;
	int n=strlen(delim);
	int i=0;
	int count_delim=0;
	while(str[i] != NULL)
	{
		for(int j=0;j<n;j++)
		{
			if(str[i]==delim[j])
				count_delim++;
		}
		i++;
	}		//Dem so luong phan tu con cua delim trong str
	ret= new char*[count_delim+1];
	char *pch= strtok(str,delim);
	i=0;
	while(pch != NULL)
	{
		ret[i]=pch;
		i++;
		pch=strtok(NULL,delim);
	}
	ret[i]=NULL;
	return ret;
}

char** explode(char *str, char *delim)
{
	char **ret = new char*[2];
	char *substr = strstr(str, delim);
	if (substr == NULL) {
		ret[0] = new char[strlen(str)+1];
		strcpy(ret[0], str);
		ret[1] = NULL;
	} else {
		int iCountChar = substr - str; // Lay so ky tu cua chuoi truoc delim
		int iLenDelim = strlen(delim);

		/* Gan xau truoc delim vao phan tu 0 */
		ret[0] = new char[iCountChar+1];
		strncpy(ret[0], str, iCountChar);
		ret[0][iCountChar] = 0;

		/* Gan xau truoc delim vao phan tu 0 */
		ret[1] = substr + iLenDelim; // Lay chuoi con lai
	}
	return ret;
}

char* strtripws(char *str, int flag)
{
	char *ret;

	return ret;
}

char* strbetween(char *str, char begin, char end)
{
	char *ret;

	return ret;
}

void strreplace(char *str, char *rep)
{
	return;
}