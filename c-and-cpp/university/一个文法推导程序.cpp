/*一个文法推导程序
   Author：Tianyong-Tsow（邹天涌）
 */

/*程序描述：
给定文法G[E]为:
E::=E+E|E-T|T
T::=T*F|T/F|F
F::=(E)|i
输入一个符号串（比如i*i+i-i），输出其推导过程。
*/

#include<iostream>
using namespace std;
const int ArSize = 10;

/* 程序说明
分析：考察i*i+i-i，程序首先处理的是+, - 的部分，调用Harli(char *sym)函数，
将符号串i*i+i-i以’+’为界分而治之，前半部分为i*i，后半部分为i-i，然后又把这
两个部分传给Harli(char *sym)，递归的调用Harli()函数来处理，当字符串中不
存在+或-时，再考虑 *和/ ，调用Honi()函数，类似的递归处理……
*/


// *, / 处理代码段
void Honi(char *sym)
{
	char sym1[ArSize]={'\0'};
	char sym2[ArSize]={'\0'};	
	int flag=1,i;
	for(i=0; i<strlen(sym); i++)
	{
		if(sym[i]=='*')
		{
			cout<<"T=>T*F\n";
			flag=0;
			strncpy(sym1,sym,i);
			sprintf(sym2,"%s",&sym[i+1]);
			Honi(sym1);
			Honi(sym2);
		}
		else if(sym[i]=='/')
		{
			cout<<"T=>T/F\n";
			flag=0;
			strncpy(sym1,sym,i);
			sprintf(sym2,"%s",&sym[i+1]);
			Honi(sym1);
			Honi(sym2);
		}
	}//END for
	if(flag)
	{
		cout<<"T=>F\n";
		cout<<"F=>i\n";
	}
}

// +, - 处理代码段
void Harli(char *sym)
{ 
	char sym1[ArSize]={'\0'};
	char sym2[ArSize]={'\0'};	
	int flag=1,i;
	for(i=0; i<strlen(sym); i++)
	{
		if(sym[i]=='+')
		{
			cout<<"E=>E+E\n";
			flag=0;
			strncpy(sym1,sym,i);	// '+'以前的部分
			sprintf(sym2,"%s",&sym[i+1]);	// '+'以后的部分
			Harli(sym1);	//递归处理
			Harli(sym2);
		}
		else if(sym[i]=='-')
		{
			cout<<"E=>E-T\n";
			flag=0;
			strncpy(sym1,sym,i);
			sprintf(sym2,"%s",&sym[i+1]);
			Harli(sym1);
			Harli(sym2);
		}
	}//END for
	if(flag)
	{
		cout<<"E=>T\n";	//如果不含+或者-则选择E=>T，并且进入*和/ 的推导程序Honi
		Honi(sym);
	}
}

int main()
{
	char sym[ArSize];

	cout<<"Enter a string:\n";
	cin.getline(sym,ArSize);

	Harli(sym);
	return 0;
}
