type
gift=record
ans,money,ngi:integer;
ng:array [1..10] of string;
n:string;
end;
var
np,i,j,k,m:integer;
s:array [1..10] of gift;
str:string;
begin
for i:=1 to 10 do s[i].ans:=0;
readln(np);
for i:=1 to np do readln(s[i].n);
for i:=1 to np do
begin
readln(str);
for j:=1 to np do if s[j].n=str then m:=j;
readln(s[m].money,s[m].ngi);
for j:=1 to s[m].ngi do readln(s[m].ng[j]);
end;
for i:=1 to np do if s[i].ngi>0 then
begin
s[i].ans:=s[i].ans-s[i].money div s[i].ngi*s[i].ngi;
for j:=1 to s[i].ngi do for k:=1 to np do if s[i].ng[j]=s[k].n then s[k].ans:=s[k].ans+s[i].money div s[i].ngi;
end;
for i:=1 to np do writeln(s[i].n,' ',s[i].ans);
end. 

