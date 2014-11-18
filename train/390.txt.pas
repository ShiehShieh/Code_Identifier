var a:array[1..10000] of longint;
    i,j,n,t,m,s:longint;
procedure sort(l,r:integer);
var x,y:longint;
begin
    i:=l; j:=r; x:=a[(i+j) div 2];
    repeat
     while x<a[i] do i:=i+1;
     while x>a[j] do j:=j-1;
     if i<=j then begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      i:=i+1; j:=j-1;
     end;
    until i>j;
   if j>l then sort(l,j);
   if i<r then sort(i,r);
end;
begin
    readln(n);
    for i:=1 to n do
     read(a[i]);
    sort(1,n);
    m:=n;
    while m>1 do
     begin
      t:=a[m]+a[m-1];
      s:=s+t;
      m:=m-1;
      i:=m;
       repeat
        if a[i]<t then a[i+1]:=a[i];
        i:=i-1;
        if i=0 then break;
       until a[i]>=t;
      a[i+1]:=t;
     end;
    write(s);
end.

