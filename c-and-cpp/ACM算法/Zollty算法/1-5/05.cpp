#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
struct Name
{
	int i;//3 int  4 char
	char na[100];
	int le;
}name[11];
int num=0;
int main()
{
	ifstream cin("data2.in");
	int j,k,w;
	int yes=1,yes2=0;
	char ss[100];
	char s2[100];
	while(1)
	{
		cin>>name[num].na;
		if(strcmp(name[num].na,"#")==0)
			break;
		cin>>ss;
		if(ss[0]=='i')
		{
			name[num].i=3;
		}
		else
		{
			name[num].i=4;
		}
		name[num].le=0;
		for(k=1,j=strlen(ss)-2;j>name[num].i;j--)
		{
			name[num].le+=(int)k*(ss[j]-48);
			k=10;
		}
		num++;
	}
	while(cin>>ss)
	{
		strcpy(s2,ss);
		for(j=0;s2[j]!='=';j++);
		s2[j]='\0';
		yes=1;
		yes2=0;
		for(j=0;j<num;j++)
		{
			if(0==strcmp(s2,name[j].na))
			{
						yes2=1;
						strcpy(s2,strstr(ss,"="));
						if(name[j].i==3)
						{
							if((strlen(s2)-1)>name[j].le)
								yes=0;
							else
							{
								for(w=1;w<strlen(s2);w++)
								{
									if(s2[w]>'9'||s2[w]<'0')
									{
										yes=0;
										break;
									}
								}
							}
						}
						else
						{
							if(s2[1]!='"'||s2[(strlen(s2)-1)]!='"'||(strlen(s2)-3)>name[j].le)
								yes=0;
							else
							{
								for(w=2;w<strlen(s2)-1;w++)
								{
									if((s2[w]>'z'||s2[w]<'a')&&(s2[w]>'Z'||s2[w]<'A'))
									{
										yes=0;
										break;
									}
								}
							}
						}
			}
		}
		if(yes==0||yes2==0)
		{
			yes=0;
			break;
		}
	}
	if(1==yes)
		cout<<"Right!"<<endl;
	else
		cout<<"Wrong!"<<endl;
	return 0;
}
