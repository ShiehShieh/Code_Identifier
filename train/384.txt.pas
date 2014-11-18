var
 a,b:array[1..10000] of longint;
 a1,b1,b2,i,j,m,sum,n:longint;
procedure work(s,t:longint);
 var
  i,j,mid,q:longint;
 begin
  i:=s;
  j:=t;
  mid:=a[(i+j+1) div 2];
  while i<j do
   begin
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
     begin
      q:=a[i];
      a[i]:=a[j];
      a[j]:=q;
      inc(i);
      dec(j);
     end;
   end;
  if i<t then work(i,t);
  if j>s then work(s,j);
 end;
begin
 read(n);
 for i:=1 to n do
  read(a[i]);
 work(1,n);
 a1:=0;
 b1:=0;b2:=0;m:=0;
 for i:=2 to n do
  begin
   if b1<>b2 then
    if a1<>n then
     if b[b1+1]>a[a1+1] then
      begin
      m:=m+a[a1+1];
      inc(a1);
      end
      else begin
            m:=m+b[b1+1];
            inc(b1);
           end
    else begin
          m:=m+b[b1+1];
          inc(b1);
         end
   else begin
          m:=m+a[a1+1];
          inc(a1);
        end;
   if b1<>b2 then
    if a1<>n then
     if b[b1+1]>a[a1+1] then
      begin
      m:=m+a[a1+1];
      inc(a1);
      end
      else begin
            m:=m+b[b1+1];
            inc(b1);
           end
    else begin
          m:=m+b[b1+1];
          inc(b1);
         end
   else begin
          m:=m+a[a1+1];
          inc(a1);
        end;
   inc(b2);
   b[b2]:=m;
   inc(sum,m);
   m:=0;
  end;
 writeln(sum);
end.
