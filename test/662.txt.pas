var n,ans:longint;
procedure search(x,z:longint);
begin
  if x>n then begin
                inc(ans);
                exit;
              end;
  search(x+1,z+1);
  if z<>0 then search(x,z-1);
end;
begin
  ans:=0;
  readln(n);
  search(1,0);
  writeln(ans);
end.
