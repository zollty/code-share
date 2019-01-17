#include <iostream>
#include <string>
using namespace std;
bool ana(string x, string y)
{
	int i,m;
	char t;
	for(i=0; i<x.length(); i++)
	for(m=i+1; m<=x.length(); m++)
		if (x[i]<x[m])
		{t=x[i]; x[i]=x[m]; x[m]=t;}
			
	for(i=0;i<y.length();i++)
	for(m=i+1;m<=y.length();m++)
		if (y[i]<y[m]) 
		{t=y[i]; y[i]=y[m]; y[m]=t;}
			
	if (x==y)
		return 1;
	else
		return 0;
}

int main()
{
	string str;
	string a[1000];
	int k=1;
	string f[1000];
	int ct,j;
	
	cin>>a[0];
	
	for(ct=0; ct<1000; ct++)
	{
		cin>>str;
		if(str=="#") break;
		
		int flag=0;
		for(j=0; j<=ct; j++)
		{
			if( ana(str,a[j]) )
			//给a[j]一个标志，str不插入
			{f[j]="S"; j=ct+1; flag=0; continue;}
			else
			//将str插入到a[k++]中
			{flag=1;}
		}
		if(flag) a[k++]=str;
	}
	
	k=0;
	for(int i=0; i<=ct; i++)
	{
		if( a[i]=="" ) break;
		//无标志才输出，输出到f[]中，等待排序
		if( f[i]!="S" )
		{f[k++]=a[i];}
	}

	//对结果进行选择排序，按字母顺序输出
	for(i=0; i<k-1; i++)
	{
		ct=i;
		for(j=i+1; j<k; j++ )
		{
			if( f[j]<f[ct] )
			{
				ct=j;
			}			
		}
		if( ct!=i )
		{
			str=f[i];
			f[i]=f[ct];
			f[ct]=str;
		}
		cout<<f[i]<<endl;
	}
	cout<<f[i]<<endl;
	
	return 0;
}
