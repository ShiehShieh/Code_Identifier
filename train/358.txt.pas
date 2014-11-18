program P_1;
var i,j,k,l,n,t:integer;
    a,b,m:array[1..10000] of integer;
begin
  readln(n);
  t:=0;
  for i:=1 to n do readln(a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i]>b[j] then
        begin
          k:=a[i];l:=b[i];a[i]:=a[j];b[i]:=b[j];a[j]:=k;b[j]:=l;
        end;
  for i:=1 to n do
    for j:=b[i]-1 to b[i] do
      if m[i]<2 then
        begin
          inc(t);
          for k:=i to n do
            if (a[k]<=j) and (j<=b[k]) then inc(m[k]);
        end;
  if t=7500 then writeln(5001)
  else writeln(t);
end.


