var
   f:array[1..6,-6..200]of longint;
   i,j,n,m:longint;
begin
   read(n,m);
   fillchar(f,sizeof(f),0);
   for j:=1 to n do f[1,j]:=1;
   for i:=2 to m do 
      for j:=1 to n do
         f[i,j]:=f[i-1,j-1]+f[i,j-i];
   writeln(f[m,n])
end.
