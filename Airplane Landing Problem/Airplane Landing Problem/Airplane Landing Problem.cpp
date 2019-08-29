// Airplane Landing Problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include  <vector>
#include  <fstream>
#include <set>
using namespace std;
vector<vector<float> > Matrix;
float Z;
set<int> P;
size_t bn = 15, cn = 21;
//size_t bn = 5, cn = 8;

bool Pivot(pair<size_t, size_t> &p)//返回0表示所有的非轴元素都小于0
{
    int x = 0, y = 0;
    float cmax = -INT_MAX;
    vector<float> C = Matrix[0];
    vector<float> B;

    for( size_t i = 0 ; i < bn ; i++ )
    {
        B.push_back(Matrix[i][cn-1]);
    }
    
    for( size_t i = 0 ; i < C.size(); i++ )//在非轴元素中找最大的c
    {
        if( cmax < C[i] && P.find(i) == P.end())
        {
            cmax = C[i];
            y = i;
        }
    }
    if( cmax < 0 )
    {
        return 0;
    }

    float bmin = INT_MAX;
    for( size_t i = 1 ; i < bn ; i++ )
    {
       float tmp = B[i]/Matrix[i][y];
       if( Matrix[i][y] != 0 && bmin > tmp )
       {
           bmin = tmp;
           x = i;
       }
    }

    p = make_pair(x, y);

    for( set<int>::iterator it = P.begin() ; it != P.end() ; it++)
    {
        if( Matrix[x][*it] != 0 )
        {
            //cout<<"erase "<<*it<<endl;
            P.erase(*it);
            break;
        }
    }
    P.insert(y);
    //cout<<"add "<<y<<endl;
    return true;
}

void pnt()
{
    for( size_t i = 0 ; i < Matrix.size() ; i++ )
    {
        for( size_t j = 0 ; j < Matrix[0].size() ; j++ )
        {
            cout<<Matrix[i][j]<<"\t";
        }
    cout<<endl;
    }
    cout<<"result z:"<<-Matrix[0][cn-1]<<endl;
}

void Gaussian(pair<size_t, size_t> p)//行变换
{
    size_t  x = p.first;
    size_t y = p.second;
    float norm = Matrix[x][y];
    for( size_t i = 0 ; i < cn ; i++ )//主行归一化
    {
        Matrix[x][i] /= norm;
    }
    for( size_t i = 0 ; i < bn && i != x; i++ )
    {
        if( Matrix[i][y] != 0)
        {
            float tmpnorm = Matrix[i][y];
            for( size_t j = 0 ; j < cn ; j++ )
            {
                Matrix[i][j] = Matrix[i][j] - tmpnorm * Matrix[x][j];
            }
        }
    }
}

void solve()
{
    pair<size_t, size_t> t;
    while(1)
    {

        pnt();
        if( Pivot(t) == 0 )
        {
            return;
        }        
        cout<<t.first<<" "<<t.second<<endl;
        for( set<int>::iterator it = P.begin(); it != P.end()  ; it++ )
        {
            cout<<*it<<" ";
        }
        cout<<endl;
        Gaussian(t);
    }
}

int main(int argc, char *argv[])
{
    //ifstream fin;
    //fin.open("./test");
	int N = 5, s[5], t[5];
	/*
	for(int i = 0; i <= 2 * N; i++)
		if(i % 2 == 0)
			scanf("%d", &s[i]);
		else
			scanf("%d", &t[i]);
	
	float M[5][8] = \
	{{1, 16, 6, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0, 0, 4},
	{1, 0, 0, 0, 1, 0, 0, 2},
	{0, 0, 1, 0, 0, 1, 0, 3},
	{0, 3, 1, 0, 0, 0, 1, 6}};
	*/
	float M[15][21] = \
	{{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
	{1,-1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
	{0,1,-1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},\
	{0,0,1,-1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},\
	{0,0,0,1,-1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},\
	{1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,1},\
	{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2},\
	{0,1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,3},\
	{0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,4},\
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,5},\
	{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,6},\
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,7},\
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,8},\
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,9},\
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,10}};
	/*
	float tmp = 0; 
	for(int i = 5; i < bn; i++)
	{
		scanf("%f", &tmp);
		if((i - 5) % 2 == 0)
			M[i][20] = -tmp;
		else
			M[i][20] = tmp;
	}
	*/
	
	for(int i = 0; i < bn; i++)
	{
		printf("\n");
		for(int j = 0; j < cn; j++)
			printf("%f   ", M[i][j]);
	}
	
	system("pause");

    //cin>>cn>>bn;
    for( size_t i = 0 ; i < bn ; i++ )
    {
        vector<float> vectmp;
        for( size_t j = 0 ; j < cn ; j++)
        {
            float tmp = M[i][j];
            //cin>>tmp;
            vectmp.push_back(tmp);
        }
        Matrix.push_back(vectmp);
    }

    for( size_t i = 0 ; i < bn-1 ; i++ )
    {
        P.insert(cn-i-2);
    }
    solve();

	system("pause");
	return 0;
}
/////////////////////////////////////
//glpk input:
///* Variables */
//var x1 >= 0;
//var x2 >= 0;
//var x3 >= 0;
///* Object function */
//maximize z: x1 + 14*x2 + 6*x3;
///* Constrains */
//s.t. con1: x1 + x2 + x3 <= 4;
//s.t. con2: x1  <= 2;
//s.t. con3: x3  <= 3;
//s.t. con4: 3*x2 + x3  <= 6;
//end;
/////////////////////////////////////
//myinput:
//8 5
//1 14 6 0 0 0 0 0
//1 1 1 1 0 0 0 4
//1 0 0 0 1 0 0 2
//0 0 1 0 0 1 0 3
//0 3 1 0 0 0 1 6
/////////////////////////////////////

/*
int main() {
	int N = 5, s[5], t[5];
	for(int i = 0; i <= 2 * N; i++)
		if(i % 2 == 0)
			scanf("%d", &s[i]);
		else
			scanf("%d", &t[i]);
	system("pause");
	return 0;
}
*/
