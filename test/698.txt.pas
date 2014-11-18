program fat;
const
num=1000;
type
     bian=^node;
     node=record
          k:longint;
          next:bian;
          end;
var
v:Array[0..num] of boolean;
f:Array[0..2*num] of longint;
a:array[0..num] of bian;
temp,ans:array[0..num] of longint;
h:array[0..num,0..num] of boolean;
i,j,k,n,m,number,total:longint;
p:bian;

function father(x:longint):longint;
begin
if f[x]=x then exit(x);
f[x]:=father(f[x]);
father:=f[x];
end;

function exist(x,y:longint):boolean;
begin
exist:=father(x)=father(y);
end;

procedure change(x,y:longint);
begin
f[father(x)]:=f[father(y)]
end;

procedure print;
begin
for i:=1 to number do
     writeln('The Graph has Fat Tour.');
for i:=number+1 to total do
     writeln('Poor Fat Tour.');
halt;
end;

procedure init;
var x,y:longint;
begin
fillchar(a,sizeof(a),0);
readln(n,m,total);
for i:=1 to n do
     v[i]:=true;
for i:=1 to m do
     begin
     readln(x,y);
     if h[x,y] then continue;
     h[x,y]:=true; h[y,x]:=true;
     new(p); p^.k:=y; p^.next:=a[x]; a[x]:=p;
     new(p); p^.k:=x; p^.next:=a[y]; a[y]:=p;
     end;
for i:=1 to total do
     begin
     read(temp[i]);
     v[temp[i]]:=false;
     end;
for i:=1 to n do
     begin
     f[i]:=i;
     f[i+num]:=i+num;
     end;
for i:=1 to n do
  if v[i] then
     begin
     p:=a[i];
     while p<>nil do
          begin
          if v[p^.k] then
               begin
               if exist(i,p^.k) or exist(i+num,p^.k+num) then
                    begin
                    number:=total;
                    print;
                    end;
               change(i,p^.k+num); change(i+num,p^.k);
               end;
          p:=p^.next;
          end;
     end;
end;

procedure work;
var x:longint;
begin
for i:=total downto 1 do
     begin
     x:=temp[i]; v[x]:=true;
     p:=a[x];
     while p<>nil do
          begin
          if v[p^.k] then
               begin
               if exist(x,p^.k) or exist(x+num,p^.k+num) then
                    begin
                    number:=i-1;
                    print;
                    end;
               change(x,p^.k+num); change(x+num,p^.k);
               end;
          p:=p^.next;
          end;
     end;
number:=0; print;
end;

begin
init;
work;
end.

