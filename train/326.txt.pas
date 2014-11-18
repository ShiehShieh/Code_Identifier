type arr=array[1..102] of qword;
var p1,c1,p2,c2:arr;   q,q1,q2:qword;
    i,l1,l2,n:longint;
procedure erzhuange(var c,p:arr; l:qword);
var i:longint;
begin
for i:=1 to l do
 c[i]:=p[i+1] xor p[i];
end;

procedure gezhuaner(var c,p:arr; l:qword);
var i:longint;
begin
for i:=1 to l do
 if i=1 then p[i]:=c[i]
       else p[i]:=p[i-1] xor c[i];
end;

procedure erzhuanshi(var c:arr;l:qword; var q:qword);
var i,j:longint;
    x:qword;
begin
q:=0;
 for i:=1 to l do
   begin
    x:=c[i];
    for j:=1 to l-i do
    x:=x*2;
    q:=q+x;
   end;
end;

procedure shizhuaner(var c:arr; var l:longint;q:qword);
var i,j:longint;
    xxxxx:arr;
begin
fillchar(xxxxx,sizeof(xxxxx),0);
i:=1;
while q>0 do
 begin
  xxxxx[i]:=q mod 2;
  q:=q div 2;
  inc(i);
 end;
l:=i-1;
for i:=1 to l do
 c[i]:=xxxxx[l-i+1];
end;

begin
readln(q);
shizhuaner(c1,l1,q);
gezhuaner(c1,p1,l1);
erzhuanshi(p1,l1,q1);
writeln(q1+1);
end.

