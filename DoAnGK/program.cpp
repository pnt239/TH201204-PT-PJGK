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
	
	createIndex(sts, _OUT_PATH);
	log("buildinfo", "Da tao file 'index.html' thanh cong...");

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

void createSVPage(ST st)
{
	//
}

void log(char *local, char *content)
{
	printf("%s -> %s\n", local, content);
}

void prepareImage(STS sts, char *inpath, char *outpath)
{
	for (int i = 0; sts[i] != NULL; i++) {
		// Tao duong dan noi luu file
		char *smallin = new char[strlen(inpath)+strlen(sts[i]->smallImg)+2];
		sprintf(smallin, "%s/%s", inpath, sts[i]->smallImg);
		char *bigin   = new char[strlen(inpath)+strlen(sts[i]->bigImg)+2];
		sprintf(bigin, "%s/%s", inpath, sts[i]->bigImg);

		// Tao duong dan noi chua file
		char *smallout = new char[strlen(outpath)+strlen(sts[i]->MSSV)+8];
		sprintf(smallout, "%s/%s_t.jpg", outpath, sts[i]->MSSV);
		char *bigout   = new char[strlen(outpath)+strlen(sts[i]->MSSV)+6];
		sprintf(bigout, "%s/%s.jpg", outpath, sts[i]->MSSV);

		// Copy file
		fcopy(smallin, smallout);
		fcopy(bigin, bigout);
	}
}