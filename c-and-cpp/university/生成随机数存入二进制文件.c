/* ****************************************************************************
�������������������ļ�����ȡ
	���ߣ�����ӿ
**************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATASIZE 10000	//�������ɵ������С

int main(int argc, char ** argv)
{
	const char * file_name = "out.dat";
	FILE * fp;	//����������������Ķ���֮ǰ
	int i, a[DATASIZE];
	srand( time(NULL) );//��ʼ��ʱ������
	fp = fopen(file_name, "wb");//�½�һ���������ļ����п�д����
	for(i=0; i<DATASIZE; i++)
	{
		a[i]=rand()%100;//����0~99֮�������
		fwrite(&a[i], sizeof(int), 1, fp);//�����������ļ�
	}

	for(i=0; i<10; i++)//��������ǰ10�����Ա�۲�
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
    return 0;
}
/*����������ĵ���out.dat�ļ��ķ�ʽ���£�
	fp = fopen(file_name, "rb");//��һ�����ڵĶ����ƽ��ж�����
	fread(&a, sizeof(int), DATASIZE, fp);//��ȡDATASIZE�����ݵ�aָ���ַ
	fclose(fp);//���Źر��ļ�
*/
