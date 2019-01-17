/* ****************************************************************************
希尔排序（带哨兵格式）
前面d[0]个元素作哨兵
	作者：邹天涌
**************************************************************************** */

#include<stdio.h>

void ShellSort(int *a, int r)//注意r=n-1
{
	int d[3]={5,3,1};//增量序列
	int i, j, k, h;
	int temp;
	k=0;
	do
	{
		h=d[k];
		for(i=h+d[0]; i<=r; i++)/*每轮while都要i=h+d[0]是因为每趟排序数据是
								 从h+d[0]开始的，前面有d[0]个是哨兵。 */
		{
			temp=a[i];
			j=i-h;
			while( temp<a[j] )
			{
				a[j+h]=a[j];
				j-=h;
			}
			a[j+h]=temp;
		}
		k++;
	}while( h!=1 );

	for(i=0; i<d[0]; i++)
	{
		a[i]=0;
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
	int a[7]={0, 0, 0, 0, 0, 8, 2};//可以对一、两个元素（a[6]、a[7]）进行排序
	print(a,7);
	ShellSort(a, 6);
	print(a,7);
	return 0;
}
