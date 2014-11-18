#include <cstdio>
#include <string>
struct people
{
char name[15];
long get,give;
}pep[10];
int np;
int Input()
{int i;
scanf("%d",&np);
for(i=0;i<np;i++)
{scanf("%s",pep[i].name);
 pep[i].get=0;
 pep[i].give=0;
}
}
int Work()
{int i,j,gi,ngi,k;
char name1[15];
for(i=0;i<np;i++)
{scanf("%s",name1);
 for(j=0;strcmp(name1,pep[j].name);j++);
 scanf("%d %d",&gi,&ngi);
 if(!ngi) pep[j].get+=gi;
 else 
{pep[j].get+=gi%ngi;
 pep[j].give=gi;
 for(j=0;j<ngi;j++)
{scanf("%s",name1);
 for(k=0;strcmp(name1,pep[k].name);k++);
 pep[k].get+=gi/ngi;
}
}
}
} 
int Output()
{int i;
for(i=0;i<np;i++)
printf("%s %ld\n",pep[i].name,pep[i].get-pep[i].give);
}
main()
{Input();
Work();
Output();
}

