program p1385;
Var
n:longint;
function calc(x:longint):longint;
begin
if x=0 then exit(0);
calc:=(x+1) div 2+calc(x div 4);
end;

Begin
readln(n);
writeln(calc(n));
End. 
