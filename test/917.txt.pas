var
   f,d,pre:array[0..100000]of longint;
   a:array[1..100]of longint;
   i,j,n,m,sum:longint;
procedure print(i:longint);
   begin
      if i=0 then exit;
      print(pre[i]);
      write(d[i]);
      if i=n then writeln else write(' ');
   end;
begin
   read(n,m);
   fillchar(f,sizeof(f),0);
   f[0]:=1;sum:=0;
   for i:=1 to m do begin
      read(a[i]);
      inc(sum,a[i]);
   end;
   for i:=1 to m do begin
      for j:=sum downto 0 do
         if f[j]<>0 then begin
            if f[j+a[i]]=0 then
            begin
               d[j+a[i]]:=i;
               pre[j+a[i]]:=j;
            end;
            inc(f[j+a[i]],f[j]);
            if f[j+a[i]]>2 then f[j+a[i]]:=2;
         end;
   end;
   n:=sum-n;
   if f[n]=0 then writeln(0)
   else if f[n]=2 then writeln(-1)
   else print(n)
end.
