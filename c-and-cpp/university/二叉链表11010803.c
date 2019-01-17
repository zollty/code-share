#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
   char data;
   struct BiTNode *lchild, *rchild;	/*���Һ���ָ��*/
}BiTNode, *BiTree;

void Create_BiTree(BiTree *T){	/*����������Ķ�������T */
   char ch;
   ch=getchar();
   if(ch=='0') *T=NULL;
   else{
      *T=(BiTree)malloc(sizeof(BiTNode));
     (*T)->data=ch;   		/*���ɸ����*/
      Create_BiTree(&(*T)->lchild);	/*����������*/
      Create_BiTree(&(*T)->rchild);	/*����������*/
   }
}

void PreOrder(BiTree T){   		/*�������������*/
   if(T){
      printf("%3c",T->data);
      PreOrder(T->lchild);
      PreOrder(T->rchild);
   }
}

void InOrder(BiTree T){		/*�������������*/
   if(T){
      InOrder(T->lchild);
      printf("%3c",T->data);
      InOrder(T->rchild);
   }
}

void PostOrder(BiTree T){   	/*�������������*/
   if(T){
      PostOrder(T->lchild);
      PostOrder(T->rchild);
      printf("%3c",T->data);
   }
}

int  num=0;
void leaf_number1(BiTree T){	/*ʹ������ݹ����ģ�����������Ҷ�ӽ�����Ŀ*/
  if(T){
     leaf_number1(T->lchild);
     if(T->lchild==NULL && T->rchild==NULL) num++;
     leaf_number1(T->rchild);
    }
}

int deep_BiTree(BiTree T){		/*���ݶ������ĵݹ鶨����������������*/
  int d,dl,dr;			/*����������ȡ�����������ȡ������������*/
  if(T==NULL) d=0;
  else{
       dl=deep_BiTree(T->lchild);
       dr=deep_BiTree(T->rchild);
       if(dl>=dr)  d=dl+1;
           else     d=dr+1;
    }
  return(d);
}


main(){
     BiTree T,p;
     printf("\ninput str : ");
     Create_BiTree(&T);		/*����������T*/
     printf("\nPreOrder  list : ");
     PreOrder(T);
     printf("\nInOrder   list : ");
     InOrder(T);
     printf("\nPostOrder list : ");
     PostOrder(T);
     printf("\ndeep of  T   : %d",deep_BiTree(T));
     leaf_number1(T);
     printf("\nleaf number : %d",num);
}
/*
���룺AB00CD00E00F000
�����A(B,C((D,E))
��������� B A D C E
��α�����A B C D E
*/
