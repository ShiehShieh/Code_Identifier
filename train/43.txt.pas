type ar=array[1..100000]of longint;
var a,b,c,sum:ar;
    n,m,i,j:longint;
procedure sort(var a:ar;s,t:longint);
var
i,j,k,x:longint;
begin
 i:=s;
 j:=t;
 k:=random(t-s+1)+s;
 x:=a[k];
 repeat
  while a[i]>x do inc(i);
  while a[j]<x do dec(j);
  if i<=j then
   begin
    k:=a[i]; a[i]:=a[j]; a[j]:=k;
    k:=c[i];c[i]:=c[j];c[j]:=k;
    inc(i); dec(j);
   end;
 until i>j;
 if s<j then sort(a,s,j);
 if i<t then sort(a,i,t);
end;
begin
 readln(m,n);
 for i:=1 to m do read(b[i]);
 for i:=1 to n do read(a[i]);
 sort(b,1,m);
 for i:=1 to n do c[i]:=i;
 sort(a,1,n);
 for i:=1 to m do
 if i mod n<>0 then  inc(sum[i mod n],b[i])
               else inc(sum[n],b[i]);
 for i:=1 to n do
  for j:=1 to n do
   if c[j]=i then begin write(sum[j],' '); break end;
end.
