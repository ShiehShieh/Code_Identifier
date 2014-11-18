var n,m,i,k,j,w:longint;
    s:string;
    g:char;
begin
  readln(n);
  readln(m);
  for i:=1 to n do
    s:=s+chr(i);
  k:=1;
   w:=n;
  for i:=1 to m do
  begin
    k:=k+i*i*i mod 5+1;
    if k>=w then k:=i*i*i mod 5+1;
    g:=s[k+1];
    delete(s,k,1);
    w:=w-1;
  end;
  if ord(g)=2 then writeln(ord(g))
         else writeln(ord(g)-1);
end.
