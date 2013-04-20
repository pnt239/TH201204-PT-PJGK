#include "HTML.h"

bool fexists(char *path)
{
	if (_access(path, 0) != -1)
		return true;
	else 
		return false;
}

int fcopy(char *src, char *des)
{
	// Mo file de doc
	FILE* pIn = fopen(src, "rb");
	if (pIn == NULL) return 1;

	// Mo file de ghi
	FILE* pOut = fopen(des, "wb");
	if (pOut == NULL) return 2;

	// Buffer cho moi lan doc
	char* buffer = (char*)malloc(sizeof(char)*BSIZE);
	int nBytes;

	// Doc 1 lan BSIZE bytes (char) tu pIn
	while ((nBytes = fread(buffer, sizeof(char), BSIZE, pIn)) > 0) {
		// Ghi so byte doc duoc (nBytes) trong buffer xuong pOut
		fwrite(buffer, sizeof(char), nBytes, pOut);
	}
	fclose(pIn);
	fclose(pOut);
	free(buffer);
}

HTML html_create(char *filename)
{
	HTML html = fopen(filename, "wb");
	if (html == NULL)
		return NULL;
	
	return html;
}

void html_close(HTML &html)
{
	fprintf(html, "</body></html>");
	fclose(html);
}

void html_header(HTML html, char *title)
{
	fprintf(html, "<!DOCTYPE html>");
	fprintf(html, "<html xmlns=\"http://www.w3.org/1999/html\">");
	fprintf(html, "<head>");
    fprintf(html, "<meta charset=\"utf-8\">");
    fprintf(html, "<meta name=\"viewport\" content=\"target-densitydpi=device-dpi, width=device-width, initial-scale=1.0, maximum-scale=1\">");
    fprintf(html, "<meta name=\"description\" content=\"HCMUS Students\">");
    fprintf(html, "<!-- Thong tin -->");
    fprintf(html, "<meta name=\"Pham Ngoc Thanh, Nguyen Nhu Quang, Phan Song Nui\" content=\"HungryBirds\">");
    fprintf(html, "<link href=\"./static/css/modern.css\" rel=\"stylesheet\">");
    fprintf(html, "<link href=\"./static/css/modern-responsive.css\" rel=\"stylesheet\">");
    fprintf(html, "<link href=\"./static/css/site.css\" rel=\"stylesheet\">");

    fprintf(html, "<script type=\"text/javascript\" src=\"./static/javascript/jquery.js\"></script>");
    fprintf(html, "<script type=\"text/javascript\" src=\"./static/javascript/dropdown.js\"></script>");

    fprintf(html, "<title>%s</title>", title);
	fprintf(html, "</head><body class=\"metrouicss\">");
}

void html_footer(HTML html, char *groupname)
{
	fprintf(html, "</div><!-- Footer -->");
    fprintf(html, "<div class=\"page\">");
    fprintf(html, "<div class=\"nav-bar\" id=\"footer\">");
    fprintf(html, "<div class=\"nav-bar-inner padding10\">");
    fprintf(html, "<span class=\"element\">");
    fprintf(html, "<!-- Thêm thông tin -->");
    fprintf(html, "2013 &copy; %s - Styled with <a class=\"fg-color-white\" href=\"http://metroui.org.ua\">Metro UI CSS</a>", groupname);
    fprintf(html, "</span>");
    fprintf(html, "</div>");
    fprintf(html, "</div>");
    fprintf(html, "</div>");
}

void html_body_navigation(HTML html)
{
	fprintf(html, "<!-- Navigation -->");
    fprintf(html, "<div class=\"page\">");
    fprintf(html, "<div class=\"nav-bar\" id=\"header\">");
    fprintf(html, "<div class=\"nav-bar-inner padding10\">");
    fprintf(html, "<span class=\"pull-menu\"></span>");
    fprintf(html, "<a href=\"index.html\">");
    fprintf(html, "<img class=\"place-left\" src=\"./static/images/logo.png\" alt=\"HCMUS\">");
    fprintf(html, "<span class=\"element brand\">HCMUS Students</span>");
    fprintf(html, "</a>");
    fprintf(html, "<div class=\"divider\"></div>");
    fprintf(html, "<ul class=\"menu\">");
    fprintf(html, "<li><a href=\"index.html\"><i class=\"icon-home\"></i>Home</a></li>");
    fprintf(html, "</ul>");
    fprintf(html, "</div>");
    fprintf(html, "</div>");
    fprintf(html, "</div>");
}

void html_body_content(HTML html, int level)
{
	if (level == 1)
		fprintf(html, "<div class=\"page\">");
	else
		fprintf(html, "<div class=\"page secondary\">");
}

void html_body_content_header(HTML html, char *title, char *subtitle, int level)
{
	fprintf(html, "<!-- Header --><div class=\"page-header\"><div class=\"page-header-content\">");
	if (level == 1)
		fprintf(html, "<h1>Students</h1>");
	else {
		fprintf(html, "<h1>%s<small>%s</small></h1>", title, subtitle);
        fprintf(html, "<a href=\"index.html\" class=\"back-button big page-back\"></a>");
	}
	fprintf(html, "</div></div>");
}

void html_idxlist_begin(HTML html)
{
	fprintf(html, "<div class=\"page-region\"><div class=\"page-region-content\"><ul class=\"listview fluid\">");
}

void html_idxlist_end(HTML html) 
{
	fprintf(html, "</ul></div></div>");
}

void html_idxlist_element(HTML html, char *mssv, char *name, char *year)
{
	fprintf(html, "<li>");
    fprintf(html, "<a href=\"%s.html\">", mssv);
    fprintf(html, "<div class=\"icon\">");
    fprintf(html, "<img src=\"./images/%s_t.jpg\" alt=\"%s\">", mssv, mssv);
    fprintf(html, "</div>");
    fprintf(html, "<div class=\"data\">");
    fprintf(html, "<h4>%s</h4>", name);
    fprintf(html, "<!-- Khoa - Khoa hoc -->");
    fprintf(html, "<p>FIT %s</p>", year);
    fprintf(html, "</div>");
    fprintf(html, "</a>");
    fprintf(html, "</li>");
}