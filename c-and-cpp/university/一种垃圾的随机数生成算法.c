/*一种垃圾的随机数生成算法
   Author：Tianyong-Tsow（邹天涌）
 */
#include <stdio.h>
#define N 20

//混合同余法
int randMixCongruence(int x0,int a,int m)
{//x0为迭代初始点，a为迭代方程x的系数，m为模（生成的随机数范围在0~m-1之间）
//n为生成随机数的个数。
	int x[N+1],i;
	int r[N];//r[n]即为生成的随机数
	x[0]=x0;
	for(i=0;i<N;i++)
	{
		x[i+1]=a*x[i]+i;//x为递增数列，即使a=2，那么迭代64次后（达10^19）显然都大得int类型无法接受！
		r[i]=(x[i+1])%m;
		printf("%d  ",r[i]);
	}
	return 0;
}


void main()
{ 
	int x0,a,m; 
	randMixCongruence(2,2,8);
	printf("\n");
}