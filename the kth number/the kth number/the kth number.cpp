// the kth number.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
//#include <cstdlib>

#include <iostream>
#include "stdio.h"
using namespace std;
//������
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
            HeapAdjust(a,min,size); //�������֮����minΪ���ڵ���������Ƕ�
        }
}
//������
void HeapBuild(int a[],int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        HeapAdjust(a,i,size);
}
//kΪ��Ҫ���ҵ����Ԫ�ظ�����sizeΪ�����С��kMax�洢k��Ԫ�ص���С��  
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
