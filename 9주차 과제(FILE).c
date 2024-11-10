#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getline(char* line)
{
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main()
{
	char input[100];
	FILE* fp;

	if ((fp = fopen("output.txt", "w")) == NULL) {
		printf("ERROR...");
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		getline(input);
		fputs(input, fp);
		fputs("\n", fp);
	}

	fclose(fp);
	return 0;

}

int getline(char* line)
{
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main()
{
	char input[100];
	FILE* fp_src;
	FILE* fp_dest;

	if ((fp_src = fopen("output.txt", "r")) == NULL) {
		printf("ERROR...");
		return 0;
	}
	if ((fp_dest = fopen("output2.txt", "w")) == NULL) {
		printf("ERROR...");
		return 0;
	}

	while (!feof(fp_src)) {
		fgets(input, 100, fp_src);
		fputs(input, fp_dest);

	}

	fclose(fp_src);
	fclose(fp_dest);
	return 0;

}

int getline(char* line)
{
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main()
{
	char input[100];
	int num1,num2;
	FILE* fp_src;
	FILE* fp_dest;

	if ((fp_src = fopen("output.txt", "r")) == NULL) {
		printf("ERROR...");
		return 0;
	}
	if ((fp_dest = fopen("output3.txt", "w")) == NULL) {
		printf("ERROR...");
		return 0;
	}

	while (!feof(fp_src)) {
		fscanf(fp_src,"%s %d %d\n",input,&num1,&num2);
		fprintf(fp_dest, "%s %d %d\n", input, num1, num2);
	}

	fclose(fp_src);
	fclose(fp_dest);
	return 0;

}
