/* 解N皇后问题的回溯递归算法 */
/* 作者：邹天涌 2011-6-18 */

#include "stdio.h"
#define N 4
int count=0;					/*记录解的总个数*/

int isCorrect(int i, int j, int (*Q)[N] )	/*判断能否放置皇后*/
{
	int s, t;
	for(s=i, t=0; t<N; t++)
		if(Q[s][t] == 1 && t != j) return 0;	/*判断行*/

	for(s=0, t=j; s<N; s++)
		if(Q[s][t] == 1 && s != i) return 0;	/*判断列*/

	for(s=i-1, t=j-1; s>=0 && t>=0; s--, t--)
		if(Q[s][t] == 1) return 0;		    	/*判断左上方*/

	for(s=i+1, t=j+1; s<N && t<N; s++, t++)
		if(Q[s][t] == 1) return 0;		    	/*判断右下方*/

	for(s=i-1, t=j+1; s>=0 && t<N; s--, t++)
		if(Q[s][t] == 1) return 0;		    	/*判断右上方*/

	for(s=i+1, t=j-1; s<N && t>=0; s++, t--)
		if(Q[s][t] == 1) return 0;		    	/*判断左下方*/

	return 1;									/*否则返回1 */
}

void Queen(int j, int (*Q)[N] ){
	int i, k;
	if(j == N)								/* j=N 时得到一个解*/
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
			Queen(j+1, Q);				/*深度优先搜索解空间树*/
			Q[i][j] = 0;				/*回溯*/
		}
	}
}

main()
{
	int Q[N][N];
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			Q[i][j] =0;					/*初始化数组*/
	Queen(0,Q);							/*从第一列开始*/
	printf("The number of answers of %d_Queen are %d",N, count);
	getche();
}
