// Basic Maximum Flow Algorithm.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 2139062143
#define ll long long
#define MAXN 1000100
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Dinic
{
    int fst[MAXN],nxt[MAXN<<3],to[MAXN<<3],val[MAXN<<3],cnt,n,m,s,t;
    Dinic() {cnt=0;memset(fst,0xff,sizeof(fst));}
    void add(int u,int v,int w) {nxt[cnt]=fst[u],fst[u]=cnt,to[cnt]=v,val[cnt++]=w;}
    int q[MAXN],dep[MAXN],cur[MAXN],vis[MAXN],tot;
    int BFS()
    {
        int l=1,r=0;
        memset(dep,0xff,sizeof(dep));
        vis[t]=++tot,q[++r]=t;
        while(l<=r)
        {
            int x=q[l++];cur[x]=fst[x];
            for(int i=fst[x];i!=-1;i=nxt[i])
            {
                if(val[i^1]&&vis[to[i]]!=tot)
                {
                    vis[to[i]]=tot,dep[to[i]]=dep[x]+1,q[++r]=to[i];
                    if(to[i]==s) return 1;
                }
            }
        }
        return vis[s]==tot;
    }
    int DFS(int x,int a)
    {
        if(x==t||!a) return a;
        int flow=0,f;
        for(int& i=cur[x];i!=-1;i=nxt[i])
        {
            if(val[i]&&dep[to[i]]==dep[x]-1&&(f=DFS(to[i],min(a,val[i]))))
            {
                val[i]-=f,val[i^1]+=f,flow+=f,a-=f;
                if(!a) break;
            }
        }
        return flow;
    }
    ll solve()
    {
        ll ans=0;int f;
        while(BFS())
        {
            memcpy(cur,fst,sizeof(cur));
            while(f=DFS(s,inf)) ans+=f;
        }
        return ans;
    }
}D;
int main()
{
    int k;
    D.n=read(),k=D.m=read(),D.s=read(),D.t=read();
    int u,v,w;
    for(int i=1;i<=k;i++) {u=read(),v=read(),w=read();D.add(u,v,w);D.add(v,u,0);}
    printf("%lld",D.solve());
}

