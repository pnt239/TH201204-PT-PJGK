/**
* Chua cac ham xu lu chuoi mo rong
**/

#pragma once

#include <string.h>

/**
* Cat chuoi theo ky tu phan cach. Tuong tu nhu strtok. Nhung tra ve 1 mang kieu chuoi chua cac chuoi duoc cat ra
* Thong so: str   - Chuoi can cat
*			delim - Chuoi chua cac ky tu phan cach
* Tra ve : mang cac chuoi duoc cat ra
* Vi du: 
* char *str = "hello,world";
* char **split = strsplit(str, ",");
* -> split[0] == "hello"
*	 split[1] == "world"
*	 split[2] == NULL
*	mang tra phai co <so phan tu thu te> + 1 phan tu va phan tu cuoi cung gan gia tri NULL, de tien trong qua trinh xu ly
*	khong phai khoi tao them bien n de lay so luong phan tu
**/
char** strsplit(char *str, char *delim);

/**
* Xoa cac khoang trang trong chuoi, theo flag cho truoc
* Thong so: str  - chuoi can xoa
*			flag - thiet lap xoa
*				1 - xoa cac khoang trang dau dong
*				2 - xoa ca khoang trang cuoi dong
* Tra ve: 1 chuoi da duoc xoa cac khoang trang theo yeu cau
* Vi du:
* char *str = "  hello world  ";
* char *ret = strtripws(str, 3);
* -> ret == "hello world"
**/
char* strtripws(char *str, int flag);

/**
* Lay chuoi o giua ky tu begin va end
* Tham so:  str	  - chuoi can lay
*			begin - ky tu mo dau
*			end	  - ky tu ket thuc
* Tra ve: mot chuoi giua ky tu begin va ky tu end
* Vi du: 
* char *str = "hello <world> ";
* char *ret = strbetween(str, '<', '>');
* -> ret == "world"
**/
char* strbetween(char *str, char begin, char end);