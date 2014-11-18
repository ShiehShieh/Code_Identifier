var
   f,d:array[1..1000,1..1000]of real;
   x,y:array[1..1000]of real;
   i,j,n:longint;
procedure sort(l,r:longint);
   var 
      mid,tmp:real;
      i,j:longint;
   begin
      i:=l;j:=r;
      mid:=x[(l+r)>>1];
      repeat
         while x[i]<mid do inc(i);
         while x[j]>mid do dec(j);
         if not(i>j) then begin
            tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
            tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
            inc(i);dec(j);
         end;
      until i>j;
      if i<r then sort(i,r);
      if l<j then sort(l,j);
   end; 
begin
   read(n);
   for i:=1 to n do read(x[i],y[i]);
   sort(1,n);
   for i:=1 to n do
      for j:=1 to i do
         if i<>j then 
         begin
            d[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
            d[j,i]:=d[i,j];
         end else d[i,i]:=0;
   f[2,1]:=d[1,2];
   for i:=3 to n do 
   begin
      for j:=1 to i-2 do 
         f[i,j]:=f[i-1,j]+d[i,i-1];
      f[i,i-1]:=1e24;
      for j:=1 to i-2 do
         if f[i-1,j]+d[i,j]<f[i,i-1] then
            f[i,i-1]:=f[i-1,j]+d[i,j];
   end;
   f[n,n]:=1e24;
   for j:=1 to n-1 do
      if f[n,j]+d[n,j]<f[n,n] then
         f[n,n]:=f[n,j]+d[n,j];
   writeln(f[n,n]:0:2)
end.
