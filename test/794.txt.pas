var
n,m,i,j,max,k,sum:integer;
apple,taotao:array[1..2000] of integer; 
a:array[1..2000] of boolean;
begin
readln(m,n);
for j:=1 to m do
readln(apple[j]);
for i:=1 to n do
readln(taotao[i]);
sum:=0;
for i:=1 to n do
a[i]:=true;
for j:=1 to m do
begin
max:=0;
k:=0;
for i:=1 to n do
begin
if (taotao[i]<apple[j]) and (a[i]=true) then 
begin
if max<taotao[i] then 
begin
max:=taotao[i];
k:=i;
end;
end;
end;
if max<>0 then a[k]:=false;
end;
for i:=1 to n do 
if a[i]=true then sum:=sum+1;
writeln(sum);
end.
