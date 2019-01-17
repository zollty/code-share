/* ****************************************************************************
快速排序（或划分交换排序）
递归算法，分治法思想
	作者：邹天涌
**************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int Partition(int *a, int h, int r)//注意r=n-1
{
	int key;
	int i;
	int j;
	i=h;
	j=r;
	key=a[h];//用区间的第1个记录作为基准

	while( i < j )//每执行一次while左右指针各移动一轮
	{
		while( a[j]>=key && i<j )//指针j从右往左移动
		{
			j--;
		}
		if( i<j )	/* 虽然外循环也有 i < j，但是前面j--可能使得i=j，这样就不
			         能再执行a[i++]了. */
		{
			a[i]=a[j];
			i++;
		}

		while( a[i]<=key && i<j )//指针i从左往右移动
		{
			i++;
		}
		if( i<j )
		{
			a[j]=a[i];
			j--;
		}
	}	//左右指针各移动一轮后，又重新开始下一轮移动

	a[i]=key;

	return i;
}

void QuickSort(int *a, int h, int r)
{
	int i;
	if( h<r )
	{
		i=Partition(a, h, r);
		QuickSort(a, h, i-1);
		QuickSort(a, i+1, r);
	}
}



//专门打印整型数组的函数，n为元素个数.
void print(int s[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", s[i]);
	printf("\n");
}

int main(void)
{
	int a[2]={3,2};//此算法可以对仅有一、两个元素的数组排序
	print(a,2);
	QuickSort(a, 0, 1);
	print(a,2);
	return 0;
}
