var
  s,t,w,i,j,k:integer;
  a:array[0..26]of byte;
  c:char;
begin
  readln(s,t,w);
  a[0]:=0;
  for i:=1 to w do
  begin
    read(c);
    a[i]:=ord(c);
  end;
  k:=1;
  while (a[0]=0)and(k<=5) do
  begin
    while a[i]=t-w+i+96 do i:=i-1;
    a[i]:=a[i]+1;
    for j:=i+1 to w do
    a[j]:=a[j-1]+1;
    for i:=1 to w do
    write(chr(a[i]));
    writeln;
    k:=k+1;
  end;
end.
