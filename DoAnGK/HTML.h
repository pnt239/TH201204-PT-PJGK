/**
* Chua cac ham xu ly html va tao xuat thong tin sinh vien ra file html
**/

#pragma once

#include <io.h>
#include <stdio.h>
#include <malloc.h>

#define BSIZE 1024

typedef FILE *HTML;

/**
* Kiem tra xem file co ton tai hay khong
* Tham so: path  - duong dan file can kiem tra
* Tra ve : true  - co ton tai
*		   false - khong ton tai
**/
bool fexists(char *path);
int fcopy(char *src, char *des);

HTML html_create(char *filename);
void html_close(HTML &html);

void html_header(HTML html, char *title);
void html_footer(HTML html, char *groupname);

void html_body_navigation(HTML html);
void html_body_content(HTML html, int level);
void html_body_content_header(HTML html, char *title, char *subtitle, int level);

void html_idxlist_begin(HTML html);
void html_idxlist_end(HTML html);
void html_idxlist_element(HTML html, char *mssv, char *name, char *year);

void html_body_content_pesonal(HTML html);

void html_create_listview(HTML html);
