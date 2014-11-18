var
   i,m,n,p,k,jj,gg,ne,xx,j,hh:longint;
   a,b,c,w,x:array[1..5000] of integer;
procedure xiangjia;
    begin
      p:=p+1;
      for jj:=1 to n do
       begin
         c[p]:=c[p]+a[w[jj]];
       end;
    end;

begin
  {1}
  readln(m,n);
  for i:=1 to m do read(a[i]);
  {2}
  for i:=1 to m do
      begin
        k:=k+a[i];
      end;
  {3}
  for j:=2 to k do x[j]:=1;
  ne:=1;
  gg:=trunc(sqrt(k));
  repeat
    ne:=ne+1;
    if x[ne]=1 then
       begin
         i:=ne;
         while i<k do
           begin
             i:=i+ne;
             x[i]:=0;
           end;
       end;
  until ne>gg;
  xx:=0;
  for j:=1 to k do
      begin
        xx:=xx+1;
        if x[j]=1 then
          begin
            b[xx]:=j   ;

          end;
      end;
  {4}
  p:=0;{P shi yong lai ji di ji ge zhuhe de }
  for j:=1 to n do  w[j]:=j;
  xiangjia;
  repeat
    hh:=n;
    while ((hh>0) and (w[hh]=m+hh-n)) do dec(hh);
     if hh>0 then
       begin
         inc(w[hh]);
         for j:=hh+1 to n do w[j]:=w[j-1]+1;
         xiangjia;
       end;

  until hh=0;
  {5}
  n:=0;
  for i:=1 to p do
   begin
     for j:=1 to xx do
       begin
         if c[i]=b[j] then  n:=n+1;
       end;
   end;
  writeln(n);
end.
