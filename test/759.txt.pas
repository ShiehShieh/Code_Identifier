var i,j,r,k,n,max:longint;
    f:array[1..200,1..200] of longint;
    da:array[1..200] of longint;
begin
 readln(n);
 for i:=1 to n do read(da[i]);
 for i:=n+1 to 2*n+1 do da[i]:=da[i-n];
 for j:=3 to 2*n do
 for i:=j-2 downto 1 do
 for k:=i+1 to j-1 do
  begin
  max:=f[i,k]+f[k,j]+da[i]*da[k]*da[j];
  if max>f[i,j] then f[i,j]:=max;
  end;
 max:=0;
 for i:=1 to n do if f[i,i+n]>max then max:=f[i,i+n];
 writeln(max);
end.                      
