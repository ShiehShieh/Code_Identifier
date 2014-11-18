var
 h,n,m,i,j:longint;
 b:array[1..2000]of boolean;
 a,tao:array[1..2000]of longint;
procedure qsort(l,r:longint);
var
 t,x,i,j:longint;
begin
 i:=l;j:=r;x:=tao[(l+r) div 2];
 repeat
while (tao[i]<x) do i:=i+1;
while (x<tao[j]) do j:=j-1;
if i<=j then
begin
  t:=tao[i];
  tao[i]:=tao[j];
  tao[j]:=t;
  i:=i+1;j:=j-1;
end;
 until i>=j;
 if l<j then qsort(l,j);
 if r>i then qsort(i,r);
end;
begin
 read(n,m);
 h:=m;
 for i:=1 to n do read(a[i]);
 for i:=1 to m do read(tao[i]);
 qsort(1,m);
 fillchar(b,sizeof(b),true);
 for i:=1 to n do
for j:=m downto 1 do if (tao[j]>0)and(b[j])and(tao[j]<a[i]) then begin h:=h-1;b[j]:=false;break;end;
  writeln(h);
end.

