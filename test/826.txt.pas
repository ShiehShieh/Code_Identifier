var sum,m,tal,min,i,j,k1,k2,n:longint;a:array[0..10000]of longint;
begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
  begin
   min:=maxlongint;
   sum:=0;
   for j:=1 to n-i+1 do
       if a[j]<min then begin min:=a[j];k1:=j;end;
   sum:=sum+min;
   min:=maxlongint;
   for j:=1 to n-i+1 do
      if (a[j]<min)and(j<>k1)then begin min:=a[j];k2:=j;end;
   sum:=sum+min;
   a[k1]:=sum;
   a[k2]:=a[n-i+1];
   tal:=tal+sum;
  end;
write(tal);end.
