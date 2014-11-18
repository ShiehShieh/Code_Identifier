var
  n,i,s,averge,ans:longint;
  a:array[1..100] of longint;
begin
  readln(n);
  ans:=0;
  s:=0;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      read(a[i]);
      s:=s+a[i];
    end;
  averge:=s div n;
  for i:=1 to n do
    begin
      if a[i]<averge then
        begin
          a[i+1]:=a[i+1]+a[i]-averge;
          inc(ans);
        end;
      if a[i]>averge then
        begin
          a[i+1]:=a[i+1]+a[i]-averge;
          inc(ans);
        end;
    end;
  writeln(ans);
end.
