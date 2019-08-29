// Cross river.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
//#include "stdlib.h"
#include <algorithm> 
using namespace std;  

int main()
{
	int num_people, max_weight;
	scanf("%d", &num_people);
	scanf("%d", &max_weight);

	int count_boat = num_people;
	int* weight = (int*)malloc(sizeof(int)*num_people);
	int* flag = (int*)malloc(sizeof(int)*num_people);

	for(int i = 0; i < num_people; i++)
	{
		scanf("%d", &weight[i]);
		flag[i] = 0;
	}

	sort(weight, weight + num_people);
	reverse(weight, weight + num_people);

	for(int i = 0; i < num_people; i++)
	{
		//if(flag[i] == 1)
			//continue;
		//if(i == num_people - 1)
			//break;
		if(weight[i] == max_weight)
			{
				flag[i] = 1;
				continue;
			}
		for(int j = num_people -1; j > i; j--)
		{
			//if(weight[i] == max_weight)
			//{
			//	flag[i] = 1;
			//	break;
			//}
			if(flag[j] == 0 && (weight[i] + weight[j]) <= max_weight)
			{
				//weight[i] = weight[i] + weight[j];
				flag[j] = 1;
				flag[i] = 1;
				count_boat--;
				break;
			}
		}
	}
	printf("%d", count_boat);
	//system("pause");
	return 0;
}

