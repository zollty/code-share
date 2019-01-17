#include<stdio.h>
#include<malloc.h>
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;
}LinkList;


/*按序号查找，返回指针p*/
LinkList *GetIst(LinkList *head,int i)  //注意必须用*GetIst，有*，因为该函数有指针类型的返回值p;
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
		printf("找不到该节点！");
		exit(1);
	}
}

/*查找值=x的元素的位置*/
int LocateX(LinkList *head,DataType x)  //LocateX前面加不加*都可以，注意与前一个函数的不同;
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
	if(p==NULL)  //即p已经指向了队尾
	{
		printf("找不到该节点！"); 
		exit(1);
	}
	else return i;
}

/*在p后插入元素*/
void InsertAfter(LinkList *p,DataType x)
{
	LinkList *s;
	s=malloc(sizeof(LinkList));
	s->data=x;
	
	//修改p后继
	s->next=p->next;
	p->next=s;
}

/*在p前插入元素，查找前驱法*/
void InsertBefore1(LinkList *head,LinkList *p,DataType x)
{
	LinkList *s,*q;
	s=malloc(sizeof(LinkList));
	s->data=x;

	//查找p的前驱
	q=head;
	while(q->next!=p) q=q->next;
	
	//将x插入q之后，p之前
	s->next=p;
	q->next=s;
}

/*在p前插入元素，交换法*/
void InsertBefore2(LinkList *p,DataType x)
{
	LinkList *s;
	s=malloc(sizeof(LinkList));
	
	//将p复制给s
	s->data=p->data;
	s->next=p->next;
	
	//给p赋新值，并修改其后继为s
	p->data=x;
	p->next=s;
}

/*在第i位插入元素x*/
void Insert(LinkList *head,DataType x,int i)
{
	LinkList *p;
	p=GetIst(head,i-1); //因为用后插法，所以要找i的前一位指针
	InsertAfter(p,x);
}

/*删除p的后一个元素*/
void DeleteAfter(LinkList *p)
{
	LinkList *r;
	if(p->next==NULL)
	{
		printf("错误位置！");
		exit(1);
	}
	else
	{
		//修改p的后继，使其后移一位，并释放原来的后继
		r=p->next;
		p->next=r->next;
		free(r);
	}
}

/*删除第i个元素*/
void Delete(LinkList *head,int i)
{
	LinkList *p;
	p=GetIst(head,i-1); //因为用后删法，所以要找i的前一位指针
	DeleteAfter(p);
}


/*头插法特点:无头结点，head指针始终指向最后插入的那个元素*/
LinkList *CreListTou()
{
	int x;
	LinkList *head,*s;
	head=NULL;
	scanf("%d",&x);
	while(x!=-1)    //输入-1代表结束
	{
		s=malloc(sizeof(LinkList));
		s->data=x;

		//修改head指向
		s->next=head;
		head=s;
		scanf("%d",&x);
	}
	return head;
}

/*尾插法特点：生成头结点，head固定指向头结点，r指向尾节点*/
LinkList *CreListWei()
{
	int x;
	LinkList *head,*s,*r;
	head=malloc(sizeof(LinkList));
	r=head;
	scanf("%d",&x);
	while(x!=-1)   //输入-1代表结束
	{
		s=malloc(sizeof(LinkList));
		s->data=x;

		//修改r指向
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return head;
}

/*单链表的遍历*/
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
	/*测试*/
	LinkList *head,*p;
	int a;
	head=CreListWei();
	Traverse(head);
	a=LocateX(head,3);
	printf("\n所找元素的位置为：%d\n",a);
/*	Insert(head,55,1);
	printf("\n");Traverse(head);
	Delete(head,1);
	printf("\n");Traverse(head);*/
}