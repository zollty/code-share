#include<iostream>
#include<string>
using namespace std;

char* toUpper(char*);
//char* toLower(char*);

int main()
{
/*	char ch,to_upper,to_lower;
	printf("\n请输入一个字母：");
	ch=getchar();
	
	if(ch>='a' && ch<='z')
	{
		to_upper=ch-32;
		printf("\n它的大写字母是:%c\n",to_upper);
	}
	
	if(ch>='A' && ch<='Z')
	{
		to_lower=ch+32;
		printf("\n它的小写字母是:%c\n",to_lower);
	}
*/
	string str;
	cin>>str;
	str=toUpper(&str);
	cout<<str;

	return 0;
}

string toUpper(string *str)
{
	int i=0;
	while(*str[i] !='\n' )
	{
		if(*str[i]>='a' && *str[i]<='z')
		{
			*str[i] = *str[i] - 32;
		}
	}
	
	return *str;
}