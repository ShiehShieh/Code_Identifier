program jiangxuejin;
var a,b:string;
e,f,i,j:longint;
d:char;
function js(var a2:string):longint;
var cost,b2,b3,b4,b5,b6,b7,b8:longint; c1,c2,c3:char; 
a3:string;
begin
cost:=0;
b8:=0;
b2:=1;
repeat
b2:=b2+1;
until ord(a2[b2])=32;
b2:=b2+1;
b3:=b2;
while (ord(a2[b3])<>32) do b3:=b3+1;
a3 := copy(a2, b2, b3-b2);
val(a3,b4,b8);
b3 := b3+1;
b2:=b3;
while (ord(a2[b3])<>32) do b3 := b3 +1;
a3 := copy(a2,b2,b3-b2);
val(a3,b5,b8);
b3:=b3+1;
c1:=a2[b3];
c2:=a2[b3+2];
b3:=b3+4;
b2:=b3;
if (ord(a2[b3+1])=48) then begin
a3:= copy(a2,b3,2);
val(a3,b6,b8);
end
else begin
a3 := copy(a2,b3,1);
val(a3,b6,b8);
end;
if (b5>80)and(c1='Y') then cost := cost+850;
if (b4>85)and(c2='Y') then cost := cost+1000;
if (b4>90) then cost := cost+2000;
if (b4>85)and(b5>80) then cost := cost+4000;
if (b4>80)and(b6>=1) then cost := cost+8000;
js := cost;
end;
begin
readln(e);
readln(a);
f:=f+js(a);
for j := 2 to e do begin
readln(b);
f:=f+js(b);
if js(b)>js(a) then a := b;
end;
j := 1;
while ord(a[j])<>32 do begin
write(a[j]);
j:=j+1;
end;
writeln;
writeln(js(a));
write(f);
end. 

