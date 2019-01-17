#include <iostream>
using namespace std;
//_Pow_int()º¯ÊıÈ¡×Ômath.h
template<class _Ty> inline
_Ty _Pow_int(_Ty _X, int _Y)
{
	unsigned int _N;
	if (_Y >= 0)
		_N = (unsigned int)_Y;
	else
		_N = (unsigned int)(-_Y);

	for (_Ty _Z = _Ty(1); ; _X *= _X)
	{
		if ((_N & 1) != 0)
			_Z *= _X;
		if ((_N >>= 1) == 0)
			return (_Y < 0 ? _Ty(1) / _Z : _Z); 
	}
}

int main()
{
	double i=2;
	unsigned int j=-3;
	double w;
	w=_Pow_int(i,j);
	cout<<w<<endl;
	return 0;
}