program p1143;
var n,i,j,k,q,x:integer;
    a:array[1..20,1..20] of integer;
    f:array[0..20,0..20,0..20,0..40] of integer;
function max(x1,x2:integer):integer;
begin
  if x1>x2 then exit(x1)
           else exit(x2);
end;
function max1(x1,x2,x3,x4,x5,x6,x7,x8:integer):integer;
begin
  max1:=max(max(max(x1,x2),max(x3,x4)),max(max(x5,x6),max(x7,x8)));
end;
begin
  readln(n);
  for i:= 1 to n do
    for j:= 1 to n do
      read(a[i,j]);
  fillchar(f,sizeof(f),0);
  for q:= 1 to 2*n do
    for i:= 1 to n do
      for j:= 1 to n do
        for k:= 1 to n do
        begin
          if ((q-i>0) and (q-j>0) and (q-k>0)) then
          begin
            f[i,j,k,q]:=max1(f[i-1,j-1,k-1,q-1],f[i-1,j-1,k,q-1],f[i-1,j,k-1,q-1],f[i,j-1,k-1,q-1],f[i-1,j,k,q-1],f[i,j-1,k,q-1],f[i,j,k-1,q-1],f[i,j,k,q-1]);
            for x:= 1 to n do
              if x in [i,j,k] then f[i,j,k,q]:=f[i,j,k,q]+a[x,q-x];
          end;
        end;
  writeln(f[n,n,n,2*n]);
end.
