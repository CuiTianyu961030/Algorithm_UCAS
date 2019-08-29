// Volunteer Recruitment.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <queue>
//#include <stdlib.h>
#define N 5000
#define M 100000
#define inf 0x3f3f3f3f
using namespace std;
queue<int> q;
int a[N], head[N], to[M], val[M], cost[M], next_[M], cnt = 1, s, t, dis[N], from[N], pre[N];

void add(int x, int y, int v, int c)
{
	to[++cnt] = y, val[cnt] = v, cost[cnt] = c, next_[cnt] = head[x], head[x] = cnt;
	to[++cnt] = x, val[cnt] = 0, cost[cnt] = -c, next_[cnt] = head[y], head[y] = cnt;
}
bool spfa()
{
	int x, i;
	memset(from, -1, sizeof(from));
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0, q.push(s);
	while(!q.empty())
	{
		x = q.front(), q.pop();
		for(i = head[x]; i; i = next_[i])
			if(val[i] && dis[to[i]] > dis[x] + cost[i])
				dis[to[i]] = dis[x] + cost[i], from[to[i]] = x, pre[to[i]] = i, q.push(to[i]);
	}
	return ~from[t];
}

int mincost()
{
	int ans = 0, i, k;
	while(spfa())
	{
		k = inf;
		for(i = t; i != s; i = from[i])
			k = min(k, val[pre[i]]);
		ans += k * dis[t];
		for(i = t; i != s; i = from[i])
			val[pre[i]] -= k, val[pre[i] ^ 1] += k;
	}
	return ans;
}

int main()
{
	int n, m, i, x, y, z;
	scanf("%d%d", &n, &m), s = 0, t = n + 2;
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]), add(i + 1, i, inf, 0);
	for(i = 1; i <= m; i++)
		scanf("%d%d%d", &x, &y, &z), add(x, y + 1, inf, z);
	for(i = 1; i <= n + 1; i++)
	{
		if(a[i] - a[i - 1] > 0)
			add(s, i, a[i] - a[i - 1], 0);
		if(a[i] - a[i - 1] < 0)
			add(i, t, a[i - 1] - a[i], 0);
	}
	printf("%d", mincost());
	//system("pause");
	return 0;
}

