/* ****************************************************************************
希尔排序（头尾哨兵法）
	作者：邹天涌

  算法思想可参见直接排序（头尾哨兵法）
**************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

/* 前面d[0]个元素做哨兵；而且用头尾哨兵的希尔排序元素个数要求>=2*d[0]，否则
 执行到第二个for循环时数组就会越界，切忌！*/
void ShellSort(int *a, int r)//注意r=n-1
{
	int i, j, k, m, n, h, temp;
	int d[3]={5,3,1};//增量序列
	if( r+1 < 2*d[0] )
	{
		printf("Error!To use shellsort, the number of the elements must \
bigger than %d.\n\n", 2*d[0]-1);/* 注意这个长英文语句是分两行写的，
		                         第一行行末要加'\'。*/
		exit(0);
	}

	k=0;
	do
	{
		h=d[k];

		for(m=0; m<h; m++)
		{
			temp=a[m];//保存a[m]的值，避免丢失，a[m]将要做哨兵

			for(i=m+h; i<=r; i+=h)
			{
				a[m]=a[i];
				j=i-h;
				while( a[j]>a[m] )
				{
					a[j+h]=a[j];
					j-=h;
				}
				a[j+h]=a[m];
			}

			a[m]=temp;//a[m]不再是哨兵，还原a[m]的值
			n=i-h;
			temp=a[n];//保存a[n]，a[n]将要做哨兵
			a[n]=a[m];

			j=m+h;
			while( a[n]>a[j] )
			{
				a[j-h]=a[j];
				j+=h;
			}
			if( temp>a[n] )//如果a[m]比a[n]大，则a[n]要放在次末尾的位置
			{
				a[j-h]=a[n];
				a[n]=temp;
			}
			else	//a[m]比a[n]小，直接放在a[n]的前面
			{
				a[j-h]=temp;
			}
		}

		k++;
	}while( h!=1 );
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
	int a[10]={75, 27, 92, 1, 12, 3, 97, 41, 84, 92};
	print(a,10);
	ShellSort(a, 9);
	print(a,10);
	return 0;
}
