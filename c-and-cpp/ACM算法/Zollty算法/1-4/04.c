#include<stdio.h> 
#define M 100

struct Mystack
{
	char element[M];
	int top;
};

void push(struct Mystack *s,char x) //��xֵѹ��ջ����
{
	s->element[s->top]=x;
	s->top++;
}

int isEmpty(struct Mystack *s) //�ж�ջ�Ƿ�Ϊ�ա�
{
	if(s->top==0)
		return 1;
	else
		return 0;
}

void pop(struct Mystack *s) //��ջ��������ջ��Ԫ��ɾ����
{
	s->top--;
}

void displayStack(struct Mystack *s) //��ʾջ�׵�ջ������Ԫ�ء�
{
	int i;
	for(i=0;i<s->top;i++)
		printf("%c",s->element[i]);
}

void clearStack(struct Mystack *s) //��ջ��ա�
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
	printf("������һ���ַ���\n");
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
	printf("��Ч�ַ�Ϊ��\n");
	displayStack(&st);
	printf("\n");
}
