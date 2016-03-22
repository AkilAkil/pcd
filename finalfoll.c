#include<stdio.h>
#include<string.h>
#include<conio.h>
char pd[10][20];int n,sptr,con;
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
int findpos(char pd)
{int v,c=0;
    for(v=0;v<n;v++)
    if(pd==states[c++].nm)
    //printf("%d",c);
    break;
    printf("%d",c);
    return c-1;
}



int follow(int x,int y,int j,struct stat *state) 
{int z,b;printf("Hoi");int rt;


printf("%c",pd[x][y]);  
    if(pd[x][y+1]>=65&&pd[x][y+1]<=90)
{rt=findpos(pd[x][y+1]);printf("%d",rt);  states[rt].ft=0;

for(z=0;z<strlen(state->fr);z++)
{
state->fo[state->fw++]=states[rt].fr[states[rt].ft++];
}}
else if(pd[x][y+1]=='E')
{// b=findpos(x);
printf("%c",pd[x][y+1]);
states[findpos(pd[x][0])].fw=0;
    
     for(z=0;z<strlen(state->fo);z++)
     
state->fo[state->fw++]=states[findpos(pd[x][0])].fo[states[findpos(pd[x][0])].fw++];
}
else if(pd[x][y+1]>=97&&pd[x][y+1]<=122)
state->fo[state->fw++]=pd[x][++y];
}

void disp(struct stat *statess)
{int i,j;
     
     printf("\nFollow(%c)-->",statess->nm);
     
     for(j=0;j<statess->fw;j++)
     
     printf("\t%c",statess->fo[j]);
     
}
    
    
    
    
int main()
{ int i,j,t=2;
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
//for(i=0;i<strlen(rpt);i++)
//{printf("%c",rpt[i]);}
//printf("%d",strlen(rpt));
for(i=0;i<n;i++)
{if(repeat(pd[i][0]))
{states[sptr].nm=pd[i][0];
states[sptr].ft=states[sptr].fw=0;
printf("\nFirst of %c -->",pd[i][0]);
if((pd[i][2]>=97&&pd[i][2]<=122)||pd[i][2]=='E')
{printf("\t%c",pd[i][2]);
states[sptr].fr[states[sptr].ft++]=pd[i][2];}
else if(pd[i][2]>=65&&pd[i][2]<=90)
first(pd[i][2]);sptr++;
//printf("%d",sptr);
}}printf("\n");con=sptr;
/*for(i=0;i<states[0].ft;i++)
{printf("%c",states[0].fr[i]);
}printf("\n");
for(i=0;i<states[1].ft;i++)
{printf("%c",states[1].fr[i]);
}printf("\n");
for(i=0;i<states[2].ft;i++)
{printf("%c ",states[2].fr[i]);
}
for(i=0;i<states[3].ft;i++)
{printf("%c ",states[3].fr[i]);
}*/
//Follow
//if(state->nm=pd[0][0])
   
sptr=0;
for(j=0;j<con;j++)
{states[j].ft=states[j].fw=0; 
   for(i=0;i<n&&pd[i][t]!='\0';i++)
{
 t=2;              //printf("Hoi");
for(j=0;j<con;j++)
if(pd[i][t]==states[j].nm)
{printf("Hoi"); 
follow(i,t,j,&states[j]);}
t++;//states[j].fo[states[j].fw++]=pd[i][t];printf("%c",states[j].fo[(states[j].fw)]);
}
sptr++;
}
printf("%c",states[0].nm);
states[0].fo[states[0].fw++]='$';
for(i=0;i<con;i++)
disp(&states[i]);
getch();
}
