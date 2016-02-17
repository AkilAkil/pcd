#include<stdio.h>
#include<string.h>
int main()
{
char dt[][8]={"int","float","double"},key[][8]={"while","for"};
int dtm[]={4,4,8};
char sc[15]=",(){}",ao[12]="<>=+-*/";
char ip[30][10];
int i=0,j=0,k,l,mem=0x4000;
printf("Input : ");
do {scanf("%s",ip[i]);}
while(ip[i++][0]!='}');
//printf("out");

//one.c
for(j=0;j<i-1;)
{//puts(ip[j]);

for(k=0;k<5;k++)
if(ip[j][0]==sc[k])
{printf("\n%s - special character",ip[j]);j++;}

for(k=0;k<7;k++)
if(ip[j][0]==ao[k])
{printf("\n%s - operator",ip[j]);j++;}

for(k=0;k<3;k++)
if(strcmp(ip[j],dt[k])==0)
{printf("\n%s - datatype",ip[j]);j++;}



for(k=0;k<2;k++)
if(strcmp(ip[j],key[k])==0)
{printf("\n%s - keyword",ip[j]);j++;}

if((ip[j][0]>=97&&ip[j][0]<=122)||(ip[j][0]>=65&&ip[j][0]<=90))
{printf("\n%s - variable",ip[j]);j++;}

if(ip[j][0]>=48&&ip[j][0]<=57)
{printf("\n%s - number ",ip[j]);j++;}

if(ip[j][0]==';')
{printf("\n; - terminator ");j++;}
}


//end
printf("\n\nID -- DT -- Size -- Mem \n");
j=0;
while(j<i)

{

for(k=0;k<4;k++)
if(strcmp(ip[j],dt[k])==0)
{
while(ip[++j][0]!=';')
if(ip[j][0]!=','&&ip[j][0]!='='&&!(ip[j][0]>=48&&ip[j][0]<=57)&&ip[j][0]!='\'')
{printf("%s -- %s -- %d bytes -- Ox%x\n",ip[j],dt[k],dtm[k],mem);mem+=dtm[k];}//if

}//while
j++;

}//for



}
