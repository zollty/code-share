/*�ַ������ܣ�����λ����
   Author��Tianyong-Tsow������ӿ��
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//���ܲ���

int IsAchar(char c)//�ж��Ƿ�Ϊ��ĸ
{
	if ( (c>='a' && c<='z') || (c>='A' && c<='Z') )
		return 1;
	else
		return 0;
}

char *cipher ( char s[] )//������洢�ַ���
{
	int i;
	for (i=0; i<strlen(s); i++)
	{
		if ( IsAchar(s[i]) )
			s[i]=toascii(s[i]) +1;//toascii()���ַ���ASCII�룬#include <ctype.h>
	}
	return s;
}

//���ܲ���
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