program p1098;
var n,i,j,max:integer;
    t,a,b:array[0..101] of integer;
begin
 readln(n);
 for i:=1 to n do read(t[i]);
 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 t[0]:=-maxint;
 for i:=1 to n do
  for j:=i-1 downto 0 do
   if (t[j]<t[i]) and (a[j]+1>a[i]) then a[i]:=a[j]+1;
 t[n+1]:=-maxint;
 for i:=n downto 1 do
  for j:=i+1 to n+1 do
   if (t[i]>t[j]) and (b[j]+1>b[i]) then b[i]:=b[j]+1;
 max:=0;
 for i:=1 to n do
  if a[i]+b[i]>max then max:=a[i]+b[i];
 writeln(n-max+1);
end.
