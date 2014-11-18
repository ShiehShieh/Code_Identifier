type
  arr=array[1..100,1..100] of longint;
var
  a,c,xx:arr;
  cc,cc2:array[1..100] of integer;
  e:array[1..10,1..100] of integer;
  k,n,kk,max,m:int64;
  i,j,lb:integer;
  b,f:array[1..100] of integer;
  ba:boolean;
function cheng(a,c:arr):arr;
  var
    b:arr;
    i,j,k1:longint;
  begin
    fillchar(b,sizeof(b),0);
    for i:=1 to n do
     for j:=1 to n do
      for k1:=1 to n do
        b[i,j]:=b[i,j]+a[i,k1]*c[k1,j];
    exit(b);
  end;
begin
  readln(n,m,k);
  for i:=1 to n do cc[i]:=i;
  for i:=1 to m do
   begin
     cc2:=cc;
     for j:=1 to n do
      begin
        read(max);
        cc[j]:=cc2[max];
        e[i,j]:=max;
      end;
     readln;
   end;
  for i:=1 to n do a[i,cc[i]]:=1;
  kk:=k mod m;
  k:=k div m;
  repeat
    lb:=lb+1;
    b[lb]:=k mod 2;
    k:=k div 2;
  until k=0;
  c:=a;
  fillchar(a,sizeof(a),0); ba:=true;
  for i:=1 to lb do
   begin
     if b[i]=1 then
      begin
        if ba=true then begin ba:=false; a:=c; end
          else a:=cheng(a,c);
      end;
     c:=cheng(c,c);
   end;
  for i:=1 to n do
   for j:=1 to n do
    if a[i,j]<>0 then f[i]:=j;
  for i:=1 to kk do
   begin
     cc2:=f;
     for j:=1 to n do
      begin
        f[j]:=cc2[e[i,j]];
      end;
   end;
  for i:=1 to n-1 do write(f[i],' ');
  writeln(f[n]);
end.



