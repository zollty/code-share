#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main(int arc, char * argv[])
{
	ifstream cin("aaa.txt");
	//���fixed�ã��������С�����3λ
	cout.precision(3);
	int n;
	double q, sum;
	while(cin>>n>>q)
	{
		if(q==1) sum=1+n;
		else
			sum=(1-pow(q,n+1))/(1-q);
		cout<<fixed<<sum<<endl;
	}
	return 0;
}