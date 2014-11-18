program ex;
var
  time,value:array[1..100] of integer;
  f:array[0..100,0..1000] of integer;
  i,j,m,t:integer;
begin
  readln(t,m);
  for i:=1 to m do readln(time[i],value[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to m do
    for j:=1 to t do
      if j>=time[i] then
        begin
          if (f[i-1,j-time[i]]+value[i])>f[i-1,j] then f[i,j]:=f[i-1,j-time[i]]+value[i]
           else f[i,j]:=f[i-1,j];
        end
        else
        f[i,j]:=f[i-1,j];
  writeln(f[m,t]);
end.

