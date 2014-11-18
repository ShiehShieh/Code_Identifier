program lkjds;
const p:array[0..9] of integer=(6,2,5,5,4,5,6,3,7,6);
var x,y,z,m,m1,m2:longint;
    n,i,j,s,o:longint;

begin

readln(n);
n:=n-4;
for i:=0 to 1000 do
 for j:=i to 1000 do
   begin
   x:=0;  y:=0;   z:=0;
   m1:=i;
   m2:=j;
   m:=i+j;

    while m1>=10 do
    begin
    x:=x+p[m1 mod 10];
     m1:=m1 div 10;
    end;
    x:=x+p[m1];

    while m2>=10 do
    begin
     y:=y+p[m2 mod 10];
    m2:= m2 div 10;
    end;
    y:=y+p[m2];


    while m>=10 do
    begin
    z:=z+p[m mod 10];
    m:= m div 10;
    end;
    z:=z+p[m];
     {inc(o); }
    if x+y+z=n then if i=j then inc(s) else inc(s,2); {write(o:10); }
   end;
   writeln(s);
   
   end.
