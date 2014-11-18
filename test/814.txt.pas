var
 j,k:INT64;
 n,i:longint;
 a,b:array[1..100]of longint;
begin
 readln(n);
 for i:=1 to n do
 readln(a[i],b[i]);
 k:=b[1];j:=a[1];
 for i:=2 to n do
 begin
   while  k mod a[i]<>b[i] do inc(k,j);
  j:=j*a[i]
  end;
  writeln(k);
 end.
