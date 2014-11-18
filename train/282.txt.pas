program gu;
type
  ao=array[1..2000]of longint;
var
  a,b:ao;
  n,m,i,j,max,o,p:longint;
begin
  readln(n,m);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to m do
  begin
    readln(b[i]);
    if b[i]=0 then b[i]:=maxlongint;
  end;
  p:=m;
  for i:=1 to n do
  begin
    o:=0;
    max:=0;
    for j:=1 to m do
      if (a[i]>b[j])and(b[j]>max) then
      begin
        max:=b[j];
        o:=j;
      end;
    if o<>0 then begin b[o]:=0;dec(p); end;
  end;
  writeln(p);
end.
