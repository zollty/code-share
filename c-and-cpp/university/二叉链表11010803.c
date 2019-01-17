#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
   char data;
   struct BiTNode *lchild, *rchild;	/*左右孩子指针*/
}BiTNode, *BiTree;

void Create_BiTree(BiTree *T){	/*构造二叉树的二叉链表T */
   char ch;
   ch=getchar();
   if(ch=='0') *T=NULL;
   else{
      *T=(BiTree)malloc(sizeof(BiTNode));
     (*T)->data=ch;   		/*生成根结点*/
      Create_BiTree(&(*T)->lchild);	/*构造左子树*/
      Create_BiTree(&(*T)->rchild);	/*构造右子树*/
   }
}

void PreOrder(BiTree T){   		/*先序遍历二叉树*/
   if(T){
      printf("%3c",T->data);
      PreOrder(T->lchild);
      PreOrder(T->rchild);
   }
}

void InOrder(BiTree T){		/*中序遍历二叉树*/
   if(T){
      InOrder(T->lchild);
      printf("%3c",T->data);
      InOrder(T->rchild);
   }
}

void PostOrder(BiTree T){   	/*后序遍历二叉树*/
   if(T){
      PostOrder(T->lchild);
      PostOrder(T->rchild);
      printf("%3c",T->data);
   }
}

int  num=0;
void leaf_number1(BiTree T){	/*使用中序递归遍历模板求二叉树中叶子结点的数目*/
  if(T){
     leaf_number1(T->lchild);
     if(T->lchild==NULL && T->rchild==NULL) num++;
     leaf_number1(T->rchild);
    }
}

int deep_BiTree(BiTree T){		/*根据二叉树的递归定义求求二叉树的深度*/
  int d,dl,dr;			/*二叉树的深度、左子树的深度、右子树的深度*/
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
     Create_BiTree(&T);		/*建立二叉树T*/
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
输入：AB00CD00E00F000
输出：A(B,C((D,E))
中序遍历： B A D C E
层次遍历：A B C D E
*/
