program p1152;
Var
 n,a,b,c:longint;
Procedure swap(var x,y:longint);
var
 temp:longint;
begin
 temp:=x;
 x:=y;
 y:=temp;
end;

Begin
 readln(n);
 readln(a,b,c);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if b<c then swap(b,c);
 if ((a-b=1) and (b-c=1)) or ((a-c=n-1) and (b-c=1)) or ((a-b=1) and (a-c=n-1)) then writeln('JMcat Win')
  else
   if odd(n) then writeln('PZ Win') else writeln('JMcat Win');
End.
