var
   f:array[0..101,0..5000]of boolean;
   a:array[1..200]of longint;
   i,j,k,sum,n,ans:longint;
begin
   fillchar(f,sizeof(f),0);
   read(n);sum:=0;
   for i:=1 to n do begin
      read(a[i]);
      inc(sum,a[i]);
   end;
   for k:=1 to n do begin
      for i:=ord(k>n>>1)*n>>1+ord(k<n>>1)*k downto 1 do
         for j:=sum>>1-a[k] downto 1 do
            if f[i,j] then f[i+1,j+a[k]]:=true;
      f[1,a[k]]:=true;
   end;
   ans:=sum>>1;
   while (ans>0) and (not f[n>>1,ans]) do dec(ans);
   writeln(ans,' ',sum-ans)
end.
