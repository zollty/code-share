#include <stdio.h>
#include "stdlib.h"
#define MAXSIZE 30		/*���Ԫ����*/
typedef struct BiTNode{
   char data;
   struct BiTNode  *lchild, *rchild;	/*���Һ���ָ��*/
}BiTNode, *BiTree;
typedef BiTree ElemType;
typedef struct{
      BiTree data[MAXSIZE];	/*ջ�ռ�*/
      int top;			/*ջ��ָ��*/
}SqStack;			/*ջ����*/

void Init_SqStack(SqStack *S){
   S->top=-1;
}
int Empty_SqStack(SqStack *S){
   if ( S->top==-1)
            return 1;
   else
            return 0;
}
void Push_SqStack (SqStack *S,ElemType x){
   if ( S->top==MAXSIZE-1){	/*ջ��,������ջ*/
        printf(" ջ��! ");
   }
   else				/*ջ����,x��ջ*/
        S->data[++S->top]=x;
}
void Pop_SqStack(SqStack *S,ElemType *x){
   if (Empty_SqStack(S)){		/*ջ��,���ܽ��г�ջ*/
         printf(" ջ��! ");
   }
   else{   			/*ջ��Ԫ�ش������x*/
         *x=S->data[S->top];
         S->top--;
   }
}
void  Top_SqStack(SqStack *S, ElemType *x){
       if ( S->top==-1) 		/*ջ��,���ܶ�ȡջ��Ԫ�� */
            printf(" ջ��!");
       else  			/*ջ��Ԫ�ش������x������*/
           *x=S->data[S->top];
}

void create_BiTree(BiTree *T){ /*�����������������������ַ�,'@'�ַ���ʾ����,����������Ķ�������*/
  char ch;
  ch=getchar();
  if(ch=='@') *T=NULL;
  else{
      *T=(BiTree)malloc(sizeof(BiTNode));
      (*T)->data=ch;   /*���ɸ����*/
      create_BiTree(&(*T)->lchild);	/*����������*/
      create_BiTree(&(*T)->rchild);	/*����������*/
  }
}

void NRpreorder(BiTree T){ 	/*�������������T�ķǵݹ��㷨*/
   SqStack S;
   BiTree p=T;
   Init_SqStack(&S);
   while(p || !Empty_SqStack(&S)){
         if(p){
             printf("%3c",p->data);
             Push_SqStack(&S,p);
             p=p->lchild;
         }
         else{
           Pop_SqStack(&S,&p);
           p=p->rchild;
         }
   }/*����������ջ��*/
}

void NRinorder(BiTree T){ 	/*�������������T�ķǵݹ��㷨*/
   SqStack S;
   BiTree p=T;
   Init_SqStack(&S);
   while(p || !Empty_SqStack(&S)){
         if(p){
             Push_SqStack(&S,p);
             p=p->lchild;
         }
         else{
           Pop_SqStack(&S,&p);
           printf("%3c",p->data);
           p=p->rchild;
         }
   }/*����������ջ��*/
}

int r1[MAXSIZE];		/*��Ƕ�������ǰ��������Ů�Ƿ���ջ*/
void NRpostorder(BiTree T){ 	/*�������������T�ķǵݹ��㷨*/
   SqStack S;
   BiTree p=T,q;
   Init_SqStack(&S);
   while(p || !Empty_SqStack(&S)){
         if(p){
             Push_SqStack(&S,p);
             p=p->lchild;
         }
         else  if(r1[S.top]==0){
             r1[S.top]=1;
             Top_SqStack(&S,&p);
             p=p->rchild;
         }
         else{
	   r1[S.top]=0;
	   Pop_SqStack(&S,&q);
	   printf("%3c",q->data);
         }
   }/*����������ջ��*/
}

int r2[MAXSIZE];/*��Ƕ�������ǰ��������Ů�Ƿ���ջ*/
void LeafPath(BiTree T){ /*���ں������������T�ķǵݹ��㷨�����������������������Ҷ����·��*/
   int j;
   SqStack S;
   BiTree p=T,q;
   Init_SqStack(&S);
   while(p || !Empty_SqStack(&S)){
         if(p){
             Push_SqStack(&S,p);
             if(p->lchild==NULL && p->rchild==NULL){ /*ջ��Ԫ��ΪҶ�����ջ��·��*/
	          printf("\n");
		  for(j=0;j<=S.top;j++)printf("%3c",S.data[j]->data);
	     }
             p=p->lchild;
         }
	 else  if(r2[S.top]==0){
	     r2[S.top]=1;
             Top_SqStack(&S,&p);
             p=p->rchild;
         }
	 else{
	   r2[S.top]=0;
	   Pop_SqStack(&S,&q);
         }
   }/*����������ջ��*/
}

main(){
     BiTree T; 
     printf("\ninput preorder str : \n");
     create_BiTree(&T);			/*����������T*/
     printf("\npreorder list : \n");
     NRpreorder(T);
     printf("\ninorder list : \n");
     NRinorder(T);
     printf("\npostorder list : \n");
     NRpostorder(T);
     printf("\nleaf path : \n");
     LeafPath(T);
     getchar();
     getchar();
}