var
 n,i:integer;
 a:array[0..10000+1] of longint;
 aa:qword;
procedure s(l,r:integer);
 var
i,j:integer;
x,g:longint;
 begin
i:=l;j:=r;x:=a[(l+r) shr 1];
repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
 if i<=j
then begin
   g:=a[i];
   a[i]:=a[j];
   a[j]:=g;
   inc(i);dec(j);
 end;
until i>j;
if l<j
  then s(l,j);
if i<r
 then s(i,r);
 end;
procedure st(nn:integer);
 var
g:longint;
 begin
while (a[nn]>a[nn+1]) and (nn<n) do
 begin
g:=a[nn];a[nn]:=a[nn+1];a[nn+1]:=g;
inc(nn);
  end;
 end;
begin
 readln(n);
 for i:=1 to n do
read(a[i]);
 s(1,n);
 aa:=0;
 for i:=2 to n do
begin
 inc(a[i],a[i-1]);
  aa:=aa+a[i];
  st(i);
end;
 writeln(aa);
end.

