#include<stdio.h>
#define QueueSize 100
typedef int DataType;
typedef struct
{
	DataType data[QueueSize];
	int front;//ͷָ��
	int rear;//βָ��     
}CirQueue;   

// �ö��п�
void Initial(CirQueue *Q)
{
	Q->front=Q->rear=QueueSize-1;     
}

// �ж��п�
int IsEmpty(CirQueue *Q)
{
	return Q->front==Q->rear;
}

//�ж�����
int IsFull(CirQueue *Q)
{
	return (Q->rear+1)%QueueSize==Q->front;
}

//���
void EnQueue(CirQueue *Q,DataType x)
{
	if (IsFull(Q))
	{
		printf("��������"); //����,�˳�����
		exit(1);
	}
	Q->data[Q->rear]=x;                 //��Ԫ�ز����β
	Q->rear=(Q->rear+1)%QueueSize;      //ѭ�������½�βָ���1
}

//����
DataType DeQueue(CirQueue *Q)
{
	DataType temp;
	if(IsEmpty(Q))
	{
		printf("����Ϊ��"); //����,�˳�����
		exit(1);
	}
	temp=Q->data[Q->front];
	Q->front=(Q->front+1)%QueueSize;   //ѭ�������µ�ͷָ���1
	return temp; 
}

// ȡ���ж�Ԫ��
DataType Front(CirQueue *Q)
{
	if(IsEmpty(Q))
	{
		printf("����Ϊ��"); //����,�˳�����
		exit(1);
	}
	return Q->data[Q->front];
}


void main()
{
	CirQueue s;
	DataType first,sec;
	Initial(&s);
	EnQueue(&s,55);
	EnQueue(&s,66);
	first=Front(&s);
	DeQueue(&s);
	sec=Front(&s);
	DeQueue(&s);
}