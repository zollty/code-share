/* ****************************************************************************
堆排序（大根堆）
	作者：邹天涌
**************************************************************************** */

#include<stdio.h>

void Sift(int *a, int i, int r)//调整以a[i]为根的堆为大根堆
{
	int j;
	a[0]=a[i];//a[0]作哨兵
	j=2*i;
	while( j<=r )
	{
		if( j!=r )/*j=r时说明最后面的那个子树只有左叶子而无右叶子，故无需进行
				  两片叶子的比较，只有j!=r才比较。*/
		{
			if( a[j]<a[j+1] )
			{
				j++;
			}
		}
		if( a[j]>a[0] )
		{
			a[i]=a[j];//a[i]的值在while之前就已经保存了，所以不必交换
			i=j;
			j=2*i;
		}
		else
		{
			break;
		}
	}
	a[i]=a[0];//经过了while，a[0](原a[i])筛选到了合适的位置
}

void HeapSort(int *a, int r)
{
	int i, temp;
	for(i=r/2; i>=1; i--)//建初始堆
	{
		Sift(a, i, r);
	}

	for(i=r; i>1; i--)//交换首尾元素，交换结束后即完成从小到大排序
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		Sift(a, 1, i-1);
	}
	a[0]=0;	//将哨兵值设为0，也可以设为-32767
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
	int a[10]={0, 65, 74, 15, 76, 20, 77, 13, 67, 65};//注意a[0]做哨兵
	print(a,10);
	HeapSort(a, 9);
	print(a,10);
	return 0;
}
