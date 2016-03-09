#include<stdio.h>
#include<string.h>
struct state {
char name;
char first[10],follow[10];
int ft,fw;
};
struct state states[10];int statesp=0;
char pro[10][10];int n;

void removeDup(struct state *x)
{int i,j;
for(i=0;i<x->fw;i++)
for(j=i+1;j<x->fw;j++)
 if(x->follow[i]==x->follow[j])
 {x->follow[j]=x->follow[x->fw-1];x->fw--;
  }

}

void copy(struct state *x,char arr[],char n)
{int i;
for(i=0;i<n;i++)
if(arr[i]!='E') x->follow[x->fw++]=arr[i]; //copies w/o E
}//not implemented

int containsE(char arr[],char n)
{char i;
for(i=0;i<n;i++)
if(arr[i]=='E') return 1;
return 0;}

void first(struct state *x,char c)
{
int i;
//printf("%c",c);
for(i=0;i<n;i++)
if(pro[i][0]==c)
{if((pro[i][2]<=122&&pro[i][2]>=97)||pro[i][2]=='E')
{x->first[x->ft++]=pro[i][2];/*printf("%d",x->first[0]);*/}
else
first(x,pro[i][2]);}

}

void disp(struct state x)
{int i;
printf("\n%c -- ",x.name);
printf("{ ");
for(i=0;i<x.ft;i++)
printf("%c ",x.first[i]);
printf("}\t");

printf("{ ");
for(i=0;i<x.fw;i++)
printf("%c ",x.follow[i]);
printf("}");
}

void Eadder(char p[],struct state *x,int pos)
{
int l,m;
if(p[pos]<=122&&p[pos]>=97) //if T add to follow of k //if NT
x->follow[x->fw++]=p[pos];


else if(p[pos]>=65&&p[pos]<=97) // if T copy first of T to follow of k  //if terminal
{//printf("sdf");
for(l=0;l<statesp;l++)
if(states[l].name==p[pos]) break;//state already exists if true and at l
copy(x,states[l].first,states[l].ft);

if(containsE(states[l].first,states[l].ft)) Eadder(p,x,pos+1);
}




else if(p[pos]=='\0') //if epsilon
{for(m=0;m<statesp;m++)
if(states[m].name==p[0]) break;//state already exists if true and at m // production state
copy(x,states[m].follow,states[m].fw);
}

}




int main()
{int i,j,k,l,m;



printf("Enter No of Productions :");scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%s",pro[i]);

for(i=0;i<n;i++) //first
{for(j=0;j<statesp;j++)
if(states[j].name==pro[i][0]) break;//state already exists if true
if(j==statesp) //create new state
{states[j].name=pro[i][0];// printf("%c",pro[i][0]);
states[j].ft=states[j].fw=0;statesp++;} //if ** state created
if((pro[i][2]<=122&&pro[i][2]>=97)||pro[i][2]=='E')
states[j].first[states[j].ft++]=pro[i][2];
else
first(&states[j],pro[i][2]);
}//i 
//first ends here
//follow starts
states[0].follow[states[0].fw++]='$';

for(i=0;i<n;i++)
for(j=2;j<strlen(pro[i]);j++)
if(pro[i][j]>=65&&pro[i][j]<=90&&pro[i][j]!='E') //if found a NT
{//printf("sdf");
for(k=0;k<statesp;k++)
if(states[k].name==pro[i][j]) break;//state already exists if true and at k

//printf("%d",pro[i][j+1]);

if(pro[i][j+1]<=122&&pro[i][j+1]>=97) //if T add to follow of k //if NT
states[k].follow[states[k].fw++]=pro[i][j+1];


else if(pro[i][j+1]>=65&&pro[i][j+1]<=97) // if T copy first of T to follow of k  //if terminal
{//printf("sdf");
for(l=0;l<statesp;l++)
if(states[l].name==pro[i][j+1]) break;//state already exists if true and at l
copy(&states[k],states[l].first,states[l].ft);

if(containsE(states[l].first,states[l].ft)) Eadder(pro[i],&states[k],j+2);
}




else if(pro[i][j+1]=='\0') //if epsilon
{for(m=0;m<statesp;m++)
if(states[m].name==pro[i][0]) break;//state already exists if true and at m // production state
copy(&states[k],states[m].follow,states[m].fw);
}

}


printf("NT -- First -- Follow --\n");
for(i=0;i<statesp;i++) 
{removeDup(&states[i]);
disp(states[i]);
}
}
