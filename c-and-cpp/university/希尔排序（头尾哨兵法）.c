/* ****************************************************************************
ϣ������ͷβ�ڱ�����
	���ߣ�����ӿ

  �㷨˼��ɲμ�ֱ������ͷβ�ڱ�����
**************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

/* ǰ��d[0]��Ԫ�����ڱ���������ͷβ�ڱ���ϣ������Ԫ�ظ���Ҫ��>=2*d[0]������
 ִ�е��ڶ���forѭ��ʱ����ͻ�Խ�磬�мɣ�*/
void ShellSort(int *a, int r)//ע��r=n-1
{
	int i, j, k, m, n, h, temp;
	int d[3]={5,3,1};//��������
	if( r+1 < 2*d[0] )
	{
		printf("Error!To use shellsort, the number of the elements must \
bigger than %d.\n\n", 2*d[0]-1);/* ע�������Ӣ������Ƿ�����д�ģ�
		                         ��һ����ĩҪ��'\'��*/
		exit(0);
	}

	k=0;
	do
	{
		h=d[k];

		for(m=0; m<h; m++)
		{
			temp=a[m];//����a[m]��ֵ�����ⶪʧ��a[m]��Ҫ���ڱ�

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

			a[m]=temp;//a[m]�������ڱ�����ԭa[m]��ֵ
			n=i-h;
			temp=a[n];//����a[n]��a[n]��Ҫ���ڱ�
			a[n]=a[m];

			j=m+h;
			while( a[n]>a[j] )
			{
				a[j-h]=a[j];
				j+=h;
			}
			if( temp>a[n] )//���a[m]��a[n]����a[n]Ҫ���ڴ�ĩβ��λ��
			{
				a[j-h]=a[n];
				a[n]=temp;
			}
			else	//a[m]��a[n]С��ֱ�ӷ���a[n]��ǰ��
			{
				a[j-h]=temp;
			}
		}

		k++;
	}while( h!=1 );
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
	int a[10]={75, 27, 92, 1, 12, 3, 97, 41, 84, 92};
	print(a,10);
	ShellSort(a, 9);
	print(a,10);
	return 0;
}
