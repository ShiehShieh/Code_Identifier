type
nt=array[0..500] of integer;
var
s1:string;
a,b,c:nt;
l,n,i,step:integer;
x:boolean;
procedure du;
var i:integer;
begin
  read(s1);
  l:=length(s1);
  for i:=1 to l do a[i]:=ord(s1[i])-ord('0');
  for i:=1 to l do
    if a[i]>9 then a[i]:=a[i]-7;
end;
procedure plus;
var i,k:integer;
begin
  for i:=1 to l do
  begin
  a[i]:=a[i]+b[i];
  a[i+1]:=a[i+1]+a[i] div n;
  a[i]:=a[i] mod n;
  end;
  if a[l+1]<>0 then l:=l+1;
  for i:=1 to l do
  c[i]:=a[l-i+1];
  for i:=1 to l do
  a[i]:=c[i];
end;
procedure change;
begin
  for i:=1 to l do
    b[i]:=a[l-i+1];
end;
procedure yan;
begin
x:=true;
for i:=1 to l div 2 do
if a[l-i+1]<>a[i] then x:=false;
end;
begin
  readln(n);
  du; change; plus; step:=1; yan;
  while (not x) and (step<30) do
  begin
  change; plus; inc(step);
  yan;
  end;
  if step<30 then write('STEP=',step)
              else write('Impossible!');
end.
