/* ��N�ʺ�����Ļ��ݵݹ��㷨 */
/* ���ߣ�����ӿ 2011-6-18 */

#include "stdio.h"
#define N 4
int count=0;					/*��¼����ܸ���*/

int isCorrect(int i, int j, int (*Q)[N] )	/*�ж��ܷ���ûʺ�*/
{
	int s, t;
	for(s=i, t=0; t<N; t++)
		if(Q[s][t] == 1 && t != j) return 0;	/*�ж���*/

	for(s=0, t=j; s<N; s++)
		if(Q[s][t] == 1 && s != i) return 0;	/*�ж���*/

	for(s=i-1, t=j-1; s>=0 && t>=0; s--, t--)
		if(Q[s][t] == 1) return 0;		    	/*�ж����Ϸ�*/

	for(s=i+1, t=j+1; s<N && t<N; s++, t++)
		if(Q[s][t] == 1) return 0;		    	/*�ж����·�*/

	for(s=i-1, t=j+1; s>=0 && t<N; s--, t++)
		if(Q[s][t] == 1) return 0;		    	/*�ж����Ϸ�*/

	for(s=i+1, t=j-1; s<N && t>=0; s++, t--)
		if(Q[s][t] == 1) return 0;		    	/*�ж����·�*/

	return 1;									/*���򷵻�1 */
}

void Queen(int j, int (*Q)[N] ){
	int i, k;
	if(j == N)								/* j=N ʱ�õ�һ����*/
	{
		for(i=0; i<N; i++)
		{
			for(k=0; k<N; k++)
				printf("%d ", Q[i][k]);
			printf("\n");
		}
		printf("\nEnter continue....\n");
		getche();
		count++;
		return;
	}
	for(i=0; i<N; i++)
	{
		if( isCorrect(i, j, Q) )
		{
			Q[i][j] = 1;
			Queen(j+1, Q);				/*�������������ռ���*/
			Q[i][j] = 0;				/*����*/
		}
	}
}

main()
{
	int Q[N][N];
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			Q[i][j] =0;					/*��ʼ������*/
	Queen(0,Q);							/*�ӵ�һ�п�ʼ*/
	printf("The number of answers of %d_Queen are %d",N, count);
	getche();
}
