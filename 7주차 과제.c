#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 100
typedef struct point {
	int x;
	int y;
}POINT;

int main()
{
	POINT point[SIZE] = { 0 };
	POINT temp = { 0,0 };
	int least;

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		point[i].x = rand() % 101;
		point[i].y = rand() % 101;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("point[%3d]=(%3d,%3d)\n", i, point[i].x, point[i].y);
	}
	for (int i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (point[least].x > point[j].x)
				least = j;
			else if (point[least].x == point[j].x && point[least].y > point[j].y)
				least = j;
		}
		temp = point[least];
		point[least] = point[i];
		point[i] = temp;
	}
	printf("Á¤·Ä\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("point[%3d]=(%3d,%3d)\n", i, point[i].x, point[i].y);
	}
	return 0;
}


int main()
{
	struct point p1 = { 10,10 };
	POINT p2 = { 20,20 };
	POINT* p3 = &p2;
	printf("p1.x=%d, p1.y=%d\n", p1.x, p1.y);
	printf("p2.x=%d, p2.y=%d\n", p2.x, p2.y);
	printf("p3.x->%d, p3->y=%d\n", p3->x, p3->y);

	p3 = &p1;
	printf("p3.x->%d, p3->y=%d\n", (*p3).x, (*p3).y);
	return 0;
}


void input_random_point(POINT* p, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		(p + i)->x = rand() % 101;
		(p + i)->y = rand() % 101;
	}
}
void swap_point(POINT* p1, POINT* p2)
{
	POINT temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void print_point_array(POINT p[], int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("p[%3d]=(%3d,%3d)\n", i, p[i].x, p[i].y);
	}
}
void selection_sort_point(POINT* point, int size)
{
	int least;
	for (int i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (point[least].x > point[j].x)
				least = j;
			else if ((point + least)->x == point[j].x && point[least].y > point[j].y)
				least = j;
		}
		swap_point(&point[i], &point[least]);
	}
}
int main()
{
	POINT point[SIZE] = { 0 };
	POINT temp = { 0,0 };
	input_random_point(point, SIZE);
	print_point_array(point, SIZE);
	selection_sort_point(point, SIZE);
	printf("Á¤·Ä\n");
	print_point_array(point, SIZE);
	return 0;
}
