/*将数组or字符串截成2部分赋值给其他数组or字符串
   Author：Tianyong-Tsow（邹天涌）
 */
#include <iostream>
using namespace std;

int main()
{
	char sym[50]="12345--i--54321";
	int i=8;	//以第8个元素为界
	char sym1[25]={'\0'};
	char sym2[25]={'\0'};

	strncpy(sym1,sym,i);	//将前8个元素赋值给sym1
    sprintf( sym2,"%s",&sym[8]);	//将第8个元素后面的部分赋值给sym2
	cout<<sym1<<endl;
	cout<<sym2<<endl;

	return 0;
}