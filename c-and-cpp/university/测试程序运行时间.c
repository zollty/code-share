/* ****************************************************************************
测试程序运行时间
	作者：邹天涌
**************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
在此可引入其他头文件或者定义宏，例如：
#define DATASIZE 180000
*/

void sleep( clock_t wait );//函数声明，定义见main后面

/*
在此可贴入要测试的函数代码，例如：
void InsertSort(int *a, int r){}
*/

void main( void )
{
	/*在此可定义其他变量，例如：
	const char * file_name = "out.dat";
	FILE * fp;//这个FILE类型的定义必须放在其他变量定义的前面
	*/

	clock_t start, finish;//定义clock_t类型的变量
	double duration;

	/*在此可进行其他操作，例如：
	int array[DATASIZE];
	int array_size = DATASIZE;
	fp = fopen(file_name, "rb");
	fread(&array, sizeof(int), DATASIZE, fp);
	*/

	//sleep的用法
	printf( "Delay for three seconds\n" );
	sleep( (clock_t)3 * CLOCKS_PER_SEC );
	printf("Done!\n");

	//计算程序的运行时间
	start = clock();//计时开始

	/*在此放入需要计时的程序，例如：
	ShellSort(array, array_size-1);
	*/

	finish = clock();//计时结束
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "This algorithm run %f seconds\n", duration );

	/*在此可进行其他操作，例如：
	printf( "After sorting: " );
	for(i = 0; i < 300; i++ )
	{
		printf( "%d ", array[i] );
	}
	printf( "\n" );
	*/

}

//定义sleep函数
void sleep( clock_t wait )
{
  clock_t goal;
  goal = wait + clock();//clock获取当前时间
  while( goal > clock() )//clock自动变化，会增加到比goal还大
  ;
}