program vijos1133;
var a:array[1..30]of longint;
    b:array[0..20000]of longint;
    v,n,i,j,t:longint;
begin
     readln(v);
     readln(n);
     for i:=1 to n do readln(a[i]);
     for i:=1 to n do
         for j:=v downto 1 do
         if j-a[i]>=0 then
            if b[j-a[i]]+a[i]>b[j] then b[j]:=b[j-a[i]]+a[i];
     t:=0;
     for i:=1 to v do
         if b[i]>t then t:=b[i];
     writeln(v-t);
end.
