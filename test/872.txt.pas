var
 x,y:array[1..100000]of double;
 i,j,k,p,n:longint;
procedure qsort(l,r: longint);
var
 i,j: longint;
 mid,t:double;
 begin
 i:=l; j:=r; mid:=x[(l+r) shr 1];
 repeat
   while x[i]<mid do inc(i);
   while mid<x[j] do dec(j);
   if not(i>j) then
 begin
t:=x[i]; x[i]:=x[j]; x[j]:=t;
t:=y[i]; y[i]:=y[j]; y[j]:=t;
inc(i); dec(j);
 end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
  end;
procedure qsorty(l,r: longint);
  var
 i,j: longint;
 mid,t:double;
  begin
 i:=l; j:=r; mid:=y[(l+r) shr 1];
 repeat
   while y[i]<mid do inc(i);
   while mid<y[j] do dec(j);
   if not(i>j) then
 begin
t:=y[i]; y[i]:=y[j]; y[j]:=t;
t:=x[i]; x[i]:=x[j]; x[j]:=t;
inc(i); dec(j);
 end;
 until i>j;
 if l<j then qsorty(l,j);
 if i<r then qsorty(i,r);
  end;
function dis(q,w:longint):double;
 begin
 exit( sqrt( sqr(x[q]-x[w])+sqr(y[q]-y[w]) ) );
 end;
function min(q,w:double):double;
 begin
 if q<w  then exit(q)else exit(w);
 end;
function merge(l,r:longint):double;
 var
s,mins:double;
i,i1,i2,j,j1,j2,mid:longint;
 begin
if l=r  then exit(1e15);
if l+1=r then exit( dis(l,r) );
mid:=(l+r)shr 1;
s:=min( merge(l,mid),merge(mid+1,r) );mins:=s;
i:=l;i1:=i;i2:=r;
while x[i1]<x[mid]-s do inc(i1);
while x[i2]>x[mid]+s do dec(i2);
qsorty(i1,i2);   {x[i1..i2] have been change}
for i:=i1 to i2 do
begin
  j1:=i;j2:=i;
  while (j1>i1)and(y[j1]>y[i]-s) do dec(j1);
  while (j2<i2)and(y[j2]<y[i]+s) do inc(j2);{change j1,j2<=6}
  for j:=j1 to j2 do
  if j<>i   then
  if  dis(i,j)<mins then
mins:=dis(i,j);
end;
exit( min(s,mins) );
 end;
begin
 readln(n);
 for i:=1 to n do
 read(x[i],y[i]);
 qsort(1,n);
 writeln( merge(1,n):0:3 );
end.

