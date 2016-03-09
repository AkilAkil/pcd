#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int nfa[10][10];
int n,a[10],l=0,y,v[10],p=0,q=0,x,k,b;
int ctoi(char a)
{
int i;
i=a-48;
return i;
}
int itoc(char a)
{
int i;
i=a+48;                                                                                                                                       
return i;
}
void main()
{
int c,i,j,m,input[3],h,t;
char a[10],dstate[10][10],st[10][10],d[50],y;
printf("Symbol Length:\n");
scanf("%d",&m);
printf("Enter the Input Symbol:\n");
for(i=0;i<m;i++)
scanf("%d",&input[i]);
printf("Enter the no of nodes:\n");
scanf("%d",&n);
printf("\t");
for(i=0;i<n;i++)
printf("q%d\t",i);
for(i=0;i<n;i++)
{
printf("\nq%d\t",i);
for(j=0;j<n;j++)
{
scanf("%d",&nfa[i][j]);
}
}
printf("Enter the Final state no:\n");
scanf("%d",&h);
a[0]='0';
a[1]='\0';
strcpy(dstate[p++],a);
strcpy(st[q++],a);
printf("\n Equivalent DFA:\n");
for(i=0;i<m;i++)
printf("\t%d",input[i]);
printf("\n\n->");
for(b=0;b<q;b++)
{
strcpy(a,st[b]);
y=itoc(h);
for(c=0;c<strlen(a);c++)
{
if(a[c]==y)
{
printf("*");
break;
}
}
printf("[%s]\t",a);
for(j=0;j<m;j++)
{
l=0;
d[l]='\0';
for(i=0;i<strlen(a);i++)
{
if(a[i]!=',')
{
x=ctoi(a[i]);
for(k=0;k<n;k++)
{
if(nfa[x][k]==input[j])
{
for(t=0;t<l;t++)
{
if(d[t]==itoc(k))
   break;
}
if(t==l)
{
d[l++]=itoc(k);
d[l++]=',';
}
}
}
}
}
d[--l]='\0';
for(i=0;i<p;i++)
{
if(strcmp(dstate[i],d)==0)
break;
}
if(i==p)
{
if(d[0]!='\0')
{
strcpy(dstate[p++],d);
strcpy(st[q++],d);
}
}
if(d[0]!='\0')
printf("[%s]\t",d);
else
printf("-\t");
}
printf("\n\n");
}
}
