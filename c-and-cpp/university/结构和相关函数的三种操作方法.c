/*�ṹ����غ��������ֲ�������
   Author��Tianyong-Tsow������ӿ��
 */

#include <stdio.h>
//#include <stdlib.h>	//cpp��Ҫ�����c����Ҫ
#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int last;	//������һ��Ԫ�ص�λ�ã�Ҳ����˳����ʵ�ʳ���-1

}SeqList;

//�±��0��ʼ///


void main()                           //������
{

////ָ����ʽ��Ӧ��L->data[i])����ͨ��ʽ��Ӧ��L.data[i] ////
	void Traverse(SeqList *L);
	void DeleteIst(SeqList *L, int i);
	SeqList *L = malloc(sizeof(SeqList));//ָ����ʽ��L
	int i;
	for(i=0;i<10;i++)
		scanf("%d", &(L->data[i]) );
	printf("Input last:");
	scanf("%d", &(L->last) );

 	Traverse(L);//Traverse(L)��void Traverse(SeqList *L)��Ӧ����Ҫд��Traverse(&L)��
	DeleteIst(L, 10);
	Traverse(L);


/*
	void Traverse(SeqList L);//�ǵ��޸ĸú����ڲ�L->data[i]ΪL.data[i]
//	void DeleteIst(SeqList L);// ��ͨ��ʽ,�޷�ʵ���Ե�ɾ��L�е�Ԫ��
	void DeleteIst(SeqList *L);//ָ����ʽ���������޸�L��
	SeqList L;//��ͨL
	int i;
	for(i=0;i<10;i++)
		scanf("%d",&L.data[i]);
	printf("Input last:");
	scanf("%d",&L.last);

	Traverse(L);
//	DeleteIst(L, 10);//��Ӧ��void DeleteIst(SeqList L)
	DeleteIst(&L, 10);//��Ӧ��void DeleteIst(SeqList *L)
	Traverse(L);
*/

/*
	void Traverse(SeqList *L);
	void DeleteIst(SeqList *L, int i);
	SeqList L={{10,11,12,13,14,15,16,17,18,19},9};//ֱ�Ӹ�ֵ��ʽ

 	Traverse(&L);// Traverse(&L)��void Traverse(SeqList *L)��Ӧ����Ҫд��Traverse(L)��
					// ������ָ����ʽ��Lʱ���ǡǡ�෴��
	DeleteIst(&L, 10);
	Traverse(&L);
*/

}//end main


//��ı���
void Traverse(SeqList *L)
{
	int i;

	if (L->last == -1)
	{
		printf("���Ǹ��ձ�");
	}
	else
	{
		for (i = 0; i <= L->last; i++)
		{
			printf("%d ", L->data[i]);
		}
	}

	printf("\n");
}

//ɾ����i��Ԫ��
void DeleteIst(SeqList *L, int i)
{
	int j;

	  //���1
	if ((i < 1) || (i > L->last+1))
	{
		printf("������Χ");
		exit(1);
	}
	  //���2
	else if (i == L->last+1)
	{
		L->data[i] = NULL;  //��βֱ��ɾ��
		L->last--;
	}
	  //���3
	else
	{
		for (j = i; j <= L->last; j++)
		{
			L->data[j-1] = L->data[j];
		}

		L->last--;
	}
}