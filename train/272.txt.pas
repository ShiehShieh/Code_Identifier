program p1421;
var
s,a,b,ss:string;
p,i,j,ii,jj,kk,la,ans,n:integer;
head,tail,lim,k:longint;
x,y,t:array[1..6]of string;
len:array[1..6]of integer;
q:array[1..1000000]of string;
new:boolean;
begin
readln(s);
p:=pos(' ',s);
a:=copy(s,1,p-1);
la:=length(a);
b:=copy(s,p+1,length(s)-p);
while not eof do
begin
readln(s);
inc(n);
p:=pos(' ',s);
x[n]:=copy(s,1,p-1);
y[n]:=copy(s,p+1,length(s)-p);
len[n]:=length(x[n]);
end;
if a=b then
begin writeln(0);halt;end;
head:=0;tail:=1;
q[1]:=a;
while head<tail do
begin
inc(head);
s:=q[head];
la:=length(s);
if head>lim then
begin
inc(ans);lim:=tail;
if (ans>10) then
begin
writeln('NO ANSWER!');halt;
end;
end;
for j:=1 to la do
begin
for i:=1 to n do
if copy(s,j,len[i])=x[i] then
begin
ss:=s;
delete(ss,j,len[i]);
insert(y[i],ss,j);
if ss=b then
begin
writeln(ans);halt;
end;
new:=true;
for k:=1 to head do
if q[k]=ss then
begin
new:=false;break;
end;
if new then
begin
inc(tail);
q[tail]:=ss;
if tail>=10000 then
begin
ss:=a;a:=b;b:=ss;
la:=length(a);
t:=x;x:=y;y:=t;
for ii:=1 to n do len[ii]:=length(x[ii]);
head:=0;tail:=1;lim:=0;ans:=0;
q[1]:=a;
while head<tail do
begin
inc(head);
s:=q[head];
la:=length(s);
if head>lim then
begin
inc(ans);lim:=tail;
if (ans>10) then
begin
 writeln('NO ANSWER!');halt;
end;
end;
for jj:=1 to la do
begin
for ii:=1 to n do
if copy(s,jj,len[ii])=x[ii] then
begin
ss:=s;
delete(ss,jj,len[ii]);
insert(y[ii],ss,jj);
if ss=b then
begin
writeln(ans);halt;
end;
new:=true;
for kk:=1 to head do
if q[kk]=ss then
begin
new:=false;break;
end;
if new then
begin
inc(tail);
q[tail]:=ss;
end;
end;
end;
end;
writeln('NO ANSWER!');
halt;
end;
end;
end;
end;
end;
writeln('NO ANSWER!');
end.
