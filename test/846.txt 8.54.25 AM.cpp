#include<stdio.h>
struct statetype {
unsigned int pre:18,a:2,b:2,c:2,d:2,e:2,f:2,g:2,h:2,i:2,op:4;
} state[262144];
char f[4][4][4][4][4][4][4][4][4];
#define turn(n) state[tail].n=(state[tail].n+1)&3
#define dest(n) !state[tail].n
#define setf(p) f[state[p].a][state[p].b][state[p].c][state[p].d][state[p].e][state[p].f][state[p].g][state[p].h][state[p].i]=1

void out(int tail) {
if(tail) {
int op=state[tail].op;
out(state[tail].pre);
printf("%d ",op);
}
}

int main() {
int t[9],i=1,head=0,tail=1;
scanf("%d%d%d%d%d%d%d%d%d",t,t+1,t+2,t+3,t+4,t+5,t+6,t+7,t+8);
state[0].a=t[0],state[0].b=t[1],state[0].c=t[2],state[0].d=t[3],state[0].e=t[4],state[0].f=t[5],state[0].g=t[6],state[0].h=t[7],state[0].i=t[8];
setf(0);
while(1) {
state[tail]=state[head];
state[tail].op=i,state[tail].pre=head;
switch(i) {
case 1: turn(a),turn(b),turn(d),turn(e);break;
case 2: turn(a),turn(b),turn(c);break;
case 3: turn(b),turn(c),turn(e),turn(f);break;
case 4: turn(a),turn(d),turn(g);break;
case 5: turn(b),turn(d),turn(e),turn(f),turn(h);break;
case 6: turn(c),turn(f),turn(i);break;
case 7: turn(d),turn(e),turn(g),turn(h);break;
case 8: turn(g),turn(h),turn(i);break;
case 9: turn(e),turn(f),turn(h),turn(i);
} if(!f[state[tail].a][state[tail].b][state[tail].c][state[tail].d][state[tail].e][state[tail].f][state[tail].g][state[tail].h][state[tail].i]) {
if(dest(a)&&dest(b)&&dest(c)&&dest(d)&&dest(e)&&dest(f)&&dest(g)&&dest(h)&&dest(i)) break;
setf(tail),tail++;
} if(++i>9) i=1,head++;
} out(tail);
return 0;
}

