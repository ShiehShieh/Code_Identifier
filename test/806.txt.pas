var
  f,sum:array [1..2000,1..2000] of longint;
  a,summ:array [0..2000] of longint;
  z,n,m,i,j:longint;

procedure init;
begin
  readln(n); readln(m);
  summ[0]:=0;
  for i:= 1 to n do begin
    read(a[i]);
    summ[i]:=summ[i-1]+a[i];
  end;
  for i:= 1 to n do
    for j:= i to n do
      sum[i,j]:=summ[j]-summ[i-1];
end;

function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;

procedure main;
begin
  fillchar(f,sizeof(f),0);
  for i:= 1 to n do
    f[i,i]:=a[i];
  for i:= 1 to n-1 do
    f[i,i+1]:=max(a[i],a[i+1]);
  for i:= 2 to n-1 do
    for j:= 1 to n-i do begin
      z:=i+j;
      f[j,z]:=max(sum[j+1,z]-f[j+1,z]+a[j],sum[j,z-1]-f[j,z-1]+a[z]);
    end;
  if m=1 then
    writeln(f[1,n])
  else
    writeln(sum[1,n]-f[1,n]);
end;

begin
  init;
  main;
end.
