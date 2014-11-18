{直接压路径，不用压的很小，能过就行了-_-||| 注意排序和S=T.}
var
 f,b:array[0..260000]of integer;
 a:array[0..2500]of longint;
 l,s,t,m,i,j,w:longint;  ch:char;
begin
  read(l,s,t,m);
  for i:=1 to m do
read(a[i]);
 w:=0;
 if s=t then begin
     for i:=1 to m  do if a[i] mod s=0 then inc(w);write(w);
exit;
end;
  for i:=1 to m do
for j:=i to m do if a[i]>a[j] then begin  w:=a[i];a[i]:=a[j];a[j]:=w;end;
 for i:=1 to m do
 if a[i]-a[i-1]>200 then
  begin w:=a[i]-a[i-1]-200;
  for j:=i to m do
a[j]:=a[j]-w;
  end;
 for i:=1 to m do b[a[i]]:=1;
l:=a[m]+10;
 for i:=1 to l do
  begin   f[i]:=100;
  for  j:=s to t do
if (i-j>=0)and(f[i]>f[i-j]+b[i]) then f[i]:=f[i-j]+b[i];
  end;
writeln(f[l]);
 end.
