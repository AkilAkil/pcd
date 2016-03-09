#include<stdio.h>
#include<string.h>
char pd[10][20];int n,sptr;
char rpt[10],rpt1[10];
struct stat
{char nm;int ft,fw;
char fr[20],fo[20];
}states[10];

int repeat(char c)
{int z;
for(z=0;z<sptr;z++)
if(states[z].nm==c)
return 0;
return 1;
}



int  first(char x)
{int i1,j1;
for(j1=0;j1<n;j1++)
{if(rpt1[j1]==x) 
break;
rpt[j1]=x;}
for(i1=0;i1<n;i1++)
{if(pd[i1][0]==x)
{if((pd[i1][2]>=97&&pd[i1][2]<=122)||pd[i1][2]=='E')
{printf("\t%c",pd[i1][2]);
states[sptr].fr[states[sptr].ft++]=pd[i1][2];
}
else
first(pd[i1][2]);
}
}}
int main()
{ int i,j;
printf("Enter the no of production\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%s",pd[i]);
//printf("Hoi");
}
//printf("Hoi");
for(i=0;i<n;i++)
{if(pd[i][0]>=65&&pd[i][0]<=90) 
{for(j=0;j<n;j++)
{if(rpt[j]==pd[i][0]) 
break;
else
rpt[i]=pd[i][0];
}}}
for(i=0;i<strlen(rpt);i++)
{printf("%c",rpt[i]);}
//printf("%d",strlen(rpt));
for(i=0;i<n;i++)
{if(repeat(pd[i][0]))
states[sptr].nm=pd[i][0];
states[sptr].ft=states[sptr].fw=0;
printf("\nFirst of %c -->",pd[i][0]);
if((pd[i][2]>=97&&pd[i][2]<=122)||pd[i][2]=='E')
{printf("\t%c",pd[i][2]);
states[sptr].fr[states[sptr].ft++]=pd[i][2];}
else if(pd[i][2]>=65&&pd[i][2]<=90)
first(pd[i][2]);sptr++;
}printf("\n");
for(i=0;i<states[0].ft;i++)
{printf("%c",states[0].fr[i]);
}printf("\n");
for(i=0;i<states[1].ft;i++)
{printf("%c",states[1].fr[i]);
}printf("\n");
for(i=0;i<states[2].ft;i++)
{printf("%c",states[2].fr[i]);
}


}

