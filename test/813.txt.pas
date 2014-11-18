var
tmp,jl,jss,n,i,j,min,sum,w:longint;
a:array[0..10000] of longint;
begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
begin
min:=maxlongint;
sum:=0;
for j:=1 to n-i+1 do if a[j]<min then begin min:=a[j];jl:=j;end;
sum:=sum+min;
min:=maxlongint;
for j:=1 to n-i+1 do if (a[j]<min)and(jl<>j) then begin min:=a[j];jss:=j;end;
sum:=sum+min;
a[jl]:=sum;
w:=w+sum;
tmp:=a[jss];
a[jss]:=a[n-i+1];
a[n-i+1]:=tmp;
end;
write(w);
end.
