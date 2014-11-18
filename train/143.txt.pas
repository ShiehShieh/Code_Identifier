program T1039_4;
const
filein='T1039_4.in';
fileout='T1039_4.out';
maxn=30;
perx:array[1..4]of -1..1=(1,0,-1,0);
pery:array[1..4]of -1..1=(0,1,0,-1);
maxlongint=1000000000;
type
Tin=longint;
Tarr=array[1..maxn,1..maxn]of qword;
Tarr2=array[0..maxn+1,0..maxn+1]of boolean;
var
x1,x2,y1,y2,start,own,time,sx,sy,timen,x3,y3:qword;
man,cla:Tarr;
pd:Tarr2;
procedure init;
var
i,j:Tin;
begin
readln(x1,y1);
for i:=1 to x1 do
begin
for j:=1 to y1 do
begin
read(man[i,j]);
if man[i,j]=0
then begin
sx:=i;
sy:=j;
end;
end;
readln;
end;
readln(x2,y2);
for i:=x2 downto 1 do
begin
for j:=1 to y2 do
begin
read(cla[i,j]);
if cla[i,j]=0
then begin
x3:=i;
y3:=j;
end;
end;
readln;
end;
readln(start);
end;
procedure dfs(nx,ny,num:Tin);
var
i:Tin;
min,minx,miny,t:qword;
begin
min:=maxlongint;
t:=0;
for i:=1 to 4 do
if pd[nx+perx[i],ny+pery[i]]
then begin
if man[nx+perx[i],ny+pery[i]]<min
then begin
min:=man[nx+perx[i],ny+pery[i]];
minx:=nx+perx[i];
miny:=ny+pery[i];
end;
end
else inc(t);
if num=x1*y1
then begin
writeln(num);
writeln(nx,',',ny);
exit;
end;
if t=4
then begin
writeln('Error!');
writeln(nx,',',ny);
exit;
end
else if timen>time
then begin
writeln(num);
writeln(minx,',',miny);
exit;
end
else begin
inc(timen,min);
pd[minx,miny]:=false;
dfs(minx,miny,num+1);
end;
end;
procedure main;
var
i,j,x,y:Tin;
begin
timen:=0;
fillchar(pd,sizeof(pd),false);
for i:=1 to x1 do
for j:=1 to y1 do
pd[i,j]:=true;
time:=0;
own:=x3*y2;
if x3 mod 2=0
then inc(own,y2-y3+1)
else inc(own,y3);
if start=1
then begin
if x3 mod 2=0
then inc(own,-y2+y3-1+y3)
else inc(own,y2+1-2*y3);
end;
if start=0
then for i:=1 to own do
begin
x:=i div y2;
y:=i mod y2;
if y=0
then begin
dec(x);
y:=y2;
end;
if x mod 2=1
then inc(time,cla[x,y])
else inc(time,cla[x,y2-y+1]);
end
else for i:=1 to own do
begin
x:=i div y2;
y:=i mod y2;
if y=0
then begin
dec(x);
y:=y2;
end;
if x mod 2=1
then inc(time,cla[x,y2-y+1])
else inc(time,cla[x,y]);
end;
pd[sx,sy]:=false;
dfs(sx,sy,1);
end;
begin
init;
main;
end. 
