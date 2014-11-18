var
   f:array[boolean,0..2000]of longint;
   a:array[1..100]of longint;
   i,j,n:longint;p,q:boolean;
function max(a,b:longint):longint;
   begin
      if a>b then exit(a) else exit(b);
   end;
begin
   read(n);
   for i:=1 to n do read(a[i]);
   for i:=0 to 2000 do begin
      f[true,i]:=-maxlongint;
      f[false,i]:=-maxlongint;
   end;
   f[false,0]:=0;
   for i:=1 to n do
   begin
      p:=odd(i);q:=not p;
      for j:=0 to 2000 do
      begin
         f[p,j]:=f[q,j];
         if f[q,j+a[i]]>=0 then
            f[p,j]:=max(f[p,j],f[q,j+a[i]]+a[i]);
         if f[q,abs(j-a[i])]>=0 then
            if j>=a[i] then
               f[p,j]:=max(f[p,j],f[q,j-a[i]])
            else
               f[p,j]:=max(f[p,j],f[q,a[i]-j]+a[i]-j);
      end;
   end;
   if f[odd(n),0]=0 then writeln('Impossible') else writeln(f[odd(n),0]);
end.
