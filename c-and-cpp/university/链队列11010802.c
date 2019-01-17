#include<stdio.h>
#define QueueSize 100 //假定预分配的队列空间最多为100个元素  
typedef char DataType ; //假定队列元素的数据类型为字符
typedef struct node{
	DataType data;
	struct node *next;
}LinkQueue;
typedef struct{
	LinkQueue *front;  //头指针
	LinkQueue *rear;
}QueueNode;

// 置队列空
void Initial(QueueNode *Q)
{
    Q->front=Q->rear=NULL;
} 
//判队列空
int IsEmpty(QueueNode *Q)
{
    return Q->front==NULL&&Q->rear==NULL;
}
//进队列
void Push(QueueNode *Q,DataType x)
{//将元素x插入链队列尾部
	LinkQueue *p=(LinkQueue *)malloc(sizeof(LinkQueue));//申请新结点
	p->data=x;
	p->next=NULL;
    if(IsEmpty(Q))
		Q->front=Q->rear=p;  //将x插入空队列
	else 
	{
		Q->rear->next=p; //(Q->rear)是队尾的指针，即：使队尾结构体的next指针指向p
		Q->rear=p;       //队尾指针指向新的尾
	}
}
//出队列
DataType Pop(QueueNode *Q)
{
	DataType x;
	LinkQueue *p;
	if(IsEmpty(Q))
	{
		printf("error,队列已为空，无法再出栈！");//下溢
		exit(1);
	}
	p=Q->front;                   //保存队头结点
	x=p->data; 
	Q->front=p->next;             //使队头指向p后面的一位
    if(Q->rear==p)//原队中只有一个结点的情况，删去后队列变空，所以尾指针也应置空
		Q->rear=NULL;
	free(p);   //释放被删队头结点
	return x;  //返回原队头数据
}
// 取队列顶元素
DataType Front(QueueNode *Q)
{
	if(IsEmpty(Q))
	{
		printf("队列为空"); //下溢,退出运行
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
