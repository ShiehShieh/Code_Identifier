program zhu;
var
  i,j,n:integer;
  a,b:array[1..1001,0..1001]of longint;
procedure readd;
var
  i,j:integer;
begin
  fillchar(a,sizeof(a),0);
  read(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  b:=a;
  for i:=2 to n do a[n,i]:=a[n,i-1]+a[n,i];
  if b[n,n]+a[n,1]<a[n,n] then a[n,n]:=b[n,n]+a[n,1];
  for i:=n-1 downto 2 do
    if b[n,i]+a[n,i+1]<a[n,i] then a[n,i]:=a[n,i+1]+b[n,i];
  for i:=1 to n do b[n,i]:=a[n,i];
end;
procedure work;
var
  i,j,min,t,l:longint;
begin
  for i:=1 to n do
    begin
      a[i,0]:=maxlongint div 10;a[i,i+1]:=maxlongint div 10;
      b[i,0]:=maxlongint div 10;b[i,i+1]:=maxlongint div 10;
    end;
  for i:=n downto 1 do
    begin
      for j:=1 to i do
        begin
          min:=a[i+1,j];
          if a[i+1,j+1]<min then min:=a[i+1,j+1];
          if j=1 then
            if a[i+1,i+1]<min then min:=a[i+1,i+1];
          if j=i then
            if a[i+1,1]<min then min:=a[i+1,1];
          a[i,j]:=b[i,j]+min;
        end;
        for j:=1 to i do
        begin
          l:=j-1;
          if l=0 then l:=i;
          if a[i,l]+b[i,j]<a[i,j] then a[i,j]:=a[i,l]+b[i,j];
        end;
        for j:=i downto 1 do
        begin
          l:=j+1;
          if l=i+1 then l:=1;
          if a[i,l]+b[i,j]<a[i,j] then a[i,j]:=a[i,l]+b[i,j];
        end;
    end;
  writeln(a[1,1]);
end;
begin
  readd;
  work;
end.
