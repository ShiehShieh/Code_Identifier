program vijos1153;
var i,j,k,n,sum,min:longint;
    a:array[1..200] of longint;
    d:array[0..100,0..4000] of longint;
begin
  readln(n);
  sum:=0;
  for i:=1 to n do
  begin
    readln(a[i]);
    sum:=sum+a[i];
  end;
  d[0,0]:=1;
  for i:=1 to n do
    for j:=n div 2 downto 1 do
      for k:=j*40 downto a[i] do
        if d[j-1,k-a[i]]=1 then d[j,k]:=1;
  min:=maxlongint;
  for i:=0 to n div 2*40 do
    if (d[n div 2,i]=1)and(abs(sum-i-i)<min) then min:=abs(sum-i-i);
  writeln((sum-min) div 2,' ',(sum+min) div 2);
end.
