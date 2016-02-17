#include<stdio.h>
char a[20],b[20]="+-/*=",c[20],d[20],temp[20];
int main()
{int i=0,k=0,j=0,z,n,v;
printf("I/p:");
scanf("%s",&a);
/*for(i=0;a[i]!='\0';i++)
{if(a[i]=='='||a[i]=='+'||a[i]=='-')
{
b[k++]=a[i-1];
}
else
{c[j++]=a[i+1];}
//printf("%d",j);}
}b[k]=a[i-2];*/
while(a[i]!='\0')
{for(j=0;j<i;j++)
{temp[j]=a[i];
}i++;}
if(strcmp(temp,b[v++]))
{for(z=0;z<i;z++)
{c[z]=temp[z];
}}
else
{d[n++]=temp[z];
}
puts(b);
puts(c);
}

