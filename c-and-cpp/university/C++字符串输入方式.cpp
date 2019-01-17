/*cin.getline用于输入一个字符串，按enter结束。
	用法:cin.getline(char*,int,char)，ENTER来结束输入。
   Author：Tianyong-Tsow（邹天涌）
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