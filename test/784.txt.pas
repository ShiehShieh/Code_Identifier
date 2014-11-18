program qu;
var data:array[1..50,1..50]of integer;
sum:array[0..50,0..50,0..50,0..50]of longint;
m,n,i,j,i1,j1,i2,j2:integer;
p:longint;
function max(a,b:longint):longint;
 begin
if a>b then max:=a else max:=b;
end;

begin
  fillchar(data,sizeof(data),0);
  fillchar(sum,sizeof(sum),0);
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        read(data[i,j]);
      readln;
    end;

for i1:=1 to m do
  for j1:=1 to n do
    for i2:=1 to m do
      for j2:=1 to n do
        if ((j2<>j1)and(i1<>i2))or((i1=m)and(i2=m)and(j1=n)and(j2=n)) then
        begin
          p:=max(sum[i1-1,j1,i2-1,j2],sum[i1-1,j1,i2,j2-1] );
          p:=max(p,sum[i1,j1-1,i2-1,j2]);
          p:=max(p,sum[i1,j1-1,i2,j2-1]);
          sum[i1,j1,i2,j2]:=p+data[i1,j1]+data[i2,j2];
        end;

writeln(sum[m,n,m,n]);

end.

