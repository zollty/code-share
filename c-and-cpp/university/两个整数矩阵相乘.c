/*���������������
   Author��Tianyong-Tsow������ӿ��
 */
#include <stdio.h>
int A[10][10];
int B[10][10];
int C[10][10];
int ar=0, ac=0, br=0, bc=0;
int i=0, j=0, k=0;
int main( )
{
	printf("Enter Details about the first matrix :\n");
	printf("How many rows :");
	scanf("%d", &ar);
	printf("How many cols :");
	scanf("%d", &ac);
	for(i=0; i<ar; i++)
	{
		for(j=0; j<ac; j++)
		{
			printf("Enter element for row %d col %d :",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter Details about the second matrix :\n");
	printf("How many rows :");
	scanf("%d", &br);
	printf("How many cols :");
	scanf("%d", &bc);
	for(i=0; i<br; i++)
	{
		for(j=0; j<bc; j++)
		{
			printf("Enter element for row %d col %d :", i+1, j+1);
			scanf("%d", &B[i][j]);
		}
	}

	//�����㷨
	if(ac != br)
		printf("Dimensions don't match.\n");
	else
	{
		for(k=0; k<ar; k++)  // C���б�ΪA���б�
			for(i=0; i<bc; i++)  // C���б�ΪB���б�
				for(j=0; j<ac; j++)  // A���б��B���б����
					C[k][i] += A[k][j]*B[j][i]; // j�����ڲ�ѭ�����õ�һ��C[k][i]
	}
	for(i=0; i<ar; i++)
	{
		for(j=0; j<bc; j++)
			printf("%d  ", C[i][j]);
		printf("\n");
	}
	return 0;
}
