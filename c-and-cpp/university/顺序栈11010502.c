/*˳��ջ*/
#include<stdio.h>
#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int top;
}SeqStack;


//��ջ��
void Initial(SeqStack *S)
{
	S->top=-1;
}


//��ջ��
int IsEmpty(SeqStack *S)
{
	return S->top==-1;
}

//��ջ
void Push(SeqStack *S,DataType x)
{
	if(S->top+1==MAXSIZE)
	{
		printf("Overflow!");
		exit(1);
	}
	S->data[++S->top]=x;
}

//��ջ
DataType Pop(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("Underflow!");
		exit(1);
	}
	return S->data[S->top--];  //�����Ѿ���ջ��Ԫ��
}

//ȡջ��
DataType Top(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("It's empty");
		exit(1);
	}
	return(S->data[S->top]);
}


void main()
{
	SeqStack S={{10,11,12,13,14,15,16,17,18,19},9};  //˳���ĸ�ֵ��ע��Ҫ�����ַ�ʽ
	
	//���Բ���
	Push(&S,20);
	printf("%d\n",S.data[10]);
	Pop(&S);
	printf("%d\n",Top(&S));
}

