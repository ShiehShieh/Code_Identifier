var
  a,b,num1,num2:array[1..1000]of longint;
  m,n,k,u,d,i,x1,y1,x2,y2:longint;
procedure qsort1(l,r:longint);
var i,j,mid,t:longint;
 begin
  i:=l;j:=r;mid:=a[(i+j)div 2];
  repeat
  while a[i]>mid do inc(i);
  while a[j]<mid do dec(j);
  if i<=j
  then
  begin
   t:=a[i];
  a[i]:=a[j];
   a[j]:=t;
   t:=num1[i];
   num1[i]:=num1[j];
   num1[j]:=t;
   inc(i);
   dec(j);
   end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
end;

procedure qsort2(l,r:longint);
var i,j,mid,t:longint;
 begin
  i:=l;j:=r;mid:=b[(i+j)div 2];
  repeat
  while b[i]>mid do inc(i);
  while b[j]<mid do dec(j);
  if i<=j
  then
  begin
   t:=b[i];
   b[i]:=b[j];
   b[j]:=t;
   t:=num2[i];
   num2[i]:=num2[j];
   num2[j]:=t;
   inc(i);
   dec(j);
   end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
end;
   procedure qsort3(l,r:longint);
var i,j,mid,t:longint;
 begin
  i:=l;j:=r;mid:=num1[(i+j)div 2];
  repeat
  while num1[i]<mid do inc(i);
  while num1[j]>mid do dec(j);
  if i<=j
  then
  begin
   t:=num1[i];
   num1[i]:=num1[j];
   num1[j]:=t;
   inc(i);
   dec(j);
   end;
  until i>j;
  if l<j then qsort3(l,j);
  if i<r then qsort3(i,r);
end;
      procedure qsort4(l,r:longint);
var i,j,mid,t:longint;
 begin
  i:=l;j:=r;mid:=num2[(i+j)div 2];
  repeat
  while num2[i]<mid do inc(i);
  while num2[j]>mid do dec(j);
  if i<=j
  then
  begin
   t:=num2[i];
   num2[i]:=num2[j];
   num2[j]:=t;
   inc(i);
   dec(j);
   end;
  until i>j;
  if l<j then qsort4(l,j);
  if i<r then qsort4(i,r);
end;

function min(a,b:longint):longint;
 begin
 if a<b
 then exit(a)
 else exit(b);
 end;
 begin
   fillchar(a,sizeof(a),0);
   fillchar(b,sizeof(b),0);
   readln(m,n,k,u,d);
   for i:=1 to d do
   begin
    readln(x1,y1,x2,y2);
    if abs(x1-x2)=1
    then
     inc(a[min(x1,x2)])
     else inc(b[min(y1,y2)]);
  end;
  for i:=1 to m do
  num1[i]:=i;
  for i:=1 to n do
  num2[i]:=i;
  qsort1(1,m);
  qsort3(1,k);
  qsort2(1,n);
  qsort4(1,u);
 for i:=1 to k-1 do
 write(num1[i],' ');
 writeln(num1[k]);
 for i:=1 to u-1 do
 write(num2[i],' ');
 write(num2[u]);
 end.







