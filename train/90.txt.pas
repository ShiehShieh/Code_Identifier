var n,m,i,j,ma:longint;
    fi,ti:array[1..30]of longint;
    f:array[0..30,0..20000]of longint;

function max(x,y:integer):integer;
begin
  if x>y then max:=x else max:=y;
end;

begin
  readln(m);
  readln(n);
  for i:=1 to n do readln(ti[i]);
  fi:=ti;
  fillchar(f,sizeof(f),0);
  ma:=0;
  for i:=1 to n do
    for j:=1 to m do
    begin
      if j>=ti[i]  
        then f[i,j]:=max(f[i-1,j-ti[i]]+fi[i],f[i-1,j])
        else f[i,j]:=f[i-1,j];
      if f[i,j]>ma then ma:=f[i,j];
    end;
   writeln(m-ma);
end.
