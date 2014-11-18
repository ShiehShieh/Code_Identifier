
 var
p:array[5..200] of longint;
i,j,k,n,w,ans:longint;
begin

 read(w,n);
 for i:=1 to n do
begin
  read(j); inc(p[j]);
end;
 i:=5; j:=w;
 repeat
while p[i]=0 do inc(i);
while p[j]=0 do dec(j);
if i+j<=w then
  begin
inc(ans); dec(n,2);
dec(p[i]); dec(p[j]);
  end
else
  begin
inc(ans); dec(n);
dec(p[j]);
  end;
 until n<=1;
 if n=1 then inc(ans);
 writeln(ans);

end.

