/* ****************************************************************************
���Գ�������ʱ��
	���ߣ�����ӿ
**************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
�ڴ˿���������ͷ�ļ����߶���꣬���磺
#define DATASIZE 180000
*/

void sleep( clock_t wait );//���������������main����

/*
�ڴ˿�����Ҫ���Եĺ������룬���磺
void InsertSort(int *a, int r){}
*/

void main( void )
{
	/*�ڴ˿ɶ����������������磺
	const char * file_name = "out.dat";
	FILE * fp;//���FILE���͵Ķ����������������������ǰ��
	*/

	clock_t start, finish;//����clock_t���͵ı���
	double duration;

	/*�ڴ˿ɽ����������������磺
	int array[DATASIZE];
	int array_size = DATASIZE;
	fp = fopen(file_name, "rb");
	fread(&array, sizeof(int), DATASIZE, fp);
	*/

	//sleep���÷�
	printf( "Delay for three seconds\n" );
	sleep( (clock_t)3 * CLOCKS_PER_SEC );
	printf("Done!\n");

	//������������ʱ��
	start = clock();//��ʱ��ʼ

	/*�ڴ˷�����Ҫ��ʱ�ĳ������磺
	ShellSort(array, array_size-1);
	*/

	finish = clock();//��ʱ����
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "This algorithm run %f seconds\n", duration );

	/*�ڴ˿ɽ����������������磺
	printf( "After sorting: " );
	for(i = 0; i < 300; i++ )
	{
		printf( "%d ", array[i] );
	}
	printf( "\n" );
	*/

}

//����sleep����
void sleep( clock_t wait )
{
  clock_t goal;
  goal = wait + clock();//clock��ȡ��ǰʱ��
  while( goal > clock() )//clock�Զ��仯�������ӵ���goal����
  ;
}