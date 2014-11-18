program pp;
const
  a:array[1..4] of integer=(-1,1,0,0);
  b:array[1..4] of integer=(0,0,-1,1);
var
 f:array[-1..500,-1..500] of longint;

 i,j,k,n,m,x,y,s:longint;
 c:array[1..21,1..21] of char;
begin

  readln(n,m);
  if n=1 then begin writeln(1); halt; end;
  for i:=1 to n  do
   begin
      for  j:=1 to m  do  read(c[i,j]);
      readln;
   end;

     for i:=1 to n*m do
        for j:=1 to n*m do
         begin
          f[i,j]:=maxint;
          f[j,i]:=f[i,j];
         end;
       for i:=1 to n do
         for j:=1 to m do
              for k:=1 to 4 do
               begin
                 x:=i+a[k];
                 y:=j+b[k];
                 if (x>0)and(x<=n)and(y>0)and(y<=m) then
                  begin
                     if c[x,y]=c[i,j] then f[(x-1)*m+y,(i-1)*m+j]:=0
                     else f[(x-1)*m+y,(i-1)*m+j]:=1;
                  f[(i-1)*m+j,(x-1)*m+y]:=f[(x-1)*m+y,(i-1)*m+j];
                  end;
               end;

      for k:=1 to n*m do
       for i:=1 to n*m do
       if i<>k   then
         for j:=1 to n*m do
         if (i<>j)and(j<>k)  then
          if f[i,j]>f[i,k]+f[k,j] then f[i,j]:=f[i,k]+f[k,j];
          s:=maxlongint;
       for i:=1 to m do
        for j:=1 to m  do
            if  f[i,n*m-j+1]<s then s:=f[i,n*m-j+1];
            if s=maxint  then s:=0;
     writeln(s+1);
end.
