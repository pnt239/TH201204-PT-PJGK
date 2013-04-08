/**
* Chua cac ham xu lu dieu lieu cua sinh vien
**/

#pragma once

#include "CSV.h"

// Struct chua thong tin cua 1 sinh vien
typedef struct SD
{
	char MSSV[10];		// Ma so sinh vien, toi da 10 kt
	char HoTen[30];		// Ho va ten sinh vien, to da 30 kt
	char Khoa[30];		// Khoa, toi da 30 kt
	int Nam;			// Kho'a
	char BirthD[11];	// Ngay sinh theo dinh dang dd/mm/yyyy
	char smallImg[255];	// Anh dai dien co nho, toi da 255 kt
	char bigImg[255];	// Anh dai dien co lon, toi da 255 kt
	char *FriendList;	// Danh sach ban be, toi da 50 ban
	char *Description;	// Mo ta ban than, toi da 1000 kt
	char *Hobby;		// So thich ca nhan, toi da 100 kt
} STUDENT;

/**
* Tao mot con tro kieu STUDENT.
* Muc dich: dung de cap phat dong tao ra mot mang 1 chieu cac phan tu STUDENT. 
* Tuc dung de luu tru thong tin cua n sinh vien vao mang 1 chieu
**/
typedef STUDENT *ST; 

/**
* Tham so:	csv - Du lieu tho^ lay tu file csv
*			st	- Luu thong tin cac sinh vien lay tu du lien to
* Tra ve: Du lien tho^ ban dau se duoc chuan hoa thanh du lieu kieu struct de tien trong viec xu ly ve sau
**/
void convertRAWtoST(RAW_CSV csv, ST &st);