var
 i,j,k,n:longint;
  a:array [1..1000] of longint;
begin
 readln(k,n);
  a[1]:=1;
   a[2]:=k;
   j:=2;
    repeat
      a[j*2]:=a[j]*k;
       for i:=1 to j-1 do a[j+i]:=a[j]+a[i];
        j:=j*2;
    until j>=n;
   writeln(a[n]);
end.   
