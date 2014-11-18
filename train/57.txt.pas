//http://www.vijos.cn/Problem_Show.asp?id=1336
var max,j,n,m,k,i:longint;x,y,f:array[0..1000]of longint;
procedure qsort(l,r:longint);
  var a,i,j,t:longint;
  begin
    i:=l;j:=r;
    a:=y[(i+j) div 2];
    repeat
      while (y[i]<a) do inc(i);
      while (y[j]>a) do dec(j);
      if i<=j then
        begin
          t:=y[i];y[i]:=y[j];y[j]:=t;
          t:=x[i];x[i]:=x[j];x[j]:=t;
          inc(i);dec(j);
        end;
    until i>j;
    if j>l then qsort(l,j);
    if i<r then qsort(i,r);
  end;
begin
  
  readln(n,m);
  readln(k);
  for i:=1 to k do
    begin
      readln(x[i],y[i]);
      f[i]:=1;
    end;
  qsort(1,k);
  max:=0;
  for i:=2 to k do
    for j:=1 to i-1 do
      begin
        if (x[i]>x[j])and(y[i]>y[j])and(f[i]<f[j]+1) then
          begin
            f[i]:=f[j]+1;
            if max<f[i] then max:=f[i];
          end;
      end;
  writeln(((m-max)+(n-max)+max*sqrt(2))*100:0:0);
end.
