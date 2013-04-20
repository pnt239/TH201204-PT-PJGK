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

// For All
void html_build_list(HTML html, char **list);

// For index file
void html_idxlist_begin(HTML html);
void html_idxlist_end(HTML html);
void html_idxlist_element(HTML html, char *mssv, char *name, char *year);

// For Member file
void html_content_pesonal_begin(HTML html, char *mssv, char *birth, char *year, char **des, char **hobby);
void html_listview_begin(HTML html);
void html_listview_item(HTML html, char *mssv, char *name, char *year);
void html_listview_end(HTML html);
void html_content_pesonal_end(HTML html);
