// Longest Increasing Subsequence.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//#include <stdlib.h>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
const int MAXN=200001;

int a[MAXN];
int d[MAXN];
int len_array[100];
int main()
{
    int n, num;
	scanf("%d", &num);
	for(int m=0;m<num;m++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		d[1]=a[1];
		int len=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>d[len])
				d[++len]=a[i];
			else
			{
				int j=std::lower_bound(d+1,d+len+1,a[i])-d;
				d[j]=a[i]; 
			}
		}
		len_array[m]=len;
	}
	for(int i=0;i<num;i++)
		printf("%d\n",len_array[i]);    
	//system("pause");
    return 0;
}

