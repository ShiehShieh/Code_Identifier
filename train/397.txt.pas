var
a:array[1..26]of string;
e:string;
s:string;
b:array[1..26]of integer;
c,d,i,j,max,min:integer;
f:boolean;
begin
d:=1;;
max:=1;
read(s);
i:=length(s);
min:=i;
for c:=1to i do
 begin
 e:=copy(s,c,1);
 f:=false;
 for j:=1to i do
  if a[j]=e then
   begin
   inc(b[j]);
   f:=true;
   break;
   end;
  if f=false then
   begin
   a[d]:=e;
   inc(b[d]);
   inc(d);
   end;
 end;
for j:=1to d-1 do
 begin
 if b[j]<min then min:=b[j];
 if b[j]>=max then max:=b[j];
 end;
c:=max-min;
f:=false;
if (c=0) or (c=1)then
 begin
 writeln('No Answer');
 writeln('0');
 halt;
 end;
for d:=2 to trunc(sqrt(c)) do
 begin
 if c mod d=0then
  begin
  writeln('No Answer');
  writeln('0');
  f:=true;
  halt;
  end;
 end;
if f=false then
 begin
 writeln('Lucky Word');
 writeln(c);
 end;
end.


