#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;
}LinkList;


/*����Ų��ң�����ָ��p*/
LinkList *GetIst(LinkList *head,int i)  //ע�������*GetIst����*����Ϊ�ú�����ָ�����͵ķ���ֵp;
{
	LinkList *p=head;
	int j=0;
	while((j<i)&&(p->next!=NULL))
	{
		p=p->next;
		j++;
	}
	if(j==i)
		return p;
	else
	{
		printf("�Ҳ����ýڵ㣡");
		exit(1);
	}
}

/*����ֵ=x��Ԫ�ص�λ��*/
int LocateX(LinkList *head,DataType x)  //LocateXǰ��Ӳ���*�����ԣ�ע����ǰһ�������Ĳ�ͬ;
{
	LinkList *p=head->next;
	int i=1;
	while(p!=NULL)
		if(p->data!=x)
		{
			p=p->next;
			i++;
		}
		else break;
	if(p==NULL)  //��p�Ѿ�ָ���˶�β
	{
		printf("�Ҳ����ýڵ㣡"); 
		exit(1);
	}
	else return i;
}

/*��p�����Ԫ��*/
void InsertAfter(LinkList *p,DataType x)
{
	LinkList *s;
	s=malloc(sizeof(LinkList));
	s->data=x;
	
	//�޸�p���
	s->next=p->next;
	p->next=s;
}

/*��pǰ����Ԫ�أ�����ǰ����*/
void InsertBefore1(LinkList *head,LinkList *p,DataType x)
{
	LinkList *s,*q;
	s=malloc(sizeof(LinkList));
	s->data=x;

	//����p��ǰ��
	q=head;
	while(q->next!=p) q=q->next;
	
	//��x����q֮��p֮ǰ
	s->next=p;
	q->next=s;
}

/*��pǰ����Ԫ�أ�������*/
void InsertBefore2(LinkList *p,DataType x)
{
	LinkList *s;
	s=malloc(sizeof(LinkList));
	
	//��p���Ƹ�s
	s->data=p->data;
	s->next=p->next;
	
	//��p����ֵ�����޸�����Ϊs
	p->data=x;
	p->next=s;
}

/*�ڵ�iλ����Ԫ��x*/
void Insert(LinkList *head,DataType x,int i)
{
	LinkList *p;
	p=GetIst(head,i-1); //��Ϊ�ú�巨������Ҫ��i��ǰһλָ��
	InsertAfter(p,x);
}

/*ɾ��p�ĺ�һ��Ԫ��*/
void DeleteAfter(LinkList *p)
{
	LinkList *r;
	if(p->next==NULL)
	{
		printf("����λ�ã�");
		exit(1);
	}
	else
	{
		//�޸�p�ĺ�̣�ʹ�����һλ�����ͷ�ԭ���ĺ��
		r=p->next;
		p->next=r->next;
		free(r);
	}
}

/*ɾ����i��Ԫ��*/
void Delete(LinkList *head,int i)
{
	LinkList *p;
	p=GetIst(head,i-1); //��Ϊ�ú�ɾ��������Ҫ��i��ǰһλָ��
	DeleteAfter(p);
}


/*ͷ�巨�ص�:��ͷ��㣬headָ��ʼ��ָ����������Ǹ�Ԫ��*/
LinkList *CreListTou()
{
	int x;
	LinkList *head,*s;
	head=NULL;
	scanf("%d",&x);
	while(x!=-1)    //����-1�������
	{
		s=malloc(sizeof(LinkList));
		s->data=x;

		//�޸�headָ��
		s->next=head;
		head=s;
		scanf("%d",&x);
	}
	return head;
}

/*β�巨�ص㣺����ͷ��㣬head�̶�ָ��ͷ��㣬rָ��β�ڵ�*/
LinkList *CreListWei()
{
	int x;
	LinkList *head,*s,*r;
	head=malloc(sizeof(LinkList));
	r=head;
	scanf("%d",&x);
	while(x!=-1)   //����-1�������
	{
		s=malloc(sizeof(LinkList));
		s->data=x;

		//�޸�rָ��
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return head;
}

/*������ı���*/
void Traverse(LinkList *head)
{
	LinkList *p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}


void main()
{
	/*����*/
	LinkList *head,*p;
	int a;
	head=CreListWei();
	Traverse(head);
	a=LocateX(head,3);
	printf("\n����Ԫ�ص�λ��Ϊ��%d\n",a);
/*	Insert(head,55,1);
	printf("\n");Traverse(head);
	Delete(head,1);
	printf("\n");Traverse(head);*/
}