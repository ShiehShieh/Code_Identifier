var
 f:array[0..40,0..40,0..40,0..40] of int64;
 a:array[0..40,0..40] of longint;
 b:array[0..40] of longint;
 i,j,k,l,n:longint;
 m:int64;
function max1(x1,x2,x3,x4,x5,x6,x7,x8:int64):int64;
 var
  max:int64;
 begin
  max:=x1;
  if x2>max then max:=x2;
  if x3>max then max:=x3;
  if x4>max then max:=x4;
  if x5>max then max:=x5;
  if x6>max then max:=x6;
  if x7>max then max:=x7;
  if x8>max then max:=x8;
  max1:=max;
 end;
 begin
  readln(n);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
   begin
    for j:=1 to n do
     begin
      read(k);
      m:=i+j-1;
      b[m]:=b[m]+1;
      a[m,b[m]]:=k;
     end;
     readln;
   end;
  fillchar(f,sizeof(f),0);
  f[1,1,1,1]:=a[1,1];
  for i:=2 to n do
   for j:=1 to i do
    for k:=1 to i do
     for l:=1 to i do
      begin
       m:=max1(f[i-1,j-1,k-1,l-1],
              f[i-1,j-1,k-1,l],
              f[i-1,j-1,k,l-1],
              f[i-1,j-1,k,l],
              f[i-1,j,k-1,l-1],
              f[i-1,j,k-1,l],
              f[i-1,j,k,l-1],
              f[i-1,j,k,l]);
             if (j=k) and (k=l) then
              f[i,j,k,l]:=m+a[i,j]
             else
              if (j=k) or (k=l) or (j=l) then
               begin
                if j=k then f[i,j,k,l]:=m+a[i,j]+a[i,l];
                if j=l then f[i,j,k,l]:=m+a[i,j]+a[i,k];
                if k=l then f[i,j,k,l]:=m+a[i,j]+a[i,k];
                end
               else
                f[i,j,k,l]:=m+a[i,j]+a[i,k]+a[i,l];
        end;
   for i:=n+1 to 2*n-1 do
    for j:=1 to 2*n-i do
     for k:=1 to 2*n-i do
      for l:=1 to 2*n-i do
       begin
        m:=max1(f[i-1,j+1,k+1,l+1],
                f[i-1,j+1,k+1,l],
                f[i-1,j+1,k,l+1],
                f[i-1,j+1,k,l],
                f[i-1,j,k+1,l+1],
                f[i-1,j,k+1,l],
                f[i-1,j,k,l+1],
                f[i-1,j,k,l]);
       if (j=k) and (k=l) then
              f[i,j,k,l]:=m+a[i,j]
             else
              if (j=k) or (k=l) or (j=l) then
               begin
                if j=k then f[i,j,k,l]:=m+a[i,j]+a[i,l];
                if j=l then f[i,j,k,l]:=m+a[i,j]+a[i,k];
                if k=l then f[i,j,k,l]:=m+a[i,j]+a[i,k];
                end
               else
                f[i,j,k,l]:=m+a[i,j]+a[i,k]+a[i,l];
    end;
   writeln(f[2*n-1,1,1,1]);
  end.



