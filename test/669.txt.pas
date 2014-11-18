var m,n,r,t:real;
begin
  readln(m,n,r);
  if m-n>=0 then begin
  t:=sqrt(sqr(m-n)+sqr(r));
  writeln(t:0:3); end
  else writeln(r:0:3);
end. 
