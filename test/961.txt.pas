var
   f:array[0..400,0..400]of longint;
   i,j,k,n,m,t,u,v,w:longint;
begin
   fillchar(f,sizeof(f),0);
   read(n,m,t);
   for k:=1 to t do begin
      read(u,v,w);
      for i:=n downto u do
         for j:=m downto v do
            if f[i-u,j-v]+w>f[i,j] then
               f[i,j]:=f[i-u,j-v]+w;
   end;
   writeln(f[n,m])
end. 
