var a:array[0..400001,0..20] of int64;
    i,j,k,l,m,n,o,p,q,b:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if b>max then max:=b;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i,0]);
  m:=trunc(ln(n)/ln(2))+1;
  k:=1;
  for i:=1 to m do
    begin
      for j:=1 to n do
        a[j,i]:=max(a[j,i-1],a[j+k,i-1]);
      k:=k*2;
    end;
  readln(m);
  for i:=1 to m do
    begin
      readln(j,k);
      l:=trunc(ln(k-j+1)/ln(2));
      o:=1;
      for p:=1 to l do o:=o*2;
      write(max(a[j,l],a[k-o+1,l]));
    end;
end.


