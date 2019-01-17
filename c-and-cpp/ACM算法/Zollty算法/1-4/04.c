#include<stdio.h> 
#define M 100

struct Mystack
{
	char element[M];
	int top;
};

void push(struct Mystack *s,char x) //将x值压入栈顶。
{
	s->element[s->top]=x;
	s->top++;
}

int isEmpty(struct Mystack *s) //判断栈是否为空。
{
	if(s->top==0)
		return 1;
	else
		return 0;
}

void pop(struct Mystack *s) //出栈操作，将栈顶元素删除。
{
	s->top--;
}

void displayStack(struct Mystack *s) //显示栈底到栈顶所有元素。
{
	int i;
	for(i=0;i<s->top;i++)
		printf("%c",s->element[i]);
}

void clearStack(struct Mystack *s) //将栈清空。
{
	s->top=0;
}

void main()
{
	struct Mystack st;
	char ch;
	int i;
	for(i=0;i<M;i++)
	{
		st.element[i]='\0';
	}
	st.top=0;
	printf("请输入一行字符：\n");
	ch=getchar();
	while(ch!=EOF && ch!='\n')
	{
		switch(ch)
		{
			case '#':
				if(!isEmpty(&st))
					pop(&st);
				break;
				
			case '@':
				clearStack(&st);
				break;
				
			default:
				push(&st,ch);
		}
		
		ch=getchar();
	}
	printf("有效字符为：\n");
	displayStack(&st);
	printf("\n");
}
