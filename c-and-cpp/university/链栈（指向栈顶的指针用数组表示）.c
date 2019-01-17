/*链栈
注意头插法建表时，遍历函数和尾插法建表时的有一点不同；
不能用cpp，因为cpp下malloc语句会出现错误.
*/
#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;  //知道名称的作用了吧，这里就要用到node

}LinkStack;


/*头插法特点:无头结点，top指针始终指向最后插入的那个元素*/
LinkStack *CreListTou()
{
	int x;
	LinkStack *K;
	LinkStack *S;
	K=NULL;  //为什么用T.top而不用T->top？注意前面T的定义，这里T是结构体而非指针。
	scanf("%d",&x);
	while(x!=-1)    //输入-1代表结束
	{
		S=malloc(sizeof(LinkStack));
		S->data=x;

		//修改top指向
		S->next=K;
		K=S;
		scanf("%d",&x);
	}
	return K;
}

//置栈空
void Initial(LinkStack *T[])
{
	//T只是一个指向栈顶的指针的名称(也是指针)，T->top才是指向栈顶的指针（LinkStack型）
	T[0]=NULL; //注意本程序里T->top是指针，不再是数字
}

//判栈空
int IsEmpty(LinkStack *T[])
{
	return T[0]==NULL;
}

//进栈
void Push(LinkStack *T[],DataType x)  //T是指向栈顶的指针的名称
{
	LinkStack *S;
	S=malloc(sizeof(LinkStack));
    S->data=x;

	//将S的后继设置为原栈顶,S成为新的栈顶
    S->next=T[0];
	T[0]=S;
}

//出栈
DataType Pop(LinkStack *T[])
{
	LinkStack *p;
	DataType x;
	if(IsEmpty(T))
	{
		printf("It's empty!");
		exit(1);
	}
	p=T[0];
	x=p->data;
	T[0]=p->next;
	free(p);
	return x;
}

//单链表的遍历
void Traverse(LinkStack *T[])
{
	LinkStack *p=T[0];
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}



void main()
{
	//测试部分
	LinkStack * TopNode[1];
	TopNode[0]=CreListTou();
	//Initial(&T);
	Push(TopNode,55);
	Push(TopNode,28);
	Traverse(TopNode);
	Pop(TopNode);
	Traverse(TopNode);
}
