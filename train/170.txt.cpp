#include <iostream>
#include <cstring>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))

namespace Solve
{
    char s[10000][76];
    char *now;
    int n,l;
    int ans = 1;
    class Node
    {
    public:
        char c;
        int count;
        Node *next;
        Node *child;
        Node():next(NULL),child(NULL),c(0),count(0) {}
        Node(char c):next(NULL),child(NULL),c(c),count(0) {}
    };
    class Tire
    {
    public:
        Node *head;
        Tire() {head = new Node;}
        ~Tire() {clear(head);}
        void clear(Node *p)
        {
            Node *q = p->child, *q2;
            while(q)
            {
                q2 = q;
                q = q->next;
                delete q2;
            }
        }
        void add()
        {
            l = strlen(now);
            add(head,0,1);
        }
        void add(Node *p, int x, int count)
        {
            if(x==l)
			{
				ans = MAX(count,ans);
				p->count++;
                return;
			}
            count += p->count;
			if(p->child==NULL)
			{
                p->child = new Node(now[x]);
				add(p->child,x+1,count);
				return;
			}
            Node *q = p->child;
            while(q->next)
            {
                if(q->c==now[x])
                {
                    add(q,x+1,count);
                    return;
                }
                q = q->next;
            }
            if(q->c==now[x])
                add(q,x+1,count);
            else
            {
                q->next = new Node(now[x]);
                add(q->next,x+1,count);
            }
        }
    };
    Tire tree;
    void init();
    void solve();
    void print();
}

void Solve::init()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%s",s[i]);
}

void Solve::solve()
{
    for(int i = 0; i < n; i++)
    {
        now = s[i];
        tree.add();
    }
}

void Solve::print()
{
    printf("%d\n",ans);
}

int main(void)
{
    //freopen("link.in","r",stdin);
    //freopen("link.out","w",stdout);
    Solve::init();
    Solve::solve();
    Solve::print();
    return 0;
}
