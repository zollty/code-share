/* ****************************************************************************
��ð������
	���ߣ�����ӿ
**************************************************************************** */
#include <stdio.h>

void BubbleSort(int *a, int r)
{
	int i, j;
	short flag;
	int temp;
	for(i=0; i<r; i++)
	{
		flag=1;
		for(j=r-1; j>=i; j--)
		{
			if( a[j+1]<a[j] )
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=0;
			}
		}
		if(flag)
		{
			break;
		}
	}
}

//ר�Ŵ�ӡ��������ĺ�����nΪԪ�ظ���.
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
	BubbleSort(a, 9);
	print(a,10);
	return 0;
}
