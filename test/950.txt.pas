var
   a,f,pre:array[1..100,1..500]of longint;
   i,j,n,m,r:longint;
procedure print(i,j:longint);
   var 
      s:array[1..50000]of longint;
      top:longint;
   begin
      top:=0;
      while i<>1 do begin
         inc(top);s[top]:=j;
         if pre[i,j]=j-1 then dec(j)
         else if pre[i,j]=j+1 then inc(j)
         else dec(i);
      end;
      inc(top);s[top]:=j;
      for j:=top downto 1 do writeln(s[j]);
   end;
begin
   readln(m,n);
   for i:=1 to m do
      for j:=1 to n do
         read(a[i,j]);
   fillchar(f,sizeof(f),0);
   fillchar(pre,sizeof(pre),0);
   for i:=1 to n do f[1,i]:=a[1,i];
   for i:=2 to m do
   begin
      for j:=1 to n do begin
         f[i,j]:=f[i-1,j]+a[i,j];
         pre[i,j]:=j;
      end;
      for j:=2 to n do
         if f[i,j]>f[i,j-1]+a[i,j] then
         begin
            f[i,j]:=f[i,j-1]+a[i,j];
            pre[i,j]:=j-1;
         end;
      for j:=n-1 downto 1 do
         if f[i,j]>f[i,j+1]+a[i,j] then
         begin
            f[i,j]:=f[i,j+1]+a[i,j];
            pre[i,j]:=j+1;
         end;
   end;
   r:=1;
   for j:=2 to n do
      if f[m,j]<f[m,r] then r:=j;
   print(m,r)
end.
