/*C语言小子集的词法分析程序
   Author：Tianyong-Tsow（邹天涌）
 */


/**************************search.h*********************************/
extern struct table
{
  int id;
  char code[10];
};
struct table key[31] = {{1,"main"},{2,"int"},{3,"char"},{4,"if"},{5,"else"},{6,"for"},{7,"while"},{10,"ID"},{20,"NUM"},{-1,"ERROR"}};
int reserve(char* p)
{  int i=0;
  for(i=0;i<9;i++)
  {
    if(strcmp(p,key[i].code)==0)
    return(key[i].id);
  }
  return(-1);
}
void output(int t,char *s)
{
  printf("  %-2d ,  \"%-2s\"\n",t,s);
}
/*******************************************************************/


/********************compiler.c*************************************/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"search.h"
extern int reserve(char*);
extern void output(int,char*);
char token[20];
char ch;
int i,c;

void scanner(FILE *fp)
{
 ch=fgetc(fp);
 if(isalpha(ch))
 {
  token[0]=ch;
  i=1;
  ch=fgetc(fp);
  while(isalpha(ch)||isalnum(ch))
  {
   token[i]=ch;
   i++;
   ch=fgetc(fp);
  }
  fseek(fp,-1,1);
  token[i]='\0';
  c=reserve(token);
  if(c!=-1)
        output(c,token);
  else
        output(10,token);
 }
 else if(isdigit(ch))
      {
  token[0]=ch;
  ch=fgetc(fp);
  i=1;
  while(isdigit(ch))
  {
   token[i]=ch;
   i++;
   ch=fgetc(fp);
  }
  token[i]='\0';
  fseek(fp,-1,1);
  output(11,token);
      }
 else
  switch(ch)
  {
   case'=':ch=fgetc(fp);
    if(ch=='=')
     output(39,"==");
    else
    {
    fseek(fp,-1,1);
    output(21,"=");
    }
    break;
   case'+':output(22,"+");break;
   case'-':output(23,"-");break;
   case'*':output(24,"*");break;
   case'/':output(25,"/");break;
   case'(':output(26,"(");break;
   case')':output(27,")");break;
   case'[':output(28,"[");break;
   case']':output(29,"]");break;
   case'{':output(30,"{");break;
   case'}':output(31,"}");break;
   case',':output(32,",");break;
   case':':output(33,":");break;
   case';':output(34,";");break;
   case'>':ch=fgetc(fp);
    if(ch=='=')
     output(37,">=");
    else
    {
    fseek(fp,-1,1);
    output(35,">");
    }
    break;
   case'<':ch=fgetc(fp);
    if(ch=='=')
     output(38,"<=");
    else
    {
    fseek(fp,-1,1);
    output(36,"<");
    }
    break;
   case'!':ch=fgetc(fp);
    if(ch=='=')
     output(40,"!=");
    else
    {
    fseek(fp,-1,1);
    output(-1,"ERROR!");
    }
    break;
  }

}
void main()
{FILE *fp;
 char wenjian[30];
 printf("Please input the file you want to transform:");
 scanf("%s",&wenjian);
 fp=fopen(wenjian,"r");
 while(!feof(fp))
 {
  scanner(fp);
 }
}
