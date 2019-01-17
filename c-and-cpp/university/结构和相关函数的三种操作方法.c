/*结构和相关函数的三种操作方法
   Author：Tianyong-Tsow（邹天涌）
 */

#include <stdio.h>
//#include <stdlib.h>	//cpp需要这个，c则不需要
#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int last;	//标记最后一个元素的位置，也即该顺序表的实际长度-1

}SeqList;

//下标从0开始///


void main()                           //主函数
{

////指针形式对应于L->data[i])，普通形式对应于L.data[i] ////
	void Traverse(SeqList *L);
	void DeleteIst(SeqList *L, int i);
	SeqList *L = malloc(sizeof(SeqList));//指针形式的L
	int i;
	for(i=0;i<10;i++)
		scanf("%d", &(L->data[i]) );
	printf("Input last:");
	scanf("%d", &(L->last) );

 	Traverse(L);//Traverse(L)与void Traverse(SeqList *L)对应，不要写成Traverse(&L)。
	DeleteIst(L, 10);
	Traverse(L);


/*
	void Traverse(SeqList L);//记得修改该函数内部L->data[i]为L.data[i]
//	void DeleteIst(SeqList L);// 普通形式,无法实质性的删除L中的元素
	void DeleteIst(SeqList *L);//指针形式，真正的修改L。
	SeqList L;//普通L
	int i;
	for(i=0;i<10;i++)
		scanf("%d",&L.data[i]);
	printf("Input last:");
	scanf("%d",&L.last);

	Traverse(L);
//	DeleteIst(L, 10);//对应于void DeleteIst(SeqList L)
	DeleteIst(&L, 10);//对应于void DeleteIst(SeqList *L)
	Traverse(L);
*/

/*
	void Traverse(SeqList *L);
	void DeleteIst(SeqList *L, int i);
	SeqList L={{10,11,12,13,14,15,16,17,18,19},9};//直接赋值方式

 	Traverse(&L);// Traverse(&L)与void Traverse(SeqList *L)对应，不要写成Traverse(L)，
					// 这与用指针形式的L时情况恰恰相反。
	DeleteIst(&L, 10);
	Traverse(&L);
*/

}//end main


//表的遍历
void Traverse(SeqList *L)
{
	int i;

	if (L->last == -1)
	{
		printf("这是个空表");
	}
	else
	{
		for (i = 0; i <= L->last; i++)
		{
			printf("%d ", L->data[i]);
		}
	}

	printf("\n");
}

//删除第i个元素
void DeleteIst(SeqList *L, int i)
{
	int j;

	  //情况1
	if ((i < 1) || (i > L->last+1))
	{
		printf("超出范围");
		exit(1);
	}
	  //情况2
	else if (i == L->last+1)
	{
		L->data[i] = NULL;  //表尾直接删除
		L->last--;
	}
	  //情况3
	else
	{
		for (j = i; j <= L->last; j++)
		{
			L->data[j-1] = L->data[j];
		}

		L->last--;
	}
}