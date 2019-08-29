// Simplex.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
//#include<bits/stdc++.h>
#include <algorithm> 
#include <math.h>
#define inf 3ef3ef3ef
#define ll long long
#define db float
#define eps 1e-8
using namespace std;
const int N=100;

db ans[N],a[N][N];int id[N];int n,m;

void privot(int x,int y)
{
	swap(id[n+x],id[y]);
	// �ѻ������ͷǻ�����ֻ�������
	// �൱�� id[n+x] x��(1,m) ��������ı��
	db tmp=1.0/a[x][y];
	a[x][y]=1.0;// ԭ�Ȼ�����ϵ��Ϊ1
	for(int i=0;i<=n;i++)	a[x][i]*=tmp;
	// �ǻ�������������ϵ����һ  ���ƽⷽ�̴��뷨֮ǰ��ϵ����һ
	for(int i=0;i<=m;i++)
	{
		if(i==x||fabs(a[i][y])<eps)	continue;
		db cur=a[i][y]; a[i][y]=0.0;
		for(int j=0;j<=n;j++)
			a[i][j]-=a[x][j]*cur;
	}
	// �����µĻ�������Ԫ
}

bool prework()
{
	// �淶�����Թ滮Ҫ��b[i]�Ǹ� ���Ǳ�׼��û�����Ҫ�� ������ҪԤ����
	// ������b[i]�Ǹ������ƥ�伸��a[i]�Ǹ���Ȼ���滻һ�� b[i]�ͱ��������
	while(1)
	{
		int x=0,y=0,i;
		for(i=1;i<=m;i++)	if(a[i][0]<-eps && (!x || rand()&1)) x=i;
		if(!x)	return true;
		for(i=1;i<=n;i++)	if(a[x][i]<-eps && (!y || rand()&1)) y=i;
		if(!y){printf("Infeasible\n");return false;}//�޿�����
		privot(x,y);
	}
	return true;
}

bool simplex()
{
	while(1)
	{
		int i,x=0,y=0; double mn=1e15;
		for(i=1;i<=n;i++)	if(a[0][i]>eps){y=i;break;}
		if(!y)	break;
		for(i=1;i<=m;i++)
			if(a[i][y]>eps&&a[i][0]/a[i][y]<mn)
				mn=a[i][0]/a[i][y],x=i;
		if(!x){printf("Unbounded\n");return false;}
		privot(x,y);
	}
	return true;
}

int main()
{
	//srand(time(0));
//	scanf("%d%d",&n,&m);
    n=6,m=14;
//	t = 1;
	for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            a[i][j]=0;
    }
	float tmp[10];
	for(int i=0;i<10;i++)
    {
        scanf("%f",&tmp[i]);
    }
	for(int i=1;i<=n;i++) id[i]=i;
	a[0][6] = 1;
    for(int i=1;i<=n;i++)	id[i]=i;
	//��ʼ�ǻ�����i ������n+i
//	for(int i=1;i<=m;i++)
//	{
//	    int s,t;
//	    scanf("%d%d",&s,&t);
//		for(int j=s;j<=t;j++)
//                a[i][j]=1;
//        for(int j=1;j<=n;j++)	scanf("%lf",&a[i][j]);
//		scanf("%lf",&a[i][0]);
//		scanf("%lf",&a[i][0]);
//	}
//    fill_n(a[1][0],)
    a[1][2]=-1,a[1][1]=1,a[1][6]=1;
    a[2][3]=-1,a[2][2]=1,a[2][6]=1;
    a[3][4]=-1,a[3][3]=1,a[3][6]=1;
    a[4][5]=-1,a[4][4]=1,a[4][6]=1;
    a[5][1]=-1,a[6][1]=1,a[7][2]=-1,a[8][2]=1,a[9][3]=-1;
    a[10][3]=1;a[11][4]=-1,a[12][4]=1,a[13][5]=-1,a[14][5]=1;
////    a[1][0]=tmp[2]-tmp[0];
//    a[2][0]=tmp[4]-tmp[2];
//    a[3][0]=tmp[6]-tmp[4];
//    a[4][0]=tmp[8]-tmp[6];
    for(int i=5;i<=m;i++)
    {
        if(i%2==1)
            a[i][0]=-tmp[i-5];
        else
            a[i][0]=tmp[i-5];
    }



//   for(int i=0;i<=m;i++)
//   {
//       for(int j=0;j<=n;j++)
//        cout<<a[i][j]<<" ";
//       cout<<endl;
//   }

	if(prework()&&simplex())
	{
//		printf("%.2f\n",-a[0][0]);
//		if(t)
//		{
			for(int i=1;i<=m;i++)	ans[id[n+i]]=a[i][0];
			for(int i=1;i<n-1;i++)	printf("%.2f ",ans[i]);
			printf("%.2f",ans[n-1]);
//		}
	}
	//system("pause");
	return 0;
}

