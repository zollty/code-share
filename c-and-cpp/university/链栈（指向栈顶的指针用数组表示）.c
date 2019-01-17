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


/*ͷ�巨�ص�:��ͷ��㣬topָ��ʼ��ָ����������Ǹ�Ԫ��*/
LinkStack *CreListTou()
{
	int x;
	LinkStack *K;
	LinkStack *S;
	K=NULL;  //Ϊʲô��T.top������T->top��ע��ǰ��T�Ķ��壬����T�ǽṹ�����ָ�롣
	scanf("%d",&x);
	while(x!=-1)    //����-1�������
	{
		S=malloc(sizeof(LinkStack));
		S->data=x;

		//�޸�topָ��
		S->next=K;
		K=S;
		scanf("%d",&x);
	}
	return K;
}

//��ջ��
void Initial(LinkStack *T[])
{
	//Tֻ��һ��ָ��ջ����ָ�������(Ҳ��ָ��)��T->top����ָ��ջ����ָ�루LinkStack�ͣ�
	T[0]=NULL; //ע�Ȿ������T->top��ָ�룬����������
}

//��ջ��
int IsEmpty(LinkStack *T[])
{
	return T[0]==NULL;
}

//��ջ
void Push(LinkStack *T[],DataType x)  //T��ָ��ջ����ָ�������
{
	LinkStack *S;
	S=malloc(sizeof(LinkStack));
    S->data=x;

	//��S�ĺ������Ϊԭջ��,S��Ϊ�µ�ջ��
    S->next=T[0];
	T[0]=S;
}

//��ջ
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

//������ı���
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
	//���Բ���
	LinkStack * TopNode[1];
	TopNode[0]=CreListTou();
	//Initial(&T);
	Push(TopNode,55);
	Push(TopNode,28);
	Traverse(TopNode);
	Pop(TopNode);
	Traverse(TopNode);
}
