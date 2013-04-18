/**
* Chua cac ham xu lu file csv
**/

#pragma once

#include <stdio.h>

/**
* Mang 1 chieu kieu xau
*/
typedef char **RAW_CSV;

/*
* Tham so:	csv   - kieu RAW_CSV de luu thong tin tu file csv
*			fpath - duong dan den file csv can doc
* Tra ve :	-1: khong the doc du lieu.
*			 0: Qua trinh load file thanh cong.
*			 Dong thoi, moi du lieu doc duoc se luu vao bien csv
* Vi du: file raw:
* line 1. hello
* line 2. world
*	->  csv[0] == "hello"
*		csv[1] == "world"
*		csv[2] == NULL
*	mang tra phai co <so dong> + 1 phan tu va phan tu cuoi cung gan gia tri NULL, de tien trong qua trinh xu ly
*	khong phai khoi tao them bien n de lay so luong phan tu
* 
*/
int initCSV(RAW_CSV &csv, char *fpath);