/*��ջ
ע��ͷ�巨����ʱ������������β�巨����ʱ����һ�㲻ͬ��
������cpp����Ϊcpp��malloc������ִ���.
*/
#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;  //֪�����Ƶ������˰ɣ������Ҫ�õ�node

}LinkStack;

typedef struct
{
	LinkStack *top;

}TopNode;


/*ͷ�巨�ص�:��ͷ��㣬topָ��ʼ��ָ����������Ǹ�Ԫ��*/
LinkStack *CreListTou()
{
	int x;
	TopNode T;
	LinkStack *S;
	T.top=NULL;  //Ϊʲô��T.top������T->top��ע��ǰ��T�Ķ��壬����T�ǽṹ�����ָ�롣
	scanf("%d",&x);
	while(x!=-1)    //����-1�������
	{
		S=malloc(sizeof(LinkStack));
		S->data=x;

		//�޸�topָ��
		S->next=T.top;
		T.top=S;
		scanf("%d",&x);
	}
	return T.top;
}

//��ջ��
void Initial(TopNode *T)
{
	//Tֻ��һ��ָ��ջ����ָ�������(Ҳ��ָ��)��T->top����ָ��ջ����ָ�루LinkStack�ͣ�
	T->top=NULL; //ע�Ȿ������T->top��ָ�룬����������
}

//��ջ��
int IsEmpty(TopNode *T)
{
	return T->top==NULL;
}

//��ջ
void Push(TopNode *T,DataType x)  //T��ָ��ջ����ָ�������
{
	LinkStack *S;
	S=malloc(sizeof(LinkStack));
    S->data=x;

	//��S�ĺ������Ϊԭջ��,S��Ϊ�µ�ջ��
    S->next=T->top;
	T->top=S;
}

//��ջ
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

//������ı���
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
	//���Բ���
	TopNode T; //T����*����Tֻ�Ǹ����ƣ����Ժ���Ҫ��T.top��&Tȥ���ã�����ָ������T->top��T����ע����䡣
	T.top=CreListTou();
	//Initial(&T);
	Push(&T,55);
	Push(&T,28);
	Traverse(&T);
	Pop(&T);
	Traverse(&T);
}

