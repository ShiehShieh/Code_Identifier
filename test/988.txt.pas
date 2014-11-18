Var
maxx,i,j,n,v:longint;
a,b:array [1..1000] of longint;
f:array [0..1000,0..1000] of longint;

function max(i,j:longint):integer;
begin
  if i<j then exit(j)
  else exit(i);
end;


Begin

  readln(v,n);
  for i:=1 to n do read(b[i],a[i]);
  fillchar(f,sizeof(f),0);
  for i:= 1 to n do
    for j:= 1 to v do
      if j>=b[i] then
       f[i,j]:=max(f[i-1,j],f[i-1,j-b[i]]+a[i])
         else f[i,j]:=f[i-1,j];
  maxx:=0;
  writeln(f[n,v]);
End.
