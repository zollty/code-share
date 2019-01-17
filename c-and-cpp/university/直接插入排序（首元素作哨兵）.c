/* ****************************************************************************
直接插入排序（首元素作哨兵）
	作者：邹天涌
**************************************************************************** */
#include<stdio.h>

void InsertSort(int *a, int r)//注意r=n-1
{
	int i, j;
	for(i=2; i<=r; i++)
	{
		a[0]=a[i];
		j=i-1;
		while( a[j]>a[0] )//比a[0]大则交换
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
	a[0]=0;
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
	int a[3]={0, 8, 2};//注意一定要将a[0]设置为哨兵
	print(a,3);
	InsertSort(a, 2);
	print(a,3);
	return 0;
}
