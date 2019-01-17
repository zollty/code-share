/* ****************************************************************************
直接插入排序（无哨兵）
	作者：邹天涌
**************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

void InsertSort(int *a, int r)//注意r=n-1
{
	int i, j;
	int temp;
	for(i=1; i<=r; i++)
	{
		temp=a[i];
		j=i-1;
		while( a[j]>temp )
		{
			a[j+1]=a[j];
			if( j != 0 )//检查越界
			{
				j--;
			}
			else
			{//理论上j--后j=-1，但是不能再执行while(a[j]>temp)，所以break
				j=-1;
				break;
			}
		}
		a[j+1]=temp;
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
	int a[2]={8, 2};
	print(a,2);
	InsertSort(a, 1);
	print(a,2);
	return 0;
}
