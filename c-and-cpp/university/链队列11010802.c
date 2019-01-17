#include<stdio.h>
#define QueueSize 100 //�ٶ�Ԥ����Ķ��пռ����Ϊ100��Ԫ��  
typedef char DataType ; //�ٶ�����Ԫ�ص���������Ϊ�ַ�
typedef struct node{
	DataType data;
	struct node *next;
}LinkQueue;
typedef struct{
	LinkQueue *front;  //ͷָ��
	LinkQueue *rear;
}QueueNode;

// �ö��п�
void Initial(QueueNode *Q)
{
    Q->front=Q->rear=NULL;
} 
//�ж��п�
int IsEmpty(QueueNode *Q)
{
    return Q->front==NULL&&Q->rear==NULL;
}
//������
void Push(QueueNode *Q,DataType x)
{//��Ԫ��x����������β��
	LinkQueue *p=(LinkQueue *)malloc(sizeof(LinkQueue));//�����½��
	p->data=x;
	p->next=NULL;
    if(IsEmpty(Q))
		Q->front=Q->rear=p;  //��x����ն���
	else 
	{
		Q->rear->next=p; //(Q->rear)�Ƕ�β��ָ�룬����ʹ��β�ṹ���nextָ��ָ��p
		Q->rear=p;       //��βָ��ָ���µ�β
	}
}
//������
DataType Pop(QueueNode *Q)
{
	DataType x;
	LinkQueue *p;
	if(IsEmpty(Q))
	{
		printf("error,������Ϊ�գ��޷��ٳ�ջ��");//����
		exit(1);
	}
	p=Q->front;                   //�����ͷ���
	x=p->data; 
	Q->front=p->next;             //ʹ��ͷָ��p�����һλ
    if(Q->rear==p)//ԭ����ֻ��һ�����������ɾȥ����б�գ�����βָ��ҲӦ�ÿ�
		Q->rear=NULL;
	free(p);   //�ͷű�ɾ��ͷ���
	return x;  //����ԭ��ͷ����
}
// ȡ���ж�Ԫ��
DataType Front(QueueNode *Q)
{
	if(IsEmpty(Q))
	{
		printf("����Ϊ��"); //����,�˳�����
		exit(1);
	}
	return Q->front->data;
}

void main()
{
	QueueNode s;
	DataType first,sec;
	Initial(&s);
	Push(&s,'a');
	first=Front(&s);
	Pop(&s);
	Pop(&s);
	sec=Front(&s);
	printf("%c",sec);
	Pop(&s);
}
