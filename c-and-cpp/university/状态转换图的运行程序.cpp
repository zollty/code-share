/*状态转换图的运行程序
   Author：Tianyong-Tsow（邹天涌）
 */

/*
状态转换矩阵如下：
S a U
S b V
U a W
U b V
V a U
V b W
*/

#include<iostream>
using namespace std;
const int ArSize = 10;

//全局变量，Tran()函数要用到的
char matr[][10]={"SaU","SbV","UaW","UbV","VaU","VbW"};
char sym[ArSize];
int i=0,j,flag=1;

void Tran(char l)
{ char m,r;	//l,m,r分别指转换矩阵元素的左，中，右字符。
  m=sym[i];
  for (j=0; j<strlen(sym); j++)
  {
	  if(matr[j][0]==l && matr[j][1]==m)//如果前两个字符匹配，则取出第三个字符作为下一次递归的参数
	  { r=matr[j][2];
	    flag=0;	//如果整个for循环这一步都没有执行，则说明输入的符号串找不到相匹配的规则
		cout<<l<<'('<<sym[i]<<')'<<"->";//输出该推导的过程
	  }
  }
  if(flag)
  { cout<<"error!\n";
    exit(1);
  }
  else
  { i++;
    if(i<strlen(sym))
		Tran(r);
	else
		cout<<'W'<<endl;//推导完成，最后加上终结符。
  }
}//END Tran()


int main()
{
	cout<<"输入符号串:\n";
	cin.getline(sym,ArSize);
	cout<<"\n状态转换图运行过程：\n";
	Tran('S');	//以开始符号串为第一次递归的形参
	return 0;
}