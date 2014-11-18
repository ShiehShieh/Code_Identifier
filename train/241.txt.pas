program fdtgsdku;
VAR
n,k:longint;
s:string;
Procedure conversion(m,n:longint);
VAR
i,j:longint;
a:array [1..100] of longint;
BEGIN
fillchar(a,sizeof(a),0);
i:=0;
s:='';
repeat
inc(i);
a[i]:=m mod n;
m:=m div n;
until m=0;
for j:=i downto 1 do
s:=s+chr((a[j])+48);
END;
Procedure algorism(VAR s:string;n:longint);
VAR
i,j,l,power:longint;
a:array [1..20] of longint;
BEGIN
fillchar(a,sizeof(a),0);
for i:=1 to length(s) do a[i]:=ord(s[i])-48;
power:=1;
l:=a[length(s)];
for i:=length(s)-1 downto 1 do
BEGIN
power:=power*n;
l:=l+a[i]*power;
END;
write(l);
END;
BEGIN
readln(k,n);
conversion(n,2);
algorism(s,k);
END.
