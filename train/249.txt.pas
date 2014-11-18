type
  arr=array[1..100,1..100] of longint;
var
  k,p,q:int64;
  n,m,i,j:longint;
  a,b:array[1..100]of longint;
  x,y,v:arr;
procedure cheng(var a,b:arr);
var i,j,k:longint;    c:arr;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
   for j:=1 to n do
    for k:=1 to n do
     c[i,j]:=c[i,j]+a[i,k]*b[k,j];
  a:=c;
end;
begin
  readln(n,m,k);
  for i:=1 to n do a[i]:=i;
  for i:=1 to m do
   begin
    for j:=1 to n do
      begin
        read(v[i,j]);
        b[j]:=a[v[i,j]];
      end;
    a:=b;
   end;
  for i:=1 to n do
    x[i,a[i]]:=1;

  p:=k div m; q:=k mod m;
  if p and 1=1 then begin y:=x;dec(p);end else for i:=1 to n do y[i,i]:=1;

  while p<>0 do
   begin
     if p and 1=1 then cheng(y,x);
      //if p<>1 then
     cheng(x,x);
     p:=p shr 1;

   end;
//  for i:=1 to n do begin
//   for j:=1 to n do   write(y[i,j],' ' );writeln;end;
//  fillchar(a,sizeof(a),0);
  for i:=1 to n do
     for j:=1 to n do
      if y[i,j]<>0 then a[i]:=j;
// for i:=1 to n do write(a[i],' ');
 // fillchar(b,sizeof(b),0);
  for i:=1 to q do
   begin
    for j:=1 to n do
      begin
        b[j]:=a[v[i,j]];
      end;
    a:=b;
   end;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);



end.
