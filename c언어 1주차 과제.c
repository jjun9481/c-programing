#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

int main()
{
	int number[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		number[i] = rand() % 100;

	}
	for (int i = 0; i < 10; i++)
	{
		printf("number[%d]=%d \n", i, number[i]);
	}

	return 0;
}

int main()
{
	int number[SIZE];
	int total = 0;
	int max, min;
	float avg = 0.0;

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		number[i] = rand() % 101;
		total += number[i];
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	avg = (float)total / SIZE;
	max = 0;
	min = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (number[max] < number[i]) max = i;
		if (number[min] > number[i]) min = i;

	}

	printf("ЦђБе=%f\n", avg);
	printf("max=%d min=%d", number[max], number[min]);
	return 0;
}


int main()
{
	int number[SIZE];
	int most;
	int temp;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		number[i] = rand() % 101;

	}
	for (int i = 0; i < SIZE - 1; i++)
	{
		most = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (number[most] < number[j]) most = j;
		}
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	return 0;
}