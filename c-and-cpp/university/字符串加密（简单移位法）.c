/*字符串加密（简单移位法）
   Author：Tianyong-Tsow（邹天涌）
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//加密部分

int IsAchar(char c)//判断是否为字母
{
	if ( (c>='a' && c<='z') || (c>='A' && c<='Z') )
		return 1;
	else
		return 0;
}

char *cipher ( char s[] )//用数组存储字符串
{
	int i;
	for (i=0; i<strlen(s); i++)
	{
		if ( IsAchar(s[i]) )
			s[i]=toascii(s[i]) +1;//toascii()求字符的ASCII码，#include <ctype.h>
	}
	return s;
}

//解密部分
char *decipher( char s[] )
{
	int i;
	for (i=0; i<strlen(s); i++)
	{
		if ( IsAchar(s[i]) )
			s[i]=toascii(s[i]) -1;
	}
	return s;
}


int main()
{
	char text[200]="I am a SSE!! But I'm really tired! ";
	printf("%s\n",cipher(text) );
	printf("%s\n",decipher(text) );
	return 0;
}