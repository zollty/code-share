/*�ݹ����_�����Լ��GCD��Joseph Stein�㷨
   Author��Tianyong-Tsow������ӿ��
 */
#include <stdio.h>

//����㷨��Ȼ���У�����ʵ����Ч�ʱȽϵ͡�
long jsgcf(long u,long v)
{
	if(u==1 || v==1)
	{
		return 1;
		exit(1);
	}
	if(u==0)
	{
		return v;
		exit(1);
	}
	if(v==0)
	{
		return u;
		exit(1);
	}
	if(u%2==0 && v%2==0)	//��Ϊż��
		return 2*jsgcf(u/2,v/2);
	if(u%2==0 && v%2!=0)
		return jsgcf(u/2,v);
	if(u%2!=0 && v%2==0)
		return jsgcf(u,v/2);
	else
	{
		if(u>v)
			return jsgcf(u-v,v);
		else
			return jsgcf(v-u,u);
	}
}


int main()
{
	long u,v,s;
	printf("������������������");
	scanf("%ld%ld",&u,&v);
	s=jsgcf(u,v);
	printf("u��v�����Լ��Ϊ��%ld\n",s);
	return 0;
}