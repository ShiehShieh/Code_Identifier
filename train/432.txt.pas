var i,j,n,m,t:longint;
    zong:array[1..500,1..3]of longint;
    a:array[1..500,1..3]of longint;

procedure main;
begin
  for i:=1 to n do
  begin
    zong[i,1]:=a[i,1]+a[i,2]+a[i,3];
    zong[i,2]:=i;
    zong[i,3]:=a[i,1];
  end;
  for i:=n downto 2 do
    for j:=1 to i-1 do
    begin
      if (zong[j,1]>zong[j+1,1])or((zong[j,1]=zong[j+1,1])
      and(zong[j,3]>zong[j+1,3]))or((zong[j,1]=zong[j+1,1])
      and(zong[j,3]=zong[j+1,3])and(zong[j,2]<zong[j+1,2])) then
      begin
        t:=zong[j,1]; zong[j,1]:=zong[j+1,1]; zong[j+1,1]:=t;
        t:=zong[j,2]; zong[j,2]:=zong[j+1,2]; zong[j+1,2]:=t;
        t:=zong[j,3]; zong[j,3]:=zong[j+1,3]; zong[j+1,3]:=t;
      end;
    end;
{  for i:=n downto 2 do
  begin
    if zong[i,1]=zong[i-1,1] then
    begin
      if (zong[i,3]) < (zong[i-1,3]) then begin
        t:=zong[i,1]; zong[i,1]:=zong[i-1,1]; zong[i-1,1]:=t;
        t:=zong[i,2]; zong[i,2]:=zong[i-1,2]; zong[i-1,2]:=t;

        t:=zong[i,3]; zong[i,3]:=zong[i-1,3]; zong[i-1,3]:=t;
      end;
      if (zong[i,3]) = (zong[i-1,3]) then
        if zong[i,2]>zong[i-1,2] then begin
          t:=zong[i,1]; zong[i,1]:=zong[i-1,1]; zong[i-1,1]:=t;
          t:=zong[i,2]; zong[i,2]:=zong[i-1,2]; zong[i-1,2]:=t;

        end;
    end;
  end;}
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to 3 do
    begin
      read(m);
      a[i,j]:=m;
    end;
  main;
  for i:=n downto (n-4) do writeln(zong[i,2],' ',zong[i,1]);
end.


