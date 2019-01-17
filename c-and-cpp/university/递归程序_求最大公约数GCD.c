/*递归程序_求最大公约数GCD，Joseph Stein算法
   Author：Tianyong-Tsow（邹天涌）
 */
#include <stdio.h>

//这个算法虽然可行，但是实际上效率比较低。
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
	if(u%2==0 && v%2==0)	//都为偶数
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
	printf("请输入两个正整数：");
	scanf("%ld%ld",&u,&v);
	s=jsgcf(u,v);
	printf("u和v的最大公约数为：%ld\n",s);
	return 0;
}