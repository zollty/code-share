/*�����ַ����洢����
   Author��Tianyong-Tsow������ӿ��
 */

#include <iostream>
#include <string>
using namespace std;

//ǰ���ֶ���C/C++ͨ�ã����һ��string����ֻ�ʺ�C++
int main()
{
	char *name1[]={"BASIC","C++","PASCAL","COBOL","SQL"};//�ַ�������ָ�뷨
	char name2[][30]={"BASIC","C++","PASCAL","COBOL","SQL"};//C-string��
	string name3[]={"BASIC","C++","PASCAL","COBOL","SQL"};//include<string>��Only C++
	cout<<name1[0]<<endl;//If C,printf("%s\n",name1[0])
	cout<<name2[0]<<endl;
	cout<<name3[0]<<endl;
	return 0;
}
//���ַ����Ĺ�ͬ����name[0]���Ǵ����"BASIC"���׵�ַ�����䱾��ע��Ա����ַ�����
