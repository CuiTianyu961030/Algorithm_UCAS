// Maximum Knights.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lng 10000000
using namespace std;
int d[210][210];
int a[400010],Next[400010],p[400010],remain[400010],tot;
int dis[400010],cur[400010];
int n,m,n1,cnt,ans;
 
inline void add(int x,int y,int flow)
{
	tot++; a[tot]=y; Next[tot]=p[x]; p[x]=tot; remain[tot]=flow;
	tot++; a[tot]=x; Next[tot]=p[y]; p[y]=tot; remain[tot]=0;
	return;
}
inline void check(int a1,int x,int y)
{
	if (d[x][y]>0&&x>0&&y>0&&x<=n&&y<=n) add(a1,d[x][y],lng);
	return; 
}
 
inline bool bfs()
{
	queue<int>que;
	memset(dis,-1,sizeof(dis));
	for (int i=0;i<=n1;++i)
	 cur[i]=p[i];
	que.push(0); dis[0]=0;
	while (!que.empty())
	 {
	 	int u,v;
	 	u=que.front(); que.pop();
	 	v=p[u];
	 	while (v!=-1)
	 	 {
	 	 	if (remain[v]&&dis[a[v]]<0)
	 	 	 {
	 	 	 	dis[a[v]]=dis[u]+1;
	 	 	 	que.push(a[v]);
	 	 	 }
	 	 	v=Next[v];
	 	 }
	 }
	if (dis[n1]<0) return false;
	 else return true;
}
inline int dfs(int now,int flow)
{
	if (now==n1||flow==0) return flow;
	int u=cur[now],s;
	while (u!=-1)
	 {
	 	cur[now]=u;
	 	if (dis[a[u]]>0&&dis[a[u]]==dis[now]+1&&(s=dfs(a[u],min(flow,remain[u]))))
	 	 {
	 	 	remain[u]-=s; remain[u^1]+=s;
	 	 	return s;
	 	 }
	 	u=Next[u];
	 }
	return 0;
}
 
int main()
{
	int i,j;
	memset(p,-1,sizeof(p));
	memset(Next,-1,sizeof(Next));
	scanf("%d%d",&n,&m);
        tot=-1;
	for (i=1;i<=m;++i)
	 {
	 	int x,y;
	 	scanf("%d%d",&x,&y);
	 	d[x][y]=-1;
	 }
	for (i=1;i<=n;++i)
	 for (j=1;j<=n;++j)
	   if (!d[i][j])
	    d[i][j]=++n1;
	n1++;
    for (i=1;i<=n;++i)
     for (j=1;j<=n;++j)
      if (d[i][j]>0)
       {
       	if (i%2==j%2)
       	 {
       	 	add(0,d[i][j],1);
			check(d[i][j],i-1,j-2); check(d[i][j],i-1,j+2);
			check(d[i][j],i-2,j-1); check(d[i][j],i-2,j+1);
			check(d[i][j],i+1,j-2); check(d[i][j],i+1,j+2);
			check(d[i][j],i+2,j-1); check(d[i][j],i+2,j+1);
       	 }
       	else add(d[i][j],n1,1);
       }
   while (bfs())
	while (cnt=dfs(0,0x7fffffff))
     ans+=cnt;
   ans=n1-ans;
   printf("%d",ans-1);
   //system("pause");
   return 0;
}

