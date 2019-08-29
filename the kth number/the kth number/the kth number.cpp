// the kth number.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//#include <cstdlib>

#include <iostream>
#include "stdio.h"
using namespace std;
//调整堆
void HeapAdjust(int a[],int i,int size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (left < size&&a[left] < a[min])
            min = left;
    if (right < size&&a[right] < a[min])
        min = right;
        if (min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            HeapAdjust(a,min,size); //避免调整之后以min为父节点的子树不是堆
        }
}
//建立堆
void HeapBuild(int a[],int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        HeapAdjust(a,i,size);
}
//k为需要查找的最大元素个数，size为数组大小，kMax存储k个元素的最小堆  
void FindMax(int Array[], int k, int size, int kMax[])
{
    for (int i = 0; i < k; i++)
        kMax[i] = Array[i];
    HeapBuild(kMax,k);
    for (int j = k; j < size; j++)
    {
        if (Array[j] <= kMax[0]) continue;
        kMax[0] = Array[j];
        HeapAdjust(kMax,0,k);
    }
}
int main()
{
    int lenth, k;
	scanf("%d %d", &lenth,&k);
	int a[5000000],i=0;
	for(i=0;i<lenth;i++)
		scanf("%d",&a[i]);
	//int a[] = {10,23,17,8,52,35,7,1,28};
    //int k = 4;
    int KMax[4] = {0};
    FindMax(a,k,lenth,KMax);
    //for (int i = 0; i < k; i++)
        //cout << KMax[i] << endl;
	cout << KMax[0] << endl;
	//system("pause");
	return 0;
}
