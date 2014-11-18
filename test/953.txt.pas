var
   f:array[2..40,0..20,0..20,0..20]of longint;
   a:array[1..20,1..20]of longint;
   i,j,k,t,l,n:longint;
function max(a,b:longint):longint;
   begin
      if a>b then exit(a) else exit(b);
   end;
function w(k,x,y,z:longint):longint;
   begin
      w:=a[x,k-x]+a[y,k-y]+a[z,k-z]
         -ord(x=y)*a[x,k-x]-ord(x=z)*a[x,k-x]-ord(y=z)*a[y,k-z]
         +ord((x=y) and (y=z))*a[x,k-x];
   end;
begin
   read(n);
   for i:=1 to n do
      for j:=1 to n do read(a[i,j]);
   fillchar(f,sizeof(f),0);
   f[2,1,1,1]:=a[1,1];
   for l:=3 to n<<1 do
   begin
      if l>n then t:=n else t:=l-1;
      for i:=1 to t do
         for j:=1 to t do
            for k:=1 to t do
            begin
               f[l,i,j,k]:=max(max(max(f[l-1,i-1,j,k],f[l-1,i,j,k]),
                                   max(f[l-1,i-1,j-1,k],f[l-1,i,j-1,k])),
                               max(max(f[l-1,i-1,j-1,k-1],f[l-1,i,j-1,k-1]),
                                   max(f[l-1,i-1,j,k-1],f[l-1,i,j,k-1])));
               inc(f[l,i,j,k],w(l,i,j,k));
            end;
   end;
   writeln(f[2*n,n,n,n])
end.
