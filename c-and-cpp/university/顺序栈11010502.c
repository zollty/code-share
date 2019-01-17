/*顺序栈*/
#include<stdio.h>
#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int top;
}SeqStack;


//置栈空
void Initial(SeqStack *S)
{
	S->top=-1;
}


//判栈空
int IsEmpty(SeqStack *S)
{
	return S->top==-1;
}

//进栈
void Push(SeqStack *S,DataType x)
{
	if(S->top+1==MAXSIZE)
	{
		printf("Overflow!");
		exit(1);
	}
	S->data[++S->top]=x;
}

//出栈
DataType Pop(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("Underflow!");
		exit(1);
	}
	return S->data[S->top--];  //返回已经出栈的元素
}

//取栈顶
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
	SeqStack S={{10,11,12,13,14,15,16,17,18,19},9};  //顺序表的赋值，注意要按这种方式
	
	//测试部分
	Push(&S,20);
	printf("%d\n",S.data[10]);
	Pop(&S);
	printf("%d\n",Top(&S));
}

