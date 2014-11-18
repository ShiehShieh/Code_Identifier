program adfs;
 var i,j,k,m,n,s,q,r:longint;
     a:array[1..10000]of longint;
 procedure swap(x,y:longint);
  var dd:longint;
 begin
  dd:=a[x];a[x]:=a[y];a[y]:=dd;
 end;
 procedure pai(l,r:longint);
  var aa,bb,cc,dd:longint;
 begin
  aa:=l;bb:=r;cc:=a[(l+r)div 2];
  repeat
   while a[aa]<cc do inc(aa);
   while a[bb]>cc do dec(bb);
   if aa<=bb then begin
    dd:=a[aa];a[aa]:=a[bb];a[bb]:=dd;
    inc(aa);dec(bb);
    end;
   until aa>bb;
  if l<bb then pai(l,bb);
  if aa<r then pai(aa,r);
 end;
begin
 readln(n);
 readln(m);
 for i:=1 to n do
  read(a[i]);
 for k:=1 to m do begin
   q:=n;
   while a[q]<a[q-1] do
    dec(q);r:=9999999;
   for i:=n downto q do
    if (a[i]>a[q-1])and(a[i]-a[q-1]<r) then begin
     r:=a[i]-a[q-1];
     j:=i;
     end;
    swap(j,q-1);
    pai(q,n);
 end;
 for i:=1 to n-1 do
  write(a[i],' ');
  writeln(a[n]);
  readln;
end.

