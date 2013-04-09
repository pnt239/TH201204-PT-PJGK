/**
* Chua cac ham xu ly html va tao xuat thong tin sinh vien ra file html
**/

#pragma once

#include <stdio.h>

#typedef FILE *HTML;

HTML html_create(char *filename);

void html_header(HTML html, char *title);
void html_footer(HTML html);

void html_body_navigation(HTML html);
void html_body_header(HTML html, int level);

void html_body_content_list(HTML html);
void html_body_content_pesonal(HTML html);

void html_create_listview(HTML html);
