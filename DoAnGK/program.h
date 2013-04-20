#pragma once

#include "stringex.h"
#include "HTML.h"
#include "student.h"
#include "CSV.h"

#define FILE_DATA "data.csv"
#define MAX_ARG 3

/**
* Hien thi log
**/
void log(char *local, char *content);

/**
* Hien thi giup do
*
**/
void showHelp();

/**
* Copy file anh o thu muc data sang tu muc result
* Tham so: sts     - Danh sach sinh vien
*		   inpath  - Duong dan thu muc 'data'
*		   outpath - Duong dan thu muc 'result'
* Tra ve : khong co gia tri tra ve
**/
void prepareImage(STS sts, char *inpath, char *outpath);

/**
* Load du lieu nhap vao
* Tham so : argc, argv lay tu ham main
*			raw_data : mang de luu du lieu tho (khai bao truoc)
*			sts		 : mang luu thong tin sinh vien lay tu du lieu tho.
* Tra ve  : 0 - Khong co loi.
*			1 - Du lieu nhap vao khong hop le.
*			2 - Khong the load du lieu.
**/
int initProgram(int argc,char *argv[], RAW_CSV &raw_data, STS &sts, char *&inpath, char *&outpath);

/**
* Tao file index.html
**/
void createIndex(STS sts, char *outpath);

/**
* Tao file <MSSV>.html
**/
void createSVPage(HTML html, STS sts, int i);
void createSVS(STS sts, char *outpath);

/**
* Chay chuong trinh 
* Tham so: argc - so tham so dua vao chuong trinh
*		   argv - mang tham so dua vao
* Tra ve: 0 - chuong trinh khong co loi
*		  -1 - chuong trinh xa ra ra loi
**/
int run(int argc,char *argv[]);
