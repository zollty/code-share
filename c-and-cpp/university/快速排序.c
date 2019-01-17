/* ****************************************************************************
�������򣨻򻮷ֽ�������
�ݹ��㷨�����η�˼��
	���ߣ�����ӿ
**************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int Partition(int *a, int h, int r)//ע��r=n-1
{
	int key;
	int i;
	int j;
	i=h;
	j=r;
	key=a[h];//������ĵ�1����¼��Ϊ��׼

	while( i < j )//ÿִ��һ��while����ָ����ƶ�һ��
	{
		while( a[j]>=key && i<j )//ָ��j���������ƶ�
		{
			j--;
		}
		if( i<j )	/* ��Ȼ��ѭ��Ҳ�� i < j������ǰ��j--����ʹ��i=j�������Ͳ�
			         ����ִ��a[i++]��. */
		{
			a[i]=a[j];
			i++;
		}

		while( a[i]<=key && i<j )//ָ��i���������ƶ�
		{
			i++;
		}
		if( i<j )
		{
			a[j]=a[i];
			j--;
		}
	}	//����ָ����ƶ�һ�ֺ������¿�ʼ��һ���ƶ�

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
	int a[2]={3,2};//���㷨���ԶԽ���һ������Ԫ�ص���������
	print(a,2);
	QuickSort(a, 0, 1);
	print(a,2);
	return 0;
}
