/* ****************************************************************************
ֱ�Ӳ����������ڱ���
	���ߣ�����ӿ
**************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

void InsertSort(int *a, int r)//ע��r=n-1
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
			if( j != 0 )//���Խ��
			{
				j--;
			}
			else
			{//������j--��j=-1�����ǲ�����ִ��while(a[j]>temp)������break
				j=-1;
				break;
			}
		}
		a[j+1]=temp;
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
	int a[2]={8, 2};
	print(a,2);
	InsertSort(a, 1);
	print(a,2);
	return 0;
}
