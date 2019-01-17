#include<stdio.h>
#define QueueSize 100
typedef int DataType;
typedef struct
{
	DataType data[QueueSize];
	int front;//头指针
	int rear;//尾指针     
}CirQueue;   

// 置队列空
void Initial(CirQueue *Q)
{
	Q->front=Q->rear=QueueSize-1;     
}

// 判队列空
int IsEmpty(CirQueue *Q)
{
	return Q->front==Q->rear;
}

//判队列满
int IsFull(CirQueue *Q)
{
	return (Q->rear+1)%QueueSize==Q->front;
}

//入队
void EnQueue(CirQueue *Q,DataType x)
{
	if (IsFull(Q))
	{
		printf("队列上溢"); //上溢,退出运行
		exit(1);
	}
	Q->data[Q->rear]=x;                 //新元素插入队尾
	Q->rear=(Q->rear+1)%QueueSize;      //循环意义下将尾指针加1
}

//出队
DataType DeQueue(CirQueue *Q)
{
	DataType temp;
	if(IsEmpty(Q))
	{
		printf("队列为空"); //下溢,退出运行
		exit(1);
	}
	temp=Q->data[Q->front];
	Q->front=(Q->front+1)%QueueSize;   //循环意义下的头指针加1
	return temp; 
}

// 取队列顶元素
DataType Front(CirQueue *Q)
{
	if(IsEmpty(Q))
	{
		printf("队列为空"); //下溢,退出运行
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