var n,m,i,i1,i2,j,j1,ans,s:longint;
    a:array[1..10000] of longint;
begin
  readln(n);
  readln(m);
  for i:=1 to n do
    read(a[i]);
  i1:=n;
  for i:=1 to n do
    if a[i]>ans then ans:=a[i];
  for i:=1 to m do
    begin
    i1:=n;
    while a[i1]<a[i1-1] do i1:=i1-1;
    i1:=i1-1;
    i2:=i1+1;
    for j:=i1+1 to n-1 do
      for j1:=j+1 to n do
        if a[j]>a[j1] then begin
                             s:=a[j];
                             a[j]:=a[j1];
                             a[j1]:=s;
                           end;
    while a[i1]>a[i2] do i2:=i2+1;
    if a[i1]<a[i2] then begin
                          s:=a[i1];
                          a[i1]:=a[i2];
                          a[i2]:=s;
                        end;
    end;
for i:=1 to n do
  write(a[i],' ');

end.
