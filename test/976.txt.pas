program p1153;
var
  i,j:longint;
  a,b:array[0..202]of longint;
  n:longint;
  sum1,sum2,l1,l2:longint;
  x,y,z:longint;
  f:boolean;
begin
  readln(n);
  sum1:=0;
  sum2:=0;
  l1:=n div 2;
  l2:=n-l1;
  for i:=1 to l1 do
    begin
      readln(a[i]);
      inc(sum1,a[i]);
    end;
  for i:=1 to l2 do
   begin
     readln(b[i]);
     inc(sum2,b[i]);
   end;
  f:=true;
  while f do
    begin
      f:=false;
      for i:=1 to l1 do
        for j:=1 to l2 do
          begin
            x:=sum1-a[i]+b[j];
            y:=sum2-b[j]+a[i];
            if abs(x-y)<abs(sum1-sum2) then begin
              z:=a[i];
              a[i]:=b[j];
              b[j]:=z;
              sum1:=x;
              sum2:=y;
              f:=true;
            end;
          end;
    end;
  if sum1<sum2 then writeln(sum1,' ',sum2)
    else writeln(sum2,' ',sum1);
end.

