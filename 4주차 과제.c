#include<stdio.h>

int main()
{
	char message2[5] = { 'a','b','c','d','\0' };
	char message[5] = { 'a','b','c','\0' };

	printf("message=%s,message2=%s", message, message2);

}

int main()
{
	int ch;
	char message[100];
	int i = 0;

	ch = getchar();
	while ((ch = getchar()) != '\n')
	{
		message[i++] = ch;
	}
	message[i] = '\0';
	printf("%s", message);
	return 0;
}