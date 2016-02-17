#include<stdio.h>
#include<string.h>
char ch[10]="+-*/%";
char dt[][10]={"int","float","double"},key[][8]={"while","for"};
char sp[20]="{}()[];,";
int dtm[]={4,4,8};
char in[][30];
int main()
{int i=0,k,j,mem=0x4000;
printf("I/p:");
do
{
scanf("%s",&in[i]);
}while(in[i++][0]!='}');
printf("%d",i); 
for(j=0;j<i-1;j++)
{
for(k=0;k<8;k++)
{if(in[j][0]==sp[k])
printf("\nSpecial Character: %s",in[j]);

}
for(k=0;k<3;k++)
{if(strcmp(in[j],dt[k])==0)
printf("\nDatatype: %s",in[j]);
}
for(k=0;k<2;k++)
if(strcmp(in[j],key[k])==0)
{printf("\n keyword: %s",in[j]);}
if((in[j][0]>=97&&in[j][0]<=122)||(in[j][0]>=65&&in[j][0]<=90))
{printf("\n%s - variable",in[j]);}

if(in[j][0]>=48&&in[j][0]<=57)
{printf("\n%s - number ",in[j]);}}
j=0;
while(j<i)

{

for(k=0;k<4;k++)
if(strcmp(in[j],dt[k])==0)
{
while(in[++j][0]!=';')
if(in[j][0]!=','&&in[j][0]!='='&&!(in[j][0]>=48&&in[j][0]<=57)&&in[j][0]!='\'')
{printf("\n%s -- %s -- %d bytes -- Ox%x\n",in[j],dt[k],dtm[k],mem);mem+=dtm[k];}//if

}
j++;

}




}
