/*������or�ַ����س�2���ָ�ֵ����������or�ַ���
   Author��Tianyong-Tsow������ӿ��
 */
#include <iostream>
using namespace std;

int main()
{
	char sym[50]="12345--i--54321";
	int i=8;	//�Ե�8��Ԫ��Ϊ��
	char sym1[25]={'\0'};
	char sym2[25]={'\0'};

	strncpy(sym1,sym,i);	//��ǰ8��Ԫ�ظ�ֵ��sym1
    sprintf( sym2,"%s",&sym[8]);	//����8��Ԫ�غ���Ĳ��ָ�ֵ��sym2
	cout<<sym1<<endl;
	cout<<sym2<<endl;

	return 0;
}