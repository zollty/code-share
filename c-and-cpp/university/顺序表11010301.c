/* 本人C程序风格说明：
	1. 一行一句（长句分几行写）；
	2. 所有花括号'{'或'}'独占一行，且上下对齐；
	3. 缩进代表语句的层次，同级语句有相同的缩进；
	4. 使用空行，使段落清晰；
	5. 使用空格，使句意明了、表达清楚；
	6. 注释在上方或右方，长注释分多行
	7. if，for，while 等语句独占一行，所跟执行语句即使只有一句也用花括号括起来。
	8. 命名规则：宏用全大写，函数名首字母大写，变量名首字母小写，兼顾简洁明了，难以理解的命名加上注释。
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

//置空
void Initial(SeqList *L)
{
	L->last = -1;
}

//求长
int Length(SeqList *L)
{
	return L->last+1;
}

//判断表空
int IsEmpty(SeqList *L)
{
	return L->last == -1;
}


//获取第i个元素的值
DataType GetiValue(SeqList *L, int i)
{
	if ((i >= 1) && (i <= L->last+1))
	{
		return L->data[i-1];
	}
	else
	{
		printf("找不到该节点！");
		exit(1);
	}
}

//查找值=x的元素的位置
int LocateX(SeqList *L, DataType x)
{
	int i = 1;

	while ((x != L->data[i-1]) && (i <= L->last))
	{
		i++;
	}

	if (i <= L->last+1)
	{
		return i;
	}
	else
	{
		printf("此元素不在表中");
		exit(1);
	}
}

//求x的前驱
DataType GetPrior(SeqList *L, DataType x)
{
	int i = LocateX(L, x);

	if (i == 1)
	{
		printf("第一个元素没有前驱");
		exit(1);
	}
	else 
	{
		return L->data[i-2];
	}
}

//求x的后继
DataType GetSuccessor(SeqList *L, DataType x)
{
	int i = LocateX(L, x);

	if (i == L->last+1)
	{
		printf("最后一个元素没有后继");
		exit(1);
	}
	else
	{
		return L->data[i];
	}
}

//在第i位插入元素，节点后移
void InsertX(SeqList *L, int i, DataType x)
{
	int j;

	if (L->last+1 == MAXSIZE)
	{
		printf("表已满，无法插入");
		exit(1);
	}

	  //情况1
	if ((i < 1) || (i > L->last+2))
	{
		printf("超出范围");
		exit(1);
	}
	  //情况2
	else if (i == L->last+2)
	{
		L->data[i] = x;  //直接插入到队尾
		L->last++;
	}
	  //情况3
	else
	{
		for (j = L->last+2; j >= i; j--)
		{
			L->data[j] = L->data[j-1];	//腾出第i位
		}

		L->data[j] = x;
		L->last++;  //last增加1
	}
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


void main()                           //主函数
{
	SeqList L={{10,11,12,13,14,15,16,17,18,19},9};  //顺序表的赋值，注意要按这种方式
	//////测试/////////////////////
	InsertX(&L, 10, 20);
 	Traverse(&L);
	DeleteIst(&L, 11);
	Traverse(&L);
	printf("%d\n", GetiValue(&L,10));
}