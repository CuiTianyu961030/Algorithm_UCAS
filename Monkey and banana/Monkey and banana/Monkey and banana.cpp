// Monkey and banana.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include "math.h"
//#include "stdlib.h"
#include <algorithm>

using namespace std;

int main()
{
	int max_second = 0;
	int monkey[1000000], banana[1000000], tmp= ' ';
	for(int i = 0; i < 1000000; i++)
	{
		monkey[i] = -1;
		banana[i] = -1;
	}
	int i = 0;
	while(tmp != '\n')
	{
		scanf("%d%c", &monkey[i], &tmp);
		i++;
	}
	//for(int i = 0; i< 100 ; i++)
		//printf("%d", monkey[i]);
	i = 0;
	tmp = ' ';
	while(tmp != '\n')
	{
		scanf("%d%c", &banana[i], &tmp);
		i++;
	}
	//int *monkey = (int*)malloc(n*sizeof(int));
	//int *banana = (int*)malloc(n*sizeof(int));
	/*
	int **distance = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++)
		distance[i] = (int*)malloc(n*sizeof(int));
	*/
	//for(int i = 0; i < n; i++)
		//scanf("%d", &monkey[i]);
	//for(int i = 0; i < n; i++)
		//scanf("%d", &banana[i]);
	sort(monkey, monkey + 1000000);
	sort(banana, banana + 1000000);
	for(int i = 0; i < 1000000; i++)
		if(abs(monkey[i] - banana[i]) > max_second)
			max_second = abs(monkey[i] - banana[i]);
	printf("%d", max_second);
	/*
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			distance[i][j] = abs(monkey[i] - banana[j]);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", distance[i][j]);
		printf("\n");
	}
	*/
	//system("pause");
	return 0;
}

