#include<iostream>
#include<string>
using namespace std;

char* toUpper(char*);
//char* toLower(char*);

int main()
{
/*	char ch,to_upper,to_lower;
	printf("\n������һ����ĸ��");
	ch=getchar();
	
	if(ch>='a' && ch<='z')
	{
		to_upper=ch-32;
		printf("\n���Ĵ�д��ĸ��:%c\n",to_upper);
	}
	
	if(ch>='A' && ch<='Z')
	{
		to_lower=ch+32;
		printf("\n����Сд��ĸ��:%c\n",to_lower);
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