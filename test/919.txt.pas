program vijos1414;
var
  i,j,k,m,n,p,t,u:longint;
  s:string;
begin
  readln(s);
  readln(n);
  i:=1;u:=0;p:=length(s);
  while u<n do
   begin
    if (s[i]>s[i+1])or(i=p-u) then
      begin
       delete(s,i,1);
       inc(u);dec(i);
       if i=0 then i:=1;
      end
     else
      inc(i);
   end;
  while (length(s)>1)and(s[1]='0') do
   delete(s,1,1);
  if n=p then writeln(0) else writeln(s);
end.


