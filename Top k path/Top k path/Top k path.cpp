// Top k path.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include "stdio.h"
//#include "stdlib.h"  
#include <algorithm> 
using namespace std;  

#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)<(b)) ? (a):(b) )
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

int main()
{
	int m, n, k, score[100][100];
	int dp[100][100][100], top[200];
	scanf("%d %d", &m, &n);
	scanf("%d", &k);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &score[i][j]);
	dp[0][0][0] = score[0][0];
	dp[0][0][1] = -1;
	for(int j=1; j<n; j++)
	{
		dp[0][j][0] = dp[0][j-1][0] + score[0][j];
		dp[0][j][1] = -1;
	}
	for(int i=1; i<m; i++)
	{
		dp[i][0][0] = dp[i-1][0][0] + score[i][0];
		dp[i][0][1] = -1;
	}
	for(int i=1; i<m; i++)
		for(int j=1; j<n; j++)
		{
			
			int t, row_klen=0, cow_klen=0;
			for(t=0; t<ARRAY_SIZE(top); t++)
				top[t]=-1;
			for(t=0; t<ARRAY_SIZE(dp[i][j]); t++)
				dp[i][j][t] =-1;
			for(t=0; t<ARRAY_SIZE(dp[i-1][j]); t++)
				if(dp[i-1][j][t]!=-1)
				{
					top[t] = dp[i-1][j][t];
					row_klen++;
				}
				else
					break;
			for(t=0; t<ARRAY_SIZE(dp[i][j-1]); t++)
				if(dp[i][j-1][t]!=-1)
				{
					top[row_klen + t] = dp[i][j-1][t];
					cow_klen++;
				}
				else
					break;
			sort(top, top+ARRAY_SIZE(top));
			for(int t=0; t<k; t++)
				if(top[ARRAY_SIZE(top) - t -1] == -1)
					dp[i][j][t] = -1;
				else
					dp[i][j][t] = score[i][j] + top[ARRAY_SIZE(top) - t -1];	
		}
	for(int t=0; t<k; t++)
		if(dp[m-1][n-1][t]>=0)
			if(t==k-1 || dp[m-1][n-1][t+1] <0)
				printf("%d", dp[m-1][n-1][t]);
			else
				printf("%d ", dp[m-1][n-1][t]);
				
	//system("pause");
	return 0;
}

