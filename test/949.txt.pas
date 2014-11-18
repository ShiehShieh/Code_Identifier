program ex;
var
  i,j,k,n,m:integer;
  a,b:array[1..30] of longint;
begin
  readln(n,m);
  a[1]:=1;
  for i:=1 to m do
    begin
      for j:=1 to n do if a[j]>0 then
        begin
          k:=j-1;
          if k=0 then k:=n;
          b[k]:=a[j]+b[k];
          k:=j+1;
          if k>n then k:=1;
          b[k]:=a[j]+b[k];
        end;
      fillchar(a,sizeof(a),0);
      a:=b;
      fillchar(b,sizeof(b),0);
    end;
  writeln(a[1]);
end.
