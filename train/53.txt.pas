program p1073;
var
  n,i,j,p,k:longint;

begin
 readln(n);
 j:=0;
 p:=0;
 while n>0 do
   begin
    inc(j);
    if n>j then
    begin
    k:=1;
    for i:=1 to j-1 do
     begin
       k:=k*2;
       k:=k mod 10000;
     end;

    p:=(p+k*j) mod 10000;
    dec(n,j);
    end
    else
    begin
    k:=1;
      for i:=1 to j-1 do
     begin
       k:=k*2;
       k:=k mod 10000;
     end;
    p:=(p+k*n) mod 10000;
    n:=-1;
    end;
   end;
  writeln(p);
end.

