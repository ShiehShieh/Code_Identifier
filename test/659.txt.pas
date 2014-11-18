const
maxn=131072;
tempt=65536;
type
     point=record
          x,y:longint;
          end;
     matrix=record
          x1,y1,x2,y2:longint;
          end;
     quene=record
          x,l,r,d:longint;
          end;
     shu=array[0..200000] of int64;
     wh=^wnode;
     wnode=record
          y:longint;
          next:wh;
          end;
     qh=^qnode;
     qnode=record
          k:quene;
          next:qh;
          end;

var
a:array[0..400000] of point;
B,W:array[0..400000] of point;
H:array[0..400000] of matrix;
l:array[0..400000] of longint;
que:array[0..400000] of quene;
can:array[0..400000] of boolean;
hash:array[-200000..200000] of wh;
hh:array[-200000..200000] of qh;
QQ:array[0..120000] of longint;
i,j,k,n,m,D:longint;
min,max:int64;
P,Q:shu;
c:array[0..270000] of longint;

procedure quesort(n:longint);
var
i,m:longint;
k:qh;
begin
for i:=1 to n do
     begin
     new(k); k^.k:=que[i]; k^.next:=hh[que[i].x];
     hh[que[i].x]:=k;
     end;
m:=0;
for i:=-200000 to 200000 do
     while hh[i]<>nil do
          begin
          inc(m); que[m]:=hh[i]^.k;
          hh[i]:=hh[i]^.next;
          end;
end;

procedure wsort(l,r:longint);
var
i,m:longint;
k:wh;
begin
for i:=l to r do
     begin
     new(k); k^.y:=a[i].y; k^.next:=hash[a[i].x-a[i].y];
     hash[a[i].x-a[i].y]:=k;
     end;
m:=l;
for i:=-200000 to 200000 do
     while hash[i]<>nil do
          begin
          a[m].x:=i+hash[i]^.y; a[m].y:=hash[i]^.y;
          inc(m); hash[i]:=hash[i]^.next;
          end;
end;

procedure insert(x0,y0,x,y,delta:longint);
var mid:longint;
begin
if (x<=x0)and(y0<=y) then
     begin c[x0+y0]:=c[x0+y0]+delta; exit; end;
mid:=(x0+y0)shr 1;
if mid>=x then
     insert(x0,mid,x,y,delta);
if mid+1<=y then
     insert(mid+1,y0,x,y,delta)
end;

function find(x0,y0,x:longint):longint;
var mid:longint;
begin
find:=0;
while true do
     begin
     find:=find+c[x0+y0];
     if x0=y0 then
          exit;
     mid:=(x0+y0)shr 1;
     if x<=mid then
          y0:=mid
     else x0:=mid+1;
     end;
end;

procedure pc1;
var
xl,xn,k,tot:longint;
begin
xl:=-maxlongint; xn:=-maxlongint;
fillchar(c,sizeof(c),0);
k:=1; i:=0;
while (k<=n)and ((not can[k])or(w[k].x<que[1].x)) do inc(k);
while i<m do
     begin
     inc(i); xl:=xn; xn:=que[i].x; tot:=0;
     while (i<=m)and(que[i].x=que[i+1].x) do
          begin
          if que[i].d<>0 then
               insert(1,maxn,que[i].l,que[i].r,que[i].d);
          inc(i);
          end;
     if que[i].d<>0 then
          insert(1,maxn,que[i].l,que[i].r,que[i].d);
     if xn>maxn then exit;
     while (k<=n)and(xl<=w[k].x)and(w[k].x<=xn)and((D=1)or(xl>-maxlongint))do
          begin
          P[k]:=find(1,maxn,w[k].y);
          inc(k);
          while (k<=n)and not can[k] do inc(k);
          end;
     if k>n then exit;
     end;
end;

procedure init;
var
temp:point;
begin
readln(n,D);
for i:=1 to 2*n do
     readln(a[i].x,a[i].y);
     //begin a[i].x:=random(100000)+1; a[i].y:=random(100000)+1; end;
wsort(1,n); wsort(n+1,2*n);
//p:

//case1:
for i:=n+1 to 2*n do
 with a[i] do
  with H[i-n] do
     if (x+y+D)mod 2=0 then
          begin
          x1:=(x-y-D) div 2; y1:=(x+y-D) div 2;
          x2:=(x-y+D) div 2; y2:=(x+y+D)shr 1;
          end
     else begin
          x1:=(x-y-D+1) div 2; y1:=(x+y-d+1) div 2;
          x2:=(x-y+D-1) div 2; y2:=(x+y+d-1)shr 1;
          end;
for i:=1 to n do
     begin
     w[i].x:=(a[i].x-a[i].y+maxn)shr 1-tempt;
     w[i].y:=(a[i].x+a[i].y)shr 1;
     can[i]:=(a[i].x+a[i].y)and 1=0;
     end;
m:=0;
for i:=1 to n do
     begin
     inc(m);
     que[m].x:=H[i].x1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=1;
     inc(m);
     que[m].x:=w[i].x;
     que[m].l:=-maxn;
     que[m].r:=maxn;
     que[m].d:=0;
     inc(m);
     que[m].x:=H[i].x2+1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=-1;
     end;
quesort(m);
pc1;

//case2:
for i:=n+1 to 2*n do
 with a[i] do
  with H[i-n] do
     if (x+y+D)mod 2=1 then
          begin
          x1:=(x-y-D-1) div 2; y1:=(x+y-D-1) div 2;
          x2:=(x-y+D-1) div 2; y2:=(x+y+D-1)shr 1;
          end
     else begin
          x1:=(x-y-D) div 2; y1:=(x+y-d)div 2;
          x2:=(x-y+D-2) div 2; y2:=(x+y+d-2)shr 1;
          end;
for i:=1 to n do
     begin
     w[i].x:=(a[i].x-a[i].y-1+maxn)shr 1-tempt;
     w[i].y:=(a[i].x+a[i].y-1)shr 1;
     can[i]:=(a[i].x+a[i].y)and 1=1;
     end;
m:=0;
for i:=1 to n do
     begin
     inc(m);
     que[m].x:=H[i].x1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=1;
     inc(m);
     que[m].x:=w[i].x;
     que[m].l:=-maxn;
     que[m].r:=maxn;
     que[m].d:=0;
     inc(m);
     que[m].x:=H[i].x2+1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=-1;
     end;
quesort(m);
pc1;

//Q:

Q:=P; fillchar(P,sizeof(P),0);
for i:=1 to n do
     begin
     temp:=a[i];
     a[i]:=a[n+i];
     a[n+i]:=temp;
     end;

//case1:
for i:=n+1 to 2*n do
 with a[i] do
  with H[i-n] do
     if (x+y+D)mod 2=0 then
          begin
          x1:=(x-y-D) div 2; y1:=(x+y-D)div 2;
          x2:=(x-y+D) div 2; y2:=(x+y+D)shr 1;
          end
     else begin
          x1:=(x-y-D+1) div 2; y1:=(x+y-d+1)div 2;
          x2:=(x-y+D-1) div 2; y2:=(x+y+d-1)shr 1;
          end;
for i:=1 to n do
     begin
     w[i].x:=(a[i].x-a[i].y+maxn)shr 1-tempt;
     w[i].y:=(a[i].x+a[i].y)shr 1;
     can[i]:=(a[i].x+a[i].y)and 1=0;
     end;
m:=0;
for i:=1 to n do
     begin
     inc(m);
     que[m].x:=H[i].x1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=1;
     inc(m);
     que[m].x:=w[i].x;
     que[m].l:=-maxn;
     que[m].r:=maxn;
     que[m].d:=0;
     inc(m);
     que[m].x:=H[i].x2+1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=-1;
     end;
quesort(m);
pc1;

//case2:
for i:=n+1 to 2*n do
 with a[i] do
  with H[i-n] do
     if (x+y+D)mod 2=1 then
          begin
          x1:=(x-y-D-1) div 2; y1:=(x+y-D-1)div 2;
          x2:=(x-y+D-1) div 2; y2:=(x+y+D-1)shr 1;
          end
     else begin
          x1:=(x-y-D) div 2; y1:=(x+y-d)div 2;
          x2:=(x-y+D-2) div 2; y2:=(x+y+d-2)shr 1;
          end;
for i:=1 to n do
     begin
     w[i].x:=(a[i].x-a[i].y-1+maxn)shr 1-tempt;
     w[i].y:=(a[i].x+a[i].y-1)shr 1;
     can[i]:=(a[i].x+a[i].y)and 1=1;
     end;
m:=0;
for i:=1 to n do
     begin
     inc(m);
     que[m].x:=H[i].x1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=1;
     inc(m);
     que[m].x:=w[i].x;
     que[m].l:=-maxn;
     que[m].r:=maxn;
     que[m].d:=0;
     inc(m);
     que[m].x:=H[i].x2+1;
     que[m].l:=H[i].y1;
     que[m].r:=H[i].y2;
     que[m].d:=-1;
     end;
quesort(m);
pc1;

end;

procedure qsort(n:longint;var a:shu);
var
i,j,m:longint;
begin
fillchar(QQ,sizeof(QQ),0);
for i:=1 to n do
     inc(QQ[a[i]]);
m:=0;
for i:=0 to 120000 do
     for j:=1 to QQ[i] do
          begin
          inc(m);
          a[m]:=i;
          end;
end;

procedure work;
begin
qsort(n,P); qsort(n,Q);
min:=0;
for i:=1 to n do
     begin
     min:=min+(n-i)*(P[i]+Q[i]);
     min:=min-(P[i]*(P[i]-1)+Q[i]*(Q[i]-1))shr 1;
     end;
max:=0;
for i:=1 to n do
     begin
     max:=max+(i-1)*(P[i]+Q[i]);
     max:=max-(P[i]*(P[i]-1)+Q[i]*(Q[i]-1))shr 1;
     end;
end;

begin
init;
work;
writeln(min,' ',max);
end. 
