/* ����C������˵����
	1. һ��һ�䣨����ּ���д����
	2. ���л�����'{'��'}'��ռһ�У������¶��룻
	3. �����������Ĳ�Σ�ͬ���������ͬ��������
	4. ʹ�ÿ��У�ʹ����������
	5. ʹ�ÿո�ʹ�������ˡ���������
	6. ע�����Ϸ����ҷ�����ע�ͷֶ���
	7. if��for��while ������ռһ�У�����ִ����伴ʹֻ��һ��Ҳ�û�������������
	8. �������򣺺���ȫ��д������������ĸ��д������������ĸСд����˼�����ˣ�����������������ע�͡�
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

//�ÿ�
void Initial(SeqList *L)
{
	L->last = -1;
}

//��
int Length(SeqList *L)
{
	return L->last+1;
}

//�жϱ��
int IsEmpty(SeqList *L)
{
	return L->last == -1;
}


//��ȡ��i��Ԫ�ص�ֵ
DataType GetiValue(SeqList *L, int i)
{
	if ((i >= 1) && (i <= L->last+1))
	{
		return L->data[i-1];
	}
	else
	{
		printf("�Ҳ����ýڵ㣡");
		exit(1);
	}
}

//����ֵ=x��Ԫ�ص�λ��
int LocateX(SeqList *L, DataType x)
{
	int i = 1;

	while ((x != L->data[i-1]) && (i <= L->last))
	{
		i++;
	}

	if (i <= L->last+1)
	{
		return i;
	}
	else
	{
		printf("��Ԫ�ز��ڱ���");
		exit(1);
	}
}

//��x��ǰ��
DataType GetPrior(SeqList *L, DataType x)
{
	int i = LocateX(L, x);

	if (i == 1)
	{
		printf("��һ��Ԫ��û��ǰ��");
		exit(1);
	}
	else 
	{
		return L->data[i-2];
	}
}

//��x�ĺ��
DataType GetSuccessor(SeqList *L, DataType x)
{
	int i = LocateX(L, x);

	if (i == L->last+1)
	{
		printf("���һ��Ԫ��û�к��");
		exit(1);
	}
	else
	{
		return L->data[i];
	}
}

//�ڵ�iλ����Ԫ�أ��ڵ����
void InsertX(SeqList *L, int i, DataType x)
{
	int j;

	if (L->last+1 == MAXSIZE)
	{
		printf("���������޷�����");
		exit(1);
	}

	  //���1
	if ((i < 1) || (i > L->last+2))
	{
		printf("������Χ");
		exit(1);
	}
	  //���2
	else if (i == L->last+2)
	{
		L->data[i] = x;  //ֱ�Ӳ��뵽��β
		L->last++;
	}
	  //���3
	else
	{
		for (j = L->last+2; j >= i; j--)
		{
			L->data[j] = L->data[j-1];	//�ڳ���iλ
		}

		L->data[j] = x;
		L->last++;  //last����1
	}
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


void main()                           //������
{
	SeqList L={{10,11,12,13,14,15,16,17,18,19},9};  //˳���ĸ�ֵ��ע��Ҫ�����ַ�ʽ
	//////����/////////////////////
	InsertX(&L, 10, 20);
 	Traverse(&L);
	DeleteIst(&L, 11);
	Traverse(&L);
	printf("%d\n", GetiValue(&L,10));
}