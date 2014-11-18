//20:10-
#include <iostream>
#define maxn 300
typedef struct Edge {
    int dest;
    struct Edge *next;
}Edge;
Edge *edge[maxn];
Edge *father[maxn];
bool visited[maxn];
int count[maxn];
int queue[maxn*maxn];

void bfs(int origin,int n)
{
    bool flag[maxn];
    int top=-1,tail=0;
    queue[tail]=origin;
    Edge *l,*k;
    memset(flag,0,sizeof(flag));
    visited[origin]=true;
    flag[origin]=true;
    count[origin]=1;
    
    while (top<tail)
    {
        top++;
        for(l=edge[queue[top]];l;l=l->next)
            if (!flag[l->dest])
            {
                flag[l->dest]=true;
                tail++;
                queue[tail]=l->dest;visited[l->dest]=true;count[origin]++;
                k=new Edge;
                k->dest=origin;
                k->next=father[l->dest];
                father[l->dest]=k;
                if (queue[top]!=origin)
                {
                    k=new Edge;
                    k->dest=l->dest;
                    k->next=edge[origin];
                    edge[origin]=k;
                }
            }
    }
}

int main()
{
    //freopen("vijios1023.in","r",stdin);
    int person,i,n,j;
    Edge *l,*k;
    memset(edge,0,sizeof(edge));
    memset(father,0,sizeof(father));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&person);
        
        while (person!=0)
        {
            //printf("%d %d\n",i,person);
            l=new Edge;
            l->dest=person;
            l->next=edge[i];
            edge[i]=l;
            scanf("%d",&person);
        }
    }
    memset(visited,0,sizeof(visited));
    memset(count,0,sizeof(count));
    for (i=1;i<=n;i++)
    {
        if (!visited[i]) bfs(i,n);
    }

    memset(visited,0,sizeof(visited));
    int max,collect,note=0;
    for (i=1;i<=n;i++)
    {
        
        max=0;collect=0;
        for (j=1;j<=n;j++)
            if (!visited[j]&&count[j]>max) {max=count[j];collect=j;}
        if (collect==0) break;
        note++;visited[collect]=true;
        for (l=edge[collect];l;l=l->next)
        {
            for (k=father[l->dest];k;k=k->next)
                count[k->dest]--;
            visited[l->dest]=true;
        }
    }
    printf("%d\n",note);
    return 0;
}

