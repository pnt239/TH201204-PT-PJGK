#include "stringex.h"

char** strsplit(char *str, char *delim)
{
	char **ret = NULL;
	// Do so phan tu
	int elem_count = 1, slen = strlen(str);
	char *temp = strstr(str, delim), *ltemp;
	for (int i = 0; temp != NULL; i++, elem_count++) {
		temp = temp + 1;
		temp = strstr(temp, delim);
	}
	
	ret = new char*[elem_count+1];
	ret[elem_count] = NULL;
	temp = str;
	for (int i = 0; i < elem_count; i++)
	{
		ltemp = temp;
		temp = strstr(temp, delim);
		if (temp == NULL) {
			ret[i] = ltemp;
			continue;
		}
		int elen = temp - ltemp;
		ret[i] = new char[elen+1];
		for (int j = 0; j < elen; j++) ret[i][j] = ltemp[j];
		ret[i][elen] = 0;
		temp++;
	}
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
void strtripws1(char *str,char *&ret)
{
	
	int slen=strlen(str);

	for(int i=0;i<slen;i++)
	{
		if(str[i]!= ' ')
		{
			int temp=slen-i;
			for(int j=0;j<temp;j++)
			{
				ret[j]=str[i];
				i++;
			}
			ret[temp]='\0';
			break;
		}
	}
	
}
void strtripws2(char *str,char *&ret)
{
	
	int slen=strlen(str);
	int j=0;
	for(int i=slen-1;i>=0;i--)
	{
		if(str[i]!= ' ')
		{
			for(j=0;j<=i;j++)
				ret[j]=str[j];				
			ret[j]='\0';
			break;
		}
	}

}
char* strtripws(char *str, int flag)
{
	char *ret;
	int slen=strlen(str);
	ret=new char[slen];
	if(flag==1)
		strtripws1(str,ret);
	else if(flag==2)
		strtripws2(str,ret);
	else if(flag==3)
	{
		strtripws1(str,ret);
		strtripws2(ret,ret);
	}
	return ret;
}

char* strbetween(char *str, char begin, char end)
{
	char *ret = NULL;

	bool start = false;
	int slen = strlen(str), chr = 0;

	ret = new char[slen];
	ret[0] = 0;

	for (int i = 0; i < slen; i++)
	{
		if (str[i] == begin && !start) {
			start = true;
		} else if (str[i] == end && start) {
			ret[chr] = 0;
		} else {
			if (start) {
				ret[chr] = str[i];
				chr++;
			}
		}
	}
	if (ret[0] == 0) strcpy(ret, str);
	return ret;
}