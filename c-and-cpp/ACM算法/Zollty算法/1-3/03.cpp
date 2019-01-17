#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char * argv[])
{
	ifstream cin("aaa.txt");
	vector<unsigned int>v;
	unsigned int n;
	//先建表，把第0~46项的菲氏数都算出来
	v.push_back(0);
	v.push_back(1);
	for(int i=2; i<=46; i++)
	{
		v.push_back(v[i-1]+v[i-2]);
	}
	//直接输出第n项菲氏数
	while(cin>>n)
	{
		cout<<v[n]<<endl;
	}
	return 0;
}