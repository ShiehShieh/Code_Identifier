program p1234;
Type
 arr=record
  x,y,data:longint;
end;
Var
 n,m,k,i,j,ans,dad:longint;
 f:array[1..3000] of longint;
 a:array[1..10001] of arr;
 finish:boolean;

Procedure qsort(l,r:longint);
var
 i,j,x:longint;

procedure swap(var q,e:arr);
var
 temp:arr;
begin
 temp:=q;
 q:=e;
 e:=temp;
end;

begin
 i:=l;
 j:=r;
 x:=a[(i+j) div 2].data;
 repeat
  while a[i].data<x do inc(i);
  while a[j].data>x do dec(j);
  if i<=j then
   begin
    swap(a[i],a[j]);
    inc(i);
    dec(j);
   end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;

Function find(z:longint):longint;
begin
 if f[z]<>z then find:=find(f[z]) else exit(z);
end;

Procedure union(z:longint);
begin
 if f[z]=z then
  begin
   f[z]:=dad;
   exit;
  end
 else
  begin
   union(f[z]);
   f[z]:=dad;
  end;
end;

Begin
 readln(n,m,k);
 for i:=1 to m do
  readln(a[i].x,a[i].y,a[i].data);
 qsort(1,m);
 for i:=1 to n do
  f[i]:=i;
 j:=1;
 for i:=1 to n-k do
  begin
   finish:=false;
   while not finish do
    if find(a[j].x)<>find(a[j].y) then
     begin
      ans:=ans+a[j].data;
      dad:=a[j].x;
      union(a[j].y);
      inc(j);
      finish:=true;
      if j>m then break;
     end
    else
     begin
      inc(j);
      if j>m then break;
     end;
   if j>m then break;
  end;
 if j>m then writeln('No Answer') else writeln(ans);
End.







