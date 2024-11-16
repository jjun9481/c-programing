#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu() {
	int input;
	printf("메뉴입력(1.구조체 만들기,2.구조체 출력하기,-1.종료)");
	scanf_s("%d", &input);
	return input;
}
int main()
{
	int menu;
	do {
		menu = inputMenu();
		printf("%d\n", menu);
		if (menu == 1) {
			//구조체 만들기
		}
		else if (menu == 2) {
			//구조체 출력하기
		}
		else if (menu == -1)
			printf("프로그램 종료");
	} while (menu > 0);

	return 0;
}
//POINT* point;
//int count;
//scanf_s("%d", &count);
//
//point = (POINT*)malloc(sizeof(POINT) * count);
//
//for (int i = 0; i < count; i++) {
//	point[i].x = rand() % 100;
//	point[i].y = rand() % 100;
//}
//for (int i = 0; i < count; i++) {
//	printf("x=%d y=%d\n", point[i].x, point[i].y);
//}
//free(point);


typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu() {
	int input;
	printf("메뉴입력(1.구조체 만들기,2.구조체 출력하기,-1.종료)");
	scanf_s("%d", &input);
	return input;
}
POINT* makePoint() {
	POINT* p = (POINT*)malloc(sizeof(POINT));
	p->x = rand() % 100;
	p->y = rand() % 100;
	return p;
}
void printPoint(POINT*p[],int size) {
	for (int i = 0; i < size; i++)
		printf("x:%d y:%d\n", p[i]->x, p[i]->y);
}
void freePoints(POINT* p[], int size) {
	for (int i = 0; i < size; i++)
		free(p[i]);
}
int main()
{
	int menu;
	int count = 0;
	POINT* points[100];
	do {
		menu = inputMenu();
		printf("%d\n", menu);
		if (menu == 1) {
			//구조체 만들기
			points[count] = makePoint();
			count++;
			printf("구조체를 만들었습니다.");
		}
		else if (menu == 2) {
			//구조체 출력하기
			printPoint(points, count);
		}
		else if (menu == -1) {
			freePoints(points, count);
			printf("프로그램 종료");
		}
	} while (menu > 0);

	return 0;
}

typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu() {
	int input;
	printf("1.만들기, 2.출력하기, 3.클리어, 4.파일저장, 5.파일로드, -1.종료\n");
	scanf_s("%d", &input);
	return input;
}
POINT* makePoint() {
	POINT* p = (POINT*)malloc(sizeof(POINT));
	p->x = rand() % 100;
	p->y = rand() % 100;
	return p;
}
void printPoint(POINT*p[],int size) {
	for (int i = 0; i < size; i++)
		printf("x:%d y:%d\n", p[i]->x, p[i]->y);
}
void freePoints(POINT* p[], int size) {
	for (int i = 0; i < size; i++)
		free(p[i]);
}
int savefile(POINT*p[],int size) {
	FILE* fp;
	fp = fopen("points.bin", "ab");
	if (fp == NULL) return 0;
	for (int i = 0; i < size; i++) 
		fwrite(p[i], sizeof(POINT), 1, fp);
	fclose(fp);
	return 1;
}
int loadfile(POINT* p[], int max) {
	FILE* fp;
	int fSize, fCount;
	fp = fopen("points.bin", "rb");
	if (fp == NULL) return 0;

	fseek(fp, 0, SEEK_END);//끝으로 보내기
	fSize = ftell(fp);
	fCount = fSize / sizeof(POINT);
	rewind(fp);//되감기

	for (int i = 0; i < fCount; i++) {
		if (i == max) break;
		p[i] = (POINT*)malloc(sizeof(POINT));
		fread(p[i], sizeof(POINT), 1, fp);
	}
	fclose(fp);
	return fCount;
}
int main()
{
	int menu;
	int count = 0;
	POINT* points[100];
	do {
		menu = inputMenu();

		switch (menu)
		{
		case 1:
			points[count] = makePoint();
			count++;
			break;
		case 2:
			printPoint(points, count);
			break;
		case 3:
			system("cls");//system("clear")
			break;
		case 4: //file save
			if (!savefile(points, count)) printf("file open error...\n");
			else printf("file writing success...\n");
			break;
		case 5: //load file
			count = loadfile(points, 100);
			break;
		case -1:
			freePoints(points, count);
			printf("프로그램 종료");
			break;

		}
	} while (menu > 0);
	return 0;
}