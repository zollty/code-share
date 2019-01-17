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

typedef struct
{
	LinkStack *top;

}TopNode;


/*头插法特点:无头结点，top指针始终指向最后插入的那个元素*/
LinkStack *CreListTou()
{
	int x;
	TopNode T;
	LinkStack *S;
	T.top=NULL;  //为什么用T.top而不用T->top？注意前面T的定义，这里T是结构体而非指针。
	scanf("%d",&x);
	while(x!=-1)    //输入-1代表结束
	{
		S=malloc(sizeof(LinkStack));
		S->data=x;

		//修改top指向
		S->next=T.top;
		T.top=S;
		scanf("%d",&x);
	}
	return T.top;
}

//置栈空
void Initial(TopNode *T)
{
	//T只是一个指向栈顶的指针的名称(也是指针)，T->top才是指向栈顶的指针（LinkStack型）
	T->top=NULL; //注意本程序里T->top是指针，不再是数字
}

//判栈空
int IsEmpty(TopNode *T)
{
	return T->top==NULL;
}

//进栈
void Push(TopNode *T,DataType x)  //T是指向栈顶的指针的名称
{
	LinkStack *S;
	S=malloc(sizeof(LinkStack));
    S->data=x;

	//将S的后继设置为原栈顶,S成为新的栈顶
    S->next=T->top;
	T->top=S;
}

//出栈
DataType Pop(TopNode *T)
{
	LinkStack *p;
	DataType x;
	if(IsEmpty(T))
	{
		printf("It's empty!");
		exit(1);
	}
	p=T->top;
	x=p->data;
	T->top=p->next;
	free(p);
	return x;
}

//单链表的遍历
void Traverse(TopNode *T)
{
	LinkStack *p=T->top;
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
	TopNode T; //T不用*代表T只是个名称，所以后面要用T.top和&T去引用（若是指针则用T->top和T），注意搭配。
	T.top=CreListTou();
	//Initial(&T);
	Push(&T,55);
	Push(&T,28);
	Traverse(&T);
	Pop(&T);
	Traverse(&T);
}

