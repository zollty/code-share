#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char * argv[])
{
	ifstream cin("aaa.txt");
	int n, sum, p;
	while(cin>>n)
	{
		sum=0;
		p=1;
		for(int i=1; i<=n; i++)
		{
			p=p*i;
			sum=sum+p;
		}
		cout<<sum<<endl;
	}
	return 0;
}
