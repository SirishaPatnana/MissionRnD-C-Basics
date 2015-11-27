/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int len(char *a)
{
	int i, j = 0;
	for (i = 0; *(a + i) != '\0'; i++)
		j++;
	return j;
}
int valid(char *p)
{
	int i, d, m, y, b[30], l;
	int g[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	l = len(p);
	if (l != 10)return 0;
	for (i = 0; i<10; i++)
	{
		if (i == 2 || i == 5)continue;
		if (*(p + i)<'0' || *(p + i)>'9')
			return 0;
	}
	for (i = 0; i<l; i++)
	{
		b[i] = (*(p + i) - 48);
	}
	d = (b[0] * 10) + b[1];
	m = (b[3] * 10) + b[4];
	y = (b[6] * 1000) + (b[7] * 100) + (b[8] * 10) + b[9];
	if (y % 4 == 0)
	{
		g[1] = 29;
	}
	if (y % 4 == 0)
	if ((y % 100 == 0) && (y % 400 == 0))
		g[1] = 29;
	if ((m == 0) || (d == 0) || (y == 0))
		return 0;
	else if (m>12 || d>31)
		return 0;
	else if (d>g[m - 1])
		return 0;
	else if (*(p + 2) != '-' || *(p + 5) != '-')
		return 0;
	return 1;
}
int isOlder(char *dob1, char *dob2) {
	int l1, l2, i, d1, m1, y1, d2, m2, y2, b[30];
	l1 = len(dob1);
	for (i = 0; i < l1; i++)
	{
		b[i] = (*(dob1 + i) - 48);
	}
	d1 = (b[0] * 10) + b[1];
	m1 = (b[3] * 10) + b[4];
	y1 = (b[6] * 1000) + (b[7] * 100) + (b[8] * 10) + b[9];
	l2 = len(dob2);
	for (i = 0; i<l2; i++)
	{
		b[i] = (*(dob2 + i) - 48);
	}
	d2 = (b[0] * 10) + b[1];
	m2 = (b[3] * 10) + b[4];
	y2 = (b[6] * 1000) + (b[7] * 100) + (b[8] * 10) + b[9];

	if (valid(dob1) == 1 && valid(dob2) == 1)
	{
		if (y2<y1)
			return 2;
		else if (y1<y2)
			return 1;
		if (m1>m2)
			return 2;
		else if (m1<m2)
			return 1;
		if (d1>d2)
			return 2;
		else if (d1 < d2)
			return 1;

		return 0;
	}
	return -1;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int len(char *a)
{
	int i, j = 0;
	for (i = 0; *(a + i) != '\0'; i++)
		j++;
	return j;
}
int valid(int d, int m, int y, int *g, char *a)
{
	int i;
	if ((m == 0) || (d == 0) || (y = 0))
		return 0;
	else if (m>12 || d>31)
		return 0;
	else if (d>g[m - 1])
		return 0;
	else if (*(a + 2) != '-' || *(a + 5) != '-')
		return 0;
	else
	{
		for (i = 0; i<10; i++)
		{
			if (i != 2 || i != 5)
			if (*(a + i)<'0' || *(a + i)>'9')
				return 0;
		}
		return 1;
	}
}
int isOlder(char *dob1, char *dob2) {
	int *d, *m, *y, i, j, l;
	int g[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int **b;
	b = (int**)malloc(2 * sizeof(int*));
	for (i = 0; i < 8; i++)
		b[i] = (int*)malloc(5 * sizeof(int));
	d = (int*)malloc(sizeof(int)* 2);
	m = (int*)malloc(sizeof(int)* 2);
	y = (int*)malloc(sizeof(int)* 2);
	if (len(dob1) == 10 && len(dob2) == 10)
	{
		for (j = 0; j<10; j++)
			b[0][j] = (*(dob1 + j) - 48);
		for (j = 0; j<10; j++)
			b[1][j] = (*(dob2 + j) - 48);
		/*for (j = 0; j < 10; j++)
			printf("%d\n", b[0][j]);
		for (j = 0; j < 10; j++)
		printf("%d\n", b[1][j]);*//*
		for (i = 0; i <= 1; i++)
		{
			d[i] = (b[i][0] * 10) + b[i][1];
			m[i] = (b[i][3] * 10) + b[i][4];
			y[i] = (b[i][6] * 1000) + (b[i][7] * 100) + (b[i][8] * 10) + b[i][9];
		}
		if (valid(d[0], m[0], y[0], g, dob1) == 1 && valid(d[1], m[1], y[1], g, dob2) == 1)
		{
			if (y[0]>y[1])
				return 2;
			else if (y[0]<y[1])
				return 1;
			if (m[0]>m[1])
				return 2;
			else if (m[0]<m[1])
				return 1;
			if (d[0]>d[1])
				return 2;
			else if (d[0] > d[1])
				return 1;
				return 0;
		}
		else
			return -1;
	}
	else
		return -1;
}*/
