var
  n,i,j:integer;
  a:array[1..100]of 130..230;
  b,c:array[1..100]of 0..100;
begin
  read(n);
  for i:=1 to n do
      read(a[i]);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
    for j:=1 to i-1 do
      begin
        if (a[j]<a[i]) and (b[j]>=b[i]) then b[i]:=b[j]+1;
        if (a[n-j+1]<a[n-i+1]) and (c[n-j+1]>=c[n-i+1]) then c[n-i+1]:=c[n-j+1]+1;
      end;
  j:=0;
  for i:=1 to n do
    if b[i]+c[i]>j then j:=b[i]+c[i];
  writeln(n-j-1);
end.
