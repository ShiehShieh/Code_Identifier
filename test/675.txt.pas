var
   f:array[0..1000]of longint;
   v,w:array[1..100]of longint;
   i,j,n,m:longint;
begin
   read(n,m);
   for i:=1 to m do read(w[i],v[i]);
   fillchar(f,sizeof(f),0);
   for i:=1 to m do
      for j:=n downto 1 do
         if (j>=w[i]) and (f[j-w[i]]+v[i]>f[j]) then
            f[j]:=f[j-w[i]]+v[i];
   writeln(f[n])
end.
