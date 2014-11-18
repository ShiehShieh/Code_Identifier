var
q:string;
n,k,s,ans,i,j:longint;
begin
readln(n,k);
for i:=1 to n do
begin
readln(q);
s:=0;
for j:=1 to length(q) do
if q[j]=' ' then s:=s+1;
if s>=k then ans:=ans+1;
end;
writeln(ans);
end.

