var i,j,k,m,n,a,b:longint;
    x:array[1..1000] of longint;
begin
     readln(n,m);
       for i:=1 to n do

         x[i]:=i;
         k:=1;
         a:=1;
         i:=1;
     while i <m+1 do
     begin
             a:=a+(k*k*k) mod 5+1;
                  if x[a]<>0 then
                  begin
                  i:=i+1;
                  k:=k+1;
                  b:=x[a];
                        for j:=a to n do
                          x[j]:=x[j+1];
                  end;
             if x[a]=0 then
             a:=1;
      end;
writeln(b);
readln;
end.                                 

