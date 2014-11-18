{
LANG:PASCAL
ID:why19931
TASK:maze1
}
var
vis:array[0..200,0..100]of boolean;
step,head,tail:longint;
x,y:array[1..20000]of longint;
b:array[0..200,0..100,1..4]of boolean;
f:array[1..200,1..100]of longint;
c:array[1..600,1..200]of char;
m,n,o,p,q:longint;
x1,x2,y1,y2:longint;

function min(i,j:longint):longint;
begin
if i>j
then exit(j)
else exit(i);
end;

function max:longint;
var
i,j:longint;
begin
max:=0;
for i:=1to m do
for j:=1to n do
if(f[i,j]>max)and(f[i,j]<>maxlongint)
then max:=f[i,j];
if max=9
then max:=4;
end;

procedure sou(i,j:longint);
begin
f[i,j]:=min(f[i,j],step);
if(b[i,j,1])and(not vis[i-1,j])
then begin
     inc(tail);
     vis[i-1,j]:=true;
     x[tail]:=i-1;
     y[tail]:=j;
     end;
if(b[i,j,2])and(not vis[i,j+1])
then begin
     inc(tail);
     vis[i,j+1]:=true;
     x[tail]:=i;
     y[tail]:=j+1;
     end;
if(b[i,j,3])and(not vis[i+1,j])
then begin
     inc(tail);
     vis[i+1,j]:=true;
     x[tail]:=i+1;
     y[tail]:=j;
     end;
if(b[i,j,4])and(not vis[i,j-1])
then begin
     inc(tail);
     vis[i,j-1]:=true;
     x[tail]:=i;
     y[tail]:=j-1;
     end;
end;

begin
readln(n,m);
for o:=1to 2*m+1do
begin
for p:=1to 2*n+1do
begin
read(c[o,p]);
if(c[o,p]=' ')and((o=1)or(p=1)or(o=2*m+1)or(p=2*n+1))
then if(x1<>0)or(y1<>0)
     then begin
          x2:=o div 2;
          y2:=p div 2;
          end
     else begin
          x1:=o div 2;
          y1:=p div 2;
          end;
end;
readln;
end;
fillchar(b,sizeof(b),true);
for o:=1to m do
for p:=1to n do
begin
if c[o*2-1,p*2]='-'
then begin
     b[o,p,1]:=false;
     b[o-1,p,3]:=false;
     end;
if c[o*2+1,p*2]='-'
then begin
     b[o,p,3]:=false;
     b[o+1,p,1]:=false;
     end;
if c[o*2,p*2-1]='|'
then begin
     b[o,p,4]:=false;
     b[o,p-1,2]:=false;
     end;
if c[o*2,p*2+1]='|'
then begin
     b[o,p,2]:=false;
     b[o,p+1,4]:=false;
     end;
end;
filldword(f,sizeof(f)div 4,maxlongint);
fillchar(vis,sizeof(vis),true);
if x1=0
then inc(x1);
if x2=0
then inc(x2);
if y1=0
then inc(y1);
if y2=0
then inc(y2);
for o:=1to m do
for p:=1to n do
vis[o,p]:=false;
vis[x1,y1]:=true;
f[x1,y1]:=1;
f[x2,y2]:=1;
x[1]:=x1;
y[1]:=y1;
head:=1;
tail:=1;
step:=0;
while head<=tail do
begin
p:=tail;
inc(step);
for q:=head to tail do
sou(x[q],y[q]);
head:=p+1;
end;
for o:=1to m do
for p:=1to n do
vis[o,p]:=false;
vis[x2,y2]:=true;
x[1]:=x2;
y[1]:=y2;
step:=0;
head:=1;
tail:=1;
while head<=tail do
begin
p:=tail;
inc(step);
for q:=head to tail do
sou(x[q],y[q]);
head:=p+1;
end;
writeln(max);
end.

