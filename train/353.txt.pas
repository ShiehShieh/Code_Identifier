var
  n,m:longint;
  a:array[0..5000] of longint;
  f:array[0..1000,0..5000] of longint;

procedure init;
var
  i:longint;
begin
  readln(m,n);
  for i:=n downto 1 do read(a[i]);
end;

function min(a,b,c,d:longint):longint;
begin
  if (a<b) and (c>=d) then exit(a)
                      else exit(b);
end;

procedure dp;
var
  i,j,t:longint;
begin
  for i:=1 to m do
   begin
     t:=i*3;
     for j:=t to n do f[i,j]:=min(f[i,j-1],f[i-1,j-2]+sqr(a[j]-a[j-1]),j,t+1);
   end;
end;

begin
  init;
  dp;
  write(f[m,n]);
end.
