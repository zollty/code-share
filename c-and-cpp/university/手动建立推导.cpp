/*�ֶ������Ƶ����㷨
   Author��Tianyong-Tsow������ӿ��
 */

#include<iostream>
#include<string>
using namespace std;
const int ArSize = 10;

int i=0,j=0;
char s[ArSize];
string d,tem[30];

void ded()
{
	int k,t;
	switch( d[d.length()-1] )	{
	case 'E':
		labelA: cout<<"��ѡ���Ƶ��Ĺ���1ΪE::=E+E��2ΪE::��E-T��3ΪE::��T����" ;
		cin>>k;
		switch( k )	{
			case 1:
				d.erase(d.end()-1);
				d.append("E+E");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			case 2:
				d.erase(d.end()-1);
				d.append("E-T");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			case 3:
				d.erase(d.end()-1);
				d.append("T");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			default:
				cout<<"\tError! input again!\n";
				goto labelA;
				break;
		}
		break;

	case 'T':
		labelB: cout<<"��ѡ���Ƶ��Ĺ���1ΪT::=T*F��2ΪT::��T/F��3ΪT::��F����" ;
		cin>>k;
		switch( k )	{
			case 1:
				d.erase(d.end()-1);
				d.append("T*F");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			case 2:
				d.erase(d.end()-1);
				d.append("T/F");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			case 3:
				d.erase(d.end()-1);
				d.append("F");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			default:
				cout<<"\tError! input again!\n";
				goto labelB;
				break;
		}
		break;

	case 'F':
		labelC: cout<<"��ѡ���Ƶ��Ĺ���1ΪF::=(E)��2ΪF::��i����" ;
		cin>>k;
		switch( k )	{
			case 1:
				d.erase(d.end()-1);
				d.append("(E)");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			case 2:
				d.erase(d.end()-1);
				d.append("i");
				tem[i]=d;
				cout<<"E=>"<<d;
				for(t=j-1;t>=0;t--)
				{ cout<<s[t];
				  tem[i].append(1,s[t]);
				}
				i++; cout<<endl;
				if(d.length()) ded();
				break;
			default:
				cout<<"\tError! input again!\n";
				goto labelC;
				break;
		}
		break;

	default:
		s[j++]=*(d.end()-1);
		d.erase(d.end()-1);
		if(d.length()) ded();
		break;
	}

}


int main()
{
	string rug[][5]={{"E+E","E-T","T"},{"T*F","T/F","F"},{"(E)","i"}};
	d="E";
	ded();
	int a=0;
	cout<<"\n�Ƶ����̣�\n"<<"E";
	do
	{ cout<<"=>"<<tem[a]<<endl;
	  a++;
	}while( tem[a] != "" );
	return 0;
}