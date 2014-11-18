var
m,n,i,x:word;
flag:boolean;
a:array[1..12]of word;
begin
m:=0;
n:=0;
flag:=true;
for i:=1 to 12 do
readln(a[i]);
for i:=1 to 12 do
begin
m:=m+300;
if m-a[i]>=100 then begin
if m-a[i]<200 then begin
n:=n+100;
m:=m-a[i]-100;
end else begin if m-a[i]<300 then begin
n:=n+200;
m:=m-a[i]-200;
end else begin
n:=n+300; m:=m-a[i]-300;
end
end
end  else begin
if a[i]>m then begin flag:=false;
x:=i;
end;
if a[i]<=m then  m:=m-a[i];
end;
if flag=false then break;
end;
if flag=true then write((n div 10)*12+m) else write('-',x);
end. 
