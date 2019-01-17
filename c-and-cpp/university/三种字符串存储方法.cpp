/*三种字符串存储方法
   Author：Tianyong-Tsow（邹天涌）
 */

#include <iostream>
#include <string>
using namespace std;

//前两种定义C/C++通用，最后一种string方法只适合C++
int main()
{
	char *name1[]={"BASIC","C++","PASCAL","COBOL","SQL"};//字符串数组指针法
	char name2[][30]={"BASIC","C++","PASCAL","COBOL","SQL"};//C-string法
	string name3[]={"BASIC","C++","PASCAL","COBOL","SQL"};//include<string>，Only C++
	cout<<name1[0]<<endl;//If C,printf("%s\n",name1[0])
	cout<<name2[0]<<endl;
	cout<<name3[0]<<endl;
	return 0;
}
//三种方法的共同点是name[0]都是代表的"BASIC"的首地址而非其本身，注意对比三种方法。
