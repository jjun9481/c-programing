#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char src[100];
	char dest[100];
	int length, result;
	gets(src);
	gets(dest);
	result = strcmp(src, dest);
	printf("result = %d\n", result);
	/*length = strlen(src);
	printf("length of src = %d\n", length);
	strcpy(dest, src);
	printf("src = %s  dest = %s\n",src, dest);
	strcat(dest, src);
	printf("src = %s, dest = %s\n", src, dest);*/


	return 0;
}

int main()
{
	char input[200] = "";
	int count[26] = { 0 };
	int ch;
	int i = 0;

	while ((ch = getchar()) != EOF)
	{
		input[i++] = ch;
	}
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			count[input[i] - 'a']++;
		}
		i++;
	}
	printf("�Է¹��ڿ�:%s \n", input);
	for (int i = 0; i < 26; i++)
		printf("%c ����Ƚ��:%d\n", 'a' + i, count[i]);



	return 0;
}