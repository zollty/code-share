/* ****************************************************************************
直接选择排序
	作者：邹天涌
**************************************************************************** */
#include <stdio.h>

void SelectSort(int *a, int r)
{
	int i, j, k;
	int temp;
	for(i=0; i<r; i++)
	{
		k=i;
		for(j=i+1; j<=r; j++ )
		{	//i到r为无序区间，依次比较i和i后面的数，k记录下最小的那个
			if( a[j]<a[k] )
			{
				k=j;//仅记录下其位置而不急着交换
			}
		}
		if( k!=i )//当i+1到r(即无序区间)中有比a[i]小的才交换
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
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
	int a[10]={75, 27, 55, 2, 7 ,6, 98, 75, 2,4};
	print(a,10);
	SelectSort(a, 9);
	print(a,10);
	return 0;
}
