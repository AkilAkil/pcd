#include<stdio.h>
int i,j,mat[10][10],n,rep[10],flag;

int closure(int p)
{ int x;
for( x=0;x<flag;x++)
{//printf("\n%d",rep[i]);
if(rep[x]==p)return 0;}
printf("\t%d",p);
rep[flag++]=p;

for(x=0;x<n;x++)
if(mat[p][x]==1)
{closure(x);}
}


int main()
{
printf("Enter the no of nodes");
scanf("%d",&n);
printf("Enter the values\n");
for(i=0;i<n;i++)
{for( j=0;j<n;j++)
{scanf("%d",&mat[i][j]);
}
}
for(i=0;i<n;i++)
{
printf("\nE-close(%d)--> ",i);
flag=0;
closure(i);
}
}


