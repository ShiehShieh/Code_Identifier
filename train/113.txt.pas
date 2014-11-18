program xi;
var
  n,i,j:integer;
  date:array[1..1000,1..1000] of integer;
  min:array[1..1000,1..1000] of longint;

procedure int;
var
  i,j:integer;
begin
  read(n);
  for i:=1 to n do
  for j:=1 to i do
  begin
    read(date[i,j]);
    min[i,j]:=99999;
  end;
  min[n,1]:=date[n,1];
end;

procedure dp;
var
  i,j:integer;
begin
  for i:=2 to n do min[n,i]:=min[n,i-1]+date[n,i];
  if min[n,n]>min[n,1]+date[n,n] then min[n,n]:=min[n,1]+date[n,n];
  for i:=n-1 downto 2 do
  if min[n,i]>min[n,i+1]+date[n,i] then min[n,i]:=min[n,i+1]+date[n,i];

  for i:=n-1 downto 2 do
  begin
    min[i,1]:=min[i+1,1]+date[i,1];
    if min[i,1]>min[i+1,2]+date[i,1] then min[i,1]:=min[i+1,2]+date[i,1];
    if min[i,1]>min[i+1,i+1]+date[i,1] then min[i,1]:=min[i+1,i+1]+date[i,1];
    
    for j:=2 to i do
    begin
      min[i,j]:=min[i+1,j]+date[i,j];
      if min[i,j]>min[i+1,j+1]+date[i,j] then min[i,j]:=min[i+1,j+1]+date[i,j];
    end;
    if min[i,i]>min[i+1,1]+date[i,j] then min[i,i]:=min[i+1,1]+date[i,i];

    if min[i,1]>min[i,i]+date[i,1] then min[i,1]:=min[i,i]+date[i,1];
    for j:=2 to i do
      if min[i,j]>min[i,j-1]+date[i,j] then min[i,j]:=min[i,j-1]+date[i,j];
        if min[i,1]>min[i,i]+date[i,1] then min[i,1]:=min[i,i]+date[i,1];

     if min[i,i]>min[i,1]+date[i,i] then min[i,i]:=min[i,1]+date[i,i];
   for j:=i-1 downto 1 do
      if min[i,j]>min[i,j+1]+date[i,j] then min[i,j]:=min[i,j+1]+date[i,j];
       

  end;
end;

begin
  int;
  dp;
  if min[2,1]>min[2,2] then writeln(date[1,1]+min[2,2]) else writeln(date[1,1]+min[2,1]);

end.
