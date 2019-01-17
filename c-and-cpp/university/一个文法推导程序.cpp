/*һ���ķ��Ƶ�����
   Author��Tianyong-Tsow������ӿ��
 */

/*����������
�����ķ�G[E]Ϊ:
E::=E+E|E-T|T
T::=T*F|T/F|F
F::=(E)|i
����һ�����Ŵ�������i*i+i-i����������Ƶ����̡�
*/

#include<iostream>
using namespace std;
const int ArSize = 10;

/* ����˵��
����������i*i+i-i���������ȴ������+, - �Ĳ��֣�����Harli(char *sym)������
�����Ŵ�i*i+i-i�ԡ�+��Ϊ��ֶ���֮��ǰ�벿��Ϊi*i����벿��Ϊi-i��Ȼ���ְ���
�������ִ���Harli(char *sym)���ݹ�ĵ���Harli()�������������ַ����в�
����+��-ʱ���ٿ��� *��/ ������Honi()���������Ƶĵݹ鴦����
*/


// *, / ��������
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

// +, - ��������
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
			strncpy(sym1,sym,i);	// '+'��ǰ�Ĳ���
			sprintf(sym2,"%s",&sym[i+1]);	// '+'�Ժ�Ĳ���
			Harli(sym1);	//�ݹ鴦��
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
		cout<<"E=>T\n";	//�������+����-��ѡ��E=>T�����ҽ���*��/ ���Ƶ�����Honi
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
