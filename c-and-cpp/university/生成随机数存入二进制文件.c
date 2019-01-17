/* ****************************************************************************
生成随机数存入二进制文件并读取
	作者：邹天涌
**************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATASIZE 10000	//设置生成的数组大小

int main(int argc, char ** argv)
{
	const char * file_name = "out.dat";
	FILE * fp;	//必须放在其他变量的定义之前
	int i, a[DATASIZE];
	srand( time(NULL) );//初始化时间种子
	fp = fopen(file_name, "wb");//新建一个二进制文件进行可写操作
	for(i=0; i<DATASIZE; i++)
	{
		a[i]=rand()%100;//生成0~99之间的整数
		fwrite(&a[i], sizeof(int), 1, fp);//将整数存入文件
	}

	for(i=0; i<10; i++)//输出数组的前10个数以便观察
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
    return 0;
}
/*在其他程序的调用out.dat文件的方式如下：
	fp = fopen(file_name, "rb");//打开一个存在的二进制进行读操作
	fread(&a, sizeof(int), DATASIZE, fp);//读取DATASIZE个数据到a指针地址
	fclose(fp);//记着关闭文件
*/
