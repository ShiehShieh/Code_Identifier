var
   a:array[1..5000]of longint;
   f:array[boolean,1..5000]of longint;
   i,j,n,m:longint;p,q:boolean;
begin
   read(m,n);
   for i:=1 to n do read(a[n+1-i]);
   for i:=1 to n do begin
      f[true ,i]:=100000000;
      f[false,i]:=0;
   end;
   for i:=1 to m do
   begin
      p:=odd(i);q:=not p;f[p,i*3-1]:=100000000;
      for j:=3*i to n do
      begin
         f[p,j]:=f[p,j-1];
         if f[p,j]>f[q,j-2]+sqr(a[j-1]-a[j])
            then f[p,j]:=f[q,j-2]+sqr(a[j-1]-a[j]);
      end;
   end;
   writeln(f[odd(m),n]);
end.
