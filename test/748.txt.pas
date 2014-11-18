var
  s,t,w,i,j,k:longint;
  c:string;
  a:array[1..30] of longint;
begin
  readln(s,t,w);
  readln(c);
  for i:=1 to w do
  a[i]:=ord(c[i]);

  for i:=1 to 5 do
  begin

  j:=w;
  while a[j]=t+96-(w-j) do j:=j-1;
  a[j]:=a[j]+1;
  for k:=j+1 to w do
  a[k]:=a[k-1]+1;

  for k:=1 to w do
  write(chr(a[k]));
  writeln;
  end;

end.
