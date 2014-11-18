program jkasdf;
 var i,j,n,m,c,r,k,p,q,maxx:longint;
     s:array[0..1000,0..1000] of longint;
     a:array[0..1000,0..1000] of longint;
 function max(a,b,c,d:longint):longint;
  var x,y:longint;
   begin
    if a>b then x:=a else x:=b;
    if c>d then y:=c else y:=d;
     if x>y then max:=x else max:=y;
   end;
 function search(i,j:longint):longint;
  var k1,k2,k3,k4:longint;
   begin
    if s[i,j]= 0 then
     begin
      k1:=0;  k2:=0;  k3:=0;  k4:=0;
      if (a[i,j]>a[i-1,j])and(i>1) then k1:=search(i-1,j);
       if (a[i,j]>a[i+1,j])and(i<r) then k2:=search(i+1,j);
      if (a[i,j]>a[i,j-1])and(j>1) then k3:=search(i,j-1);
      if (a[i,j]>a[i,j+1])and(j<c) then k4:=search(i,j+1);
      s[i,j]:=max(k1,k2,k3,k4)+1;
     end;
     search:=s[i,j];
   end;
  begin
   read(r,c);
    fillchar(s,sizeof(s),0);
   for i:= 1 to r do
    for j:= 1 to c do
     read(a[i,j]);
     maxx:=0;
   for i:= 1 to r do
    for j:= 1 to c do
     begin
      k:=search(i,j);
      if k>maxx then maxx:=k;
     end;
   writeln(maxx);
  end.
