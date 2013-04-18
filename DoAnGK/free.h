#pragma once

#include <stdio.h>
#include "CSV.h"

/**
* Lay phan tu thu 2 trong explode, giai phong bo nho explode (4byte)
* Tham so: exp - con tro cua ham explode tra ve
* Tra ve: xau cua phan tu thu 2
*
* VD: char **temp = explode("Hello,World", ",");
* char *temp1 = freeExplode(temp);
* -> temp1 == "World"
**/
char *freeExplode(char **exp);

/** 
* Giai phong bo nho do RAW_CSV tao ra
* Tham so: csv - du lieu csv truyen vao
**/
void freeRAWCSV(RAW_CSV &csv);