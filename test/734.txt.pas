var
  n,m,i,j:integer;
  a,b,f:array[0..1000] of integer;

function max(a,b:integer):integer;
begin
  if a>=b then exit(a)
   else exit(b);
end;

begin
  readln(n);
  readln(m);
  for i:=1 to n do 
    readln(a[i],b[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=m downto b[i] do
      f[j]:=max(f[j],f[j-b[i]]+a[i]);
  writeln(f[m]);
end.
