#include <stdio.h>
#include "stdlib.h"
#define MAXSIZE 30		/*最多元素数*/
typedef struct BiTNode{
   char data;
   struct BiTNode  *lchild, *rchild;	/*左右孩子指针*/
}BiTNode, *BiTree;
typedef BiTree ElemType;
typedef struct{
      BiTree data[MAXSIZE];	/*栈空间*/
      int top;			/*栈顶指针*/
}SqStack;			/*栈类型*/

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
   if ( S->top==MAXSIZE-1){	/*栈满,不能入栈*/
        printf(" 栈满! ");
   }
   else				/*栈非满,x入栈*/
        S->data[++S->top]=x;
}
void Pop_SqStack(SqStack *S,ElemType *x){
   if (Empty_SqStack(S)){		/*栈空,不能进行出栈*/
         printf(" 栈空! ");
   }
   else{   			/*栈顶元素存入变量x*/
         *x=S->data[S->top];
         S->top--;
   }
}
void  Top_SqStack(SqStack *S, ElemType *x){
       if ( S->top==-1) 		/*栈空,不能读取栈顶元素 */
            printf(" 栈空!");
       else  			/*栈顶元素存入变量x并返回*/
           *x=S->data[S->top];
}

void create_BiTree(BiTree *T){ /*按先序次序输入二叉树结点的字符,'@'字符表示空树,构造二叉树的二叉链表*/
  char ch;
  ch=getchar();
  if(ch=='@') *T=NULL;
  else{
      *T=(BiTree)malloc(sizeof(BiTNode));
      (*T)->data=ch;   /*生成根结点*/
      create_BiTree(&(*T)->lchild);	/*构造左子树*/
      create_BiTree(&(*T)->rchild);	/*构造右子树*/
  }
}

void NRpreorder(BiTree T){ 	/*先序遍历二叉树T的非递归算法*/
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
   }/*二叉树空且栈空*/
}

void NRinorder(BiTree T){ 	/*中序遍历二叉树T的非递归算法*/
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
   }/*二叉树空且栈空*/
}

int r1[MAXSIZE];		/*标记二叉树当前结点的右子女是否入栈*/
void NRpostorder(BiTree T){ 	/*后序遍历二叉树T的非递归算法*/
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
   }/*二叉树空且栈空*/
}

int r2[MAXSIZE];/*标记二叉树当前结点的右子女是否入栈*/
void LeafPath(BiTree T){ /*基于后序遍历二叉树T的非递归算法，从左到右依次输出根到所有叶结点的路径*/
   int j;
   SqStack S;
   BiTree p=T,q;
   Init_SqStack(&S);
   while(p || !Empty_SqStack(&S)){
         if(p){
             Push_SqStack(&S,p);
             if(p->lchild==NULL && p->rchild==NULL){ /*栈顶元素为叶，输出栈内路径*/
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
   }/*二叉树空且栈空*/
}

main(){
     BiTree T; 
     printf("\ninput preorder str : \n");
     create_BiTree(&T);			/*建立二叉树T*/
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