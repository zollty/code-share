/*cin.getline��������һ���ַ�������enter������
	�÷�:cin.getline(char*,int,char)��ENTER���������롣
   Author��Tianyong-Tsow������ӿ��
*/
#include<iostream>
using namespace std;
int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout<<"Enter your name:\n";
	cin.getline(name,ArSize);
	cout<<"Enter your favorite dessert:\n";
	cin.getline(dessert,ArSize);
	cout<<"I have some delicious "<<dessert;
	cout<<" for you, "<<name<<".\n";
	return 0;
}