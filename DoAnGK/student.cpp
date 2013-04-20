#include "student.h"

void convertRAWtoST(RAW_CSV csv, STS &st)
{
	int iNumST = 0;
	char **sTemp = NULL;
	/* Lay so luong sinh vien */
	for (int i = 0; csv[i] != NULL; i++) iNumST++;
	/* Cap phat danh sach sinh vien */
	st = new ST[iNumST+1];
	for (int i = 0; csv[i] != NULL; i++)
	{
		st[i] = new STUDENT;
		// Lay MSSV
		sTemp = explode(csv[i], ",");
		st[i]->MSSV = sTemp[0];
		// Lay Ho va Ten
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->HoTen = sTemp[0];
		// Lay Khoa
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->Khoa = sTemp[0];
		// Lay Kho'a
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->Nam = atoi(sTemp[0]);
		// Lay Ngay sinh
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->BirthD = sTemp[0];
		// Lay Avatar nho
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->smallImg = sTemp[0];
		// Lay Avatar lon
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->bigImg = sTemp[0];
		// Lay Danh sach ban be
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->FriendList = sTemp[0];
		// Lay Mo ta
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->Description = sTemp[0];
		// Lay So thich
		sTemp = explode(freeExplode(sTemp), ",");
		st[i]->Hobby = sTemp[0];
	}
	st[iNumST] = NULL;
}

void freeST(STS &st) {
	for (int i = 0; st[i] != NULL; i++)
		delete st[i];
	delete st;
}
