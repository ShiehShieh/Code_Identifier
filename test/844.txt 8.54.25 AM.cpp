#include <cstdio>
#include <cstring>
using namespace std;

const int MAXNP=10;
int NP;
char name[MAXNP][15];
int init[MAXNP],account[MAXNP]={0};

void Init(){
    scanf("%d",&NP);
    for(int i=0;i<NP;i++)
        scanf("%s",name[i]);
}

int NameInput(){
    char st[15];
    scanf("%s",st);
    for(int i=0;i<NP;i++)
        if(!strcmp(st,name[i]))
            return i;
}

void Solve(){
    int giver,receiver,NG,amount;
    for(int i=0;i<NP;i++){
        giver=NameInput();
        scanf("%d%d",&init[giver],&NG);
        account[giver]+=init[giver];
        if(NG){
            amount=init[giver]/NG;
            account[giver]-=amount*NG;
        }
        for(int j=0;j<NG;j++){
            receiver=NameInput();
            account[receiver]+=amount;
        }
    }
}

void Output(){
    for(int i=0;i<NP;i++){
        printf("%s ",name[i]);
        printf("%d\n",account[i]-init[i]);
    }
}

int main(){
    Init();
    Solve();
    Output();
    return 0;
}
