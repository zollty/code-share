/*״̬ת��ͼ�����г���
   Author��Tianyong-Tsow������ӿ��
 */

/*
״̬ת���������£�
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

//ȫ�ֱ�����Tran()����Ҫ�õ���
char matr[][10]={"SaU","SbV","UaW","UbV","VaU","VbW"};
char sym[ArSize];
int i=0,j,flag=1;

void Tran(char l)
{ char m,r;	//l,m,r�ֱ�ָת������Ԫ�ص����У����ַ���
  m=sym[i];
  for (j=0; j<strlen(sym); j++)
  {
	  if(matr[j][0]==l && matr[j][1]==m)//���ǰ�����ַ�ƥ�䣬��ȡ���������ַ���Ϊ��һ�εݹ�Ĳ���
	  { r=matr[j][2];
	    flag=0;	//�������forѭ����һ����û��ִ�У���˵������ķ��Ŵ��Ҳ�����ƥ��Ĺ���
		cout<<l<<'('<<sym[i]<<')'<<"->";//������Ƶ��Ĺ���
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
		cout<<'W'<<endl;//�Ƶ���ɣ��������ս����
  }
}//END Tran()


int main()
{
	cout<<"������Ŵ�:\n";
	cin.getline(sym,ArSize);
	cout<<"\n״̬ת��ͼ���й��̣�\n";
	Tran('S');	//�Կ�ʼ���Ŵ�Ϊ��һ�εݹ���β�
	return 0;
}