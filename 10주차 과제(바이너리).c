#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main()
{
	char input[SIZE];
	FILE* fp = NULL;

	if ((fp = fopen("output.bin", "wb")) == NULL)
	{
		printf("error...");
		return 0;
	}

	gets(input);
	/*fputs(input,fp);*/
	fwrite(input, strlen(input), 1, fp);

	fclose(fp);

	return 0;
}

int main()
{
char input[SIZE];
FILE* fp = NULL;
int i=0;
if ((fp = fopen("output.bin", "rb")) == NULL)
{
    printf("error...");
    return 0;
	}
while(!feof(fp))
{
    fread(&input[i],sizeof(char),1,fp);
    i++;
}
input[--i]='\0';
puts(input);
    
fclose(fp);

return 0;
 }

int main()
{
    int array[1000];
    FILE* fp;
    
    fp=fopen("array.bin","rb");
    if(fp==NULL) return -1;
    
    fread(array,sizeof(int),100,fp);
    for(int i=0;i<100;i++) printf(" %d ",array[i]);
    fclose(fp);
    return 0;
}

typedef struct point {
	int x;
	int y;
}POINT;
POINT makePoint(void) {
	POINT p;
	scanf("%d %d", &p.x, &p.y);
	return p;
}
void makeRandomPoints(POINT p[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		p[i].x = rand() % 100;
		p[i].y = rand() % 100;
	}
}
void printPoints(POINT p[], int size) {
	for (int i = 0; i < size; i++)
		printf("pount[%d]=x : %d, y : %d\n", i, p[i].x, p[i].y);
}
void saveFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "wb");
	if (fp == NULL) exit(-1);
	fwrite(p, sizeof(POINT), size, fp);
	fclose(fp);
}
void loadFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "rb");
	if (fp == NULL) exit(-1);
	fread(p, sizeof(POINT), size, fp);
	fclose(fp);
}
int main() {
	POINT p[10];
	makeRandomPoints(p, 10);
	printPoints(p, 10);
	saveFile(p, 10);
	return 0;
}

typedef struct point {
	int x;
	int y;
}POINT;
POINT makePoint(void) {
	POINT p;
	scanf("%d %d", &p.x, &p.y);
	return p;
}
void makeRandomPoints(POINT p[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		p[i].x = rand() % 100;
		p[i].y = rand() % 100;
	}
}
void printPoints(POINT p[], int size) {
	for (int i = 0; i < size; i++)
		printf("pount[%d]=x : %d, y : %d\n", i, p[i].x, p[i].y);
}
void saveFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "wb");
	if (fp == NULL) exit(-1);
	fwrite(p, sizeof(POINT), size, fp);
	fclose(fp);
}
void loadFile(POINT p[], int size) {
	FILE* fp;
	fp = fopen("struct.bin", "rb");
	if (fp == NULL) exit(-1);
	fread(p, sizeof(POINT), size, fp);
	fclose(fp);
}


int main() {
    FILE* fp;
	POINT p[10];
	POINT p2;
	int pi;
	loadFile(p, 10);
	printPoints(p,10);
	
	fp=fopen("struct.bin","rb");
	if(fp==NULL)exit(-1);
	fseek(fp,sizeof(POINT)*3,SEEK_SET);
	pi=ftell(fp);
	printf("pi=%d\n",pi);
	fread(&p2,sizeof(POINT),1,fp);
	printf("p2--> %d %d\n",p2.x,p2.y);
	fseek(fp, sizeof(POINT)*-2,SEEK_END );
	pi=ftell(fp);
	printf("pi=%d\n",pi);
	fread(&p2,sizeof(POINT),1,fp);
	printf("p2--> %d %d\n",p2.x,p2.y);
	fseek(fp,0,SEEK_END);
	printf("size=%d\n",ftell(fp));
	fclose(fp);
	
	return 0;
}












