#include<stdio.h>
struct state
{char name;
int n,states[10];};
int table[10][10],tno=0;
char sname='A',pname='a';
int prod[10][10],nodes,symbols; // used for eclose
int clr[10],clrp=0; // used for eclose
struct state dfa[10]; int dfap=0;
int anagram(struct state x,int seq[],int len) 
{int i;
if(x.n!=len) return 0;
for(i=0;i<len;i++)
if(x.states[i]!=seq[i])
return 0;
return 1;}
void move(struct state x,char sym) 
{int i,j,k,flag,temp;
int mov[10],movp=0;
int emov[10],emovp=0;
clrp=0; 
for(i=0;i<x.n;i++)
for(j=0;j<nodes;j++)
if(prod[x.states[i]][j]==sym)
{flag=0;
for(k=0;k<movp;k++)
if(j==mov[k]) {flag=1;break;}
if(flag==0) mov[movp++]=j;
}
//find eclose of mov here
emovp=0;
for(i=0;i<movp;i++)
{clrp=0;
eclose(mov[i]);
temp=clrp;
for(j=0;j<temp;j++)
{for(k=0;k<emovp;k++)
if(emov[k]==clr[j]) break;
if(k==emovp)
emov[emovp++]=clr[j];
}
}
for(i=0;i<emovp;i++) // sorting
for(j=i+1;j<emovp;j++)
if(emov[i]<emov[j])
emov[i]=emov[j]+emov[i]-(emov[j]=emov[i]); //woking till here
//disparray(emov,emovp);
for(i=0;i<dfap;i++)
if(anagram(dfa[i],emov,emovp)==1)
break;
if(i==dfap&&emovp!=0) //create a dfa state and the dfap of it is i
{dfa[dfap].name=sname++;
dfa[dfap].n=emovp;
for(j=0;j<emovp;j++)
dfa[dfap].states[j]=emov[j];
dfap++;
}
if(emovp==0) return;
table[x.name-'A'][i]=sym;
}
int eclose(int node) //done
{int i;
for(i=0;i<clrp;i++)
if(node==clr[i]) return 0;
clr[clrp++]=node;
for(i=0;i<nodes;i++)
if(prod[node][i]=='E')
eclose(i);
}
void disp(struct state x) //done
{int i;
printf("\n%c------",x.name);
for(i=0;i<x.n;i++)
printf("%d",x.states[i]);}
int main()
{int i,j;
char temp[10];
printf("Enter No. of Nodes : ");
scanf("%d",&nodes);
printf("Enter No. of Symbols : ");
scanf("%d",&symbols);
printf("Enter production Table :\n");
for(i=0;i<10;i++) 

for(j=0;j<10;j++)
table[i][j]='-';
for(i=0;i<nodes;i++) //input
for(j=0;j<nodes;j++)
{scanf("%s",temp);
prod[i][j]=temp[0];
}
clrp=0;
eclose(0);
dfa[0].name=sname++;
dfa[0].n=clrp;
for(i=0;i<clrp;i++)
{for(j=i+1;j<clrp;j++)
{if(clr[i]<clr[j])
clr[i]=clr[j]+clr[i]-(clr[j]=clr[i]);}
dfa[0].states[i]=clr[i];}
dfap=1;
for(i=0;i<dfap;i++)
for(j=0;j<symbols;j++)
move(dfa[i],j+'a');
i=dfap-1;
while(dfa[i--].n==0)
dfap--;
printf("\n\nDFA : \n");
for(i=0;i<dfap;i++)
{for(j=0;j<dfap;j++)
printf("%c ",table[i][j]);
printf("\n");}
printf("\nStates : \n");
printf("DFA -- NFA\n");
for(i=0;i<dfap;i++)
disp(dfa[i]);
}

