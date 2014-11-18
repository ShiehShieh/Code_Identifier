var a:ansistring;
    b:longint;
begin
read(a);
val(a[length(a)-1]+a[length(a)],b);
case b mod 4 of 
0,3:writeln(0);
1,2:writeln(1);
end;
end.                 
