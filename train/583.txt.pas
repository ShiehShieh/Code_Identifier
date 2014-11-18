var
   f:array[0..50,0..50]of qword;
   s:array[1..50,1..50]of word;
   a:array[1..50]of word;
   i,j,k,l,t,n:longint;
procedure print(l,r:longint);
   begin
      if l=r then s[l,r]:=l;
      inc(t);
      write(s[l,r]);
      if t=n then writeln else write(' ');
      if l=r then exit;
      if s[l,r]>l then print(l,s[l,r]-1);
      if s[l,r]<r then print(s[l,r]+1,r);
   end;
begin
   read(n);
   fillchar(f,sizeof(f),0);
   for i:=1 to n do begin
      read(a[i]);
      f[i,i-1]:=1;
      f[i,i]:=a[i];
   end;
   f[n+1,n]:=1;
   for l:=1 to n-1 do
      for i:=1 to n-l do
      begin
         j:=i+l;
         for k:=i to j do
            if f[i,k-1]*f[k+1,j]+a[k]>f[i,j] then
            begin
               f[i,j]:=f[i,k-1]*f[k+1,j]+a[k];
               s[i,j]:=k;
            end;
      end;
   writeln(f[1,n]);
   t:=0;print(1,n)
end.var
   f:array[0..50,0..50]of qword;
   s:array[1..50,1..50]of word;
   a:array[1..50]of word;
   i,j,k,l,t,n:longint;
procedure print(l,r:longint);
   begin
      if l=r then s[l,r]:=l;
      inc(t);
      write(s[l,r]);
      if t=n then writeln else write(' ');
      if l=r then exit;
      if s[l,r]>l then print(l,s[l,r]-1);
      if s[l,r]<r then print(s[l,r]+1,r);
   end;
begin
   read(n);
   fillchar(f,sizeof(f),0);
   for i:=1 to n do begin
      read(a[i]);
      f[i,i-1]:=1;
      f[i,i]:=a[i];
   end;
   f[n+1,n]:=1;
   for l:=1 to n-1 do
      for i:=1 to n-l do
      begin
         j:=i+l;
         for k:=i to j do
            if f[i,k-1]*f[k+1,j]+a[k]>f[i,j] then
            begin
               f[i,j]:=f[i,k-1]*f[k+1,j]+a[k];
               s[i,j]:=k;
            end;
      end;
   writeln(f[1,n]);
   t:=0;print(1,n)
end.
