/*һ������������������㷨
   Author��Tianyong-Tsow������ӿ��
 */
#include <stdio.h>
#define N 20

//���ͬ�෨
int randMixCongruence(int x0,int a,int m)
{//x0Ϊ������ʼ�㣬aΪ��������x��ϵ����mΪģ�����ɵ��������Χ��0~m-1֮�䣩
//nΪ����������ĸ�����
	int x[N+1],i;
	int r[N];//r[n]��Ϊ���ɵ������
	x[0]=x0;
	for(i=0;i<N;i++)
	{
		x[i+1]=a*x[i]+i;//xΪ�������У���ʹa=2����ô����64�κ󣨴�10^19����Ȼ�����int�����޷����ܣ�
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