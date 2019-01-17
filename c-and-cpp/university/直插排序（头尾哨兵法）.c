/* ****************************************************************************
直接插入排序（头尾哨兵法）
	作者：邹天涌

  思路是这样的：我们先把a[0]的值保存，然后用a[0]做哨兵，最后再恢复a[0]的值并
插入到合适的位置，这就相当于我们先对a[1]到a[r]进行排序，然后再插入a[0]，插入
的时候又有可能插入到最末尾的情况，这是又会造成越界，所以还必须用最末尾的元素
a[r]做哨兵，这就是为什么我取名为“头尾哨兵法”的原因。
**************************************************************************** */
#include<stdio.h>

void InsertSort(int *a, int r)//注意r=n-1，且要求r>=1
{
	int i, j, temp;
	if( r<1 )
	{
		printf("Error, the element number must bigger than 1!");
		exit(0);
	}
	temp=a[0];//保存a[0]的值，避免丢失，a[0]将要做哨兵
	for(i=2; i<=r; i++)
	{
		a[0]=a[i];
		j=i-1;
		while( a[j]>a[0] )
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}

	a[0]=temp;//a[0]不再是哨兵，还原a[0]的值
	temp=a[r];//保存a[r]，a[r]将要做哨兵
	a[r]=a[0];

	j=1;
	while( a[r]>a[j] )
	{
		a[j-1]=a[j];
		j++;
	}
	if( temp>a[r] )//如果a[0]比a[r]大，则a[r]要放在次末尾的位置
	{
		a[j-1]=a[r];
		a[r]=temp;
	}
	else	//a[0]比a[r]小，直接放在a[r]的前面
	{
		a[j-1]=temp;
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
	int a[2]={8, 2};//注意排序元素最少2个
	print(a,2);
	InsertSort(a, 1);
	print(a,2);
	return 0;
}
