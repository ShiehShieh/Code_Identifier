var
 x,y,s,total,m:qword;
 i:longint;
function gcd(a,b:int64):int64;
 begin
  if (a=0) then
   gcd:=b
   else
    if b=0 then
     gcd:=a
     else
      if a>b then
       gcd:=gcd(a mod b,b)
       else
        gcd:=gcd(a,b mod a);
 end;
begin
 readln(x,y);
 s:=x*y;
 total:=0;
 m:=trunc(sqrt(s));
 for i:=x to m do
  begin
   if (s mod i=0)and(gcd(i,s div i)=x) then
    inc(total);
  end;
 total:=total*2;
 {if m*m=s then
  total:=total-1;}
 writeln(total);
end.
