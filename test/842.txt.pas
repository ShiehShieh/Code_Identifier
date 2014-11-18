program adfasd;
 var i,j,k,m,n,s:longint;
procedure p(a,b,c:longint);
 begin
 if c=n then inc(s) else begin
  if a>0 then p(a-1,b+1,c);
  if b>0 then p(a,b-1,c+1);
  end;
 end;
begin
 readln(n);
 s:=0;
 p(n,0,0);
 writeln(s);
 readln;
end.
