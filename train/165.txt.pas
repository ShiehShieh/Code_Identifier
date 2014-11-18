var x1,y1,i,p,q,pq,m,sum:longint;
    ok1,ok2:boolean;
function lcd(x,y:longint):longint;
var z:longint;
begin
    z:=y mod x;
    while z<>0 do
    begin y:=x;x:=z;z:=y mod x ;end;
    lcd:=x;
end;
function gogo(x:integer):boolean;
var i:integer;
begin
  for i:=2 to trunc(sqrt(x)) do
     if x mod i =0 then exit(false);
  exit(true);
end;

begin

     readln(x1,y1);
     ok1:=gogo(x1);
     ok2:=gogo(y1);
     if ok1 and ok2 then begin sum:=2; halt; end;
     if (y1 div x1)*x1<>y1 then sum:=0
       else
         begin
             sum:=2;
             for i:=2 to (y1 div x1 -1) do
                 begin
                    p:=i*x1;
                    q:=y1 div i;
                    if (q<=p)  then break;
                    pq:=lcd(p,q);
                    if (pq=x1) and (p div pq * q=y1) then sum:=sum+2;
                 end;
         end;

     writeln(sum);
    
end.

