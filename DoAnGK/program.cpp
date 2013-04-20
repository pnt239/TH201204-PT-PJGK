#include "program.h"

int run(int argc,char *argv[])
{
	char  *_IN_PATH, *_OUT_PATH;

	RAW_CSV raw_data;
	STS sts;

	// Lay du lieu dua vao chuong trinh
	int error = initProgram(argc, argv, raw_data, sts, _IN_PATH, _OUT_PATH);
	if (error == 1) {
		printf("Thong tin nhap vao khong hop le!\nDung lenh 'buildinfo -h' de xem huong dan\n");
		return error;
	} else if (error == 2) {
		printf("Qua trinh nap du lieu that bai! Vui long kiem tra lai thong tin nhap vao...\n");
		return error;
	}
	
	log("buildinfo", "Chuan bi tao file 'index.html'...");
	createIndex(sts, _OUT_PATH);
	log("buildinfo", "Da tao file 'index.html' thanh cong...");

	log("buildinfo", "Chuan bi xuat file thong tin cac sinh vien...");
	createSVS(sts, _OUT_PATH);
	log("buildinfo", "Qua trinh hoan tat...");

	// Giai phong du lieu tho
	freeST(sts);
	freeCSV(raw_data);
	return 0;
}

int initProgram(int argc,char *argv[], RAW_CSV &raw_data, STS &sts, char *&inpath, char *&outpath)
{
	if (argc == 1) {
		// Show help
		showHelp();
		return 0;
	} else if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0) {
			showHelp();
			return 0;
		}
	}
	if (argc < 3 || argc > MAX_ARG) return 1;
	// Lay tham so nhap vao
	inpath = argv[1];
	outpath = argv[argc-1];
	
	// Lay du lieu tu tham so nhap vao
	// Load du lieu tho
	char *filedata = new char[strlen(inpath)+strlen(FILE_DATA)+2];
	sprintf(filedata, "%s/%s", inpath, FILE_DATA);

	if (initCSV(raw_data, filedata) == -1) {
		printf("Khong the lay du lieu duoc\n");
		return 2;
	}
	// Xy ly du lieu tho
	convertRAWtoST(raw_data, sts);

	// Chuan bi file anh
	prepareImage(sts, inpath, outpath);
	delete filedata;
}

void showHelp()
{
	printf("Do an GK Ky Thuat Lap Trinh - HKII - 2013\n");
	printf("Chuong trinh tu dong phat sinh trang HTML gioi thieu thanh vien cua lop hoc.\n");
	printf("\tChu du an:\n");
	printf("\t1212358: Pham Ngoc Thanh\n");
	printf("\t1212283: Phan Song Nui\n");
	printf("\t1212307: Nguyen Nhu Quang\n");
	printf("Cach su dung:\n\n");
	printf("buildinfo <data folder> <out folder>\n\n");
	printf("\tdata folder: \tDuong dan thu muc chua du lieu vao\n");
	printf("\tout folder: \tDuong dan thu muc chua ket qua\n");
	printf("Chu y: Cac duong dan nhap vao khong co dau '\\' o cuoi duong dan\n");
	printf("\tDe duoc tro giup, dung lenh: buildinfo -h\n\n");
}

void createIndex(STS sts, char *outpath)
{
	char *filename = new char[strlen(outpath)+12];
	sprintf(filename, "%s/index.html", outpath);
	
	HTML html = html_create(filename);
	if (html == NULL) {
		log("createIndex", "Khong the tao file 'index.html' duoc!");
		return;
	}

	html_header(html, "HCMUS Students");
	html_body_navigation(html);
	html_body_content(html, 1);
	html_body_content_header(html, "", "", 1);
	html_idxlist_begin(html);
	for (int i = 0; sts[i] != NULL; i++) {
		char year[5];
		itoa(sts[i]->Nam, year, 10);
		html_idxlist_element(html, sts[i]->MSSV, sts[i]->HoTen, year);
	}
	html_idxlist_end(html);
	html_footer(html, "HungryBirds");
	html_close(html);
	delete filename;
}

void createSVPage(HTML html, STS sts, int i)
{
	ST st = sts[i];

	printf("buildinfo -> Dang tao file HTML cua sinh vien %s\n", sts[i]->MSSV);

	char *buf = new char[41];
	sprintf(buf, "%s - %s", st->HoTen, st->MSSV);
	html_header(html, buf);
	delete buf;
	html_body_navigation(html);
	html_body_content(html, 2);
	html_body_content_header(html, st->HoTen, st->MSSV, 2);
	
	char year[5];
	itoa(st->Nam, year, 10);
	html_content_pesonal_begin(html, st->MSSV, st->BirthD, year, strsplit(st->Description, ","), strsplit(st->Hobby, ","));
	html_listview_begin(html);
		char **friendlist = strsplit(st->FriendList, ";");
		for (int i = 0; friendlist[i] != NULL; i++)
		{
			int pos = getFList(sts, friendlist[i]);
			if (pos != -1) {
				itoa(sts[pos]->Nam, year, 10);
				html_listview_item(html, friendlist[i], sts[pos]->HoTen, year);
			} else {
				printf("error -> Khong the lay thong tin cua sinh vien %s\n", friendlist[i]);
			}
		}
	html_listview_end(html);
	html_content_pesonal_end(html);
}

void createSVS(STS sts, char *outpath)
{
	char *filename;
	HTML html;

	for (int i = 0; sts[i] != NULL; i++)
	{
		filename = new char[strlen(outpath)+14];
		sprintf(filename, "%s/%s.html", outpath, sts[i]->MSSV);
		html = html_create(filename);
		if (html == NULL) {
			printf("%s -> Khong the tao file '%s.html' duoc!\n", "createSV", sts[i]->MSSV);
			continue;
		}

		createSVPage(html, sts, i);

		html_footer(html, "HungryBirds");
		html_close(html);
		delete filename;
	}
}

void prepareImage(STS sts, char *inpath, char *outpath)
{
	for (int i = 0; sts[i] != NULL; i++) {
		// Tao duong dan noi luu file
		char *smallin = new char[strlen(inpath)+strlen(sts[i]->smallImg)+9];
		sprintf(smallin, "%s/images/%s", inpath, sts[i]->smallImg);
		char *bigin   = new char[strlen(inpath)+strlen(sts[i]->bigImg)+9];
		sprintf(bigin, "%s/images/%s", inpath, sts[i]->bigImg);

		// Tao duong dan noi chua file
		char *smallout = new char[strlen(outpath)+strlen(sts[i]->MSSV)+17];
		sprintf(smallout, "%s/images/%s_t.jpg", outpath, sts[i]->MSSV);
		char *bigout   = new char[strlen(outpath)+strlen(sts[i]->MSSV)+15];
		sprintf(bigout, "%s/images/%s.jpg", outpath, sts[i]->MSSV);

		// Copy file
		fcopy(smallin, smallout);
		fcopy(bigin, bigout);
	}
}

void log(char *local, char *content)
{
	printf("%s -> %s\n", local, content);
}