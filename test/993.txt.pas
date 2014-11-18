program p1495;
var
  j,m,x:longint;
  i:char;
  s:string;
  a:array['a'..'z']of longint;
begin
  readln(s);
  for i:='a' to 'z' do
  for j:=1 to length(s) do
  if s[j]=i then inc(a[i]);
  m:=0;
  x:=100;
  for i:='a' to 'z' do
  begin
    if a[i]>m then m:=a[i];
    if (a[i]<x)and(a[i]<>0) then x:=a[i];
  end;
  m:=m-x;
  x:=1;
  if (m=0)or(m=1) then begin
                         writeln('No Answer');
                         writeln('0');
                         exit;
                       end;
  for j:=1 to trunc(sqrt(m)) do
       if m mod j =0 then inc(x);
  if x=2 then begin
                writeln('Lucky Word');
                writeln(m);
              end
         else begin
                writeln('No Answer');
                writeln('0');
              end;
end.
